#include <stdio.h>
#include <stdarg.h>
#include "libresistance.h"
#include "libpower.h"
#include "libcomponent.h"

int main() {
	int count;
	int c;
	float array[100];
	float res[] = { 0.0, 0.0, 0.0 };
	char conn;
	int volt;

	printf("Ange spänningskälla i V: ");
	scanf("%d", &volt);

	printf("Ange koppling: ");
	scanf(" %c", &conn);

	printf("Antal komponenter: ");
	scanf("%d", &count);

	for(c = 0; c < count; c++) {
		printf("Komponent %d i ohm: ", c + 1);
		scanf("%f", &array[c]);
	}
 
	// Beräkna resistansen
	float resistance = calc_resistance(count, conn, array);	
	printf("Ersättningsresistans:\n%0.1f ohm\n", resistance);

	// Beräkna effekten
	float P = calc_power_r(volt, resistance);
	printf("Effekt:\n%0.2f W\n", P);

	// Beräkna ersättningsresistanser
	count = e_resistance(resistance, res);
	printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");

	if (count == 0) {
		printf("Det finns inga resistanser som matchar!\n");
        }

	for (c=0; c < count; c++) {
		printf("%f\n", res[c]);
	}

	return 0;
}
