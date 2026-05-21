import 'dart:ui' as ui;

import 'package:flmln/src/gen/flmln_bindings.dart';
import 'package:flmln/src/style/style.dart';
import 'package:flmln/src/utils/ffi_utils.dart';

abstract class PropertyValue<T> extends NativeOwning<mbgl_style_property_value_t> {
  PropertyValue(super.ptr, {super.ownedByDart = false}) : super();

  factory PropertyValue.constant(T value) => PropertyValueFactory.constant(value);
  factory PropertyValue.fromNative(mbgl_style_property_value_t ptr, {bool ownedByDart = false}) =>
      PropertyValueFactory.fromNative<T>(ptr, ownedByDart: ownedByDart);

  bool get isConstant;
  bool get isDataDriven;
  bool get isExpression;
  bool get isUndefined;
  bool get isZoomConstant;

  T get asConstant;
}

// TODO
class ColorRampPropertyValue extends PropertyValue<ui.Color> {
  ColorRampPropertyValue.fromNative(super.ptr, {super.ownedByDart = false}) : super();

  @override
  // TODO: implement asConstant
  ui.Color get asConstant => throw UnimplementedError();

  @override
  void attachFinalizer() {
    // TODO: implement attachFinalizer
  }

  @override
  void detachFinalizer() {
    // TODO: implement detachFinalizer
  }

  @override
  // TODO: implement isConstant
  bool get isConstant => false;

  @override
  // TODO: implement isDataDriven
  bool get isDataDriven => false;

  @override
  // TODO: implement isExpression
  bool get isExpression => false;

  @override
  // TODO: implement isUndefined
  bool get isUndefined => true;

  @override
  // TODO: implement isZoomConstant
  bool get isZoomConstant => false;
}
