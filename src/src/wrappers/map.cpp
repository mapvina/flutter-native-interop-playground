#include "map.h"

#include <mbgl/map/map.hpp>

#include "../flmln/map_observer.hpp"
#include "../flmln/renderer_frontend.hpp";

#include "animation_options.h"
#include "camera_options.h"


// Unimplemented methods:
// - addAnnotation
// - addAnnotationImage
// - cameraForGeometry
// - cameraForLatLngBounds
// - cameraForLatLngs
// - getActionJournal
// - getTopOffsetPixelsForAnnotationImage
// - removeAnnotation
// - removeAnnotationImage
// - updateAnnotation

mbgl_map_t mbgl_map_create(flmln_renderer_frontend_t _rendererFrontend, flmln_map_observer_t _mapObserver,
                           mbgl_map_options_t _mapOptions, mbgl_resource_options_t _resourceOptions) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  auto* mapObserver = reinterpret_cast<flmln::MapObserver*>(_mapObserver);
  auto* mapOptions = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  auto* resourceOptions = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);

  auto* map = new mbgl::Map(*rendererFrontend, *mapObserver, *mapOptions, *resourceOptions);
  return reinterpret_cast<mbgl_map_t>(map);
}

void mbgl_map_destroy(mbgl_map_t _map) {
  auto* map = reinterpret_cast<mbgl::Map*>(_map);
  // map->addAnnotation;
  // map->addAnnotationImage;
  // map->cameraForGeometry;
  // map->cameraForLatLngBounds;
  // map->cameraForLatLngs;
  map->cancelTransitions;
  map->dumpDebugLogs;
  map->easeTo;
  map->enableRenderingStatsView;
  map->flyTo;
  // map->getActionJournal;
  map->getBounds;
  map->getCameraOptions;
  map->getDebug;
  map->getFreeCameraOptions;
  map->getMapOptions;
  map->getPrefetchZoomDelta;
  map->getProjectionMode;
  map->getStyle;
  map->getTileLodMinRadius;
  map->getTileLodPitchThreshold;
  map->getTileLodScale;
  map->getTileLodZoomShift;
  // map->getTopOffsetPixelsForAnnotationImage;
  map->getTransfromState;
  map->isFullyLoaded;
  map->isGestureInProgress;
  map->isPanning;
  map->isRenderingStatsViewEnabled;
  map->isRotating;
  map->isScaling;
  map->jumpTo;
  map->latLngBoundsForCamera;
  map->latLngBoundsForCameraUnwrapped;
  map->latLngForPixel;
  map->latLngsForPixels;
  map->moveBy;
  map->pitchBy;
  map->pixelForLatLng;
  map->pixelsForLatLngs;
  // map->removeAnnotation;
  // map->removeAnnotationImage;
  map->rotateBy;
  map->scaleBy;
  map->setBounds;
  map->setConstrainMode;
  map->setDebug;
  map->setFreeCameraOptions;
  map->setGestureInProgress;
  map->setNorthOrientation;
  map->setPrefetchZoomDelta;
  map->setProjectionMode;
  map->setSize;
  map->setStyle;
  map->setTileLodMinRadius;
  map->setTileLodPitchThreshold;
  map->setTileLodScale;
  map->setTileLodZoomShift;
  map->setViewportMode;
  map->triggerRepaint;
  // map->updateAnnotation;
  delete map;
}

void mbgl_map_cancel_transitions(mbgl_map_t _map) {
  auto* map = reinterpret_cast<mbgl::Map*>(_map);
  map->cancelTransitions();
}

void mbgl_map_dump_debug_logs(mbgl_map_t _map) {
  auto* map = reinterpret_cast<mbgl::Map*>(_map);
  map->dumpDebugLogs();
}

void mbgl_map_ease_to(mbgl_map_t _map, mbgl_camera_options_t _cameraOptions, mbgl_animation_options_t _animationOptions) {
  auto* map = reinterpret_cast<mbgl::Map*>(_map);
  auto* cameraOptions = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  auto* animationOptions = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  map->easeTo(*cameraOptions, *animationOptions);
}

void mbgl_map_enable_rendering_stats_view(mbgl_map_t _map, bool enable) {
  auto* map = reinterpret_cast<mbgl::Map*>(_map);
  map->enableRenderingStatsView(enable);
}

void mbgl_map_fly_to(mbgl_map_t _map, mbgl_camera_options_t _cameraOptions, mbgl_animation_options_t _animationOptions) {
  auto* map = reinterpret_cast<mbgl::Map*>(_map);
  auto* cameraOptions = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  auto* animationOptions = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  map->flyTo(*cameraOptions, *animationOptions);
}

