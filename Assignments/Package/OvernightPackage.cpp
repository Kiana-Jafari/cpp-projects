#include <string>
#include <sstream>
#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(
    
    const PersonInfo& infoOfSender,
    const PersonInfo& infoOfReceiver,
    const double packageWeight,
    const double cost,
    const double l,
    const double w,
    const double h,
    const double feePerWeight

) : Package(infoOfSender, infoOfReceiver, packageWeight, cost, l, w, h)

{
    // validity checking
    setFeePerWeight(feePerWeight);
}

void OvernightPackage::setFeePerWeight(const double feePerWeight)
{
    this->feePerWight = feePerWeight;
}

const double OvernightPackage::getFeePerWight() const
{
    return feePerWight;
}

double OvernightPackage::calculateCost() const
{
    return ((getFeePerWight() + Package::getCostPerWeight()) * (Package::getWeight()));
}

std::string OvernightPackage::toString() const
{
    std::stringstream output;

    output
    << "additional overnight flat fee: $" << getFeePerWight()
    << Package::toString();

    return output.str();
}
