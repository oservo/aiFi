#include <stdio.h>
#include <stdlib.h>

#include "popc.h"
#include "ann.h"

double annRandomizer () {
	double r;
	//r = rand () % 1000000 / 999998.0 + 0.000001;
	r = ((double) rand() / (RAND_MAX));
	//it works fine/ dbcEnsure (r >= 0 && r <= 1.0, "Invalid Random Number: %lf", r);
	//return r / 2.0;
	return r;
}

