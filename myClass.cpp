

#include "myClass.h"
#include <string>

void plotData::plot(){
FILE *f = fopen ("myfile","wt");
fprintf(f, "set zeroaxis \n");
fprintf(f, "plot 'data1.dat' w lines ls 1\n");
fclose(f);
system("gnuplot -p <myfile");
}

