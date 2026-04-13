#pragma once

#include <string>
#include <vector>

struct Train {
    int id;
    std::string trainName;
    std::string source;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    int totalSeats;
    int remainingSeats;
    std::string trainType; // Express, InterCity, Regional, Local, HighSpeed, Sleeper
};

struct Passenger {
    int id;
    std::string firstName;
    std::string lastName;
    int age;
};

struct Booking {
    int bookingID;
    int passengerID;
    int trainID;
    int seatNumber;
    std::string status; // Booked or Canceled
};