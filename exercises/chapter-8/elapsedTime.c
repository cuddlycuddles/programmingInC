#include <stdio.h>
#include <stdbool.h>

struct time
{
	int hours;
	int minutes;
	int seconds;
};

struct time elapsed_time (struct time time1, struct time time2)
{
	int total1, total2;
	int elapsed;
	struct time time_passed;
	
	total1 = time1.hours * 3600 + time1.minutes * 60 + time1.seconds;
	total2 = time2.hours * 3600 + time2.minutes * 60 + time2.seconds;
	
	if (total2 > total1) {
		elapsed = total2 - total1;
	} else {
		elapsed = 86400 - (total1 - total2);
	}
	
	time_passed.hours = elapsed / 3600;
	elapsed %= 3600;
	
	time_passed.minutes = elapsed / 60;
	elapsed %= 60;
	
	time_passed.seconds = elapsed;

	return time_passed;
}

int main (void)
{
	struct time time1 = { 18, 12, 3 };
	struct time time2 = { 17, 4, 4 };
	struct time elapsed_time (struct time time1, struct time time2);
	struct time time_passed;
	
	printf ("The amount of time between %.2i:%.2i:%.2i and %.2i:%.2i:%.2i is ",
			time1.hours, time1.minutes, time1.seconds,
			time2.hours, time2.minutes, time2.seconds);
	
	time_passed = elapsed_time (time1, time2);
	
	printf ("%i hours, %i minutes, and %i seconds.\n",
			time_passed.hours, time_passed.minutes, time_passed.seconds);
	
	return 0;
}
