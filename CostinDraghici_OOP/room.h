#pragma once
#include "seat.h"

class Room {
private:
	unsigned int roomId = 0;
	char* name = nullptr;
	bool isVIP = false;
	unsigned int numberOfSeats = 0;
	unsigned int numberOfRows = 0;
	Seat** seats = nullptr;

	static unsigned int TOTAL_ROOMS;

	// - Setters

	void setRoomId(unsigned int roomId);
	void setName(const char* name);
	void setType(const bool isVIP);
	void setNumberOfSeats(unsigned int numberOfSeats);
	void setNumberOfRows(unsigned int numberOfRows);
	void setSeats(Seat** seats);

	// - Private Interface

	unsigned int getNumberOfColumns();

public:

	// - Public interface

	void setAllSeatsToFree();
	void printLayout(std::ostream& out = std::cout);
	// change Seat status based on seatId
	void changeSeatStatus(unsigned int seatId, SeatStatus newAvailability);
	// change Seat status relatively
	void changeSeatStatus(unsigned int row, unsigned int col, SeatStatus newAvailability);
	static Seat** generateRoomOfSeats(unsigned int numberOfSeats);

	// - Getters

	char* getName();
	bool getIsVIP();
	Seat** getSeats();
	unsigned int getNumberOfSeats();
	unsigned int getNumberOfRows();

	// - Constructors / Destructor

	// copy constructor
	Room(const Room& anotherRoom);
	// make a room and generate 'n' number of seats
	Room(const char* name, bool isVIP, unsigned int n, unsigned int numberOfRows);
	// make an empty room
	Room();
	~Room();

	// - Operators

		// copy assignment

	Room operator=(const Room& anotherRoom);

	// typecast operator

	explicit operator std::string();

	// compare operators

	bool operator==(const Room& anotherRoom);
	bool operator!=(const Room& anotherRoom);

	// stream operators

	friend std::ostream& operator << (std::ostream& out, const Room& room);
	friend std::istream& operator >> (std::istream& in, Room& room);
};