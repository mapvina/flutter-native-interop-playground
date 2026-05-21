import 'dart:ffi';

import 'package:ffi/ffi.dart';
import 'package:flutter/widgets.dart' as ui;

import 'package:flmln/src/gen/flmln_bindings.dart';

extension ColorToMbgl on ui.Color {
  mbgl_color_t toMbglColor() {
    return mbgl_color_create_from_rgba(r, g, b, a);
  }
}

extension EdgeInsetsToMbgl on ui.EdgeInsets {
  mbgl_padding_t toMbglPadding() {
    return mbgl_padding_create(left, top, right, bottom);
  }
}

extension ToNativeListEnum<T extends Enum> on List<T> {
  Pointer<UnsignedInt> toNativeList(Enum Function(T) mapper) {
    final ptr = malloc.allocate<UnsignedInt>(length * sizeOf<UnsignedInt>());
    for (var i = 0; i < length; i++) ptr[i] = mapper(this[i]).index; // TODO: maybe use value?
    return ptr;
  }
}

extension ToNativeListString on List<String> {
  Pointer<Pointer<Char>> toNativeList({Allocator allocator = malloc}) {
    final ptr = allocator.allocate<Pointer<Char>>(length * sizeOf<Pointer<Char>>());
    for (var i = 0; i < length; i++) ptr[i] = this[i].toNativeUtf8().cast();
    return ptr;
  }
}

extension ToNativeListFloat on List<double> {
  Pointer<Float> toNativeList({Allocator allocator = malloc}) {
    final ptr = allocator.allocate<Float>(length * sizeOf<Float>());
    for (var i = 0; i < length; i++) ptr[i] = this[i];
    return ptr;
  }
}

extension ToDartUtils on Pointer<Void> {
  List<T> toDartList<T, N>(
    int Function(Pointer<Void>) lengthFn,
    N Function(Pointer<Void>, int) getAtFn,
    T Function(N) mapper,
  ) {
    final length = lengthFn(this);
    final result = <T>[];
    for (var i = 0; i < length; i++) result.add(mapper(getAtFn(this, i)));
    return result;
  }

  ui.Color toDartColor() {
    final r = mbgl_color_get_r(this);
    final g = mbgl_color_get_g(this);
    final b = mbgl_color_get_b(this);
    final a = mbgl_color_get_a(this);

    return ui.Color.from(alpha: a, red: r, green: g, blue: b);
  }

  ui.EdgeInsets toDartPadding() {
    final top = mbgl_padding_get_top(this);
    final right = mbgl_padding_get_right(this);
    final bottom = mbgl_padding_get_bottom(this);
    final left = mbgl_padding_get_left(this);

    return ui.EdgeInsets.fromLTRB(left, top, right, bottom);
  }
}
