#include "seat.h"

unsigned int Seat::TOTAL_SEATS = 0;

// - SeatStatus operators

std::ostream& operator << (std::ostream& out, const SeatStatus& availability) {
	switch (availability) {
	case SeatStatus::FREE:
		out << "free"; break;
	case SeatStatus::RESERVED:
		out << "reserved"; break;
	case SeatStatus::PAID:
		out << "paid"; break;
	default:
		out << "unknown";
	}
	return out;
}

std::istream& operator >> (std::istream& in, SeatStatus& availability) {
	int i = 0;
	if (!(in >> i) || i > 2) {
		availability = SeatStatus::FREE;
		return in;
	}
	else
		availability = (SeatStatus)i;
	return in;
}

// - Setters

void Seat::setSeatId(unsigned int seatId) {
	if (seatId != 0)
		this->seatId = seatId;
	else throw;
}

void Seat::setAvailability(SeatStatus newAvailability) {
	if ((int)newAvailability > 2 || (int)newAvailability < 0)
		this->availability = SeatStatus::FREE;
	else
		this->availability = newAvailability;
}

// - Public Interface

char Seat::getAvailabilityAsSymbol() {
	if (availability == SeatStatus::FREE)
		return '-';
	if (availability == SeatStatus::PAID)
		return '+';
	if (availability == SeatStatus::RESERVED)
		return '/';
	return '?';
}

// - Getters

int Seat::getSeatId() {
	return this->seatId;
}

SeatStatus Seat::getAvailability() {
	return this->availability;
}

// - Constructors

Seat::Seat(const Seat& anotherSeat) {
	this->setSeatId(anotherSeat.seatId);
	this->setAvailability(anotherSeat.availability);
	++TOTAL_SEATS;
}

Seat::Seat() {
	this->setSeatId(++TOTAL_SEATS);
}

Seat::~Seat() {
	--TOTAL_SEATS;
}

// - Operators

// copy assignment

Seat Seat::operator=(const Seat& anotherSeat) {
	this->setSeatId(anotherSeat.seatId);
	this->setAvailability(anotherSeat.availability);
	return *this;
}

// compare operators

bool Seat::operator==(const Seat& anotherSeat) {
	if (this == &anotherSeat)
		return true;
	if (this->seatId == anotherSeat.seatId)
		return false;
	if (this->availability == anotherSeat.availability)
		return false;
	return true;
}

bool Seat::operator!=(const Seat& anotherSeat) {
	return !(*this == anotherSeat);
}

// string typecast

Seat::operator std::string() {
	std::stringstream ss;
	ss << "Seat #" << this->seatId << " is currently: " << this->availability;
	return ss.str();
}

// stream operators

std::ostream& operator << (std::ostream& out, const Seat& seat) {
	out << "S" << seat.seatId << "-" << (int)seat.availability << ";";
	return out;
}

std::istream& operator >> (std::istream& in, Seat& seat) {
	std::string seatId;
	std::string availability;
	if (std::getline(in, seatId, 'S') &&
		std::getline(in, seatId, '-') &&
		std::getline(in, availability, ';')) {
		seat.setSeatId(std::stoi(seatId));
		seat.setAvailability((SeatStatus)std::stoi(availability));
	}
	else throw;
	return in;
}