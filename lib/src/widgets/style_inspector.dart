import 'package:flmln/src/style/style.dart';
import 'package:flutter/material.dart';

class StyleInspector extends StatelessWidget {
  const StyleInspector({super.key, required this.style});

  final Style style;

  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        _Header(style: style),
        Expanded(
          child: SingleChildScrollView(child: _Layers(style: style)),
        ),
      ],
    );
  }
}

class _Header extends StatelessWidget {
  const _Header({required this.style});

  final Style style;

  @override
  Widget build(BuildContext context) {
    return ListTile(
      title: Text('Style inspector'),
      subtitle: Text('Name: ${style.name}'),
    );
  }
}

class _Layers extends StatelessWidget {
  const _Layers({required this.style});

  final Style style;

  @override
  Widget build(BuildContext context) {
    return ExpansionTile(
      leading: Icon(Icons.layers_rounded),
      title: Text('Layers (${style.layerCount})'),
      children: [
        for (final layer in style.layers)
          _Layer(
            key: Key(layer.id),
            layer: layer,
          ),
      ],
    );
  }
}

class _Layer extends StatelessWidget {
  const _Layer({super.key, required this.layer});

  final Layer layer;

  @override
  Widget build(BuildContext context) {
    return ExpansionTile(
      leading: Icon(
        switch (layer.type) {
          LayerType.background => Icons.format_color_fill_rounded,
          LayerType.fill => Icons.square_rounded,
          LayerType.fillExtrusion => Icons.view_in_ar_rounded,
          LayerType.line => Icons.show_chart_rounded,
          LayerType.circle => Icons.circle_rounded,
          LayerType.symbol => Icons.label_rounded,
          LayerType.raster => Icons.image_rounded,
          LayerType.heatmap => Icons.whatshot_rounded,
          LayerType.hillshade => Icons.terrain_rounded,
          LayerType.unknown => Icons.help_rounded,
        },
      ),
      title: Text(layer.id),
      subtitle: Text(layer.type.name),
      children: [
        for (final property in layer.properties.entries)
          _LayerField(
            key: Key('${layer.id}-${property.key}'),
            name: property.key,
            field: property.value,
          ),
      ],
    );
  }
}

class _LayerField extends StatelessWidget {
  const _LayerField({
    super.key,
    required this.name,
    required this.field,
  });

  final String name;
  final Object field;

  @override
  Widget build(BuildContext context) {
    final String value;
    var isUndefined = false;

    if (field is PropertyValue) {
      final _field = field as PropertyValue;
      if (_field.isConstant) {
        value = 'Constant: ${_field.asConstant}';
      } else if (_field.isExpression) {
        value = 'Expression: TODO';
      } else {
        value = 'Undefined';
        isUndefined = true;
      }
    } else {
      value = field.toString();
    }

    return Opacity(
      opacity: isUndefined ? 0.5 : 1.0,
      child: ListTile(
        title: Text(name),
        subtitle: Text(value),
      ),
    );
  }
}
