#include <string>
#include <sstream>
#include <stdexcept>
#include "Package.h"
#include "Person.h"

Package::Package(

    const PersonInfo& senderInfo,
    const PersonInfo& receiverInfo,
    const double weight,
    const double costPerWeight,
    const double length,
    const double width,
    const double height

) : sender{senderInfo}, receiver{receiverInfo}

{
    // validity checking
    setWeight(weight);
    setCostPerWeight(costPerWeight);
    setLength(length);
    setWidth(width);
    setHeight(height);
}

// Setters
void Package::setWeight(const double weight)
{
    if (weight < 0)
    throw std::invalid_argument("Weight should be positive");

    else
    this->weight = weight;
}

void Package::setCostPerWeight(const double costPerWeight)
{
    if (costPerWeight < 0)
    throw std::invalid_argument("Cost per weight should be positive");

    else
    this->costPerWeight = costPerWeight;
}

void Package::setLength(const double length)
{
    if (length < 0)
    throw std::invalid_argument("Length can't be negative");

    else
    this->length = length;
}

void Package::setWidth(const double width)
{
    if (width < 0)
    throw std::invalid_argument("Width can't be negative");

    else
    this->width = width;
}

void Package::setHeight(const double height)
{
    if (height < 0)
    throw std::invalid_argument("Height can't be negative");

    else
    this->height = height;
}

void Package::setDimensions(const double length, const double width, const double height)
{
    this->length = length;
    this->width = width;
    this->height = height;
}

void Package::setTrackingID(const std::string& trackingNumber)
{
    this->trackingNumber = trackingNumber;
}

void Package::updateStatus(const std::string& status)
{
    this->status = status;
}

// Getters
const double Package::getWeight() const
{
    return weight;
}

const double Package::getCostPerWeight() const
{
    return costPerWeight;
}

const double Package::getLength() const
{
    return length;
}

const double Package::getWidth() const
{
    return width;
}

const double Package::getHeight() const
{
    return height;
}

const double Package::getVolume() const
{
    return (getLength() * getWidth() * getHeight());
}

const std::string& Package::getStatus() const
{
    return status;
}

const std::string& Package::getTrackingID() const
{
    return trackingNumber;
}

const bool Package::isOversized(const double threshold) const
{
    if (getVolume() > threshold)
    return true;

    else
    return false;
}

double Package::calculateCost() const
{
    // returns a double indicating the cost associated with shipping the package.
    return getWeight() * getCostPerWeight();
}

std::string Package::toString() const
{
    std::stringstream output;

    output
    << "\nSender info:\n"
    << sender.toString()
    << "\n\nsending a package to..."
    << "\n\nReceiver info:\n"
    << receiver.toString()
    << packageInfo();

    return output.str();
}

// utility function
std::string Package::packageInfo() const
{
    std::stringstream output;

    output
    << "\n\nPackage info:"
    << "\ntrackingID: " << getTrackingID()
    << "\n\nweight: " << getWeight()
    << "\nvolume: " << getVolume()
    << "\ncost per ounce: $" << getCostPerWeight()
    << "\nstatus: " << getStatus();

    return output.str();
}
