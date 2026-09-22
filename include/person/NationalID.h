#pragma once

#include <string>

#include "person/Country.h"

// A person's identification number together with the country that issued
// it. The pairing matters because ID numbers aren't globally unique or
// comparable on their own: "12345" issued by Egypt and "12345" issued by
// Germany follow different national schemes and identify different
// people, so the two are never meaningfully interchangeable.
class NationalID {
public:
    // Default-constructed: no ID has been assigned yet.
    NationalID() = default;

    // Throws std::invalid_argument if number is empty or issuingCountry is
    // unset -- an ID is only meaningful together with the country that
    // issued it.
    NationalID(std::string number, Country issuingCountry);

    const std::string& number() const noexcept { return number_; }
    const Country& issuingCountry() const noexcept { return issuingCountry_; }
    bool isSet() const noexcept { return !number_.empty() && issuingCountry_.isSet(); }

    // e.g. "EG-29001010112345"
    std::string toString() const;

    bool operator==(const NationalID& other) const noexcept {
        return number_ == other.number_ && issuingCountry_ == other.issuingCountry_;
    }
    bool operator!=(const NationalID& other) const noexcept { return !(*this == other); }

private:
    std::string number_;
    Country issuingCountry_;
};
