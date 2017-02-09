#include <stdio.h>
#include <stdbool.h>

struct date
{
	int day;
	int month;
	int year;
};

int main (void)
{
	struct date dateUpdate (struct date *today);
	struct date *today;
	
	printf ("Enter today's date (dd/mm/yy): ");
	scanf ("%i/%i/%i", &today->day, &today->month, &today->year);
	
	dateUpdate (today);
	
	printf ("The date one day later is: %i/%i/%i\n", today->day, today->month, today->year);
	
	return 0;
}

struct date dateUpdate (struct date *today)
{
	struct date tomorrow;
	int numberOfDays (struct date *d);
	
	if ( today->day != numberOfDays (today) )
	{
		++today->day;
	}
	else if ( today->month == 12 )
	{
		today->day = 1;
		today->month = 1;
		++today->year;
	}
	else
	{
		today->day = 1;
		++today->month;
	}
	
	return tomorrow;
}

// number of days in a month
int numberOfDays (struct date *d)
{
	int days;
	bool isLeapYear (struct date *d);
	
	const int daysPerMonth[12] =
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if ( isLeapYear (d) == true && d->month == 2 )
		days = 29;
	else
		days = daysPerMonth[d->month - 1];
	
	return days;
}

// determine if leap year
bool isLeapYear (struct date *d)
{
	bool leapYearFlag;
	
	if ( (d->year % 4 == 0 && d->year % 100 != 0) || d->year % 400 == 0)
		leapYearFlag = true;
	else
		leapYearFlag = false;
	
	return leapYearFlag;
}

/* output:
 Enter today's date (dd/mm/yy): 28/02/2000
 The date one day later is: 29/2/2000
 */


