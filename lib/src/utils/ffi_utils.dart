import 'dart:ffi';

import 'package:ffi/ffi.dart';

extension ReadCharPtr on Pointer<Char> {
  String toDartString({required bool free}) {
    final str = cast<Utf8>().toDartString();
    if (free) calloc.free(this);
    return str;
  }
}

abstract class NativeOwning<T extends Pointer> implements Finalizable {
  NativeOwning(this.ptr, {required this.ownedByDart}) {
    if (ownedByDart) attachFinalizer();
  }

  final T ptr;
  bool ownedByDart;

  void attachFinalizer();
  void detachFinalizer();

  void setOwnershipToDart() {
    if (ownedByDart) return;
    ownedByDart = true;
    attachFinalizer();
  }

  void setOwnershipToNative() {
    if (!ownedByDart) return;
    ownedByDart = false;
    detachFinalizer();
  }
}
