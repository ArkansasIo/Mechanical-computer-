#include "GearLogic.hpp"
#include <algorithm>
#include <stdexcept>
#include <utility>
namespace gearlogic {
Gear360::Gear360(unsigned position) noexcept : position_(position % 360U) {}
void Gear360::step(int teeth) noexcept {
 const int normalized = ((teeth % 360) + 360) % 360;
 position_ = (position_ + static_cast<unsigned>(normalized)) % 360U;
}
void AntikytheraSequencer::advance() noexcept { state_.step(); ++cycle_; }
DifferenceEngine::DifferenceEngine(std::vector<std::int64_t> values) : row_(std::move(values)) {
 if (row_.empty()) throw std::invalid_argument("Difference engine needs at least one value");
}
std::vector<std::int64_t> DifferenceEngine::nextRow() const {
 std::vector<std::int64_t> result;
 if (row_.size() < 2) return result;
 result.reserve(row_.size() - 1);
 for (std::size_t i = 1; i < row_.size(); ++i) result.push_back(row_[i] - row_[i - 1]);
 return result;
}
double PlanetaryGearSet::carrierSpeed(double sunTeeth, double ringTeeth, double sunSpeed, double ringSpeed) {
 if (sunTeeth <= 0.0 || ringTeeth <= 0.0) throw std::invalid_argument("Gear tooth counts must be positive");
 return (sunTeeth * sunSpeed + ringTeeth * ringSpeed) / (sunTeeth + ringTeeth);
}
double Differential::sumOutput(double left, double right) noexcept { return (left + right) / 2.0; }
double Differential::differenceOutput(double left, double right) noexcept { return (left - right) / 2.0; }
void RuleEngine::addFact(std::string fact) {
 if (fact.empty()) throw std::invalid_argument("Fact cannot be empty");
 if (!contains(fact)) facts_.push_back(std::move(fact));
}
void RuleEngine::addRule(std::string ifFact, std::string thenFact) {
 if (ifFact.empty() || thenFact.empty()) throw std::invalid_argument("Rule premise/conclusion cannot be empty");
 rules_.push_back({std::move(ifFact), std::move(thenFact)});
}
bool RuleEngine::contains(std::string_view fact) const {
 return std::find(facts_.begin(), facts_.end(), fact) != facts_.end();
}
std::vector<std::string> RuleEngine::infer() {
 bool changed = true;
 while (changed) {
  changed = false;
  for (const auto& rule : rules_) {
   if (contains(rule.premise) && !contains(rule.conclusion)) {
    facts_.push_back(rule.conclusion); changed = true;
   }
  }
 }
 return facts_;
}
LanguageEngine::LanguageEngine(std::string language) { setLanguage(std::move(language)); }
void LanguageEngine::setLanguage(std::string language) {
 if (language.empty()) throw std::invalid_argument("Language code cannot be empty");
 language_ = std::move(language);
}
std::string LanguageEngine::renderFact(std::string_view fact) const {
 if (language_ == "en") return "Known fact: " + std::string(fact) + ".";
 return "[" + language_ + "] " + std::string(fact);
}
std::string toDecimal(const UInt1024& value) { return value.convert_to<std::string>(); }
}
