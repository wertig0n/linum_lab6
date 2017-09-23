#include <stdio.h>
#include <stdlib.h>
#include "libresistance.h"
#include "libpower.h"
#include "libcomponent.h"

int main() {
	char input[10] = {0};  /* input buffer */
	char *res =0;          /* Make sure fgets work properly... */
	float *values = 0;     /* Contains all values we put in */
	char conn;
	float resistance=0.0, power=0.0;
	int volt;
	int res_count=0, e_count=0;
	int c;

	printf("Ange spänningskälla i V: ");
	res = fgets(input, 10, stdin);
	volt = atoi(input);

	printf("Ange koppling: ");
	res = fgets(input, 10, stdin);
	conn = input[0];

	printf("Antal komponenter: ");
	res = fgets(input, 10, stdin);	
	res_count = atoi(input);

	values = calloc(res_count+3,sizeof(float)); /* Dynamicly allocate array */

	for(c = 0; c < res_count; c++) {
		printf("Komponent %d i ohm: ", c + 1);
		res = fgets(input, 10, stdin);
		values[c] = atof(input);
	}
 
	// Beräkna resistansen
	resistance = calc_resistance(res_count, conn, values);	
	printf("Ersättningsresistans:\n%0.1f ohm\n", resistance);

	// Beräkna effekten
	power = calc_power_r(volt, resistance);
	printf("Effekt:\n%0.2f W\n", power);

	// Beräkna ersättningsresistanser
	e_count = e_resistance(resistance, &values[res_count]);
	printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");

	if (e_count == 0) {
		printf("Det finns inga resistanser som matchar!\n");
        }

	for (c=0; c < e_count; c++) {
		printf("%f\n", values[res_count+c]);
	}

	free(values);

	return 0;
}
