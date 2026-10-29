#include "GearLogic.hpp"
#include <iostream>
int main() {
 using namespace gearlogic;
 Gear360 gear; AntikytheraSequencer sequencer;
 DifferenceEngine difference({1, 4, 9, 16, 25});
 RuleEngine reasoning;
 reasoning.addFact("the gear has 360 positions");
 reasoning.addRule("the gear has 360 positions", "one position represents one degree");
 reasoning.infer();
 UInt1024 big = 1; big <<= 1023; big += 12345;
 std::cout << "GEAR-LOGIC 1024 / C++23\n";
 gear.step(); sequencer.advance();
 std::cout << "Gear position: " << gear.position() << " degrees\n";
 std::cout << "Sequencer cycles: " << sequencer.cycle() << ", state: " << sequencer.state() << "\n";
 std::cout << "Difference row: ";
 for (auto v : difference.nextRow()) std::cout << v << ' ';
 std::cout << "\n1024-bit example integer: " << toDecimal(big) << "\nInferred facts:\n";
 LanguageEngine language("en");
 for (const auto& fact : reasoning.facts()) std::cout << " - " << language.renderFact(fact) << "\n";
 std::cout << "Deterministic rule-based prototype; not a neural network.\n";
}
