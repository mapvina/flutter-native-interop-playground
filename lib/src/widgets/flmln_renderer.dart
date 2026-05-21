import 'dart:ffi' hide Size;

import 'package:flmln/src/gen/flmln_bindings.dart';
import 'package:flutter/material.dart';

class FlMlnRendererWidget extends StatefulWidget {
  const FlMlnRendererWidget({
    super.key,
    required this.map,
    required this.rendererFrontend,
  });

  final mbgl_map_t map;
  final flmln_renderer_frontend_t rendererFrontend;

  @override
  State<FlMlnRendererWidget> createState() => _FlMlnRendererWidgetState();
}

typedef NativeVoidCallback = Void Function();

class _FlMlnRendererWidgetState extends State<FlMlnRendererWidget> {
  Size? _lastSize;
  double? _lastPixelRatio;

  mbgl_map_t get map => widget.map;
  flmln_renderer_frontend_t get rendererFrontend => widget.rendererFrontend;

  @override
  void initState() {
    super.initState();

    final onInvalidate = NativeCallable<NativeVoidCallback>.listener(_onInvalidate);
    flmln_renderer_frontend_set_invalidate_callback(rendererFrontend, onInvalidate.nativeFunction);
  }

  void _onInvalidate() {
    WidgetsBinding.instance.scheduleFrameCallback((_) {
      if (mounted) {
        setState(() {});
      }
    });
  }

  @override
  void dispose() {
    flmln_renderer_frontend_set_invalidate_callback(rendererFrontend, nullptr);
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    final pixelRatio = MediaQuery.devicePixelRatioOf(context);

    return LayoutBuilder(
      builder: (context, constraints) {
        final size = constraints.biggest;
        final isSurfaceDifferent = size != _lastSize || pixelRatio != _lastPixelRatio;

        // If the size or pixel ratio has changed, update the map and renderer frontend.
        if (isSurfaceDifferent) {
          _lastSize = size;
          _lastPixelRatio = pixelRatio;

          mbgl_map_set_size(map, size.width.round(), size.height.round());
          flmln_renderer_frontend_set_size_and_pixel_ratio(
            rendererFrontend,
            size.width.toInt(),
            size.height.toInt(),
            pixelRatio,
          );
        }

        // TODO: maybe call this during paint phase.
        flmln_renderer_frontend_render(rendererFrontend);

        return SizedBox.fromSize(
          size: size,
          child: Texture(
            textureId: flmln_renderer_frontend_get_texture_id(rendererFrontend),
          ),
        );
      },
    );
  }
}
