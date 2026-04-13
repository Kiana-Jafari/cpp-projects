# 🚆 Train Recommender System

In this project, we're going to build a C++ console-based application that simulates a train management and recommendation system. <br>
The system is ID-based and works like a database with keys in tables. <br>
It also utilizes modularized and functional programming, in which each function is written in a separate module, and is included in the `main`. <br>
The project is one of the Tehran University's mini-project with a few more additional features. 

---

This program manages:

1. Read data from text files
2. Add data to a table
3. Remove a record from the train table 
4. Display data
5. Display recommended trains
6. Find available seat efficiently and book a ticket
7. Cancel a ticket
8. Display reservations and their current status
9. Save data back to the text files

---

## Overview of Data Structure

There is three structures that store info about trains, passengers, and reservations.

A train has the following features:

``` <id> <train_name> <source> <destination> <departure_time> <arrival_time> <total_seats> <remaining_seats> <train_type> ```

- trainName: `string` 
- source: `string`
- destination: `string`
- departureTime: `string` (of the form *hh:mm* from 00:00 to 23:59)
- arrivalTime : `string`
- totalSeats: `integer`
- remainingSeats: `integer`
- type: `string` (Express, Regular, Sleeping, Special)

---

An overview:

---

|id|train_name|source|destination|departure_time|arrival_time|total_capacity|remaining_capacity|train_type|
|----------|------|-----------|----|--------------|------------------|----------|------|----|
|1|Raja_501|Tehran|Shiraz|23:55|10:00|45|45|Express|
|2|Raja_511 |Tehran| Shiraz| 21:15 |11:00 |1| 0 |Local|
|3| Raja_423 |Mashhad |Shiraz| 16:20 |17:30 |5 |5 |Sleeping|

---

**Passenger**

----

``` <id> <firstName> <lastName> <age> ```

- id: `int`
- firstName: `string`
- lastName: `string`
- age: `int`

---

**Booking**

---

``` <bookingID> <passengerID> <trainID> <seatNumber> <status> ```

- bookingID: `int`
- passengerID: `int`
- trainID: `int`
- seatNumber: `int`
- status: `string` (Booked vs. Canceled)

---

Example:

---

|BookingID|passengerID|trainID|seatNumber|status|
|---------|-----------|-------|----------|------|
|1| 1| 2| 1| Booked|

---

**Removing a train from the table**

---

This program is also able to remove a train using soft deletion from the trains table, if there's been no ticket sold of this trip. (i.e. only if the train is not in use)

Example:

Delete the trip which has an ID of 2:

|id|train_name|source|destination|departure_time|arrival_time|total_capacity|remaining_capacity|train_type|
|----------|------|-----------|----|--------------|------------------|----------|------|----|
|2|Raja_511 |Tehran| Shiraz| 21:15 |11:00 |1| 0 |Local|

```

Output:

"This train has active bookings and cannot be deleted."

```

---

Delete the trip whose ID is 1:

```
Output:

"Deletion was successful."

```

---

**Canceling a ticket**

---

BookingID to be removed: 1

Train capacity after canceling the ticket:

|id|train_name|source|destination|departure_time|arrival_time|total_capacity|remaining_capacity|train_type|
|----------|------|-----------|----|--------------|------------------|----------|------|----|
|2|Raja_511 |Tehran| Shiraz| 21:15 |11:00 |1| 1 |Local|

---

Feel free to test the program!