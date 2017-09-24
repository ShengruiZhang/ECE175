// Author: Shengrui Zhang
// Date Created: 09/03/17
/* Description:
   Input: Peak altitude of an object
          Time it took to reach the peak
		  
   Output: Gravitational constant
           Peak velocity
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void) {
	
	double alt_Peak = 0;
	double time = 0;
	double const_gravta = 0;
	double vel_Peak = 0;
	
	
	printf("Enter the peak altitude that the object traveled (meters): ");
	scanf("%lf", &alt_Peak);
	
	printf("Enter the time it took for the object to reach its peak altitude (seconds): ");
	scanf("%lf", &time);
	
	
	const_gravta = 2 * alt_Peak;
	//printf("%.2lf\n", time);
	const_gravta = (const_gravta / pow(time, 2));
	printf("The planet's gravitational constant is calculated to be %.2lf meters per second per second.\n", const_gravta);
	
	vel_Peak = const_gravta * time;
	printf("The peak velocity that the object reached is %.2lf meters/second.\n", vel_Peak);
	
	return 0;
	
}