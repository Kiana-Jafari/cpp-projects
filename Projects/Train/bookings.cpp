#include <iostream>
#include "IdGenerator.h"

int getNextSeat(const std::vector<Booking>& bookings);

void bookTicket(std::vector<Booking>& bookings, std::vector<Train>& trains, std::vector<Passenger>& passengers)
{
    // This function gets the passengerID and trainID and books a seat for them.
    int passID, trainID;
    bool passFound{false}, trainFound{false};

    std::cout << "Enter the passengerID and trainID: ";
    std::cin >> passID >> trainID;

    if (!bookings.empty())
    {
        for (const auto& booking : bookings)
        {
            if (booking.passengerID == passID && booking.trainID == trainID) // Check for duplicates
            {
                std::cout << "Already booked a ticket.\n";
                return ;
            }
        }
    }

    for (const auto& passenger : passengers)
    {
        if (passenger.id == passID) // Check if the passenger exists
        {
            passFound = true;

            for (auto& train : trains)
            {
                if (train.id == trainID) // Check if the train exists
                {
                    trainFound = true;

                    if (train.remainingSeats == 0) // Check if the train already has capacity
                    {
                        std::cout << "Train is full. No seats available.\n";
                        return ;
                    }

                    // Book a seat 
                    bookings.emplace_back();
                    auto& booking{bookings.back()};

                    booking.bookingID = getBookingID(bookings);
                    booking.passengerID = passID;
                    booking.trainID = trainID;
                    booking.seatNumber = getNextSeat(bookings);
                    booking.status = "Booked";

                    train.remainingSeats --; // Decrement current capacity of the train by one

                    break; // Break once the booking is done
                }
            }

            break;
        }
    }

    if (!passFound || !trainFound)
    std::cout << "Passenger or Train not found.\n";

    else
    std::cout << "Booking confirmed!\n";
}

void cancelTicket(std::vector<Train>& trains, std::vector<Passenger>& passengers, std::vector<Booking>& bookings)
{
    // This function cancels and withdraws a specific ticket of a passenger.
    int trainID, passID;
    bool passengerFound{false}, trainFound{false};

    if (bookings.empty())
    {
        std::cout << "No bookings available.\n";
        return ;
    }

    std::cout << "Enter the passengerID and trainID: ";
    std::cin >> passID >> trainID;

    for (const auto& passenger : passengers)
    {
        if (passenger.id == passID)
        {
            passengerFound = true;

            for (auto& train : trains)
            {
                if (train.id == trainID)
                {
                    trainFound = true;

                    for (auto& booking : bookings)
                    {
                        if (booking.passengerID == passID && booking.trainID == trainID)
                        {
                            booking.status = "Canceled";
                            break;
                        }
                    }

                    train.remainingSeats ++; // Increment the current remaining seats
                    break;
                }
            }

            break;
        }
    }

    if (!passengerFound || !trainFound)
    std::cout << "Passenger or Train not found.\n";

    else
    std::cout << "Booking canceled successfully.\n";
}

void displayReservations(const std::vector<Train>& trains, const std::vector<Passenger>& passengers, const std::vector<Booking>& bookings)
{
    // This function displays all reservations (booked or canceled) to the user.
    if (bookings.empty())
    {
        std::cout << "No reservations exist yet.\n";
        return ;
    }

    std::cout 
        << "| first name"
        << " | last name" 
        << " | train name" 
        << " | source"
        << " | destination"
        << " | departure time" 
        << " | arrival time" 
        << " | seat number"
        << " | train type" 
        << " | status\n";
    
    for (const auto& booking : bookings)
    {
        for (const auto& passenger : passengers)
        {
            for (const auto& train : trains)
            {
                if (booking.passengerID == passenger.id && booking.trainID == train.id)
                std::cout 
                    << "| " << passenger.firstName
                    << " | " << passenger.lastName
                    << " | " << train.trainName
                    << " | " << train.source
                    << " | " << train.destination
                    << " | " << train.departureTime
                    << " | " << train.arrivalTime
                    << " | " << booking.seatNumber
                    << " | " << train.trainType
                    << " | " << booking.status << "\n";
            }
        }
    }
}

int getNextSeat(const std::vector<Booking>& bookings)
{
    // This function returns the next seat number for a passenger starting from 1.
    int nextSeat = 0;

    for (const auto& booking : bookings)
    {
        if (booking.seatNumber > nextSeat)
        nextSeat = booking.seatNumber;
    }
    return nextSeat + 1;
}