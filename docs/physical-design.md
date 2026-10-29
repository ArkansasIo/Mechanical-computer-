# Physical prototype concept

Preliminary tabletop envelope: 600 mm wide × 400 mm deep × 350 mm high. This is a packaging estimate, not a validated manufacturing drawing.

## Modules
1. Input keyboard or serial interface.
2. 360-tooth gear module with nominal one-degree indexing per tooth.
3. Antikythera-style sequencer for repeatable state changes.
4. Difference-engine-inspired demonstrator for finite differences.
5. Planetary transmission with sun, planets, carrier, and internal ring gear.
6. Differential module combining two rotational inputs.
7. Controller and encoders bridging physical state to the C++ reference model.
8. Software text pipeline and compact printer.

## Constraints
- Tooth count alone does not determine gear diameter; tooth module, profile, pressure angle, material, and manufacturing method must be selected.
- A 360-position gear needs at least 9 binary bits to encode its position, but is not itself a 1024-bit processor.
- Use guards, emergency stop, current limiting, and low-voltage power in a prototype.
- A mechanical engineer must verify tooth geometry, shaft/bearing loads, torque, backlash, and manufacturability before fabrication.
- Full multilingual dictionaries/grammars and general-purpose language understanding are not part of this starter build.
