#include <iostream>
#include "Structures.h"

void DisplayVehicles(const std::array<Vehicle, MAX_VEHICLES>& vehicles, int& count)
{
    // This function displays all parked vehicles.
    if (count == 0)
    {
        std::cout << "The garage is empty\n";
        return ;
    }

    std::cout << "\nlicense plate | type | entry time | level | spot number\n";
    
    for (size_t i{0}; i < count; ++i)
    
    std::cout << 
        vehicles.at(i).licensePlate << " | " << 
        vehicles.at(i).vehicleType << " | " << 
        vehicles.at(i).entryTime << " | " << 
        vehicles.at(i).level << " | " << 
        vehicles.at(i).spotNumber << "\n";

    std::cout << "\n";
}

void DisplayFreeSpots(const std::array<std::array<ParkingSpot, MAX_SPOTS>, LEVELS>& spots)
{
    // This function displays all free spots per level (vehicle type).
    int type;

    std::cout 
        << "Which vehicle's free spots do you want to display?:\n"
        << "Motorcycles : 0\n"
        << "Cars : 1\n"
        << "Trucks : 2\n"
        << "> ";

    std::cin >> type;

    for (size_t level{0}; level < LEVELS; ++level)
    {
        if (level == type)
        {
            std::cout << "Free Spots per level " << level << "\n";
            std::cout << "level | spot number\n";

            for (size_t j{0}; j < MAX_SPOTS; ++j)
            {
                if (spots.at(level).at(j).occupied == false)
                std::cout << level << "-" << j << "\n";

                else
                std::cout << "Full\n";
            }
        }
    }

    std::cout << "\n";
}

void SearchVehicle(const std::array<Vehicle, MAX_VEHICLES>& vehicles, int& count)
{
    // This function gets the license plate of a vehicle and prints its information.
    std::string plate;
    bool isFound{false};

    std::cout << "\nEnter the vehicle plate: ";
    std::cin >> plate;

    for (size_t i{0}; i < count; ++i)
    {
        if (vehicles.at(i).licensePlate == plate)
        {
            isFound = true;
            
            std::cout << "\ntype | entry time | level | spot number \n";
            
            std::cout 
                << vehicles.at(i).vehicleType << " | "   
                << vehicles.at(i).entryTime << " | " 
                << vehicles.at(i).level << " | " 
                << vehicles.at(i).spotNumber << "\n";
            
            break;
        }
    }

    std::cout << "\n";

    // Vehicle not found
    if (!isFound)
    std::cout << "Vehicle not found.\n";
}