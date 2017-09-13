#include "libcomponent.h"

int e_resistance(float orig_resistance, float *res_array) {
    int i;
    int count=0;
    float resistances[] = { 8.2e9, 6.8e9, 5.6e9, 4.7e9, 3.9e9, 3.3e9,
                            2.7e9, 2.2e9, 1.8e9, 1.5e9, 1.2e9, 1.0e9,
                            8.2e8, 6.8e8, 5.6e8, 4.7e8, 3.9e8, 3.3e8,
                            2.7e8, 2.2e8, 1.8e8, 1.5e8, 1.2e8, 1.0e8,
                            8.2e7, 6.8e7, 5.6e7, 4.7e7, 3.9e7, 3.3e7,
                            2.7e7, 2.2e7, 1.8e7, 1.5e7, 1.2e7, 1.0e7,
                            8.2e6, 6.8e6, 5.6e6, 4.7e6, 3.9e6, 3.3e6,
                            2.7e6, 2.2e6, 1.8e6, 1.5e6, 1.2e6, 1.0e6,
                            8.2e5, 6.8e5, 5.6e5, 4.7e5, 3.9e5, 3.3e5,
                            2.7e5, 2.2e5, 1.8e5, 1.5e5, 1.2e5, 1.0e5,
                            8.2e4, 6.8e4, 5.6e4, 4.7e4, 3.9e4, 3.3e4,
                            2.7e4, 2.2e4, 1.8e4, 1.5e4, 1.2e4, 1.0e4,
                            8.2e3, 6.8e3, 5.6e3, 4.7e3, 3.9e3, 3.3e3,
                            2.7e3, 2.2e3, 1.8e3, 1.5e3, 1.2e3, 1.0e3,
                            8.2e2, 6.8e2, 5.6e2, 4.7e2, 3.9e2, 3.3e2,
                            2.7e2, 2.2e2, 1.8e2, 1.5e2, 1.2e2, 1.0e2,
                            8.2e1, 6.8e1, 5.6e1, 4.7e1, 3.9e1, 3.3e1,
                            2.7e1, 2.2e1, 1.8e1, 1.5e1, 1.2e1, 1.0e1,
                            8.2e0, 6.8e0, 5.6e0, 4.7e0, 3.9e0, 3.3e0,
                            2.7e0, 2.2e0, 1.8e0, 1.5e0, 1.2e0, 1.0e0 };

    res_array[0] = 0.0;
    res_array[1] = 0.0;
    res_array[2] = 0.0;

    if (orig_resistance >= 1.0 && orig_resistance <= 1.0e10) {
        while (orig_resistance >= 1.0 && count < 4) {
            for (i=0; i < 120; i++) {
                if (orig_resistance >= resistances[i]) {
                    break;
                }
            }

            res_array[count] = resistances[i];
            orig_resistance -= resistances[i];
            count++;
        }
    }

    return count;
}
