import 'package:flmln/src/gen/flmln_bindings.dart';
import 'package:flmln/src/widgets/flmln_renderer.dart';
import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';

class FlutterMapFlMlnWidget extends StatelessWidget {
  const FlutterMapFlMlnWidget({
    super.key,
    required this.map,
    required this.rendererFrontend,
  });

  final mbgl_map_t map;
  final flmln_renderer_frontend_t rendererFrontend;

  @override
  Widget build(BuildContext context) {
    final camera = MapCamera.of(context);

    // Sync the Flutter Map camera to the FlMln map.
    final cameraOptions = mbgl_camera_options_create();
    mbgl_camera_options_set_center(cameraOptions, camera.center.latitude, camera.center.longitude);
    mbgl_camera_options_set_zoom(cameraOptions, camera.zoom - 1);
    mbgl_camera_options_set_bearing(cameraOptions, -camera.rotation);
    mbgl_map_jump_to(map, cameraOptions);
    mbgl_camera_options_destroy(cameraOptions);

    return FlMlnRendererWidget(map: map, rendererFrontend: rendererFrontend);
  }
}
