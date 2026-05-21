#pragma once

#include <iostream>
#include <mbgl/map/map.hpp>

namespace flmln {
class MapObserver : public mbgl::MapObserver {
  void onCameraWillChange(CameraChangeMode mode) override {
    // std::cout << "onCameraWillChange: " << (static_cast<uint32_t>(mode)) << std::endl;
  }

  void onCameraIsChanging() override { 
    // std::cout << "onCameraIsChanging" << std::endl; 
  }

  void onCameraDidChange(CameraChangeMode mode) override {
    // std::cout << "onCameraDidChange: " << (static_cast<uint32_t>(mode)) << std::endl;
  }

  void onWillStartLoadingMap() override { 
    // std::cout << "onWillStartLoadingMap" << std::endl; 
  }

  void onDidFinishLoadingMap() override { 
    // std::cout << "onDidFinishLoadingMap" << std::endl; 
  }

  void onDidFailLoadingMap(mbgl::MapLoadError error, const std::string& message) override {
    // std::cout << "onDidFailLoadingMap: " << static_cast<uint32_t>(error) << ", " << message << std::endl;
  }

  void onWillStartRenderingFrame() override {
    // std::cout << "onWillStartRenderingFrame" << std::endl;
  }

  void onDidFinishRenderingFrame(const RenderFrameStatus&) override {
    // std::cout << "onDidFinishRenderingFrame" << std::endl;
  }

  void onWillStartRenderingMap() override { 
    // std::cout << "onWillStartRenderingMap" << std::endl; 
  }

  void onDidFinishRenderingMap(RenderMode) override { 
    // std::cout << "onDidFinishRenderingMap" << std::endl; 
  }

  void onDidFinishLoadingStyle() override { 
    // std::cout << "onDidFinishLoadingStyle" << std::endl; 
  }

  void onSourceChanged(mbgl::style::Source& source) override {
    // std::cout << "onSourceChanged: " << source.getID() << std::endl;
  }

  void onDidBecomeIdle() override { 
    // std::cout << "onDidBecomeIdle" << std::endl; 
  }

  void onStyleImageMissing(const std::string&) override { 
    // std::cout << "onStyleImageMissing" << std::endl; 
  }

  // This method should return true if unused image can be removed,
  // false otherwise. By default, unused image will be removed.
  bool onCanRemoveUnusedStyleImage(const std::string& name) override {
    // std::cout << "onCanRemoveUnusedStyleImage: " << name << std::endl;
    return true;
  }

  // Observe this event to easily mutate or observe shaders as soon
  // as the registry becomes available.
  void onRegisterShaders(mbgl::gfx::ShaderRegistry& registry) override {
    // std::cout << "onRegisterShaders" << std::endl;
  }

  // Shaders compilation
  void onPreCompileShader(mbgl::shaders::BuiltIn, mbgl::gfx::Backend::Type, const std::string&) override {
    // std::cout << "onPreCompileShader" << std::endl;
  }

  void onPostCompileShader(mbgl::shaders::BuiltIn, mbgl::gfx::Backend::Type, const std::string&) override {
    // std::cout << "onPostCompileShader" << std::endl;
  }

  void onShaderCompileFailed(mbgl::shaders::BuiltIn, mbgl::gfx::Backend::Type, const std::string&) override {
    // std::cout << "onShaderCompileFailed" << std::endl;
  }

  // Glyph requests
  void onGlyphsLoaded(const mbgl::FontStack&, const mbgl::GlyphRange&) override {
    // std::cout << "onGlyphsLoaded" << std::endl;
  }

  void onGlyphsError(const mbgl::FontStack&, const mbgl::GlyphRange&, std::exception_ptr) override {
    // std::cout << "onGlyphsError" << std::endl;
  }

  void onGlyphsRequested(const mbgl::FontStack&, const mbgl::GlyphRange&) override {
    // std::cout << "onGlyphsRequested" << std::endl;
  }

  // Tile requests
  void onTileAction(mbgl::TileOperation, const mbgl::OverscaledTileID&, const std::string&) override {
    // std::cout << "onTileAction" << std::endl;
  }

  // Sprite requests
  void onSpriteLoaded(const std::optional<mbgl::style::Sprite>&) override {
    // std::cout << "onSpriteLoaded" << std::endl;
  }

  void onSpriteError(const std::optional<mbgl::style::Sprite>&, std::exception_ptr) override {
    // std::cout << "onSpriteError" << std::endl;
  }

  void onSpriteRequested(const std::optional<mbgl::style::Sprite>&) override {
    // std::cout << "onSpriteRequested" << std::endl;
  }
};
}  // namespace flmln
