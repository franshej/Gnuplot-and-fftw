/* Start reading here */

#include <iostream>
#include <stdlib.h>
#include <fftw3.h>
#include "myClass.cpp"
#include <fstream>
#include <wiringPi.h>

#define NUM_POINTS 1000
#define FS 500

/* Never mind this bit */

#include <stdio.h>
#include <math.h>

#define REAL 0
#define IMAG 1

void acquire_from_somewhere(fftw_complex* signal) {
    /* Generate two sine waves of different frequencies and
     * amplitudes.
     */
    double T = 1/(double)FS;

    for (int i = 0; i < NUM_POINTS; ++i) {
        double t = (double)i * T;
        signal[i][REAL] = 100.0 * sin(t*2*M_PI*(50 + (rand()%5))) + 100.0*sin(300*t*2*M_PI) + (rand() % 300);
        signal[i][IMAG] = 0;
    cout << rand()%5 << endl;
    }
}

void do_something_with(fftw_complex* result) {
    int i;
    ofstream myfile;
    myfile.open ("data1.dat");
    for (i = 0; i < NUM_POINTS; ++i) {
        double mag = sqrt(result[i][REAL] * result[i][REAL] +
                          result[i][IMAG] * result[i][IMAG]);

	myfile << FS*i/NUM_POINTS << " " << mag/(double)NUM_POINTS << endl;

    }
    myfile.close();
}


/* Resume reading here */

int main() {
    fftw_complex signal[NUM_POINTS];
    fftw_complex result[NUM_POINTS];

    fftw_plan plan = fftw_plan_dft_1d(NUM_POINTS,
                                      signal,
                                      result,
                                      FFTW_FORWARD,
                                      FFTW_ESTIMATE);

    acquire_from_somewhere(signal);
int time = 0;
    time = micros();
    fftw_execute(plan);
    time = micros() - time;
    cout << "Micros for fft: " << time << " Numbers of samples: " << NUM_POINTS << endl;
    do_something_with(result);
    fftw_destroy_plan(plan);
    plotData a;
    a.plot();

    return 0;
}
