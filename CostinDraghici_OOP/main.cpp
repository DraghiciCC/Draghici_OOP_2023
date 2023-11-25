#include <iostream>
#include <string>
#include "date.h"
#include "seat.h"
#include "room.h"

using namespace std;


int main() {
	Date a(48, 6, 21, Month::AUGUST, 2022);
	cout << a << endl << endl;
	Room b("Amadeus", 1, 3, 1);
	cout << b << endl << endl;
}
