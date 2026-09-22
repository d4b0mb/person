#pragma once

#include <string>

// The country that issued a person's identification document, identified
// by its ISO 3166-1 alpha-2 code (e.g. "EG", "US", "GB").
//
// Using the ISO code instead of a fixed enum means new countries never
// require a change to this class: any two-letter code is accepted, and
// name() falls back to the raw code for countries not in the built-in
// lookup table.
class Country {
public:
    // A default-constructed Country is "unset" and represents "unknown" /
    // "not provided".
    Country() = default;

    // Throws std::invalid_argument if isoAlpha2Code isn't exactly two
    // ASCII letters. The code is normalized to upper case.
    explicit Country(const std::string& isoAlpha2Code);

    const std::string& code() const noexcept { return isoCode_; }
    bool isSet() const noexcept { return !isoCode_.empty(); }

    // Best-effort human-readable name (e.g. "Egypt"). Falls back to the
    // ISO code for countries not in the built-in lookup table.
    std::string name() const;

    bool operator==(const Country& other) const noexcept { return isoCode_ == other.isoCode_; }
    bool operator!=(const Country& other) const noexcept { return !(*this == other); }

private:
    std::string isoCode_;
};
