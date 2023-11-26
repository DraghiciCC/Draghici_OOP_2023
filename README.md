# Draghici_OOP_2023

## Introduction

 This C++ application provides a simple yet robust system for booking cinema tickets. The project is structured using several classes to model different aspects of the cinema experience, including dates, events, locations, rooms, seats, tickets

 ## Features

### Date Class
Represents dates and provides methods for handling date-related operations.

- **Attributes** 
  - `minutes`: Minutes component of the time.
  - `hour`: Hour component of the time.
  - `month`: Month component using the `Month` enum.
  - `day`: Day of the month.
  - `year`: Year.

- **Operators:**
  - `operator=(const Date& anotherDate)`: Copy assignment operator.
  - `operator std::string()`: Typecast operator for converting to a string.
  - `operator==(const Date& anotherDate)`: Equality comparison operator.
  - `operator!=(const Date& anotherDate)`: Inequality comparison operator.
  - Stream operators for input and output.

### Event Class
  Represents cinema events and manages details such as event ID, name, start time, runtime, and associated room

  - **Attributes:**
    - `eventId`: Unique identifier for the event.
    - `name`: Name of the event.
    - `startTime`: Pointer to a `Date` object representing the start time.
    - `runtime`: Duration of the event in minutes.
    - `room`: Pointer to a `Room` object representing the venue.

- **Operators:**
  - `operator=(const Event& anotherEvent)`: Copy assignment operator.
  - `operator std::string()`: Typecast operator for converting to a string.
  - `operator==(const Event& anotherEvent)`: Equality comparison operator.
  - `operator!=(const Event& anotherEvent)`: Inequality comparison operator.
  - Stream operators for input and output.

### Location Class
  Represents physical locations of cinemas and manages details such as location ID, name, address, and associated events.

  - **Attributes:**
    - `locationId`: Unique identifier for the location.
    - `name`: Name of the location.
    - `address`: Address of the location.
    - `events`: Pointer to an array of `Event` objects representing scheduled events.
    - `runningEvents`: Number of currently running events at the location.

- **Public Interface:**
  - `addEvent(const char* name, unsigned int runtime, Room& room, unsigned int minutes, unsigned int hour, unsigned int day, Month month, unsigned int year)`: Add a new event to the location.
  
- **Operators:**
  - `operator=(const Location& anotherLocation)`: Copy assignment operator.
  - `operator std::string()`: Typecast operator for converting to a string.
  - `operator==(const Location& anotherLocation)`: Equality comparison operator.
  - `operator!=(const Location& anotherLocation)`: Inequality comparison operator.
  - Stream operators for input and output.

### Room Class
  Represents cinema rooms and manages details such as room ID, name, VIP status, number of seats, number of rows, and seat layout.

- **Attributes:**
  - `roomId`: Unique identifier for the room.
  - `name`: Name of the room.
  - `isVIP`: Boolean indicating whether the room is a VIP room.
  - `numberOfSeats`: Total number of seats in the room.
  - `numberOfRows`: Number of rows in the room.
  - `seats`: Pointer to an array of `Seat` objects representing the seat layout.

  - **Private Interface:**
  - `getNumberOfColumns()`: Helper function to calculate the number of columns based on the total number of seats and rows.

- **Public Interface:**
  - `setAllSeatsToFree()`: Set the status of all seats in the room to free.
  - `printLayout(std::ostream& out = std::cout)`: Print the seat layout to the specified output stream.
  - `changeSeatStatus(unsigned int seatId, SeatStatus newAvailability)`: Change the status of a seat based on its seat ID.
  - `changeSeatStatus(unsigned int row, unsigned int col, SeatStatus newAvailability)`: Change the status of a seat based on its row and column.
  - `static Seat** generateRoomOfSeats(unsigned int numberOfSeats)`: Generate an array of `Seat` objects representing the seat layout.
 
- **Operators:**
  - `operator=(const Room& anotherRoom)`: Copy assignment operator.
  - `operator std::string()`: Typecast operator for converting to a string.
  - `operator==(const Room& anotherRoom)`: Equality comparison operator.
  - `operator!=(const Room& anotherRoom)`: Inequality comparison operator.
  - Stream operators for input and output.

### Seat Class
  Represents individual seats within a cinema room and manages details such as seat ID and availability status

  - **Attributes:**
    - `seatId`: Unique identifier for the seat.
    - `availability`: Enumeration representing the seat's status (`FREE`, `PAID`, `RESERVED`).

  - **Public Interface:**
    - `char getAvailabilityAsSymbol()`: Get the availability status as a symbol (`F` for FREE, `P` for PAID, `R` for RESERVED).

- **Operators:**
  - `operator=(const Seat& anotherSeat)`: Copy assignment operator.
  - `operator==(const Seat& anotherSeat)`: Equality comparison operator.
  - `operator!=(const Seat& anotherSeat)`: Inequality comparison operator.
  - `operator std::string()`: Typecast operator for converting to a string.
  - Stream operators for input and output.

### Ticket Class
  Represents tickets for cinema events and manages details such as ticket ID and associated event.

  - **Attributes:**
    - `ticketId`: A unique identifier for the ticket.
    - `event`: Pointer to the associated `Event` for which the ticket is issued.

  - **Private Interface:**
    - `static char* generateId()`: Helper function to generate a unique ticket ID.

### Util Class
Provides utility functions for general-purpose tasks.

- **Utility Function:**
  - `deepCopy(const char* arr)`: Deep copies a character array (C-string).