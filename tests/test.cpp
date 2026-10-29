#include "GearLogic.hpp"
#include <cassert>
#include <iostream>
int main() {
 using namespace gearlogic;
 Gear360 gear(359); gear.step(); assert(gear.position() == 0);
 DifferenceEngine engine({1, 4, 9, 16});
 assert((engine.nextRow() == std::vector<std::int64_t>{3, 5, 7}));
 assert(PlanetaryGearSet::carrierSpeed(20, 60, 4.0, 0.0) == 1.0);
 assert(Differential::sumOutput(4.0, 2.0) == 3.0);
 assert(Differential::differenceOutput(4.0, 2.0) == 1.0);
 RuleEngine rules; rules.addFact("A"); rules.addRule("A", "B"); rules.addRule("B", "C"); rules.infer();
 assert(rules.contains("C"));
 UInt1024 value = 1; value <<= 1023; assert(toDecimal(value).size() > 300);
 std::cout << "All Gear-Logic tests passed.\n";
}
