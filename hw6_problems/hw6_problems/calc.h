#define _CALC_H_

void calc_sum(int IMEI[], int *sum_14digits) {
	unsigned a = 0;
	for (a = 1; a <= 13; a += 2) {
		IMEI[a] *= 2;
	}

	for (a = 1; a <= 13; a += 2) {
		if (IMEI[a] >= 10) {
			IMEI[a] = 1 + (IMEI[a] - 10);
		}
	}

	for (a = 0; a < 14; ++a) {
		*sum_14digits += IMEI[a];
	}
}
