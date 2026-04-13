#include <iostream>
#include <fstream>
#include "Structures.h"

void readFromFile(std::vector<Train>& trains, std::vector<Passenger>& passengers, std::vector<Booking>& bookings)
{
    // This function reads data from a text file and stores it in the vectors.
    std::ifstream read_trains("trains.txt");

    Train train;

    while (read_trains >> train.id >> train.trainName >> train.source >> train.destination >> train.departureTime >> train.arrivalTime >> train.totalSeats >> train.remainingSeats >> train.trainType)
    trains.push_back(train);

    read_trains.close(); // Close the file

    // -----

    std::ifstream read_passengers("passengers.txt");

    Passenger passenger;

    while (read_passengers >> passenger.id >> passenger.firstName >> passenger.lastName >> passenger.age)
    passengers.push_back(passenger);

    read_passengers.close();

    // -----

    std::ifstream read_bookings("bookings.txt");

    Booking booking;

    while (read_bookings >> booking.bookingID >> booking.passengerID >> booking.trainID >> booking.seatNumber >> booking.status)
    bookings.push_back(booking);

    read_bookings.close();

    // -----

    std::cout << "Data loaded successfully!\n";
}

void saveToFile(std::vector<Train>& trains, std::vector<Passenger>& passengers, std::vector<Booking>& bookings)
{
    // This function writes data from the vectors back to the text files.
    std::ofstream save_trains("trains.txt");

    for (const auto& train : trains)
    save_trains << train.id <<  " " << train.trainName <<  " " << train.source <<  " " << train.destination <<  " " << train.departureTime <<  " " << train.arrivalTime <<  " " << train.totalSeats <<  " " << train.remainingSeats <<  " " << train.trainType << "\n";

    save_trains.close();

    // -----

    std::ofstream save_passengers("passengers.txt");

    for (const auto& passenger : passengers)
    save_passengers << passenger.id << " " << passenger.firstName << " " << passenger.lastName << " " << passenger.age << "\n";

    save_passengers.close();

    // -----

    std::ofstream save_bookings("bookings.txt");

    for (const auto& booking : bookings)
    save_bookings << booking.bookingID << " " << booking.passengerID << " " << booking.trainID << " " << booking.seatNumber << " " << booking.status << "\n";

    save_bookings.close();

    std::cout << "All data saved successfully!\n";
}