#pragma once

#include "Structures.h"

void bookTicket(std::vector<Booking>& bookings, std::vector<Train>& trains, std::vector<Passenger>& passengers);
void cancelTicket(std::vector<Train>& trains, std::vector<Passenger>& passengers, std::vector<Booking>& bookings);
void displayReservations(const std::vector<Train>& trains, const std::vector<Passenger>& passengers, const std::vector<Booking>& bookings);