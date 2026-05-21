#pragma once

#include <mbgl/map/map_options.hpp>

#include "enums.h"

inline MBGL_CONSTRAIN_MODE mbgl_constrain_mode_to_c(mbgl::ConstrainMode mode) {
  switch (mode) {
    case mbgl::ConstrainMode::None:
      return MBGL_CONSTRAIN_MODE::MBGL_CONSTRAIN_MODE_NONE;
    case mbgl::ConstrainMode::HeightOnly:
      return MBGL_CONSTRAIN_MODE::MBGL_CONSTRAIN_MODE_HEIGHT_ONLY;
    case mbgl::ConstrainMode::WidthAndHeight:
      return MBGL_CONSTRAIN_MODE::MBGL_CONSTRAIN_MODE_WIDTH_AND_HEIGHT;
    case mbgl::ConstrainMode::Screen:
      return MBGL_CONSTRAIN_MODE::MBGL_CONSTRAIN_MODE_SCREEEN;
  }

  throw std::invalid_argument("Invalid ConstrainMode value");
}

inline mbgl::ConstrainMode mbgl_constrain_mode_from_c(MBGL_CONSTRAIN_MODE mode) {
  switch (mode) {
    case MBGL_CONSTRAIN_MODE::MBGL_CONSTRAIN_MODE_NONE:
      return mbgl::ConstrainMode::None;
    case MBGL_CONSTRAIN_MODE::MBGL_CONSTRAIN_MODE_HEIGHT_ONLY:
      return mbgl::ConstrainMode::HeightOnly;
    case MBGL_CONSTRAIN_MODE::MBGL_CONSTRAIN_MODE_WIDTH_AND_HEIGHT:
      return mbgl::ConstrainMode::WidthAndHeight;
    case MBGL_CONSTRAIN_MODE::MBGL_CONSTRAIN_MODE_SCREEEN:
      return mbgl::ConstrainMode::Screen;
  }

  throw std::invalid_argument("Invalid MBGL_CONSTRAIN_MODE value");
}

inline MBGL_MAP_MODE mbgl_map_mode_to_c(mbgl::MapMode mode) {
  switch (mode) {
    case mbgl::MapMode::Continuous:
      return MBGL_MAP_MODE::MBGL_MAP_MODE_CONTINUOUS;
    case mbgl::MapMode::Static:
      return MBGL_MAP_MODE::MBGL_MAP_MODE_STATIC;
    case mbgl::MapMode::Tile:
      return MBGL_MAP_MODE::MBGL_MAP_MODE_TILE;
  }

  throw std::invalid_argument("Invalid MapMode value");
}

inline mbgl::MapMode mbgl_map_mode_from_c(MBGL_MAP_MODE mode) {
  switch (mode) {
    case MBGL_MAP_MODE::MBGL_MAP_MODE_CONTINUOUS:
      return mbgl::MapMode::Continuous;
    case MBGL_MAP_MODE::MBGL_MAP_MODE_STATIC:
      return mbgl::MapMode::Static;
    case MBGL_MAP_MODE::MBGL_MAP_MODE_TILE:
      return mbgl::MapMode::Tile;
  }

  throw std::invalid_argument("Invalid MBGL_MAP_MODE value");
}

inline mbgl::NorthOrientation mbgl_north_orientation_from_c(MBGL_NORTH_ORIENTATION orientation) {
  switch (orientation) {
    case MBGL_NORTH_ORIENTATION::MBGL_NORTH_ORIENTATION_UPWARDS:
      return mbgl::NorthOrientation::Upwards;
    case MBGL_NORTH_ORIENTATION::MBGL_NORTH_ORIENTATION_RIGHTWARDS:
      return mbgl::NorthOrientation::Rightwards;
    case MBGL_NORTH_ORIENTATION::MBGL_NORTH_ORIENTATION_DOWNWARDS:
      return mbgl::NorthOrientation::Downwards;
    case MBGL_NORTH_ORIENTATION::MBGL_NORTH_ORIENTATION_LEFTWARDS:
      return mbgl::NorthOrientation::Leftwards;
  }

  throw std::invalid_argument("Invalid MBGL_NORTH_ORIENTATION value");
}

inline MBGL_NORTH_ORIENTATION mbgl_north_orientation_to_c(mbgl::NorthOrientation orientation) {
  switch (orientation) {
    case mbgl::NorthOrientation::Upwards:
      return MBGL_NORTH_ORIENTATION::MBGL_NORTH_ORIENTATION_UPWARDS;
    case mbgl::NorthOrientation::Rightwards:
      return MBGL_NORTH_ORIENTATION::MBGL_NORTH_ORIENTATION_RIGHTWARDS;
    case mbgl::NorthOrientation::Downwards:
      return MBGL_NORTH_ORIENTATION::MBGL_NORTH_ORIENTATION_DOWNWARDS;
    case mbgl::NorthOrientation::Leftwards:
      return MBGL_NORTH_ORIENTATION::MBGL_NORTH_ORIENTATION_LEFTWARDS;
  }

  throw std::invalid_argument("Invalid NorthOrientation value");
}

inline MBGL_VIEWPORT_MODE mbgl_viewport_mode_to_c(mbgl::ViewportMode mode) {
  switch (mode) {
    case mbgl::ViewportMode::Default:
      return MBGL_VIEWPORT_MODE::MBGL_VIEWPORT_MODE_DEFAULT;
    case mbgl::ViewportMode::FlippedY:
      return MBGL_VIEWPORT_MODE::MBGL_VIEWPORT_MODE_FLIPPED_Y;
  }

  throw std::invalid_argument("Invalid ViewportMode value");
}

inline mbgl::ViewportMode mbgl_viewport_mode_from_c(MBGL_VIEWPORT_MODE mode) {
  switch (mode) {
    case MBGL_VIEWPORT_MODE::MBGL_VIEWPORT_MODE_DEFAULT:
      return mbgl::ViewportMode::Default;
    case MBGL_VIEWPORT_MODE::MBGL_VIEWPORT_MODE_FLIPPED_Y:
      return mbgl::ViewportMode::FlippedY;
  }

  throw std::invalid_argument("Invalid MBGL_VIEWPORT_MODE value");
}
