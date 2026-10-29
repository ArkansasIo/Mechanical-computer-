# Gear-Logic 1024 — Mechanical Reasoning Computer

C++23 starter implementation for a deterministic, rule-based language and logic computer inspired by historical geared calculators. This is a software prototype and conceptual hardware design, not a finished physical machine or general intelligence.

## Included
- 360-position gear-state model.
- Antikythera-style sequencing and Difference-Engine-style finite differences.
- Ideal planetary carrier-speed calculation and differential output functions.
- Rule-based inference.
- 1024-bit unsigned integer using Boost.Multiprecision.
- 25-language target list; complete dictionaries and grammar coverage are not included yet.
- CMake build and automated tests.

## Requirements
C++23 compiler, CMake 3.20+, and Boost headers.

## Build and test
    cmake -S . -B build
    cmake --build build
    ctest --test-dir build --output-on-failure
    ./build/gearlogic_demo

On Windows with Visual Studio, the executable is commonly at build\Debug\gearlogic_demo.exe.

## Scope and limitations
The software is the reference model. Physical gears would demonstrate selected state transitions; complex 1024-bit arithmetic and language generation remain software tasks. The proposed 600 × 400 × 350 mm enclosure is a preliminary estimate, not a validated manufacturing design. Gear dimensions and tolerances require engineering validation. The reasoning engine is explicit and rule-based, not sentient and not a neural network.
