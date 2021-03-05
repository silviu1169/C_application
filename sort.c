#include "sort.h"


/**
* Sorteaza in place
* cmpf - relatia dupa care se sorteaza
*/


void sort(Store* s, FunctieComparare cmpF) {
	int i = 0, j = 0;
	for (i = 0; i < s->dimension; i++) {
		for (j = i + 1; j < s->dimension; j++) {
			void* p1 = get(s, i);
			void* p2 = get(s, j);
			if (cmpF(p1, p2) > 0) {
				//interschimbam
				set(s, i, p2);
				set(s, j, p1);
			}
		}
	}
}
