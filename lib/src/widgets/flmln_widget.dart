import 'dart:ffi' hide Size;

import 'package:ffi/ffi.dart';
import 'package:flmln/src/gen/flmln_bindings.dart';
import 'package:flmln/src/style/style.dart';
import 'package:flmln/src/widgets/style_inspector.dart';
import 'package:flmln/src/widgets/flutter_map_flmln.dart';
import 'package:flutter/material.dart' hide Visibility;
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';
import 'package:metal_capture_util/metal_capture_util.dart';

void test() async {
  debugPrint(test_flmln().toString());
}

class FlMlnWidget extends StatefulWidget {
  const FlMlnWidget({super.key, required this.styleUrl, required this.apiKey});

  final String styleUrl;
  final String apiKey;

  @override
  State<FlMlnWidget> createState() => FlMlnWidgetState();
}

typedef VoidCallback = Void Function();

class FlMlnWidgetState extends State<FlMlnWidget> with WidgetsBindingObserver {
  var enabled = false;
  var isRasterOverlayEnabled = false;

  late mbgl_tile_server_options_t tileServerOptions;
  late flmln_renderer_frontend_t rendererFrontend;
  late flmln_map_observer_t mapObserver;
  late mbgl_map_options_t mapOptions;
  late mbgl_resource_options_t resourceOptions;
  late mbgl_map_t map;

  final repaint = ChangeNotifier();

  @override
  void initState() {
    super.initState();
    flmln_initialize();

    mapOptions = mbgl_map_options_create();
    mbgl_map_options_set_mode(mapOptions, MbglMapMode.MbglMapMode_Continuous);
    tileServerOptions = mbgl_tile_server_options_maptiler_configuration_create();

    resourceOptions = mbgl_resource_options_create();
    mbgl_resource_options_set_api_key(resourceOptions, widget.apiKey.toNativeUtf8().cast());
    mbgl_resource_options_set_tile_server_options(resourceOptions, tileServerOptions);

    mapObserver = flmln_map_observer_create();
    rendererFrontend = flmln_renderer_frontend_create();

    map = mbgl_map_create(
      rendererFrontend,
      mapObserver,
      mapOptions,
      resourceOptions,
    );

    mbgl_map_style_load_url(map, widget.styleUrl.toNativeUtf8().cast());
  }

  @override
  void didHaveMemoryPressure() {
    flmln_renderer_frontend_reduce_memory_use(rendererFrontend);
    super.didHaveMemoryPressure();
  }

  @override
  Widget build(BuildContext context) {
    // NYC
    final initialPosition = LatLng(40.7128, -74.0060);
    final initialZoom = 12.0;

    return Row(
      children: [
        Drawer(
          width: 320.0,
          child: enabled ? StyleInspector(style: Style.fromNative(mbgl_map_get_style(map))) : null,
        ),
        Expanded(
          child: FlutterMap(
            options: MapOptions(
              backgroundColor: Colors.black,
              initialCenter: initialPosition,
              initialZoom: initialZoom,
            ),
            children: [
              if (enabled) FlutterMapFlMlnWidget(map: map, rendererFrontend: rendererFrontend),

              if (isRasterOverlayEnabled)
                Opacity(
                  opacity: 0.5,
                  child: TileLayer(
                    urlTemplate: 'https://tile.openstreetmap.org/{z}/{x}/{y}.png',
                    userAgentPackageName: 'com.kekland.flmln_example',
                  ),
                ),

              // Example marker
              MarkerLayer(
                markers: [
                  // Kyiv
                  Marker(
                    point: initialPosition,
                    width: 80,
                    height: 80,
                    child: Icon(
                      Icons.location_on,
                      color: Colors.red,
                      size: 40,
                    ),
                  ),
                ],
              ),

              // Actions
              SafeArea(
                minimum: const EdgeInsets.all(16.0),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  spacing: 8.0,
                  children: [
                    ElevatedButton(
                      onPressed: () {
                        enabled = !enabled;
                        setState(() {});
                      },
                      child: Text('Toggle'),
                    ),
                    ElevatedButton(
                      onPressed: () {
                        isRasterOverlayEnabled = !isRasterOverlayEnabled;
                        setState(() {});
                      },
                      child: Text('Toggle raster overlay'),
                    ),
                    ElevatedButton(
                      onPressed: () {
                        final layer = FillLayer(
                          id: 'my-fill-layer',
                          sourceId: 'maptiler_planet',
                          fillColor: PropertyValue.constant(Colors.purple),
                          fillOpacity: PropertyValue.constant(0.5),
                          sourceLayer: 'landuse',
                        );

                        // change parameters
                        layer.fillColor = PropertyValue.constant(Colors.orange);

                        // insert layer
                        final style = Style.fromNative(mbgl_map_get_style(map));
                        style.addLayer(layer);
                      },
                      child: Text('Insert layer'),
                    ),
                    ElevatedButton(
                      onPressed: () {
                        MetalCapture.captureNextFrame(reassemble: true, openFile: true);
                      },
                      child: Text('Metal capture'),
                    ),
                  ],
                ),
              ),
            ],
          ),
        ),
      ],
    );
  }
}
