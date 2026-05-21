#pragma once

#include "../flmln.h"

typedef void* mbgl_tile_server_options_t;

FFI mbgl_tile_server_options_t mbgl_tile_server_options_create();
FFI mbgl_tile_server_options_t mbgl_tile_server_options_mapbox_configuration_create();
FFI mbgl_tile_server_options_t mbgl_tile_server_options_maptiler_configuration_create();
FFI mbgl_tile_server_options_t mbgl_tile_server_options_mapvina_configuration_create();
FFI void mbgl_tile_server_options_destroy(mbgl_tile_server_options_t _tileServerOptions);

FFI char* mbgl_tile_server_options_api_key_parameter_name_get(mbgl_tile_server_options_t _tileServerOptions);
FFI void mbgl_tile_server_options_api_key_parameter_name_set(mbgl_tile_server_options_t _tileServerOptions,
                                                             const char* apiKeyParameterName);

FFI char* mbgl_tile_server_options_base_url_get(mbgl_tile_server_options_t _tileServerOptions);
FFI void mbgl_tile_server_options_base_url_set(mbgl_tile_server_options_t _tileServerOptions, const char* baseURL);

FFI char* mbgl_tile_server_options_default_style_get(mbgl_tile_server_options_t _tileServerOptions);
FFI void mbgl_tile_server_options_default_style_set(mbgl_tile_server_options_t _tileServerOptions,
                                                    const char* defaultStyle);

FFI void mbgl_tile_server_options_default_styles_set(mbgl_tile_server_options_t _tileServerOptions,
                                                     struct ArrayVoidPtr defaultStyles);
FFI struct ArrayVoidPtr mbgl_tile_server_options_default_styles_get(mbgl_tile_server_options_t _tileServerOptions);

FFI char* mbgl_tile_server_options_glyphs_template_get(mbgl_tile_server_options_t _tileServerOptions);
FFI void mbgl_tile_server_options_glyphs_template_set(mbgl_tile_server_options_t _tileServerOptions,
                                                      const char* glyphsTemplate, const char* domainName,
                                                      const char* versionPrefix);

FFI char* mbgl_tile_server_options_source_template_get(mbgl_tile_server_options_t _tileServerOptions);
FFI void mbgl_tile_server_options_source_template_set(mbgl_tile_server_options_t _tileServerOptions,
                                                      const char* sourceTemplate, const char* domainName,
                                                      const char* versionPrefix);

FFI char* mbgl_tile_server_options_sprites_template_get(mbgl_tile_server_options_t _tileServerOptions);
FFI void mbgl_tile_server_options_sprites_template_set(mbgl_tile_server_options_t _tileServerOptions,
                                                       const char* spritesTemplate, const char* domainName,
                                                       const char* versionPrefix);

FFI char* mbgl_tile_server_options_style_template_get(mbgl_tile_server_options_t _tileServerOptions);
FFI void mbgl_tile_server_options_style_template_set(mbgl_tile_server_options_t _tileServerOptions,
                                                     const char* styleTemplate, const char* domainName,
                                                     const char* versionPrefix);

FFI char* mbgl_tile_server_options_tile_url_template_get(mbgl_tile_server_options_t _tileServerOptions);
FFI void mbgl_tile_server_options_tile_url_template_set(mbgl_tile_server_options_t _tileServerOptions,
                                                        const char* tileURLTemplate, const char* domainName,
                                                        const char* versionPrefix);

FFI char* mbgl_tile_server_options_uri_scheme_alias_get(mbgl_tile_server_options_t _tileServerOptions);
FFI void mbgl_tile_server_options_uri_scheme_alias_set(mbgl_tile_server_options_t _tileServerOptions,
                                                       const char* uriSchemeAlias);