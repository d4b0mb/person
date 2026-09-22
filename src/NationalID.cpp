#include "person/NationalID.h"

#include <stdexcept>

NationalID::NationalID(std::string number, Country issuingCountry)
    : number_(std::move(number)), issuingCountry_(std::move(issuingCountry)) {
    if (number_.empty()) {
        throw std::invalid_argument("NationalID: number must not be empty");
    }
    if (!issuingCountry_.isSet()) {
        throw std::invalid_argument("NationalID: an issuing country is required");
    }
}

std::string NationalID::toString() const {
    if (!isSet()) {
        return "(not assigned)";
    }
    return issuingCountry_.code() + "-" + number_;
}
