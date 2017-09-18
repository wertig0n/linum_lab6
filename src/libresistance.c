#include "libresistance.h"

float calc_resistance(int count, char conn, float *array) {
	float R = 0;
	float r = 0;
	
	// Kolla så count är en int över 0
	if(count < 1) {
		return -1;
	}
	// Kolla så conn är S eller P
	if(conn != 'S' && conn != 'P') {
		return -1;
	}
	// Kolla så *array inte är 0 
	if(*array == 0) {
		return -1;
	}

	// Vid seriekoppling
	if(conn == 'S') {
		for(int i = 0; i < count; i++) {
			R += array[i];
		}
	} 
	// Vid parallell koppling
	if(conn == 'P') {
		for(int i = 0; i < count; i++) {
			// Kolla så ingen resistor har värde 0
			if(array[i] == 0) {
				return 0;
			}
			r += 1 /array[i];
		}
		if(r == 0) {
			return 0;
		}
		R = 1/r;
	}
	return R;	
}
