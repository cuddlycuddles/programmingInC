#include <stdio.h>
#include <stdbool.h>

bool midnight;

struct date
{
	int day;
	int month;
	int year;
};

struct time
{
	int hour;
	int minutes;
	int seconds;
};

struct dateAndTime
{
	struct date sdate;
	struct time stime;
};

int main (void)
{
	struct time timeUpdate (struct time now);
	struct date dateUpdate (struct date today);
	struct dateAndTime clockKeeper (struct dateAndTime currentTime);
	struct dateAndTime currentTime, nextTime;
	
	printf ("Enter the time (hh:mm:ss): ");
	scanf ("%i:%i:%i", &currentTime.stime.hour, &currentTime.stime.minutes,
		   &currentTime.stime.seconds);
	
	printf ("Enter the date (dd/mm/yyyy): ");
	scanf ("%i/%i/%i", &currentTime.sdate.day, &currentTime.sdate.month, &currentTime.sdate.year);
	
	nextTime = clockKeeper (currentTime);
	
	printf ("\nUpdated time is %.2i:%.2i:%.2i,\nUpdated date is %i/%i/%i.\n",
			nextTime.stime.hour, nextTime.stime.minutes, nextTime.stime.seconds,
			nextTime.sdate.day, nextTime.sdate.month, nextTime.sdate.year);
	
	return 0;
}

struct dateAndTime clockKeeper (struct dateAndTime currentTime)
{
	struct time timeUpdate (struct time now);
	struct date dateUpdate (struct date today);
	
	currentTime.stime = timeUpdate (currentTime.stime);
	
	if (midnight) {
		currentTime.sdate = dateUpdate (currentTime.sdate);
	}
	
	return currentTime;
}

struct time timeUpdate (struct time now)
{
	++now.seconds;
	
	if (now.seconds == 60) {
		now.seconds = 0;
		++now.minutes;
		
		if (now.minutes == 60) {
			now.minutes = 0;
			++now.hour;
			
			if (now.hour == 24) {
				now.hour = 0;
				midnight = true;
			}
		}
	}
	
	return now;
}

struct date dateUpdate (struct date today)
{
	struct date tomorrow;
	int numberOfDays (struct date d);
	
	if (today.day != numberOfDays (today)) {
		tomorrow = (struct date) { ++today.day, today.month, today.year };
	}
	else if (today.month == 12) {
		tomorrow = (struct date) { 1, 1, ++today.year };
	}
	else {
		tomorrow = (struct date) { 1, ++today.month, today.year };
	}
	
	return tomorrow;
}

int numberOfDays (struct date d)
{
	int days;
	bool isLeapYear (struct date d);
	
	const int daysPerMonth[12] =
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if (isLeapYear (d) == true && d.month == 2)
		days = 29;
	else
		days = daysPerMonth[d.month - 1];
	
	return days;
}

bool isLeapYear (struct date d)
{
	bool leapYearFlag;
	
	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
		leapYearFlag = true;
	else
		leapYearFlag = false;
	
	return leapYearFlag;
}




