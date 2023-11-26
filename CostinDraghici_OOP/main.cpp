#include <iostream>
#include "ticket.h"

using namespace std;

int main() {

	Room Danubia("Danubia", 1, 40, 4);
	Room CinemaCityR2("CinemaCityR2", 1, 46, 7);
	Location cinema("Cinema", "Str. dov 2");
	cinema.addEvent("Miami Bici2", 87, Danubia, 30, 16, 27, Month::DECEMBER, 2022);
	cinema.addEvent("Nunta pe bani", 85, CinemaCityR2, 30, 16, 27, Month::DECEMBER, 2022);

	// display Danubia

	Danubia.changeSeatStatus(3, 4, SeatStatus::PAID);
	Danubia.changeSeatStatus(2, 1, SeatStatus::RESERVED);
	Danubia.changeSeatStatus(4, 7, SeatStatus::PAID);

	cout << (string)Danubia << endl;
	Danubia.printLayout(cout);

	// display CinemaCity

	CinemaCityR2.changeSeatStatus(3, 4, SeatStatus::PAID);
	CinemaCityR2.changeSeatStatus(2, 1, SeatStatus::PAID);
	CinemaCityR2.changeSeatStatus(3, 3, SeatStatus::RESERVED);

	cout << (string)CinemaCityR2 << endl;
	CinemaCityR2.printLayout(cout);

	// display a location

	cout << endl << (string)cinema << endl;
	cout << "How it will be stored in a file: " << endl << cinema;

	return 0;
}