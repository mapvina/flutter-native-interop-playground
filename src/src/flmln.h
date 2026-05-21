#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define FLMLN_EXPORT __attribute__((__visibility__("default"))) __attribute__((__used__))

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#define FFI EXTERNC FLMLN_EXPORT

EXTERNC FLMLN_EXPORT int test_flmln();
EXTERNC FLMLN_EXPORT void flmln_initialize();

// typedefs
typedef void* mbgl_map_options_t;
typedef void* mbgl_tile_server_options_t;
typedef void* mbgl_resource_options_t;
typedef void* mbgl_map_t;
typedef void* flmln_map_observer_t;
typedef void* flmln_renderer_frontend_t;
typedef void* mbgl_camera_options_t;
typedef void* mbgl_style_t;
typedef void* mbgl_style_layer_t;
typedef void* mbgl_style_background_layer_t;
typedef void* mbgl_style_expression_t;
typedef void* mbgl_style_expression_image_t;
typedef void* mbgl_style_expression_formatted_t;
typedef void* mbgl_style_property_value_t;
typedef void* mbgl_color_t;
typedef void* mbgl_padding_t;
typedef void* mbgl_variable_anchor_offset_collection_t;

// ---------------------------------
// mbgl_map_options_t
// ---------------------------------

EXTERNC FLMLN_EXPORT mbgl_map_options_t mbgl_map_options_create();
EXTERNC FLMLN_EXPORT void mbgl_map_options_destroy(mbgl_map_options_t _mapOptions);

enum MbglMapMode {
  MbglMapMode_Continuous = 0,
  MbglMapMode_Static = 1,
  MbglMapMode_Tile = 2,
};
EXTERNC FLMLN_EXPORT void mbgl_map_options_set_mode(mbgl_map_options_t _mapOptions, enum MbglMapMode mode);
EXTERNC FLMLN_EXPORT void mbgl_map_options_set_size(mbgl_map_options_t _mapOptions, uint32_t width, uint32_t height);
EXTERNC FLMLN_EXPORT void mbgl_map_options_set_pixel_ratio(mbgl_map_options_t _mapOptions, float pixelRatio);

// ----------------------------------
// mbgl_tile_server_options_t
// ----------------------------------

EXTERNC FLMLN_EXPORT mbgl_tile_server_options_t mbgl_tile_server_options_create();
EXTERNC FLMLN_EXPORT mbgl_tile_server_options_t mbgl_tile_server_options_mapbox_configuration_create();
EXTERNC FLMLN_EXPORT mbgl_tile_server_options_t mbgl_tile_server_options_maptiler_configuration_create();
EXTERNC FLMLN_EXPORT mbgl_tile_server_options_t mbgl_tile_server_options_mapvina_configuration_create();
EXTERNC FLMLN_EXPORT void mbgl_tile_server_options_destroy(mbgl_tile_server_options_t _tileServerOptions);

// ---------------------------------
// mbgl_resource_options_t
// ---------------------------------

EXTERNC FLMLN_EXPORT mbgl_resource_options_t mbgl_resource_options_create();
EXTERNC FLMLN_EXPORT void mbgl_resource_options_destroy(mbgl_resource_options_t _resourceOptions);
EXTERNC FLMLN_EXPORT void mbgl_resource_options_set_api_key(mbgl_resource_options_t _resourceOptions,
                                                            const char* apiKey);
EXTERNC FLMLN_EXPORT void mbgl_resource_options_set_tile_server_options(mbgl_resource_options_t _resourceOptions,
                                                                        mbgl_tile_server_options_t _tileServerOptions);

// ---------------------------------
// flmln_map_observer_t
// ---------------------------------

EXTERNC FLMLN_EXPORT flmln_map_observer_t flmln_map_observer_create();
EXTERNC FLMLN_EXPORT void flmln_map_observer_destroy(flmln_map_observer_t _mapObserver);

// ---------------------------------
// flmln_renderer_frontend_t
// ---------------------------------

EXTERNC FLMLN_EXPORT flmln_renderer_frontend_t flmln_renderer_frontend_create();
EXTERNC FLMLN_EXPORT void flmln_renderer_frontend_destroy(flmln_renderer_frontend_t _rendererFrontend);
EXTERNC FLMLN_EXPORT void flmln_renderer_frontend_render(flmln_renderer_frontend_t _rendererFrontend);
EXTERNC FLMLN_EXPORT void flmln_renderer_frontend_set_size_and_pixel_ratio(flmln_renderer_frontend_t _rendererFrontend,
                                                                           uint32_t width, uint32_t height,
                                                                           float pixelRatio);
EXTERNC FLMLN_EXPORT int64_t flmln_renderer_frontend_get_texture_id(flmln_renderer_frontend_t _rendererFrontend);
EXTERNC FLMLN_EXPORT void flmln_renderer_frontend_set_invalidate_callback(flmln_renderer_frontend_t _rendererFrontend,
                                                                          void (*invalidateCallback)(void));
EXTERNC FLMLN_EXPORT void flmln_renderer_frontend_reduce_memory_use(flmln_renderer_frontend_t _rendererFrontend);
EXTERNC FLMLN_EXPORT void flmln_renderer_frontend_set_tile_cache_enabled(flmln_renderer_frontend_t _rendererFrontend,
                                                                         bool enabled);
EXTERNC FLMLN_EXPORT bool flmln_renderer_frontend_get_tile_cache_enabled(flmln_renderer_frontend_t _rendererFrontend);

// ---------------------------------
// mbgl_camera_options_t
// ---------------------------------

EXTERNC FLMLN_EXPORT mbgl_camera_options_t mbgl_camera_options_create();
EXTERNC FLMLN_EXPORT void mbgl_camera_options_destroy(mbgl_camera_options_t _cameraOptions);
EXTERNC FLMLN_EXPORT void mbgl_camera_options_set_center(mbgl_camera_options_t _cameraOptions, double latitude,
                                                         double longitude);
EXTERNC FLMLN_EXPORT void mbgl_camera_options_set_zoom(mbgl_camera_options_t _cameraOptions, double zoom);
EXTERNC FLMLN_EXPORT void mbgl_camera_options_set_bearing(mbgl_camera_options_t _cameraOptions, double bearing);
EXTERNC FLMLN_EXPORT void mbgl_camera_options_set_pitch(mbgl_camera_options_t _cameraOptions, double pitch);

// ---------------------------------
// mbgl_map_t
// ---------------------------------

EXTERNC FLMLN_EXPORT mbgl_map_t mbgl_map_create(flmln_renderer_frontend_t _rendererFrontend,
                                                flmln_map_observer_t _mapObserver, mbgl_map_options_t _mapOptions,
                                                mbgl_resource_options_t _resourceOptions);
EXTERNC FLMLN_EXPORT void mbgl_map_destroy(mbgl_map_t map);
EXTERNC FLMLN_EXPORT void mbgl_map_style_load_url(mbgl_map_t _map, const char* url);
EXTERNC FLMLN_EXPORT void mbgl_map_jump_to(mbgl_map_t _map, mbgl_camera_options_t _cameraOptions);
EXTERNC FLMLN_EXPORT void mbgl_map_set_size(mbgl_map_t _map, uint32_t width, uint32_t height);
EXTERNC FLMLN_EXPORT mbgl_style_t mbgl_map_get_style(mbgl_map_t _map);

// ---------------------------------
// mbgl_style_t
// ---------------------------------

EXTERNC FLMLN_EXPORT char* mbgl_style_get_name(mbgl_style_t _style);

EXTERNC FLMLN_EXPORT size_t mbgl_style_get_layers_length(mbgl_style_t _style);
EXTERNC FLMLN_EXPORT mbgl_style_layer_t mbgl_style_get_layer_at(mbgl_style_t _style, size_t index);

EXTERNC FLMLN_EXPORT mbgl_style_layer_t mbgl_style_get_layer(mbgl_style_t _style, const char* layerId);
EXTERNC FLMLN_EXPORT void mbgl_style_add_layer(mbgl_style_t _style, mbgl_style_layer_t _layer,
                                               const char* beforeLayerId);
EXTERNC FLMLN_EXPORT mbgl_style_layer_t mbgl_style_remove_layer(mbgl_style_t _style, const char* layerId);

// ---------------------------------
// mbgl_style_layer_t
// ---------------------------------

enum MbglStyleLayerType {
  MbglStyleLayerType_Fill = 0,
  MbglStyleLayerType_Line = 1,
  MbglStyleLayerType_Symbol = 2,
  MbglStyleLayerType_Circle = 3,
  MbglStyleLayerType_Heatmap = 4,
  MbglStyleLayerType_FillExtrusion = 5,
  MbglStyleLayerType_Raster = 6,
  MbglStyleLayerType_Hillshade = 7,
  MbglStyleLayerType_Background = 8,
  MbglStyleLayerType_Unknown = 9,
};

EXTERNC FLMLN_EXPORT void mbgl_style_layer_destroy(mbgl_style_layer_t _layer);

EXTERNC FLMLN_EXPORT const char* mbgl_style_layer_get_id(mbgl_style_layer_t _layer);
EXTERNC FLMLN_EXPORT enum MbglStyleLayerType mbgl_style_layer_get_type(mbgl_style_layer_t _layer);

EXTERNC FLMLN_EXPORT const char* mbgl_style_layer_get_source(mbgl_style_layer_t _layer);
EXTERNC FLMLN_EXPORT void mbgl_style_layer_set_source(mbgl_style_layer_t _layer, const char* sourceId);

EXTERNC FLMLN_EXPORT const char* mbgl_style_layer_get_source_layer(mbgl_style_layer_t _layer);
EXTERNC FLMLN_EXPORT void mbgl_style_layer_set_source_layer(mbgl_style_layer_t _layer, const char* sourceLayerId);

EXTERNC FLMLN_EXPORT float mbgl_style_layer_get_min_zoom(mbgl_style_layer_t _layer);
EXTERNC FLMLN_EXPORT void mbgl_style_layer_set_min_zoom(mbgl_style_layer_t _layer, float minZoom);

EXTERNC FLMLN_EXPORT float mbgl_style_layer_get_max_zoom(mbgl_style_layer_t _layer);
EXTERNC FLMLN_EXPORT void mbgl_style_layer_set_max_zoom(mbgl_style_layer_t _layer, float maxZoom);

// ---------------------------------
// mbgl_color_t
// ---------------------------------

EXTERNC FLMLN_EXPORT mbgl_color_t mbgl_color_create_from_rgba(float r, float g, float b, float a);
EXTERNC FLMLN_EXPORT void mbgl_color_destroy(mbgl_color_t _color);
EXTERNC FLMLN_EXPORT float mbgl_color_get_r(mbgl_color_t _color);
EXTERNC FLMLN_EXPORT float mbgl_color_get_g(mbgl_color_t _color);
EXTERNC FLMLN_EXPORT float mbgl_color_get_b(mbgl_color_t _color);
EXTERNC FLMLN_EXPORT float mbgl_color_get_a(mbgl_color_t _color);

// --------------------------------
// mbgl_padding_t
// --------------------------------

EXTERNC FLMLN_EXPORT mbgl_padding_t mbgl_padding_create(float top, float left, float bottom, float right);
EXTERNC FLMLN_EXPORT void mbgl_padding_destroy(mbgl_padding_t _padding);
EXTERNC FLMLN_EXPORT float mbgl_padding_get_top(mbgl_padding_t _padding);
EXTERNC FLMLN_EXPORT float mbgl_padding_get_right(mbgl_padding_t _padding);
EXTERNC FLMLN_EXPORT float mbgl_padding_get_bottom(mbgl_padding_t _padding);
EXTERNC FLMLN_EXPORT float mbgl_padding_get_left(mbgl_padding_t _padding);

// ---------------------------------
// utils
// ---------------------------------

EXTERNC FLMLN_EXPORT void flmln_utils_run_loop_once();
