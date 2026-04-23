#include <string>
#include "Person.h"

#ifndef PACKAGE_H
#define PACKAGE_H

class Package {

public:

    Package(
        const PersonInfo&,
        const PersonInfo&,
        const double,
        const double,
        const double,
        const double,
        const double
    );

    void setWeight(const double);
    void setCostPerWeight(const double);
    void setLength(const double);
    void setWidth(const double);
    void setHeight(const double);
    void setDimensions(const double, const double, const double);

    void setTrackingID(const std::string&);
    void updateStatus(const std::string&);

    const double getWeight() const;
    const double getCostPerWeight() const;
    const double getLength() const;
    const double getWidth() const;
    const double getHeight() const;
    const double getVolume() const;
    const std::string& getStatus() const;
    const std::string& getTrackingID() const;

    const bool isOversized(const double) const; // check whether the package is oversized

    double calculateCost() const;

    std::string toString() const;

private:

    PersonInfo sender;
    PersonInfo receiver;
    double weight{0};
    double costPerWeight{0};
    double length{0};
    double width{0};
    double height{0};
    std::string trackingNumber;
    std::string status;

    std::string packageInfo() const;
};

#endif
