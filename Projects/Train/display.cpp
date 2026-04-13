#include <iostream>
#include "Structures.h"

void displayData(const std::vector<Train>& trains, const std::vector<Passenger>& passengers)
{
    // This function displays a table's info based on the user choice.
    std::string choice;
    
    std::cout << "Which table do you want to display? (trains / passengers): ";
    std::cin >> choice;

    if (choice == "trains")
    {
        if (trains.empty())
        {
            std::cout << "No trains added yet.\n";
            return ;
        }

        std::cout 
            << "| id" 
            << " | train name" 
            << " | source" 
            << " | destination" 
            << " | departure time" 
            << " | arrival time" 
            << " | total seats" 
            << " | remaining seats" 
            << " | train type\n";

        for (const auto& train : trains)
        
        std::cout 
            << "| " << train.id 
            << " | " << train.trainName 
            << " | " << train.source 
            << " | " << train.destination 
            << " | " << train.departureTime 
            << " | " << train.arrivalTime 
            << " | " << train.totalSeats 
            << " | " << train.remainingSeats 
            << " | " << train.trainType << "\n";
    }

    else if (choice == "passengers")
    {
        if (passengers.empty())
        {
            std::cout << "No passengers added yet.\n";
            return ;
        }
        
        std::cout 
            << "| id" 
            << " | first name" 
            << " | last name "
            << " | age\n";

        for (const auto& passenger : passengers)
        
        std::cout 
            << "| " << passenger.id 
            << " | " << passenger.firstName 
            << " | " << passenger.lastName 
            << " | " << passenger.age << "\n";
    }
}

void recommendedTrains(std::vector<Train>& trains)
{
    // This function displays recommended trains based on the source and destination of the traveler and only if the train has already seats to book.
    std::string origin, destination;
    bool isFound{false};

    std::cout << "Enter the source and destination: ";
    std::cin >> origin >> destination;

    std::cout << "Recommended train(s):\n";
    for (const auto& train : trains)
    {
        if (train.source == origin && train.destination == destination && train.remainingSeats > 0) // Search for the trains
        {
            isFound = true;
            
            std::cout 
                << "| " << train.id
                << " | " << train.trainName
                << " | " << train.source
                << " | " << train.destination
                << " | " << train.departureTime
                << " | " << train.arrivalTime
                << " | " << train.totalSeats
                << " | " << train.remainingSeats
                << " | " << train.trainType << "\n";
        }
    }

    if (!isFound)
    std::cout << "No trains available at this time.\n";
}