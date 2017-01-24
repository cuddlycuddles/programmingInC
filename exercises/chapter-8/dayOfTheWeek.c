#include <stdio.h>

struct date
{
	int day;
	int month;
	int year;
};

struct days
{
	char day[7];
};

void dayOfTheWeek (struct date desu)
{
	int day;
	int f, g;
	
	const struct days daysOfWeek[7] = {
		{ 'S', 'U', 'N' }, { 'M', 'O', 'N' }, { 'T', 'U', 'E' }, { 'W', 'E', 'D' },
		{ 'T', 'H', 'U' }, { 'F', 'R', 'I' }, { 'S', 'A', 'T' }
	};
	
	f = desu.month <= 2 ? --desu.year : desu.year;
	g = desu.month <= 2 ? desu.month + 13 : ++desu.month;
	
	day = ((1461 * f) / 4 + (153 * g) / 5 + desu.day - 621049) % 7;
	
	printf ("The day of the week is %c%c%c.\n",
			daysOfWeek[day].day[0],
			daysOfWeek[day].day[1],
			daysOfWeek[day].day[2]);
}

int main (void)
{
	struct date input;
	
	printf ("Day of the week calculator: \n");
	printf ("Enter date (dd/mm/yy) to calculate: ");
	scanf ("%i/%i/%i", &input.day, &input.month, &input.year);
	
	dayOfTheWeek(input);
	
	return 0;
}
