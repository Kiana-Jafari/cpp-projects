#include <iostream>
#include "IdGenerator.h"

void addData(std::vector<Train>& trains, std::vector<Passenger>& passengers)
{
    // This function adds data to passengers and trains vectors based on the user choice.
    std::string option;
    char answer;
    
    do {

        std::cout << "Which table do you want to add data to? (passengers / trains): ";
        std::cin >> option;

        if (option == "passengers")
        {
            passengers.emplace_back();
            auto& passenger{passengers.back()};

            std::cout << "Enter the passenger info:\n";
            std::cout << "first name | last name | age\n";

            std::cin >> passenger.firstName >> passenger.lastName >> passenger.age;
            passenger.id = getPassengerID(passengers);
            
        }

        else if (option == "trains")
        {
            trains.emplace_back();
            auto& train{trains.back()};

            std::cout << "Enter the train info:\n";
            std::cout << "train name | source | destination | departure time | arrival time | total seats | train type\n";

            std::cin >> train.trainName >> train.source >> train.destination >> train.departureTime >> train.arrivalTime >> train.totalSeats >> train.trainType;
            train.id = getTrainID(trains);
            train.remainingSeats = train.totalSeats; // At first glance, the two fields would be equal
        }

        std::cout << "Do you still want to add data? (y / n): ";
        std::cin >> answer;
    }

    while (answer == 'y');

    std::cout << "Data added successfully!\n";
}

void removeTrain(std::vector<Train>& trains, std::vector<Booking>& bookings)
{
    // This function gets a trainID of interest and removes all records from the table if no bookings exist.
    unsigned int targetID;

    std::cout << "Enter the ID to be removed: ";
    std::cin >> targetID;

    for (const auto& train : trains) // Linear Search
    {
        if (train.id == targetID)
        {
            std::cout << "This train has active bookings and cannot be deleted.\n";
            return ;
        }
    }

    for (auto iter = trains.begin(); iter != trains.end(); ++iter)
    {
        if (iter->id == targetID) // If no active booking is found, erase the record from the table
        {
            trains.erase(iter);
            std::cout << "Trip with ID " << iter->id << " has been deleted successfully.\n";
            break;
        }
    }
}