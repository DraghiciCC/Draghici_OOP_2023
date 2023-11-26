#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "util.h"

enum class SeatStatus {
	FREE,
	PAID,
	RESERVED
};

// - SeatStatus operators

std::ostream& operator << (std::ostream& out, const SeatStatus& availability);
std::istream& operator >> (std::istream& in, SeatStatus& availability);

class Seat {
private:

	friend class Room;

	unsigned int seatId = 0;
	SeatStatus availability = SeatStatus::FREE;

	static unsigned int TOTAL_SEATS;

	// - Setters

	void setAvailability(SeatStatus newAvailability);
	void setSeatId(unsigned int seatId);

public:

	// - Public Interface

	char getAvailabilityAsSymbol();

	// - Getters

	int getSeatId();
	SeatStatus getAvailability();

	// - Constructors

	// copy constructor
	Seat(const Seat& anotherSeat);
	// make an empty seat
	Seat();
	~Seat();

	// - Operators

		// copy assignment

	Seat operator=(const Seat& anotherSeat);

	// compare operators

	bool operator==(const Seat& anotherSeat);
	bool operator!=(const Seat& anotherSeat);

	// string typecast, print a verbose Seat

	explicit operator std::string();

	// stream operators

	friend std::ostream& operator << (std::ostream& out, const Seat& seat);
	friend std::istream& operator >> (std::istream& in, Seat& seat);

};
