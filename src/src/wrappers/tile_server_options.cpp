#include <mbgl/util/default_style.hpp>
#include <mbgl/util/tile_server_options.hpp>

#include "default_style.h"
#include "map_options.h"
#include "types.h"

mbgl_tile_server_options_t mbgl_tile_server_options_create() {
  auto* options = new mbgl::TileServerOptions();
  return static_cast<mbgl_tile_server_options_t>(options);
}

mbgl_tile_server_options_t mbgl_tile_server_options_mapbox_configuration_create() {
  auto* options = new auto(mbgl::TileServerOptions::MapboxConfiguration());
  return static_cast<mbgl_tile_server_options_t>(options);
}

mbgl_tile_server_options_t mbgl_tile_server_options_maptiler_configuration_create() {
  auto* options = new auto(mbgl::TileServerOptions::MapTilerConfiguration());
  return static_cast<mbgl_tile_server_options_t>(options);
}

mbgl_tile_server_options_t mbgl_tile_server_options_mapvina_configuration_create() {
  auto* options = new auto(mbgl::TileServerOptions::MapVinaConfiguration());
  return static_cast<mbgl_tile_server_options_t>(options);
}

void mbgl_tile_server_options_destroy(mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  delete options;
}

char* mbgl_tile_server_options_api_key_parameter_name_get(mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  auto apiKeyParameterName = options->apiKeyParameterName();
  return strdup(apiKeyParameterName.c_str());
}

void mbgl_tile_server_options_api_key_parameter_name_set(mbgl_tile_server_options_t _tileServerOptions,
                                                         const char* apiKeyParameterName) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  options->withApiKeyParameterName(std::string(apiKeyParameterName));
}

char* mbgl_tile_server_options_base_url_get(mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  auto baseURL = options->baseURL();
  return strdup(baseURL.c_str());
}

void mbgl_tile_server_options_base_url_set(mbgl_tile_server_options_t _tileServerOptions, const char* baseURL) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  options->withBaseURL(std::string(baseURL));
}

char* mbgl_tile_server_options_default_style_get(mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  auto defaultStyle = options->defaultStyle();
  return strdup(defaultStyle.c_str());
}

void mbgl_tile_server_options_default_style_set(mbgl_tile_server_options_t _tileServerOptions,
                                                const char* defaultStyle) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  options->withDefaultStyle(std::string(defaultStyle));
}

ArrayVoidPtr mbgl_tile_server_options_default_styles_get(mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  const auto& defaultStyles = options->defaultStyles();

  ArrayVoidPtr array;
  array.length = defaultStyles.size();
  array.data = new void*[array.length];

  for (size_t i = 0; i < array.length; ++i) {
    array.data[i] = reinterpret_cast<void*>(new mbgl::util::DefaultStyle(defaultStyles[i]));
  }

  return array;
}

void mbgl_tile_server_options_default_styles_set(mbgl_tile_server_options_t _tileServerOptions,
                                                 ArrayVoidPtr _defaultStyles) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  std::vector<mbgl::util::DefaultStyle> defaultStyles;
  for (size_t i = 0; i < _defaultStyles.length; ++i) {
    auto* defaultStyle = reinterpret_cast<mbgl::util::DefaultStyle*>(_defaultStyles.data[i]);
    defaultStyles.push_back(*defaultStyle);
  }
  options->withDefaultStyles(defaultStyles);
}

char* mbgl_tile_server_options_glyphs_template_get(mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  auto glyphsTemplate = options->glyphsTemplate();
  return strdup(glyphsTemplate.c_str());
}

void mbgl_tile_server_options_glyphs_template_set(mbgl_tile_server_options_t _tileServerOptions,
                                                  const char* glyphsTemplate, const char* domainName,
                                                  const char* versionPrefix) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  options->withGlyphsTemplate(std::string(glyphsTemplate), std::string(domainName),
                              std::optional<std::string>(versionPrefix));
}

char* mbgl_tile_server_options_source_template_get(mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  auto sourceTemplate = options->sourceTemplate();
  return strdup(sourceTemplate.c_str());
}

void mbgl_tile_server_options_source_template_set(mbgl_tile_server_options_t _tileServerOptions,
                                                  const char* sourceTemplate, const char* domainName,
                                                  const char* versionPrefix) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  options->withSourceTemplate(std::string(sourceTemplate), std::string(domainName),
                              std::optional<std::string>(versionPrefix));
}

char* mbgl_tile_server_options_sprites_template_get(mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  auto spriteTemplate = options->spritesTemplate();
  return strdup(spriteTemplate.c_str());
}

void mbgl_tile_server_options_sprites_template_set(mbgl_tile_server_options_t _tileServerOptions,
                                                   const char* spritesTemplate, const char* domainName,
                                                   const char* versionPrefix) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  options->withSpritesTemplate(std::string(spritesTemplate), std::string(domainName),
                               std::optional<std::string>(versionPrefix));
}

char* mbgl_tile_server_options_style_template_get(mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  auto stylesTemplate = options->styleTemplate();
  return strdup(stylesTemplate.c_str());
}

void mbgl_tile_server_options_style_template_set(mbgl_tile_server_options_t _tileServerOptions,
                                                 const char* styleTemplate, const char* domainName,
                                                 const char* versionPrefix) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  options->withStyleTemplate(std::string(styleTemplate), std::string(domainName),
                             std::optional<std::string>(versionPrefix));
}

char* mbgl_tile_server_options_tile_template_get(mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  auto tileTemplate = options->tileTemplate();
  return strdup(tileTemplate.c_str());
}

void mbgl_tile_server_options_tile_template_set(mbgl_tile_server_options_t _tileServerOptions, const char* tileTemplate,
                                                const char* domainName, const char* versionPrefix) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  options->withTileTemplate(std::string(tileTemplate), std::string(domainName),
                            std::optional<std::string>(versionPrefix));
}

char* mbgl_tile_server_options_uri_scheme_alias_get(mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  auto uriSchemeAlias = options->uriSchemeAlias();
  return strdup(uriSchemeAlias.c_str());
}

void mbgl_tile_server_options_uri_scheme_alias_set(mbgl_tile_server_options_t _tileServerOptions,
                                                   const char* uriSchemeAlias) {
  auto* options = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  options->withUriSchemeAlias(std::string(uriSchemeAlias));
}