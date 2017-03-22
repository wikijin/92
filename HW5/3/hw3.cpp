#include "Time.h"

/*
  Provide the hours and minutes member functions.
 */
Time::Time(int hr, int min)
{
	minutesSinceMidnight = 0;
	add_minutes(60 * hr + min);   
}
...
void Time::add_minutes(int minutes)
{
	minutesSinceMidnight += minutes;
	minutesSinceMidnight %= 24 * 60;      
	if (minutesSinceMidnight < 0) minutesSinceMidnight += 24 * 60;
}