#include <string>
#include <sstream>
#include <stdexcept>
#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(
    
    const PersonInfo& infoOfSender,
    const PersonInfo& infoOfReceiver,
    const double packageWeight,
    const double cost,
    const double l,
    const double w,
    const double h,
    const double flatFee

) : Package(infoOfSender, infoOfReceiver, packageWeight, cost, l, w, h)

{
    // validity checking
    setFlatFee(flatFee);
}

void TwoDayPackage::setFlatFee(const double flatFee)
{
    if (flatFee < 0)
    throw std::invalid_argument("Flat fee must be positive");

    else
    this->flatFee = flatFee;
}

const double TwoDayPackage::getFlatFee() const
{
    return flatFee;
}

double TwoDayPackage::calculateCost() const
{
    return getFlatFee() + Package::calculateCost();
}

std::string TwoDayPackage::toString() const
{
    std::stringstream output;

    output
    << "two-day flat fee: $" << getFlatFee()
    << "\n"
    << Package::toString();

    return output.str();
}
