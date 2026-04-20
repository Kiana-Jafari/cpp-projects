#include <iostream>
#include <map>
#include "Structures.h"

int mapVehicleType(const std::string);
double mapFeeVehicle(const std::string);
double CalculateFee(const int&, const int&, const std::string&);

void ParkVehicle(std::array<Vehicle, MAX_VEHICLES>& vehicles, std::array<std::array<ParkingSpot, MAX_SPOTS>, LEVELS>& spots, int& count)
{
    // This function gets the license plate of a vehicle and parks it in the first compatible spot.
    if (count == vehicles.max_size())
    {
        std::cout << "Garage is full.\n"; // edge case
        return ;
    }

    // Get the plate of the vehicle
    std::string plate, type;
    int time;

    std::cout << "\nEnter the plate and type of the vehicle: ";
    std::cin >> plate >> type;

    std::cout << "Enter the entryTime in minutes since midnight: ";
    std::cin >> time;

    // Check for duplicates
    for (size_t i{0}; i < count; ++i)
    {
        if (vehicles.at(i).licensePlate == plate)
        {
            std::cout << "The vehicle already exists.\n\n";
            return ;
        }
    }

    // Otherwise, add the vehicle to the array and mark spot as true
    int level{mapVehicleType(type)};

    for (size_t i{0}; i < MAX_SPOTS; ++i)
    {
        if (spots.at(level).at(i).occupied == false)
        {
            spots.at(level).at(i).occupied = true; // Park the vehicle here

            vehicles.at(count).licensePlate = plate;
            vehicles.at(count).vehicleType = type;
            vehicles.at(count).entryTime = time;
            vehicles.at(count).level = level;
            vehicles.at(count).spotNumber = i;

            count ++;

            std::cout << "Vehicle parked successfully!\n\n";

            break; // Stop when the spot is found
        }
    }
}

void SortVehicle(std::array<Vehicle, MAX_VEHICLES>& vehicles, int& count)
{
    // This function sorts the vehicles using Bubble Sort and based on the entry time (earliest first).
    bool swapped;

    for (size_t i{0}; i < (count - 1); ++i)
    {
        swapped = false;

        for (size_t j{0}; j < (count - 1 - i); ++j)
        {
            if (vehicles.at(j).entryTime > vehicles.at(j + 1).entryTime)
            {
                swapped = true;

                std::swap(vehicles.at(j).licensePlate, vehicles.at(j + 1).licensePlate);
                std::swap(vehicles.at(j).vehicleType, vehicles.at(j + 1).vehicleType);
                std::swap(vehicles.at(j).entryTime, vehicles.at(j + 1).entryTime);
                std::swap(vehicles.at(j).level, vehicles.at(j + 1).level);
                std::swap(vehicles.at(j).spotNumber, vehicles.at(j + 1).spotNumber);
            }
        }

        if (!swapped)
        break;
    }

    std::cout << "Vehicles sorted successfully!\n\n";
}

void ExitVehicle(std::array<Vehicle, MAX_VEHICLES>& vehicles, std::array<std::array<ParkingSpot, MAX_SPOTS>, LEVELS>& spots, int& count)
{
    // This function gets the license plate of a vehicle and removes it (exits).
    std::string plate;
    int exitTime;
    double fee;

    std::cout << "\nEnter the license plate: ";
    std::cin >> plate;

    std::cout << "Enter the exitTime in minutes since midnight: ";
    std::cin >> exitTime;

    for (size_t i{0}; i < count; ++i)
    {
        if (vehicles.at(i).licensePlate == plate)
        {
            std::string type{vehicles.at(i).vehicleType};
            int spotNumber{vehicles.at(i).spotNumber};
            int level{vehicles.at(i).level};

            spots.at(level).at(spotNumber).occupied = false; // Free the spot

            fee = CalculateFee(exitTime, vehicles.at(i).entryTime, type); // Calculate the fee

            // Shift the elements to the left
            count --;

            for (size_t j{i}; j < count; ++j)
            {
                vehicles.at(j).licensePlate = vehicles.at(j + 1).licensePlate;
                vehicles.at(j).vehicleType = vehicles.at(j + 1).vehicleType;
                vehicles.at(j).entryTime = vehicles.at(j + 1).entryTime;
                vehicles.at(j).level = vehicles.at(j + 1).level;
                vehicles.at(j).spotNumber = vehicles.at(j + 1).spotNumber;
            }

            break;
        }
    }

    std::cout << "\nSpot freed\n";
    std::cout << "Fee: $" << fee << "\n\n";
}

double CalculateFee(const int& exitTime, const int& entryTime, const std::string& type)
{
    // This function calculates the fee based on the time duration and type of the vehicle
    double rate{mapFeeVehicle(type)};

    int diffTime{exitTime - entryTime};
    double fee{diffTime * rate};

    return fee;
}

int mapVehicleType(const std::string type)
{
    // This function gets the type of the vehicle and returns the associated level.
    std::map<std::string, int> VehicleType = {
        {"Motorcycle", 0}, {"Car", 1}, {"Truck", 2}
    };

    int level{VehicleType[type]};

    return level;
}

double mapFeeVehicle(const std::string type)
{
    // This function gets type of the vehicle and returns the fee based on the type.
    std::map<std::string, double> Fee = {
        {"Motorcycle", 0.03}, {"Car", 0.05}, {"Truck", 0.08}
    };

    double rate{Fee[type]};

    return rate;
}
