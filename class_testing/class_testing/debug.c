#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double Dip_2PtForm(double x_1, double y_1, double x_2, double y_2) {

	double m = 0;

	m = (y_2 - y_1) / (x_2 - x_1);

	printf("Two-point form\n");
	printf("     (%lf - %lf)\n", y_2, y_1);
	printf("m =  -------------\n");
	printf("     (%lf - %lf)", x_2, x_1);

	return m;
}

void Disp_SlopeInterceptForm(double slope, double x1, double y1) {

	double b = 0;
	
	b = y1 - slope * x1;

	printf("Slope-intercept form\n");
	printf("y = %.2lfx + %.2lf", slope, b);

	return;
}

int main(void) {

	double x1, x2, y1, y2;
	double slope = 0;

	slope = Dip_2PtForm(x1, y1, x2, y2);
	Disp_SlopeInterceptForm(slope, x1, x2);

	return 0;
}