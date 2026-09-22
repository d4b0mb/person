#include "person/Country.h"

#include <cctype>
#include <stdexcept>
#include <unordered_map>

namespace {

bool isTwoLetterCode(const std::string& code) {
    return code.size() == 2 && std::isalpha(static_cast<unsigned char>(code[0])) &&
           std::isalpha(static_cast<unsigned char>(code[1]));
}

std::string toUpper(std::string s) {
    for (char& c : s) {
        c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }
    return s;
}

// Convenience lookup for common countries. Not exhaustive by design: add
// entries as they're needed, or swap in a full ISO 3166-1 table if the
// project grows to require one. Country works correctly for any valid
// code even when it isn't listed here -- name() just falls back to the code.
const std::unordered_map<std::string, std::string>& countryNames() {
    static const std::unordered_map<std::string, std::string> names = {
        {"EG", "Egypt"},        {"US", "United States"}, {"GB", "United Kingdom"},
        {"DE", "Germany"},      {"FR", "France"},        {"CA", "Canada"},
        {"AU", "Australia"},    {"IN", "India"},         {"CN", "China"},
        {"JP", "Japan"},        {"BR", "Brazil"},        {"SA", "Saudi Arabia"},
        {"AE", "United Arab Emirates"}, {"TR", "Turkey"}, {"IT", "Italy"},
        {"ES", "Spain"},        {"NL", "Netherlands"},   {"RU", "Russia"},
        {"ZA", "South Africa"}, {"MX", "Mexico"},
    };
    return names;
}

}  // namespace

Country::Country(const std::string& isoAlpha2Code) : isoCode_(toUpper(isoAlpha2Code)) {
    if (!isTwoLetterCode(isoCode_)) {
        throw std::invalid_argument("Country: expected an ISO 3166-1 alpha-2 code, got \"" + isoAlpha2Code + "\"");
    }
}

std::string Country::name() const {
    if (!isSet()) {
        return "Unknown";
    }
    const auto& names = countryNames();
    auto it = names.find(isoCode_);
    return it != names.end() ? it->second : isoCode_;
}
