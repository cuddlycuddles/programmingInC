#include <stdio.h>

struct date
{
	int day;
	int month;
	int year;
};

struct days
{
	char day[10];
};

void dayOfTheWeek (struct date desu)
{
	int day;
	int f, g;
	
	char daysOfWeek[7][10] = {
		{ 'S', 'u', 'n', 'd', 'a', 'y' },
		{ 'M', 'o', 'n', 'd', 'a', 'y' },
		{ 'T', 'u', 'e', 's', 'd', 'a', 'y' },
		{ 'W', 'e', 'd', 'n', 'e', 's', 'd', 'a', 'y' },
		{ 'T', 'h', 'u', 'r', 's', 'd', 'a', 'y' },
		{ 'F', 'r', 'i', 'd', 'a', 'y' },
		{ 'S', 'a', 't', 'u', 'r', 'd', 'a', 'y' }
	};
	
	f = desu.month <= 2 ? --desu.year : desu.year;
	g = desu.month <= 2 ? desu.month + 13 : ++desu.month;
	
	day = ((1461 * f) / 4 + (153 * g) / 5 + desu.day - 621049) % 7;
	
	printf ("The day of the week is %s\n", daysOfWeek[day]);
}

int main (void)
{
	struct date input;
	
	printf ("Day of the week calculator: \n");
	printf ("Enter date (dd/mm/yyyy) to calculate: ");
	scanf ("%i/%i/%i", &input.day, &input.month, &input.year);
	
	dayOfTheWeek(input);
	
	return 0;
}
