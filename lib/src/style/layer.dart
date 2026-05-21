import 'dart:ffi';

import 'package:flutter/widgets.dart' as ui;

import 'package:ffi/ffi.dart';
import 'package:flmln/src/gen/flmln_bindings.dart';
import 'package:flmln/src/utils/ffi_utils.dart';

import 'style.dart';

part 'package:flmln/src/gen/style.gen.dart';

/// Rendering type of this layer.
enum LayerType {
  /// The background color or pattern of the map.
  background,

  /// A filled polygon with an optional stroked border.
  fill,

  /// A stroked line.
  line,

  /// An icon or a text label.
  symbol,

  /// Raster map textures such as satellite imagery.
  raster,

  /// A filled circle.
  circle,

  /// A heatmap.
  heatmap,

  /// Client-side hillshading visualization based on DEM data. The implementation supports Mapbox Terrain RGB, Mapzen Terrarium tiles and custom encodings.
  hillshade,

  /// An extruded (3D) polygon.
  fillExtrusion,

  /// Unknown layer type: supported by mapvina-native, but not yet by this binding.
  unknown;

  static LayerType _fromNative(MbglStyleLayerType type) => switch (type) {
    MbglStyleLayerType.MbglStyleLayerType_Background => LayerType.background,
    MbglStyleLayerType.MbglStyleLayerType_Fill => LayerType.fill,
    MbglStyleLayerType.MbglStyleLayerType_Line => LayerType.line,
    MbglStyleLayerType.MbglStyleLayerType_Symbol => LayerType.symbol,
    MbglStyleLayerType.MbglStyleLayerType_Raster => LayerType.raster,
    MbglStyleLayerType.MbglStyleLayerType_Circle => LayerType.circle,
    MbglStyleLayerType.MbglStyleLayerType_Heatmap => LayerType.heatmap,
    MbglStyleLayerType.MbglStyleLayerType_Hillshade => LayerType.hillshade,
    MbglStyleLayerType.MbglStyleLayerType_FillExtrusion => LayerType.fillExtrusion,
    _ => LayerType.unknown,
  };
}

abstract class Layer extends NativeOwning<mbgl_style_layer_t> {
  Layer._fromNative(super.ptr, {super.ownedByDart = false});

  Layer._(
    super.ptr, {
    String? sourceLayer,
    double? minZoom,
    double? maxZoom,
  }) : super(ownedByDart: true) {
    if (sourceLayer != null) this.sourceLayer = sourceLayer;
    if (minZoom != null) this.minZoom = minZoom;
    if (maxZoom != null) this.maxZoom = maxZoom;
  }

  /// Unique layer name.
  String get id => mbgl_style_layer_get_id(ptr).toDartString(free: true);

  /// Rendering type of this layer.
  LayerType get type => LayerType._fromNative(mbgl_style_layer_get_type(ptr));

  /// Name of a source description to be used for this layer. Required for all layer types except `background`.
  String get sourceId => mbgl_style_layer_get_source(ptr).toDartString(free: true);
  set sourceId(String value) => withZoneArena(
    () => mbgl_style_layer_set_source(ptr, value.toNativeUtf8(allocator: zoneArena).cast()),
  );

  /// Layer to use from a vector tile source. Required for vector tile sources; prohibited for all other source types, including GeoJSON sources.
  String get sourceLayer => mbgl_style_layer_get_source_layer(ptr).toDartString(free: true);
  set sourceLayer(String value) => withZoneArena(
    () => mbgl_style_layer_set_source_layer(ptr, value.toNativeUtf8(allocator: zoneArena).cast()),
  );

  /// The minimum zoom level for the layer. At zoom levels less than the minzoom, the layer will be hidden.
  double get minZoom => mbgl_style_layer_get_min_zoom(ptr);
  set minZoom(double value) => mbgl_style_layer_set_min_zoom(ptr, value);

  /// The maximum zoom level for the layer. At zoom levels equal to or greater than the maxzoom, the layer will be hidden.
  double get maxZoom => mbgl_style_layer_get_max_zoom(ptr);
  set maxZoom(double value) => mbgl_style_layer_set_max_zoom(ptr, value);

  /// A expression specifying conditions on source features. Only features that match the filter are displayed. Zoom expressions in filters are only evaluated at integer zoom levels. The `feature-state` expression is not supported in filter expressions.
  // final dynamic filter;

  Map<String, Object> get properties => {
    'sourceId': sourceId,
    'sourceLayer': sourceLayer,
    'minZoom': minZoom,
    'maxZoom': maxZoom,
  };
}
