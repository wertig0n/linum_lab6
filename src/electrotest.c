#include <stdio.h>
#include <stdarg.h>
#include "libresistance.h"

int main() {
	int count;
	int c;
	float array[100];
	char conn;

	printf("Ange koppling: ");
	scanf(" %c", &conn);

	printf("Antal komponenter: ");
	scanf("%d", &count);

	for(c = 0; c < count; c++) {
		printf("Komponent %d i ohm: ", c + 1);
		scanf("%f", &array[c]);
	}
 
	float total = calc_resistance(count, conn, array);	
 
	printf("Ersättningsresistans: %0.1f\n", total);

	return 0;
}
