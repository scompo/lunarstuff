/* Prints the moon stuff from a date to another */

#include <stdio.h>
#include <time.h>
#include <libnova/lunar.h>
#include <libnova/julian_day.h>

int main (void)
{
	double julian_time;
	double disk;
	double disk_prima;
	time_t day;
	time_t poco_prima;
	struct tm *ss;
	int NUM=900;
	int i;

	day = time(NULL);
	ss = localtime(&day);
	ss->tm_hour = 2;
	ss->tm_min = 0;
	day = mktime(ss);
	for (i = 0 ; i < NUM ; i++) 
	{
		char str[80];
		char *cosa ="boh";
		day = day + ( 60 * 60 * 24);
		ss = localtime(&day);
		if(!strftime(str, sizeof str, "%d/%m/%Y %H:%M", ss))
		{
			printf("error strftime\n");
		}
		julian_time = ln_get_julian_from_timet(&day);
		disk = ln_get_lunar_disk(julian_time);

		if(disk > 0.99)
		{
			cosa = "piena";
		}
		else if (disk < 0.01)
		{
			cosa = "nuova";
		}
		else
		{
			poco_prima = day - (60 * 60);
			julian_time = ln_get_julian_from_timet(&poco_prima);
			disk_prima = ln_get_lunar_disk(julian_time);
			if (disk > disk_prima)
			{
				cosa = "crescente";
			}
			else
			{
				cosa = "calante";
			}
		}



		printf("%s -  %f - %s \n", str , disk, cosa);
	}
	return 0;
}
