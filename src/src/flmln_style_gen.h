// GENERATED CODE - DO NOT MODIFY BY HAND
// Generated via tool/generate_style.dart

#pragma once

#include "flmln.h"
#include "stdbool.h"
#include "stddef.h"

#define const_char const char*

/**
 * Whether this layer is displayed.
 */
enum MBGL_STYLE_VISIBILITY {
  /**
   * The layer is shown.
   */
  MBGL_STYLE_VISIBILITY_VISIBLE = 0,
  /**
   * The layer is not shown.
   */
  MBGL_STYLE_VISIBILITY_NONE = 1,
};

/**
 * Controls the frame of reference for `fill-translate`.
 */
enum MBGL_STYLE_FILL_TRANSLATE_ANCHOR {
  /**
   * The fill is translated relative to the map.
   */
  MBGL_STYLE_FILL_TRANSLATE_ANCHOR_MAP = 0,
  /**
   * The fill is translated relative to the viewport.
   */
  MBGL_STYLE_FILL_TRANSLATE_ANCHOR_VIEWPORT = 1,
};

/**
 * The display of line endings.
 */
enum MBGL_STYLE_LINE_CAP {
  /**
   * A cap with a squared-off end which is drawn to the exact endpoint of the line.
   */
  MBGL_STYLE_LINE_CAP_BUTT = 0,
  /**
   * A cap with a rounded end which is drawn beyond the endpoint of the line at a radius of one-half of the line's width and centered on the endpoint of the line.
   */
  MBGL_STYLE_LINE_CAP_ROUND = 1,
  /**
   * A cap with a squared-off end which is drawn beyond the endpoint of the line at a distance of one-half of the line's width.
   */
  MBGL_STYLE_LINE_CAP_SQUARE = 2,
};

/**
 * The display of lines when joining.
 */
enum MBGL_STYLE_LINE_JOIN {
  /**
   * A join with a squared-off end which is drawn beyond the endpoint of the line at a distance of one-half of the line's width.
   */
  MBGL_STYLE_LINE_JOIN_BEVEL = 0,
  /**
   * A join with a rounded end which is drawn beyond the endpoint of the line at a radius of one-half of the line's width and centered on the endpoint of the line.
   */
  MBGL_STYLE_LINE_JOIN_ROUND = 1,
  /**
   * A join with a sharp, angled corner which is drawn with the outer sides beyond the endpoint of the path until they meet.
   */
  MBGL_STYLE_LINE_JOIN_MITER = 2,
};

/**
 * Controls the frame of reference for `line-translate`.
 */
enum MBGL_STYLE_LINE_TRANSLATE_ANCHOR {
  /**
   * The line is translated relative to the map.
   */
  MBGL_STYLE_LINE_TRANSLATE_ANCHOR_MAP = 0,
  /**
   * The line is translated relative to the viewport.
   */
  MBGL_STYLE_LINE_TRANSLATE_ANCHOR_VIEWPORT = 1,
};

/**
 * Label placement relative to its geometry.
 */
enum MBGL_STYLE_SYMBOL_PLACEMENT {
  /**
   * The label is placed at the point where the geometry is located.
   */
  MBGL_STYLE_SYMBOL_PLACEMENT_POINT = 0,
  /**
   * The label is placed along the line of the geometry. Can only be used on `LineString` and `Polygon` geometries.
   */
  MBGL_STYLE_SYMBOL_PLACEMENT_LINE = 1,
  /**
   * The label is placed at the center of the line of the geometry. Can only be used on `LineString` and `Polygon` geometries. Note that a single feature in a vector tile may contain multiple line geometries.
   */
  MBGL_STYLE_SYMBOL_PLACEMENT_LINE_CENTER = 2,
};

/**
 * Determines whether overlapping symbols in the same layer are rendered in the order that they appear in the data source or by their y-position relative to the viewport. To control the order and prioritization of symbols otherwise, use `symbol-sort-key`.
 */
enum MBGL_STYLE_SYMBOL_Z_ORDER {
  /**
   * Sorts symbols by `symbol-sort-key` if set. Otherwise, sorts symbols by their y-position relative to the viewport if `icon-allow-overlap` or `text-allow-overlap` is set to `true` or `icon-ignore-placement` or `text-ignore-placement` is `false`.
   */
  MBGL_STYLE_SYMBOL_Z_ORDER_AUTO = 0,
  /**
   * Sorts symbols by their y-position relative to the viewport if `icon-allow-overlap` or `text-allow-overlap` is set to `true` or `icon-ignore-placement` or `text-ignore-placement` is `false`.
   */
  MBGL_STYLE_SYMBOL_Z_ORDER_VIEWPORT_Y = 1,
  /**
   * Sorts symbols by `symbol-sort-key` if set. Otherwise, no sorting is applied; symbols are rendered in the same order as the source data.
   */
  MBGL_STYLE_SYMBOL_Z_ORDER_SOURCE = 2,
};

/**
 * In combination with `symbol-placement`, determines the rotation behavior of icons.
 */
enum MBGL_STYLE_ICON_ROTATION_ALIGNMENT {
  /**
   * When `symbol-placement` is set to `point`, aligns icons east-west. When `symbol-placement` is set to `line` or `line-center`, aligns icon x-axes with the line.
   */
  MBGL_STYLE_ICON_ROTATION_ALIGNMENT_MAP = 0,
  /**
   * Produces icons whose x-axes are aligned with the x-axis of the viewport, regardless of the value of `symbol-placement`.
   */
  MBGL_STYLE_ICON_ROTATION_ALIGNMENT_VIEWPORT = 1,
  /**
   * When `symbol-placement` is set to `point`, this is equivalent to `viewport`. When `symbol-placement` is set to `line` or `line-center`, this is equivalent to `map`.
   */
  MBGL_STYLE_ICON_ROTATION_ALIGNMENT_AUTO = 2,
};

/**
 * Scales the icon to fit around the associated text.
 */
enum MBGL_STYLE_ICON_TEXT_FIT {
  /**
   * The icon is displayed at its intrinsic aspect ratio.
   */
  MBGL_STYLE_ICON_TEXT_FIT_NONE = 0,
  /**
   * The icon is scaled in the x-dimension to fit the width of the text.
   */
  MBGL_STYLE_ICON_TEXT_FIT_WIDTH = 1,
  /**
   * The icon is scaled in the y-dimension to fit the height of the text.
   */
  MBGL_STYLE_ICON_TEXT_FIT_HEIGHT = 2,
  /**
   * The icon is scaled in both x- and y-dimensions.
   */
  MBGL_STYLE_ICON_TEXT_FIT_BOTH = 3,
};

/**
 * Part of the icon placed closest to the anchor.
 */
enum MBGL_STYLE_ICON_ANCHOR {
  /**
   * The center of the icon is placed closest to the anchor.
   */
  MBGL_STYLE_ICON_ANCHOR_CENTER = 0,
  /**
   * The left side of the icon is placed closest to the anchor.
   */
  MBGL_STYLE_ICON_ANCHOR_LEFT = 1,
  /**
   * The right side of the icon is placed closest to the anchor.
   */
  MBGL_STYLE_ICON_ANCHOR_RIGHT = 2,
  /**
   * The top of the icon is placed closest to the anchor.
   */
  MBGL_STYLE_ICON_ANCHOR_TOP = 3,
  /**
   * The bottom of the icon is placed closest to the anchor.
   */
  MBGL_STYLE_ICON_ANCHOR_BOTTOM = 4,
  /**
   * The top left corner of the icon is placed closest to the anchor.
   */
  MBGL_STYLE_ICON_ANCHOR_TOP_LEFT = 5,
  /**
   * The top right corner of the icon is placed closest to the anchor.
   */
  MBGL_STYLE_ICON_ANCHOR_TOP_RIGHT = 6,
  /**
   * The bottom left corner of the icon is placed closest to the anchor.
   */
  MBGL_STYLE_ICON_ANCHOR_BOTTOM_LEFT = 7,
  /**
   * The bottom right corner of the icon is placed closest to the anchor.
   */
  MBGL_STYLE_ICON_ANCHOR_BOTTOM_RIGHT = 8,
};

/**
 * Orientation of icon when map is pitched.
 */
enum MBGL_STYLE_ICON_PITCH_ALIGNMENT {
  /**
   * The icon is aligned to the plane of the map.
   */
  MBGL_STYLE_ICON_PITCH_ALIGNMENT_MAP = 0,
  /**
   * The icon is aligned to the plane of the viewport.
   */
  MBGL_STYLE_ICON_PITCH_ALIGNMENT_VIEWPORT = 1,
  /**
   * Automatically matches the value of `icon-rotation-alignment`.
   */
  MBGL_STYLE_ICON_PITCH_ALIGNMENT_AUTO = 2,
};

/**
 * Orientation of text when map is pitched.
 */
enum MBGL_STYLE_TEXT_PITCH_ALIGNMENT {
  /**
   * The text is aligned to the plane of the map.
   */
  MBGL_STYLE_TEXT_PITCH_ALIGNMENT_MAP = 0,
  /**
   * The text is aligned to the plane of the viewport.
   */
  MBGL_STYLE_TEXT_PITCH_ALIGNMENT_VIEWPORT = 1,
  /**
   * Automatically matches the value of `text-rotation-alignment`.
   */
  MBGL_STYLE_TEXT_PITCH_ALIGNMENT_AUTO = 2,
};

/**
 * In combination with `symbol-placement`, determines the rotation behavior of the individual glyphs forming the text.
 */
enum MBGL_STYLE_TEXT_ROTATION_ALIGNMENT {
  /**
   * When `symbol-placement` is set to `point`, aligns text east-west. When `symbol-placement` is set to `line` or `line-center`, aligns text x-axes with the line.
   */
  MBGL_STYLE_TEXT_ROTATION_ALIGNMENT_MAP = 0,
  /**
   * Produces glyphs whose x-axes are aligned with the x-axis of the viewport, regardless of the value of `symbol-placement`.
   */
  MBGL_STYLE_TEXT_ROTATION_ALIGNMENT_VIEWPORT = 1,
  /**
   * When `symbol-placement` is set to `point`, this is equivalent to `viewport`. When `symbol-placement` is set to `line` or `line-center`, this is equivalent to `map`.
   */
  MBGL_STYLE_TEXT_ROTATION_ALIGNMENT_AUTO = 2,
};

/**
 * Text justification options.
 */
enum MBGL_STYLE_TEXT_JUSTIFY {
  /**
   * The text is aligned towards the anchor position.
   */
  MBGL_STYLE_TEXT_JUSTIFY_AUTO = 0,
  /**
   * The text is aligned to the left.
   */
  MBGL_STYLE_TEXT_JUSTIFY_LEFT = 1,
  /**
   * The text is centered.
   */
  MBGL_STYLE_TEXT_JUSTIFY_CENTER = 2,
  /**
   * The text is aligned to the right.
   */
  MBGL_STYLE_TEXT_JUSTIFY_RIGHT = 3,
};

enum MBGL_STYLE_TEXT_VARIABLE_ANCHOR {
  /**
   * The center of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_VARIABLE_ANCHOR_CENTER = 0,
  /**
   * The left side of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_VARIABLE_ANCHOR_LEFT = 1,
  /**
   * The right side of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_VARIABLE_ANCHOR_RIGHT = 2,
  /**
   * The top of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_VARIABLE_ANCHOR_TOP = 3,
  /**
   * The bottom of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_VARIABLE_ANCHOR_BOTTOM = 4,
  /**
   * The top left corner of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_VARIABLE_ANCHOR_TOP_LEFT = 5,
  /**
   * The top right corner of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_VARIABLE_ANCHOR_TOP_RIGHT = 6,
  /**
   * The bottom left corner of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_VARIABLE_ANCHOR_BOTTOM_LEFT = 7,
  /**
   * The bottom right corner of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_VARIABLE_ANCHOR_BOTTOM_RIGHT = 8,
};

/**
 * Part of the text placed closest to the anchor.
 */
enum MBGL_STYLE_TEXT_ANCHOR {
  /**
   * The center of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_ANCHOR_CENTER = 0,
  /**
   * The left side of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_ANCHOR_LEFT = 1,
  /**
   * The right side of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_ANCHOR_RIGHT = 2,
  /**
   * The top of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_ANCHOR_TOP = 3,
  /**
   * The bottom of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_ANCHOR_BOTTOM = 4,
  /**
   * The top left corner of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_ANCHOR_TOP_LEFT = 5,
  /**
   * The top right corner of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_ANCHOR_TOP_RIGHT = 6,
  /**
   * The bottom left corner of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_ANCHOR_BOTTOM_LEFT = 7,
  /**
   * The bottom right corner of the text is placed closest to the anchor.
   */
  MBGL_STYLE_TEXT_ANCHOR_BOTTOM_RIGHT = 8,
};

enum MBGL_STYLE_TEXT_WRITING_MODE {
  /**
   * If a text's language supports horizontal writing mode, symbols with point placement would be laid out horizontally.
   */
  MBGL_STYLE_TEXT_WRITING_MODE_HORIZONTAL = 0,
  /**
   * If a text's language supports vertical writing mode, symbols with point placement would be laid out vertically.
   */
  MBGL_STYLE_TEXT_WRITING_MODE_VERTICAL = 1,
};

/**
 * Specifies how to capitalize text, similar to the CSS `text-transform` property.
 */
enum MBGL_STYLE_TEXT_TRANSFORM {
  /**
   * The text is not altered.
   */
  MBGL_STYLE_TEXT_TRANSFORM_NONE = 0,
  /**
   * Forces all letters to be displayed in uppercase.
   */
  MBGL_STYLE_TEXT_TRANSFORM_UPPERCASE = 1,
  /**
   * Forces all letters to be displayed in lowercase.
   */
  MBGL_STYLE_TEXT_TRANSFORM_LOWERCASE = 2,
};

/**
 * Controls the frame of reference for `icon-translate`.
 */
enum MBGL_STYLE_ICON_TRANSLATE_ANCHOR {
  /**
   * Icons are translated relative to the map.
   */
  MBGL_STYLE_ICON_TRANSLATE_ANCHOR_MAP = 0,
  /**
   * Icons are translated relative to the viewport.
   */
  MBGL_STYLE_ICON_TRANSLATE_ANCHOR_VIEWPORT = 1,
};

/**
 * Controls the frame of reference for `text-translate`.
 */
enum MBGL_STYLE_TEXT_TRANSLATE_ANCHOR {
  /**
   * The text is translated relative to the map.
   */
  MBGL_STYLE_TEXT_TRANSLATE_ANCHOR_MAP = 0,
  /**
   * The text is translated relative to the viewport.
   */
  MBGL_STYLE_TEXT_TRANSLATE_ANCHOR_VIEWPORT = 1,
};

/**
 * Controls the frame of reference for `circle-translate`.
 */
enum MBGL_STYLE_CIRCLE_TRANSLATE_ANCHOR {
  /**
   * The circle is translated relative to the map.
   */
  MBGL_STYLE_CIRCLE_TRANSLATE_ANCHOR_MAP = 0,
  /**
   * The circle is translated relative to the viewport.
   */
  MBGL_STYLE_CIRCLE_TRANSLATE_ANCHOR_VIEWPORT = 1,
};

/**
 * Controls the scaling behavior of the circle when the map is pitched.
 */
enum MBGL_STYLE_CIRCLE_PITCH_SCALE {
  /**
   * Circles are scaled according to their apparent distance to the camera.
   */
  MBGL_STYLE_CIRCLE_PITCH_SCALE_MAP = 0,
  /**
   * Circles are not scaled.
   */
  MBGL_STYLE_CIRCLE_PITCH_SCALE_VIEWPORT = 1,
};

/**
 * Orientation of circle when map is pitched.
 */
enum MBGL_STYLE_CIRCLE_PITCH_ALIGNMENT {
  /**
   * The circle is aligned to the plane of the map.
   */
  MBGL_STYLE_CIRCLE_PITCH_ALIGNMENT_MAP = 0,
  /**
   * The circle is aligned to the plane of the viewport.
   */
  MBGL_STYLE_CIRCLE_PITCH_ALIGNMENT_VIEWPORT = 1,
};

/**
 * Controls the frame of reference for `fill-extrusion-translate`.
 */
enum MBGL_STYLE_FILL_EXTRUSION_TRANSLATE_ANCHOR {
  /**
   * The fill extrusion is translated relative to the map.
   */
  MBGL_STYLE_FILL_EXTRUSION_TRANSLATE_ANCHOR_MAP = 0,
  /**
   * The fill extrusion is translated relative to the viewport.
   */
  MBGL_STYLE_FILL_EXTRUSION_TRANSLATE_ANCHOR_VIEWPORT = 1,
};

/**
 * The resampling/interpolation method to use for overscaling, also known as texture magnification filter
 */
enum MBGL_STYLE_RASTER_RESAMPLING {
  /**
   * (Bi)linear filtering interpolates pixel values using the weighted average of the four closest original source pixels creating a smooth but blurry look when overscaled
   */
  MBGL_STYLE_RASTER_RESAMPLING_LINEAR = 0,
  /**
   * Nearest neighbor filtering interpolates pixel values using the nearest original source pixel creating a sharp but pixelated look when overscaled
   */
  MBGL_STYLE_RASTER_RESAMPLING_NEAREST = 1,
};

/**
 * Direction of light source when map is rotated.
 */
enum MBGL_STYLE_HILLSHADE_ILLUMINATION_ANCHOR {
  /**
   * The hillshade illumination is relative to the north direction.
   */
  MBGL_STYLE_HILLSHADE_ILLUMINATION_ANCHOR_MAP = 0,
  /**
   * The hillshade illumination is relative to the top of the viewport.
   */
  MBGL_STYLE_HILLSHADE_ILLUMINATION_ANCHOR_VIEWPORT = 1,
};

typedef void* mbgl_style_property_value_float_t;

typedef void* mbgl_style_property_value_bool_t;

typedef void* mbgl_style_property_value_mbgl_color_t;

typedef void* mbgl_style_property_value_std_array_float_2_t;

typedef void* mbgl_style_property_value_mbgl_style_fill_translate_anchor_t;

typedef void* mbgl_style_property_value_mbgl_style_expression_image_t;

typedef void* mbgl_style_property_value_mbgl_style_line_cap_t;

typedef void* mbgl_style_property_value_mbgl_style_line_join_t;

typedef void* mbgl_style_property_value_mbgl_style_line_translate_anchor_t;

typedef void* mbgl_style_property_value_std_vector_float_t;

typedef void* mbgl_style_property_value_mbgl_color_ramp_t;

typedef void* mbgl_style_property_value_mbgl_style_symbol_placement_t;

typedef void* mbgl_style_property_value_mbgl_style_symbol_z_order_t;

typedef void* mbgl_style_property_value_mbgl_style_icon_rotation_alignment_t;

typedef void* mbgl_style_property_value_mbgl_style_icon_text_fit_t;

typedef void* mbgl_style_property_value_std_array_float_4_t;

typedef void* mbgl_style_property_value_mbgl_padding_t;

typedef void* mbgl_style_property_value_mbgl_style_icon_anchor_t;

typedef void* mbgl_style_property_value_mbgl_style_icon_pitch_alignment_t;

typedef void* mbgl_style_property_value_mbgl_style_text_pitch_alignment_t;

typedef void* mbgl_style_property_value_mbgl_style_text_rotation_alignment_t;

typedef void* mbgl_style_property_value_mbgl_style_expression_formatted_t;

typedef void* mbgl_style_property_value_std_vector_const_char_t;

typedef void* mbgl_style_property_value_mbgl_style_text_justify_t;

typedef void* mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_t;

typedef void* mbgl_style_property_value_mbgl_variable_anchor_offset_collection_t;

typedef void* mbgl_style_property_value_mbgl_style_text_anchor_t;

typedef void* mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_t;

typedef void* mbgl_style_property_value_mbgl_style_text_transform_t;

typedef void* mbgl_style_property_value_mbgl_style_icon_translate_anchor_t;

typedef void* mbgl_style_property_value_mbgl_style_text_translate_anchor_t;

typedef void* mbgl_style_property_value_mbgl_style_circle_translate_anchor_t;

typedef void* mbgl_style_property_value_mbgl_style_circle_pitch_scale_t;

typedef void* mbgl_style_property_value_mbgl_style_circle_pitch_alignment_t;

typedef void* mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_t;

typedef void* mbgl_style_property_value_mbgl_style_raster_resampling_t;

typedef void* mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_t;

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_property_value_float_create_constant(float value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_float_destroy(mbgl_style_property_value_float_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_float_is_constant(mbgl_style_property_value_float_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_float_is_data_driven(mbgl_style_property_value_float_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_float_is_expression(mbgl_style_property_value_float_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_float_is_undefined(mbgl_style_property_value_float_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_float_is_zoom_constant(mbgl_style_property_value_float_t ptr_);
EXTERNC FLMLN_EXPORT float mbgl_style_property_value_float_as_constant(mbgl_style_property_value_float_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_property_value_bool_create_constant(bool value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_bool_destroy(mbgl_style_property_value_bool_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_bool_is_constant(mbgl_style_property_value_bool_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_bool_is_data_driven(mbgl_style_property_value_bool_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_bool_is_expression(mbgl_style_property_value_bool_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_bool_is_undefined(mbgl_style_property_value_bool_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_bool_is_zoom_constant(mbgl_style_property_value_bool_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_bool_as_constant(mbgl_style_property_value_bool_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_property_value_mbgl_color_create_constant(mbgl_color_t value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_color_destroy(mbgl_style_property_value_mbgl_color_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_color_is_constant(mbgl_style_property_value_mbgl_color_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_color_is_data_driven(mbgl_style_property_value_mbgl_color_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_color_is_expression(mbgl_style_property_value_mbgl_color_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_color_is_undefined(mbgl_style_property_value_mbgl_color_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_color_is_zoom_constant(mbgl_style_property_value_mbgl_color_t ptr_);
EXTERNC FLMLN_EXPORT mbgl_color_t mbgl_style_property_value_mbgl_color_as_constant(mbgl_style_property_value_mbgl_color_t ptr_);

typedef void* std_array_float_2_t;
EXTERNC FLMLN_EXPORT std_array_float_2_t std_array_float_2_create(float v0, float v1);
EXTERNC FLMLN_EXPORT void std_array_float_2_destroy(std_array_float_2_t ptr_);
EXTERNC FLMLN_EXPORT size_t std_array_float_2_length(std_array_float_2_t ptr_);
EXTERNC FLMLN_EXPORT float std_array_float_2_get_at(std_array_float_2_t ptr_, size_t index_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_array_float_2_t mbgl_style_property_value_std_array_float_2_create_constant(std_array_float_2_t value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_std_array_float_2_destroy(mbgl_style_property_value_std_array_float_2_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_array_float_2_is_constant(mbgl_style_property_value_std_array_float_2_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_array_float_2_is_data_driven(mbgl_style_property_value_std_array_float_2_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_array_float_2_is_expression(mbgl_style_property_value_std_array_float_2_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_array_float_2_is_undefined(mbgl_style_property_value_std_array_float_2_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_array_float_2_is_zoom_constant(mbgl_style_property_value_std_array_float_2_t ptr_);
EXTERNC FLMLN_EXPORT std_array_float_2_t mbgl_style_property_value_std_array_float_2_as_constant(mbgl_style_property_value_std_array_float_2_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_fill_translate_anchor_t mbgl_style_property_value_mbgl_style_fill_translate_anchor_create_constant(enum MBGL_STYLE_FILL_TRANSLATE_ANCHOR value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_fill_translate_anchor_destroy(mbgl_style_property_value_mbgl_style_fill_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_fill_translate_anchor_is_constant(mbgl_style_property_value_mbgl_style_fill_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_fill_translate_anchor_is_data_driven(mbgl_style_property_value_mbgl_style_fill_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_fill_translate_anchor_is_expression(mbgl_style_property_value_mbgl_style_fill_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_fill_translate_anchor_is_undefined(mbgl_style_property_value_mbgl_style_fill_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_fill_translate_anchor_is_zoom_constant(mbgl_style_property_value_mbgl_style_fill_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_FILL_TRANSLATE_ANCHOR mbgl_style_property_value_mbgl_style_fill_translate_anchor_as_constant(mbgl_style_property_value_mbgl_style_fill_translate_anchor_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_expression_image_t mbgl_style_property_value_mbgl_style_expression_image_create_constant(mbgl_style_expression_image_t value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_expression_image_destroy(mbgl_style_property_value_mbgl_style_expression_image_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_expression_image_is_constant(mbgl_style_property_value_mbgl_style_expression_image_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_expression_image_is_data_driven(mbgl_style_property_value_mbgl_style_expression_image_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_expression_image_is_expression(mbgl_style_property_value_mbgl_style_expression_image_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_expression_image_is_undefined(mbgl_style_property_value_mbgl_style_expression_image_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_expression_image_is_zoom_constant(mbgl_style_property_value_mbgl_style_expression_image_t ptr_);
EXTERNC FLMLN_EXPORT mbgl_style_expression_image_t mbgl_style_property_value_mbgl_style_expression_image_as_constant(mbgl_style_property_value_mbgl_style_expression_image_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_line_cap_t mbgl_style_property_value_mbgl_style_line_cap_create_constant(enum MBGL_STYLE_LINE_CAP value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_line_cap_destroy(mbgl_style_property_value_mbgl_style_line_cap_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_cap_is_constant(mbgl_style_property_value_mbgl_style_line_cap_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_cap_is_data_driven(mbgl_style_property_value_mbgl_style_line_cap_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_cap_is_expression(mbgl_style_property_value_mbgl_style_line_cap_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_cap_is_undefined(mbgl_style_property_value_mbgl_style_line_cap_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_cap_is_zoom_constant(mbgl_style_property_value_mbgl_style_line_cap_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_LINE_CAP mbgl_style_property_value_mbgl_style_line_cap_as_constant(mbgl_style_property_value_mbgl_style_line_cap_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_line_join_t mbgl_style_property_value_mbgl_style_line_join_create_constant(enum MBGL_STYLE_LINE_JOIN value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_line_join_destroy(mbgl_style_property_value_mbgl_style_line_join_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_join_is_constant(mbgl_style_property_value_mbgl_style_line_join_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_join_is_data_driven(mbgl_style_property_value_mbgl_style_line_join_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_join_is_expression(mbgl_style_property_value_mbgl_style_line_join_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_join_is_undefined(mbgl_style_property_value_mbgl_style_line_join_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_join_is_zoom_constant(mbgl_style_property_value_mbgl_style_line_join_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_LINE_JOIN mbgl_style_property_value_mbgl_style_line_join_as_constant(mbgl_style_property_value_mbgl_style_line_join_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_line_translate_anchor_t mbgl_style_property_value_mbgl_style_line_translate_anchor_create_constant(enum MBGL_STYLE_LINE_TRANSLATE_ANCHOR value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_line_translate_anchor_destroy(mbgl_style_property_value_mbgl_style_line_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_translate_anchor_is_constant(mbgl_style_property_value_mbgl_style_line_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_translate_anchor_is_data_driven(mbgl_style_property_value_mbgl_style_line_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_translate_anchor_is_expression(mbgl_style_property_value_mbgl_style_line_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_translate_anchor_is_undefined(mbgl_style_property_value_mbgl_style_line_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_line_translate_anchor_is_zoom_constant(mbgl_style_property_value_mbgl_style_line_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_LINE_TRANSLATE_ANCHOR mbgl_style_property_value_mbgl_style_line_translate_anchor_as_constant(mbgl_style_property_value_mbgl_style_line_translate_anchor_t ptr_);

typedef void* std_vector_float_t;
EXTERNC FLMLN_EXPORT std_vector_float_t std_vector_float_create(size_t length_, float* values_);
EXTERNC FLMLN_EXPORT void std_vector_float_destroy(std_vector_float_t ptr_);
EXTERNC FLMLN_EXPORT size_t std_vector_float_length(std_vector_float_t ptr_);
EXTERNC FLMLN_EXPORT float std_vector_float_get_at(std_vector_float_t ptr_, size_t index_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_vector_float_t mbgl_style_property_value_std_vector_float_create_constant(std_vector_float_t value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_std_vector_float_destroy(mbgl_style_property_value_std_vector_float_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_float_is_constant(mbgl_style_property_value_std_vector_float_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_float_is_data_driven(mbgl_style_property_value_std_vector_float_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_float_is_expression(mbgl_style_property_value_std_vector_float_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_float_is_undefined(mbgl_style_property_value_std_vector_float_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_float_is_zoom_constant(mbgl_style_property_value_std_vector_float_t ptr_);
EXTERNC FLMLN_EXPORT std_vector_float_t mbgl_style_property_value_std_vector_float_as_constant(mbgl_style_property_value_std_vector_float_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_symbol_placement_t mbgl_style_property_value_mbgl_style_symbol_placement_create_constant(enum MBGL_STYLE_SYMBOL_PLACEMENT value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_symbol_placement_destroy(mbgl_style_property_value_mbgl_style_symbol_placement_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_symbol_placement_is_constant(mbgl_style_property_value_mbgl_style_symbol_placement_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_symbol_placement_is_data_driven(mbgl_style_property_value_mbgl_style_symbol_placement_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_symbol_placement_is_expression(mbgl_style_property_value_mbgl_style_symbol_placement_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_symbol_placement_is_undefined(mbgl_style_property_value_mbgl_style_symbol_placement_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_symbol_placement_is_zoom_constant(mbgl_style_property_value_mbgl_style_symbol_placement_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_SYMBOL_PLACEMENT mbgl_style_property_value_mbgl_style_symbol_placement_as_constant(mbgl_style_property_value_mbgl_style_symbol_placement_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_symbol_z_order_t mbgl_style_property_value_mbgl_style_symbol_z_order_create_constant(enum MBGL_STYLE_SYMBOL_Z_ORDER value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_symbol_z_order_destroy(mbgl_style_property_value_mbgl_style_symbol_z_order_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_symbol_z_order_is_constant(mbgl_style_property_value_mbgl_style_symbol_z_order_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_symbol_z_order_is_data_driven(mbgl_style_property_value_mbgl_style_symbol_z_order_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_symbol_z_order_is_expression(mbgl_style_property_value_mbgl_style_symbol_z_order_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_symbol_z_order_is_undefined(mbgl_style_property_value_mbgl_style_symbol_z_order_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_symbol_z_order_is_zoom_constant(mbgl_style_property_value_mbgl_style_symbol_z_order_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_SYMBOL_Z_ORDER mbgl_style_property_value_mbgl_style_symbol_z_order_as_constant(mbgl_style_property_value_mbgl_style_symbol_z_order_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_icon_rotation_alignment_t mbgl_style_property_value_mbgl_style_icon_rotation_alignment_create_constant(enum MBGL_STYLE_ICON_ROTATION_ALIGNMENT value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_icon_rotation_alignment_destroy(mbgl_style_property_value_mbgl_style_icon_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_rotation_alignment_is_constant(mbgl_style_property_value_mbgl_style_icon_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_rotation_alignment_is_data_driven(mbgl_style_property_value_mbgl_style_icon_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_rotation_alignment_is_expression(mbgl_style_property_value_mbgl_style_icon_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_rotation_alignment_is_undefined(mbgl_style_property_value_mbgl_style_icon_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_rotation_alignment_is_zoom_constant(mbgl_style_property_value_mbgl_style_icon_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_ICON_ROTATION_ALIGNMENT mbgl_style_property_value_mbgl_style_icon_rotation_alignment_as_constant(mbgl_style_property_value_mbgl_style_icon_rotation_alignment_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_icon_text_fit_t mbgl_style_property_value_mbgl_style_icon_text_fit_create_constant(enum MBGL_STYLE_ICON_TEXT_FIT value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_icon_text_fit_destroy(mbgl_style_property_value_mbgl_style_icon_text_fit_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_text_fit_is_constant(mbgl_style_property_value_mbgl_style_icon_text_fit_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_text_fit_is_data_driven(mbgl_style_property_value_mbgl_style_icon_text_fit_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_text_fit_is_expression(mbgl_style_property_value_mbgl_style_icon_text_fit_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_text_fit_is_undefined(mbgl_style_property_value_mbgl_style_icon_text_fit_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_text_fit_is_zoom_constant(mbgl_style_property_value_mbgl_style_icon_text_fit_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_ICON_TEXT_FIT mbgl_style_property_value_mbgl_style_icon_text_fit_as_constant(mbgl_style_property_value_mbgl_style_icon_text_fit_t ptr_);

typedef void* std_array_float_4_t;
EXTERNC FLMLN_EXPORT std_array_float_4_t std_array_float_4_create(float v0, float v1, float v2, float v3);
EXTERNC FLMLN_EXPORT void std_array_float_4_destroy(std_array_float_4_t ptr_);
EXTERNC FLMLN_EXPORT size_t std_array_float_4_length(std_array_float_4_t ptr_);
EXTERNC FLMLN_EXPORT float std_array_float_4_get_at(std_array_float_4_t ptr_, size_t index_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_array_float_4_t mbgl_style_property_value_std_array_float_4_create_constant(std_array_float_4_t value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_std_array_float_4_destroy(mbgl_style_property_value_std_array_float_4_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_array_float_4_is_constant(mbgl_style_property_value_std_array_float_4_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_array_float_4_is_data_driven(mbgl_style_property_value_std_array_float_4_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_array_float_4_is_expression(mbgl_style_property_value_std_array_float_4_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_array_float_4_is_undefined(mbgl_style_property_value_std_array_float_4_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_array_float_4_is_zoom_constant(mbgl_style_property_value_std_array_float_4_t ptr_);
EXTERNC FLMLN_EXPORT std_array_float_4_t mbgl_style_property_value_std_array_float_4_as_constant(mbgl_style_property_value_std_array_float_4_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_padding_t mbgl_style_property_value_mbgl_padding_create_constant(mbgl_padding_t value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_padding_destroy(mbgl_style_property_value_mbgl_padding_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_padding_is_constant(mbgl_style_property_value_mbgl_padding_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_padding_is_data_driven(mbgl_style_property_value_mbgl_padding_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_padding_is_expression(mbgl_style_property_value_mbgl_padding_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_padding_is_undefined(mbgl_style_property_value_mbgl_padding_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_padding_is_zoom_constant(mbgl_style_property_value_mbgl_padding_t ptr_);
EXTERNC FLMLN_EXPORT mbgl_padding_t mbgl_style_property_value_mbgl_padding_as_constant(mbgl_style_property_value_mbgl_padding_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_icon_anchor_t mbgl_style_property_value_mbgl_style_icon_anchor_create_constant(enum MBGL_STYLE_ICON_ANCHOR value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_icon_anchor_destroy(mbgl_style_property_value_mbgl_style_icon_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_anchor_is_constant(mbgl_style_property_value_mbgl_style_icon_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_anchor_is_data_driven(mbgl_style_property_value_mbgl_style_icon_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_anchor_is_expression(mbgl_style_property_value_mbgl_style_icon_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_anchor_is_undefined(mbgl_style_property_value_mbgl_style_icon_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_anchor_is_zoom_constant(mbgl_style_property_value_mbgl_style_icon_anchor_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_ICON_ANCHOR mbgl_style_property_value_mbgl_style_icon_anchor_as_constant(mbgl_style_property_value_mbgl_style_icon_anchor_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_icon_pitch_alignment_t mbgl_style_property_value_mbgl_style_icon_pitch_alignment_create_constant(enum MBGL_STYLE_ICON_PITCH_ALIGNMENT value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_icon_pitch_alignment_destroy(mbgl_style_property_value_mbgl_style_icon_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_pitch_alignment_is_constant(mbgl_style_property_value_mbgl_style_icon_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_pitch_alignment_is_data_driven(mbgl_style_property_value_mbgl_style_icon_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_pitch_alignment_is_expression(mbgl_style_property_value_mbgl_style_icon_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_pitch_alignment_is_undefined(mbgl_style_property_value_mbgl_style_icon_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_pitch_alignment_is_zoom_constant(mbgl_style_property_value_mbgl_style_icon_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_ICON_PITCH_ALIGNMENT mbgl_style_property_value_mbgl_style_icon_pitch_alignment_as_constant(mbgl_style_property_value_mbgl_style_icon_pitch_alignment_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_pitch_alignment_t mbgl_style_property_value_mbgl_style_text_pitch_alignment_create_constant(enum MBGL_STYLE_TEXT_PITCH_ALIGNMENT value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_text_pitch_alignment_destroy(mbgl_style_property_value_mbgl_style_text_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_pitch_alignment_is_constant(mbgl_style_property_value_mbgl_style_text_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_pitch_alignment_is_data_driven(mbgl_style_property_value_mbgl_style_text_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_pitch_alignment_is_expression(mbgl_style_property_value_mbgl_style_text_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_pitch_alignment_is_undefined(mbgl_style_property_value_mbgl_style_text_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_pitch_alignment_is_zoom_constant(mbgl_style_property_value_mbgl_style_text_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_TEXT_PITCH_ALIGNMENT mbgl_style_property_value_mbgl_style_text_pitch_alignment_as_constant(mbgl_style_property_value_mbgl_style_text_pitch_alignment_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_rotation_alignment_t mbgl_style_property_value_mbgl_style_text_rotation_alignment_create_constant(enum MBGL_STYLE_TEXT_ROTATION_ALIGNMENT value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_text_rotation_alignment_destroy(mbgl_style_property_value_mbgl_style_text_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_rotation_alignment_is_constant(mbgl_style_property_value_mbgl_style_text_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_rotation_alignment_is_data_driven(mbgl_style_property_value_mbgl_style_text_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_rotation_alignment_is_expression(mbgl_style_property_value_mbgl_style_text_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_rotation_alignment_is_undefined(mbgl_style_property_value_mbgl_style_text_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_rotation_alignment_is_zoom_constant(mbgl_style_property_value_mbgl_style_text_rotation_alignment_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_TEXT_ROTATION_ALIGNMENT mbgl_style_property_value_mbgl_style_text_rotation_alignment_as_constant(mbgl_style_property_value_mbgl_style_text_rotation_alignment_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_expression_formatted_t mbgl_style_property_value_mbgl_style_expression_formatted_create_constant(mbgl_style_expression_formatted_t value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_expression_formatted_destroy(mbgl_style_property_value_mbgl_style_expression_formatted_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_expression_formatted_is_constant(mbgl_style_property_value_mbgl_style_expression_formatted_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_expression_formatted_is_data_driven(mbgl_style_property_value_mbgl_style_expression_formatted_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_expression_formatted_is_expression(mbgl_style_property_value_mbgl_style_expression_formatted_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_expression_formatted_is_undefined(mbgl_style_property_value_mbgl_style_expression_formatted_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_expression_formatted_is_zoom_constant(mbgl_style_property_value_mbgl_style_expression_formatted_t ptr_);
EXTERNC FLMLN_EXPORT mbgl_style_expression_formatted_t mbgl_style_property_value_mbgl_style_expression_formatted_as_constant(mbgl_style_property_value_mbgl_style_expression_formatted_t ptr_);

typedef void* std_vector_const_char_t;
EXTERNC FLMLN_EXPORT std_vector_const_char_t std_vector_const_char_create(size_t length_, const char** values_);
EXTERNC FLMLN_EXPORT void std_vector_const_char_destroy(std_vector_const_char_t ptr_);
EXTERNC FLMLN_EXPORT size_t std_vector_const_char_length(std_vector_const_char_t ptr_);
EXTERNC FLMLN_EXPORT const char* std_vector_const_char_get_at(std_vector_const_char_t ptr_, size_t index_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_vector_const_char_t mbgl_style_property_value_std_vector_const_char_create_constant(std_vector_const_char_t value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_std_vector_const_char_destroy(mbgl_style_property_value_std_vector_const_char_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_const_char_is_constant(mbgl_style_property_value_std_vector_const_char_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_const_char_is_data_driven(mbgl_style_property_value_std_vector_const_char_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_const_char_is_expression(mbgl_style_property_value_std_vector_const_char_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_const_char_is_undefined(mbgl_style_property_value_std_vector_const_char_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_const_char_is_zoom_constant(mbgl_style_property_value_std_vector_const_char_t ptr_);
EXTERNC FLMLN_EXPORT std_vector_const_char_t mbgl_style_property_value_std_vector_const_char_as_constant(mbgl_style_property_value_std_vector_const_char_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_justify_t mbgl_style_property_value_mbgl_style_text_justify_create_constant(enum MBGL_STYLE_TEXT_JUSTIFY value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_text_justify_destroy(mbgl_style_property_value_mbgl_style_text_justify_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_justify_is_constant(mbgl_style_property_value_mbgl_style_text_justify_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_justify_is_data_driven(mbgl_style_property_value_mbgl_style_text_justify_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_justify_is_expression(mbgl_style_property_value_mbgl_style_text_justify_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_justify_is_undefined(mbgl_style_property_value_mbgl_style_text_justify_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_justify_is_zoom_constant(mbgl_style_property_value_mbgl_style_text_justify_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_TEXT_JUSTIFY mbgl_style_property_value_mbgl_style_text_justify_as_constant(mbgl_style_property_value_mbgl_style_text_justify_t ptr_);

typedef void* std_vector_mbgl_style_text_variable_anchor_t;
EXTERNC FLMLN_EXPORT std_vector_mbgl_style_text_variable_anchor_t std_vector_mbgl_style_text_variable_anchor_create(size_t length_, enum MBGL_STYLE_TEXT_VARIABLE_ANCHOR* values_);
EXTERNC FLMLN_EXPORT void std_vector_mbgl_style_text_variable_anchor_destroy(std_vector_mbgl_style_text_variable_anchor_t ptr_);
EXTERNC FLMLN_EXPORT size_t std_vector_mbgl_style_text_variable_anchor_length(std_vector_mbgl_style_text_variable_anchor_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_TEXT_VARIABLE_ANCHOR std_vector_mbgl_style_text_variable_anchor_get_at(std_vector_mbgl_style_text_variable_anchor_t ptr_, size_t index_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_t mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_create_constant(std_vector_mbgl_style_text_variable_anchor_t value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_destroy(mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_is_constant(mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_is_data_driven(mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_is_expression(mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_is_undefined(mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_is_zoom_constant(mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_t ptr_);
EXTERNC FLMLN_EXPORT std_vector_mbgl_style_text_variable_anchor_t mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_as_constant(mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_variable_anchor_offset_collection_t mbgl_style_property_value_mbgl_variable_anchor_offset_collection_create_constant(mbgl_variable_anchor_offset_collection_t value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_variable_anchor_offset_collection_destroy(mbgl_style_property_value_mbgl_variable_anchor_offset_collection_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_variable_anchor_offset_collection_is_constant(mbgl_style_property_value_mbgl_variable_anchor_offset_collection_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_variable_anchor_offset_collection_is_data_driven(mbgl_style_property_value_mbgl_variable_anchor_offset_collection_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_variable_anchor_offset_collection_is_expression(mbgl_style_property_value_mbgl_variable_anchor_offset_collection_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_variable_anchor_offset_collection_is_undefined(mbgl_style_property_value_mbgl_variable_anchor_offset_collection_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_variable_anchor_offset_collection_is_zoom_constant(mbgl_style_property_value_mbgl_variable_anchor_offset_collection_t ptr_);
EXTERNC FLMLN_EXPORT mbgl_variable_anchor_offset_collection_t mbgl_style_property_value_mbgl_variable_anchor_offset_collection_as_constant(mbgl_style_property_value_mbgl_variable_anchor_offset_collection_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_anchor_t mbgl_style_property_value_mbgl_style_text_anchor_create_constant(enum MBGL_STYLE_TEXT_ANCHOR value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_text_anchor_destroy(mbgl_style_property_value_mbgl_style_text_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_anchor_is_constant(mbgl_style_property_value_mbgl_style_text_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_anchor_is_data_driven(mbgl_style_property_value_mbgl_style_text_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_anchor_is_expression(mbgl_style_property_value_mbgl_style_text_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_anchor_is_undefined(mbgl_style_property_value_mbgl_style_text_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_anchor_is_zoom_constant(mbgl_style_property_value_mbgl_style_text_anchor_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_TEXT_ANCHOR mbgl_style_property_value_mbgl_style_text_anchor_as_constant(mbgl_style_property_value_mbgl_style_text_anchor_t ptr_);

typedef void* std_vector_mbgl_style_text_writing_mode_t;
EXTERNC FLMLN_EXPORT std_vector_mbgl_style_text_writing_mode_t std_vector_mbgl_style_text_writing_mode_create(size_t length_, enum MBGL_STYLE_TEXT_WRITING_MODE* values_);
EXTERNC FLMLN_EXPORT void std_vector_mbgl_style_text_writing_mode_destroy(std_vector_mbgl_style_text_writing_mode_t ptr_);
EXTERNC FLMLN_EXPORT size_t std_vector_mbgl_style_text_writing_mode_length(std_vector_mbgl_style_text_writing_mode_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_TEXT_WRITING_MODE std_vector_mbgl_style_text_writing_mode_get_at(std_vector_mbgl_style_text_writing_mode_t ptr_, size_t index_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_t mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_create_constant(std_vector_mbgl_style_text_writing_mode_t value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_destroy(mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_is_constant(mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_is_data_driven(mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_is_expression(mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_is_undefined(mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_is_zoom_constant(mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_t ptr_);
EXTERNC FLMLN_EXPORT std_vector_mbgl_style_text_writing_mode_t mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_as_constant(mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_transform_t mbgl_style_property_value_mbgl_style_text_transform_create_constant(enum MBGL_STYLE_TEXT_TRANSFORM value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_text_transform_destroy(mbgl_style_property_value_mbgl_style_text_transform_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_transform_is_constant(mbgl_style_property_value_mbgl_style_text_transform_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_transform_is_data_driven(mbgl_style_property_value_mbgl_style_text_transform_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_transform_is_expression(mbgl_style_property_value_mbgl_style_text_transform_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_transform_is_undefined(mbgl_style_property_value_mbgl_style_text_transform_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_transform_is_zoom_constant(mbgl_style_property_value_mbgl_style_text_transform_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_TEXT_TRANSFORM mbgl_style_property_value_mbgl_style_text_transform_as_constant(mbgl_style_property_value_mbgl_style_text_transform_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_icon_translate_anchor_t mbgl_style_property_value_mbgl_style_icon_translate_anchor_create_constant(enum MBGL_STYLE_ICON_TRANSLATE_ANCHOR value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_icon_translate_anchor_destroy(mbgl_style_property_value_mbgl_style_icon_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_translate_anchor_is_constant(mbgl_style_property_value_mbgl_style_icon_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_translate_anchor_is_data_driven(mbgl_style_property_value_mbgl_style_icon_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_translate_anchor_is_expression(mbgl_style_property_value_mbgl_style_icon_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_translate_anchor_is_undefined(mbgl_style_property_value_mbgl_style_icon_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_icon_translate_anchor_is_zoom_constant(mbgl_style_property_value_mbgl_style_icon_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_ICON_TRANSLATE_ANCHOR mbgl_style_property_value_mbgl_style_icon_translate_anchor_as_constant(mbgl_style_property_value_mbgl_style_icon_translate_anchor_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_translate_anchor_t mbgl_style_property_value_mbgl_style_text_translate_anchor_create_constant(enum MBGL_STYLE_TEXT_TRANSLATE_ANCHOR value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_text_translate_anchor_destroy(mbgl_style_property_value_mbgl_style_text_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_translate_anchor_is_constant(mbgl_style_property_value_mbgl_style_text_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_translate_anchor_is_data_driven(mbgl_style_property_value_mbgl_style_text_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_translate_anchor_is_expression(mbgl_style_property_value_mbgl_style_text_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_translate_anchor_is_undefined(mbgl_style_property_value_mbgl_style_text_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_text_translate_anchor_is_zoom_constant(mbgl_style_property_value_mbgl_style_text_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_TEXT_TRANSLATE_ANCHOR mbgl_style_property_value_mbgl_style_text_translate_anchor_as_constant(mbgl_style_property_value_mbgl_style_text_translate_anchor_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_circle_translate_anchor_t mbgl_style_property_value_mbgl_style_circle_translate_anchor_create_constant(enum MBGL_STYLE_CIRCLE_TRANSLATE_ANCHOR value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_circle_translate_anchor_destroy(mbgl_style_property_value_mbgl_style_circle_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_translate_anchor_is_constant(mbgl_style_property_value_mbgl_style_circle_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_translate_anchor_is_data_driven(mbgl_style_property_value_mbgl_style_circle_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_translate_anchor_is_expression(mbgl_style_property_value_mbgl_style_circle_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_translate_anchor_is_undefined(mbgl_style_property_value_mbgl_style_circle_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_translate_anchor_is_zoom_constant(mbgl_style_property_value_mbgl_style_circle_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_CIRCLE_TRANSLATE_ANCHOR mbgl_style_property_value_mbgl_style_circle_translate_anchor_as_constant(mbgl_style_property_value_mbgl_style_circle_translate_anchor_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_circle_pitch_scale_t mbgl_style_property_value_mbgl_style_circle_pitch_scale_create_constant(enum MBGL_STYLE_CIRCLE_PITCH_SCALE value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_circle_pitch_scale_destroy(mbgl_style_property_value_mbgl_style_circle_pitch_scale_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_pitch_scale_is_constant(mbgl_style_property_value_mbgl_style_circle_pitch_scale_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_pitch_scale_is_data_driven(mbgl_style_property_value_mbgl_style_circle_pitch_scale_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_pitch_scale_is_expression(mbgl_style_property_value_mbgl_style_circle_pitch_scale_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_pitch_scale_is_undefined(mbgl_style_property_value_mbgl_style_circle_pitch_scale_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_pitch_scale_is_zoom_constant(mbgl_style_property_value_mbgl_style_circle_pitch_scale_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_CIRCLE_PITCH_SCALE mbgl_style_property_value_mbgl_style_circle_pitch_scale_as_constant(mbgl_style_property_value_mbgl_style_circle_pitch_scale_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_circle_pitch_alignment_t mbgl_style_property_value_mbgl_style_circle_pitch_alignment_create_constant(enum MBGL_STYLE_CIRCLE_PITCH_ALIGNMENT value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_circle_pitch_alignment_destroy(mbgl_style_property_value_mbgl_style_circle_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_pitch_alignment_is_constant(mbgl_style_property_value_mbgl_style_circle_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_pitch_alignment_is_data_driven(mbgl_style_property_value_mbgl_style_circle_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_pitch_alignment_is_expression(mbgl_style_property_value_mbgl_style_circle_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_pitch_alignment_is_undefined(mbgl_style_property_value_mbgl_style_circle_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_circle_pitch_alignment_is_zoom_constant(mbgl_style_property_value_mbgl_style_circle_pitch_alignment_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_CIRCLE_PITCH_ALIGNMENT mbgl_style_property_value_mbgl_style_circle_pitch_alignment_as_constant(mbgl_style_property_value_mbgl_style_circle_pitch_alignment_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_t mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_create_constant(enum MBGL_STYLE_FILL_EXTRUSION_TRANSLATE_ANCHOR value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_destroy(mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_is_constant(mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_is_data_driven(mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_is_expression(mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_is_undefined(mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_is_zoom_constant(mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_FILL_EXTRUSION_TRANSLATE_ANCHOR mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_as_constant(mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_raster_resampling_t mbgl_style_property_value_mbgl_style_raster_resampling_create_constant(enum MBGL_STYLE_RASTER_RESAMPLING value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_raster_resampling_destroy(mbgl_style_property_value_mbgl_style_raster_resampling_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_raster_resampling_is_constant(mbgl_style_property_value_mbgl_style_raster_resampling_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_raster_resampling_is_data_driven(mbgl_style_property_value_mbgl_style_raster_resampling_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_raster_resampling_is_expression(mbgl_style_property_value_mbgl_style_raster_resampling_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_raster_resampling_is_undefined(mbgl_style_property_value_mbgl_style_raster_resampling_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_raster_resampling_is_zoom_constant(mbgl_style_property_value_mbgl_style_raster_resampling_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_RASTER_RESAMPLING mbgl_style_property_value_mbgl_style_raster_resampling_as_constant(mbgl_style_property_value_mbgl_style_raster_resampling_t ptr_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_t mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_create_constant(enum MBGL_STYLE_HILLSHADE_ILLUMINATION_ANCHOR value_);
EXTERNC FLMLN_EXPORT void mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_destroy(mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_is_constant(mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_is_data_driven(mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_is_expression(mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_is_undefined(mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_t ptr_);
EXTERNC FLMLN_EXPORT bool mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_is_zoom_constant(mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_t ptr_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_HILLSHADE_ILLUMINATION_ANCHOR mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_as_constant(mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_t ptr_);

typedef void* mbgl_style_fill_layer_t;

EXTERNC FLMLN_EXPORT mbgl_style_fill_layer_t mbgl_style_fill_layer_create(char* layerId_, char* sourceId_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_layer_destroy(mbgl_style_fill_layer_t layer_);
EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_fill_layer_fill_sort_key_get(mbgl_style_fill_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_layer_fill_sort_key_set(mbgl_style_fill_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT enum MBGL_STYLE_VISIBILITY mbgl_style_fill_layer_visibility_get(mbgl_style_fill_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_layer_visibility_set(mbgl_style_fill_layer_t layer_, enum MBGL_STYLE_VISIBILITY value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_fill_layer_fill_antialias_get(mbgl_style_fill_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_layer_fill_antialias_set(mbgl_style_fill_layer_t layer_, mbgl_style_property_value_bool_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_fill_layer_fill_opacity_get(mbgl_style_fill_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_layer_fill_opacity_set(mbgl_style_fill_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_fill_layer_fill_color_get(mbgl_style_fill_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_layer_fill_color_set(mbgl_style_fill_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_fill_layer_fill_outline_color_get(mbgl_style_fill_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_layer_fill_outline_color_set(mbgl_style_fill_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_array_float_2_t mbgl_style_fill_layer_fill_translate_get(mbgl_style_fill_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_layer_fill_translate_set(mbgl_style_fill_layer_t layer_, mbgl_style_property_value_std_array_float_2_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_fill_translate_anchor_t mbgl_style_fill_layer_fill_translate_anchor_get(mbgl_style_fill_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_layer_fill_translate_anchor_set(mbgl_style_fill_layer_t layer_, mbgl_style_property_value_mbgl_style_fill_translate_anchor_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_expression_image_t mbgl_style_fill_layer_fill_pattern_get(mbgl_style_fill_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_layer_fill_pattern_set(mbgl_style_fill_layer_t layer_, mbgl_style_property_value_mbgl_style_expression_image_t value_);

typedef void* mbgl_style_line_layer_t;

EXTERNC FLMLN_EXPORT mbgl_style_line_layer_t mbgl_style_line_layer_create(char* layerId_, char* sourceId_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_destroy(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_line_cap_t mbgl_style_line_layer_line_cap_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_cap_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_mbgl_style_line_cap_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_line_join_t mbgl_style_line_layer_line_join_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_join_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_mbgl_style_line_join_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_line_layer_line_miter_limit_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_miter_limit_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_line_layer_line_round_limit_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_round_limit_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_line_layer_line_sort_key_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_sort_key_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT enum MBGL_STYLE_VISIBILITY mbgl_style_line_layer_visibility_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_visibility_set(mbgl_style_line_layer_t layer_, enum MBGL_STYLE_VISIBILITY value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_line_layer_line_opacity_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_opacity_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_line_layer_line_color_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_color_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_array_float_2_t mbgl_style_line_layer_line_translate_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_translate_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_std_array_float_2_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_line_translate_anchor_t mbgl_style_line_layer_line_translate_anchor_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_translate_anchor_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_mbgl_style_line_translate_anchor_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_line_layer_line_width_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_width_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_line_layer_line_gap_width_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_gap_width_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_line_layer_line_offset_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_offset_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_line_layer_line_blur_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_blur_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_vector_float_t mbgl_style_line_layer_line_dasharray_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_dasharray_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_std_vector_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_expression_image_t mbgl_style_line_layer_line_pattern_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_pattern_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_mbgl_style_expression_image_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_ramp_t mbgl_style_line_layer_line_gradient_get(mbgl_style_line_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_line_layer_line_gradient_set(mbgl_style_line_layer_t layer_, mbgl_style_property_value_mbgl_color_ramp_t value_);

typedef void* mbgl_style_symbol_layer_t;

EXTERNC FLMLN_EXPORT mbgl_style_symbol_layer_t mbgl_style_symbol_layer_create(char* layerId_, char* sourceId_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_destroy(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_symbol_placement_t mbgl_style_symbol_layer_symbol_placement_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_symbol_placement_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_symbol_placement_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_symbol_spacing_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_symbol_spacing_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_symbol_layer_symbol_avoid_edges_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_symbol_avoid_edges_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_bool_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_symbol_sort_key_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_symbol_sort_key_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_symbol_z_order_t mbgl_style_symbol_layer_symbol_z_order_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_symbol_z_order_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_symbol_z_order_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_symbol_layer_icon_allow_overlap_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_allow_overlap_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_bool_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_symbol_layer_icon_ignore_placement_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_ignore_placement_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_bool_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_symbol_layer_icon_optional_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_optional_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_bool_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_icon_rotation_alignment_t mbgl_style_symbol_layer_icon_rotation_alignment_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_rotation_alignment_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_icon_rotation_alignment_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_icon_size_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_size_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_icon_text_fit_t mbgl_style_symbol_layer_icon_text_fit_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_text_fit_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_icon_text_fit_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_array_float_4_t mbgl_style_symbol_layer_icon_text_fit_padding_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_text_fit_padding_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_std_array_float_4_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_expression_image_t mbgl_style_symbol_layer_icon_image_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_image_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_expression_image_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_icon_rotate_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_rotate_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_padding_t mbgl_style_symbol_layer_icon_padding_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_padding_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_padding_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_symbol_layer_icon_keep_upright_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_keep_upright_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_bool_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_array_float_2_t mbgl_style_symbol_layer_icon_offset_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_offset_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_std_array_float_2_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_icon_anchor_t mbgl_style_symbol_layer_icon_anchor_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_anchor_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_icon_anchor_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_icon_pitch_alignment_t mbgl_style_symbol_layer_icon_pitch_alignment_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_pitch_alignment_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_icon_pitch_alignment_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_pitch_alignment_t mbgl_style_symbol_layer_text_pitch_alignment_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_pitch_alignment_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_text_pitch_alignment_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_rotation_alignment_t mbgl_style_symbol_layer_text_rotation_alignment_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_rotation_alignment_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_text_rotation_alignment_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_expression_formatted_t mbgl_style_symbol_layer_text_field_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_field_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_expression_formatted_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_vector_const_char_t mbgl_style_symbol_layer_text_font_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_font_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_std_vector_const_char_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_text_size_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_size_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_text_max_width_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_max_width_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_text_line_height_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_line_height_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_text_letter_spacing_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_letter_spacing_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_justify_t mbgl_style_symbol_layer_text_justify_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_justify_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_text_justify_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_text_radial_offset_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_radial_offset_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_t mbgl_style_symbol_layer_text_variable_anchor_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_variable_anchor_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_std_vector_mbgl_style_text_variable_anchor_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_variable_anchor_offset_collection_t mbgl_style_symbol_layer_text_variable_anchor_offset_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_variable_anchor_offset_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_variable_anchor_offset_collection_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_anchor_t mbgl_style_symbol_layer_text_anchor_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_anchor_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_text_anchor_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_text_max_angle_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_max_angle_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_t mbgl_style_symbol_layer_text_writing_mode_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_writing_mode_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_std_vector_mbgl_style_text_writing_mode_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_text_rotate_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_rotate_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_text_padding_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_padding_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_symbol_layer_text_keep_upright_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_keep_upright_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_bool_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_transform_t mbgl_style_symbol_layer_text_transform_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_transform_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_text_transform_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_array_float_2_t mbgl_style_symbol_layer_text_offset_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_offset_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_std_array_float_2_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_symbol_layer_text_allow_overlap_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_allow_overlap_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_bool_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_symbol_layer_text_ignore_placement_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_ignore_placement_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_bool_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_symbol_layer_text_optional_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_optional_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_bool_t value_);

EXTERNC FLMLN_EXPORT enum MBGL_STYLE_VISIBILITY mbgl_style_symbol_layer_visibility_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_visibility_set(mbgl_style_symbol_layer_t layer_, enum MBGL_STYLE_VISIBILITY value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_icon_opacity_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_opacity_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_symbol_layer_icon_color_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_color_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_symbol_layer_icon_halo_color_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_halo_color_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_icon_halo_width_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_halo_width_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_icon_halo_blur_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_halo_blur_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_array_float_2_t mbgl_style_symbol_layer_icon_translate_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_translate_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_std_array_float_2_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_icon_translate_anchor_t mbgl_style_symbol_layer_icon_translate_anchor_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_icon_translate_anchor_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_icon_translate_anchor_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_text_opacity_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_opacity_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_symbol_layer_text_color_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_color_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_symbol_layer_text_halo_color_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_halo_color_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_text_halo_width_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_halo_width_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_symbol_layer_text_halo_blur_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_halo_blur_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_array_float_2_t mbgl_style_symbol_layer_text_translate_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_translate_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_std_array_float_2_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_text_translate_anchor_t mbgl_style_symbol_layer_text_translate_anchor_get(mbgl_style_symbol_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_symbol_layer_text_translate_anchor_set(mbgl_style_symbol_layer_t layer_, mbgl_style_property_value_mbgl_style_text_translate_anchor_t value_);

typedef void* mbgl_style_circle_layer_t;

EXTERNC FLMLN_EXPORT mbgl_style_circle_layer_t mbgl_style_circle_layer_create(char* layerId_, char* sourceId_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_destroy(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_circle_layer_circle_sort_key_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_sort_key_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT enum MBGL_STYLE_VISIBILITY mbgl_style_circle_layer_visibility_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_visibility_set(mbgl_style_circle_layer_t layer_, enum MBGL_STYLE_VISIBILITY value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_circle_layer_circle_radius_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_radius_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_circle_layer_circle_color_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_color_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_circle_layer_circle_blur_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_blur_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_circle_layer_circle_opacity_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_opacity_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_array_float_2_t mbgl_style_circle_layer_circle_translate_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_translate_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_std_array_float_2_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_circle_translate_anchor_t mbgl_style_circle_layer_circle_translate_anchor_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_translate_anchor_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_mbgl_style_circle_translate_anchor_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_circle_pitch_scale_t mbgl_style_circle_layer_circle_pitch_scale_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_pitch_scale_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_mbgl_style_circle_pitch_scale_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_circle_pitch_alignment_t mbgl_style_circle_layer_circle_pitch_alignment_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_pitch_alignment_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_mbgl_style_circle_pitch_alignment_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_circle_layer_circle_stroke_width_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_stroke_width_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_circle_layer_circle_stroke_color_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_stroke_color_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_circle_layer_circle_stroke_opacity_get(mbgl_style_circle_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_circle_layer_circle_stroke_opacity_set(mbgl_style_circle_layer_t layer_, mbgl_style_property_value_float_t value_);

typedef void* mbgl_style_heatmap_layer_t;

EXTERNC FLMLN_EXPORT mbgl_style_heatmap_layer_t mbgl_style_heatmap_layer_create(char* layerId_, char* sourceId_);
EXTERNC FLMLN_EXPORT void mbgl_style_heatmap_layer_destroy(mbgl_style_heatmap_layer_t layer_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_VISIBILITY mbgl_style_heatmap_layer_visibility_get(mbgl_style_heatmap_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_heatmap_layer_visibility_set(mbgl_style_heatmap_layer_t layer_, enum MBGL_STYLE_VISIBILITY value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_heatmap_layer_heatmap_radius_get(mbgl_style_heatmap_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_heatmap_layer_heatmap_radius_set(mbgl_style_heatmap_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_heatmap_layer_heatmap_weight_get(mbgl_style_heatmap_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_heatmap_layer_heatmap_weight_set(mbgl_style_heatmap_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_heatmap_layer_heatmap_intensity_get(mbgl_style_heatmap_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_heatmap_layer_heatmap_intensity_set(mbgl_style_heatmap_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_ramp_t mbgl_style_heatmap_layer_heatmap_color_get(mbgl_style_heatmap_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_heatmap_layer_heatmap_color_set(mbgl_style_heatmap_layer_t layer_, mbgl_style_property_value_mbgl_color_ramp_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_heatmap_layer_heatmap_opacity_get(mbgl_style_heatmap_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_heatmap_layer_heatmap_opacity_set(mbgl_style_heatmap_layer_t layer_, mbgl_style_property_value_float_t value_);

typedef void* mbgl_style_fill_extrusion_layer_t;

EXTERNC FLMLN_EXPORT mbgl_style_fill_extrusion_layer_t mbgl_style_fill_extrusion_layer_create(char* layerId_, char* sourceId_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_extrusion_layer_destroy(mbgl_style_fill_extrusion_layer_t layer_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_VISIBILITY mbgl_style_fill_extrusion_layer_visibility_get(mbgl_style_fill_extrusion_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_extrusion_layer_visibility_set(mbgl_style_fill_extrusion_layer_t layer_, enum MBGL_STYLE_VISIBILITY value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_fill_extrusion_layer_fill_extrusion_opacity_get(mbgl_style_fill_extrusion_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_extrusion_layer_fill_extrusion_opacity_set(mbgl_style_fill_extrusion_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_fill_extrusion_layer_fill_extrusion_color_get(mbgl_style_fill_extrusion_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_extrusion_layer_fill_extrusion_color_set(mbgl_style_fill_extrusion_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_std_array_float_2_t mbgl_style_fill_extrusion_layer_fill_extrusion_translate_get(mbgl_style_fill_extrusion_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_extrusion_layer_fill_extrusion_translate_set(mbgl_style_fill_extrusion_layer_t layer_, mbgl_style_property_value_std_array_float_2_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_t mbgl_style_fill_extrusion_layer_fill_extrusion_translate_anchor_get(mbgl_style_fill_extrusion_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_extrusion_layer_fill_extrusion_translate_anchor_set(mbgl_style_fill_extrusion_layer_t layer_, mbgl_style_property_value_mbgl_style_fill_extrusion_translate_anchor_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_expression_image_t mbgl_style_fill_extrusion_layer_fill_extrusion_pattern_get(mbgl_style_fill_extrusion_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_extrusion_layer_fill_extrusion_pattern_set(mbgl_style_fill_extrusion_layer_t layer_, mbgl_style_property_value_mbgl_style_expression_image_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_fill_extrusion_layer_fill_extrusion_height_get(mbgl_style_fill_extrusion_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_extrusion_layer_fill_extrusion_height_set(mbgl_style_fill_extrusion_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_fill_extrusion_layer_fill_extrusion_base_get(mbgl_style_fill_extrusion_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_extrusion_layer_fill_extrusion_base_set(mbgl_style_fill_extrusion_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_bool_t mbgl_style_fill_extrusion_layer_fill_extrusion_vertical_gradient_get(mbgl_style_fill_extrusion_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_fill_extrusion_layer_fill_extrusion_vertical_gradient_set(mbgl_style_fill_extrusion_layer_t layer_, mbgl_style_property_value_bool_t value_);

typedef void* mbgl_style_raster_layer_t;

EXTERNC FLMLN_EXPORT mbgl_style_raster_layer_t mbgl_style_raster_layer_create(char* layerId_, char* sourceId_);
EXTERNC FLMLN_EXPORT void mbgl_style_raster_layer_destroy(mbgl_style_raster_layer_t layer_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_VISIBILITY mbgl_style_raster_layer_visibility_get(mbgl_style_raster_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_raster_layer_visibility_set(mbgl_style_raster_layer_t layer_, enum MBGL_STYLE_VISIBILITY value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_raster_layer_raster_opacity_get(mbgl_style_raster_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_raster_layer_raster_opacity_set(mbgl_style_raster_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_raster_layer_raster_hue_rotate_get(mbgl_style_raster_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_raster_layer_raster_hue_rotate_set(mbgl_style_raster_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_raster_layer_raster_brightness_min_get(mbgl_style_raster_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_raster_layer_raster_brightness_min_set(mbgl_style_raster_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_raster_layer_raster_brightness_max_get(mbgl_style_raster_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_raster_layer_raster_brightness_max_set(mbgl_style_raster_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_raster_layer_raster_saturation_get(mbgl_style_raster_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_raster_layer_raster_saturation_set(mbgl_style_raster_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_raster_layer_raster_contrast_get(mbgl_style_raster_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_raster_layer_raster_contrast_set(mbgl_style_raster_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_raster_resampling_t mbgl_style_raster_layer_raster_resampling_get(mbgl_style_raster_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_raster_layer_raster_resampling_set(mbgl_style_raster_layer_t layer_, mbgl_style_property_value_mbgl_style_raster_resampling_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_raster_layer_raster_fade_duration_get(mbgl_style_raster_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_raster_layer_raster_fade_duration_set(mbgl_style_raster_layer_t layer_, mbgl_style_property_value_float_t value_);

typedef void* mbgl_style_hillshade_layer_t;

EXTERNC FLMLN_EXPORT mbgl_style_hillshade_layer_t mbgl_style_hillshade_layer_create(char* layerId_, char* sourceId_);
EXTERNC FLMLN_EXPORT void mbgl_style_hillshade_layer_destroy(mbgl_style_hillshade_layer_t layer_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_VISIBILITY mbgl_style_hillshade_layer_visibility_get(mbgl_style_hillshade_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_hillshade_layer_visibility_set(mbgl_style_hillshade_layer_t layer_, enum MBGL_STYLE_VISIBILITY value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_hillshade_layer_hillshade_illumination_direction_get(mbgl_style_hillshade_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_hillshade_layer_hillshade_illumination_direction_set(mbgl_style_hillshade_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_t mbgl_style_hillshade_layer_hillshade_illumination_anchor_get(mbgl_style_hillshade_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_hillshade_layer_hillshade_illumination_anchor_set(mbgl_style_hillshade_layer_t layer_, mbgl_style_property_value_mbgl_style_hillshade_illumination_anchor_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_hillshade_layer_hillshade_exaggeration_get(mbgl_style_hillshade_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_hillshade_layer_hillshade_exaggeration_set(mbgl_style_hillshade_layer_t layer_, mbgl_style_property_value_float_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_hillshade_layer_hillshade_shadow_color_get(mbgl_style_hillshade_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_hillshade_layer_hillshade_shadow_color_set(mbgl_style_hillshade_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_hillshade_layer_hillshade_highlight_color_get(mbgl_style_hillshade_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_hillshade_layer_hillshade_highlight_color_set(mbgl_style_hillshade_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_hillshade_layer_hillshade_accent_color_get(mbgl_style_hillshade_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_hillshade_layer_hillshade_accent_color_set(mbgl_style_hillshade_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

typedef void* mbgl_style_background_layer_t;

EXTERNC FLMLN_EXPORT mbgl_style_background_layer_t mbgl_style_background_layer_create(char* layerId_);
EXTERNC FLMLN_EXPORT void mbgl_style_background_layer_destroy(mbgl_style_background_layer_t layer_);
EXTERNC FLMLN_EXPORT enum MBGL_STYLE_VISIBILITY mbgl_style_background_layer_visibility_get(mbgl_style_background_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_background_layer_visibility_set(mbgl_style_background_layer_t layer_, enum MBGL_STYLE_VISIBILITY value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_color_t mbgl_style_background_layer_background_color_get(mbgl_style_background_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_background_layer_background_color_set(mbgl_style_background_layer_t layer_, mbgl_style_property_value_mbgl_color_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_mbgl_style_expression_image_t mbgl_style_background_layer_background_pattern_get(mbgl_style_background_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_background_layer_background_pattern_set(mbgl_style_background_layer_t layer_, mbgl_style_property_value_mbgl_style_expression_image_t value_);

EXTERNC FLMLN_EXPORT mbgl_style_property_value_float_t mbgl_style_background_layer_background_opacity_get(mbgl_style_background_layer_t layer_);
EXTERNC FLMLN_EXPORT void mbgl_style_background_layer_background_opacity_set(mbgl_style_background_layer_t layer_, mbgl_style_property_value_float_t value_);
