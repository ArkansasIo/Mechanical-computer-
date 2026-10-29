#pragma once
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
namespace gearlogic {
using UInt1024 = boost::multiprecision::uint1024_t;
class Gear360 {
public:
 explicit Gear360(unsigned position = 0) noexcept;
 void step(int teeth = 1) noexcept;
 [[nodiscard]] unsigned position() const noexcept { return position_; }
 [[nodiscard]] double degrees() const noexcept { return static_cast<double>(position_); }
private: unsigned position_{};
};
class AntikytheraSequencer {
public:
 void advance() noexcept;
 [[nodiscard]] std::uint64_t cycle() const noexcept { return cycle_; }
 [[nodiscard]] unsigned state() const noexcept { return state_.position(); }
private: Gear360 state_{}; std::uint64_t cycle_{};
};
class DifferenceEngine {
public:
 explicit DifferenceEngine(std::vector<std::int64_t> values);
 [[nodiscard]] std::vector<std::int64_t> nextRow() const;
 [[nodiscard]] const std::vector<std::int64_t>& row() const noexcept { return row_; }
private: std::vector<std::int64_t> row_;
};
class PlanetaryGearSet {
public:
 static double carrierSpeed(double sunTeeth, double ringTeeth, double sunSpeed, double ringSpeed);
};
class Differential {
public:
 [[nodiscard]] static double sumOutput(double left, double right) noexcept;
 [[nodiscard]] static double differenceOutput(double left, double right) noexcept;
};
class RuleEngine {
public:
 void addFact(std::string fact);
 void addRule(std::string ifFact, std::string thenFact);
 [[nodiscard]] bool contains(std::string_view fact) const;
 [[nodiscard]] std::vector<std::string> infer();
 [[nodiscard]] const std::vector<std::string>& facts() const noexcept { return facts_; }
private:
 struct Rule { std::string premise; std::string conclusion; };
 std::vector<std::string> facts_; std::vector<Rule> rules_;
};
class LanguageEngine {
public:
 explicit LanguageEngine(std::string language = "en");
 void setLanguage(std::string language);
 [[nodiscard]] std::string renderFact(std::string_view fact) const;
private: std::string language_;
};
[[nodiscard]] std::string toDecimal(const UInt1024& value);
}
