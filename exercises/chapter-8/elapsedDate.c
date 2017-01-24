#include <stdio.h>
#include <stdbool.h>

struct date
{
	int day;
	int month;
	int year;
};

int totalDays (struct date desu)
{
	int total;
	int f, g;
	
	f = desu.month <= 2 ? --desu.year : desu.year;
	g = desu.month <= 2 ? desu.month + 13 : ++desu.month;
	
	total = (1461 * f) / 4 + (153 * g) / 5 + desu.day;
	
	return total;
}

int main (void)
{
	struct date date1 = { 8, 8, 2014 };
	struct date date2 = { 22, 2, 2015 };
	int elapsedTime;
	
	elapsedTime = totalDays(date2) - totalDays(date1);
	
	printf ("The number of days between %i/%i/%i and %i/%i/%i is %i days.\n",
			date1.day, date1.month, date1.year,
			date2.day, date2.month, date2.year,
			elapsedTime); // Output: "The number of days between 8/8/2014 and 22/2/2015 is 198 days."
	
	return 0;
}
