#include <iostream>
#include <string>
#include "date.h"
#include "seat.h"
#include "room.h"
#include "event.h"

using namespace std;


int main() {
	Date a(48, 6, 21, Month::AUGUST, 2022);
	cout << a << endl << endl;
	Room b("Amadeus", 1, 3, 1);
	cout << b << endl << endl;
	Event c("Miami Bici", a, 32, b);
	cout << c << endl << endl;


}
