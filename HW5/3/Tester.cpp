#include <iostream>
#include <iomanip>

#include "Time.h"

using namespace std;

int main()
{
	Time wakeup(6, 0);
	wakeup.add_minutes(5);
	cout << wakeup.hours() << ":" << setfill('0') << setw(2) << wakeup.minutes() << endl;
	cout << "Expected: 6:05" << endl;

	Time homework_due(18, 30);
	homework_due.add_minutes(3000);
	cout << homework_due.hours() << ":" << setfill('0') << setw(2) << homework_due.minutes() << endl;
	cout << "Expected: 20:30" << endl;
	
	return 0;
}