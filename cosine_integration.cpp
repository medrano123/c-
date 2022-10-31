//sum the area under the curve of a cos curve at multiple steps and compare it to the sine value of each one.
// Name:        Giovanni Medrano
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <math.h>
#include <climits>

using namespace std;

double meanError1= 0;
double maxError1 = 0;
double meanError2= 0;
double maxError2 = 0;
double meanError3= 0;
double maxError3 = 0;
double meanError4= 0;
double maxError4 = 0;

//funciton that calculates the integral of sign using the limit formula summation 1 to n of the cos calculation timesthe step function
//writes it out to the file
double cosIntegrator(int N,std::ostream& infile){
    double maxError=0;
    float meanError=0;
    double step = (2 * M_PI)/N;
    double estSin = 0;

    infile << "For npts = "<<N<< " (steps of 2PI/"<<N<<")" <<endl;
    infile <<"i x[i] sin(x) est(sin(x)) error"<<endl;

    for (int i = 1; i < N + 1; i++)
    {
        double analyticalSine = sin(i *step);
        estSin += cos(i * step) * step;
        double error = abs(analyticalSine - estSin);        
        maxError = max(maxError, error);
        meanError += error;
        infile << i * step << '\t' << analyticalSine << '\t' << estSin << "\t" << error << endl;
    }
    meanError = meanError / N;
    infile << endl;
    //cout <<"meanError is    " <<meanError<<endl;
    //cout <<"maxError is    " <<maxError<<endl;
    if(N==10){
        meanError1= meanError;
        maxError1= maxError;
    }else if(N==20){
        meanError2= meanError;
        maxError2= maxError; 
    }else if(N==100){
        meanError3= meanError;
        maxError3= maxError; 
    }else{
        meanError4= meanError;
        maxError4= maxError;         
    }
    return 0;
};

int main(void)
{
    int N1 = 10;
    int N2 = 20;
    int N3 = 100;
    int N4 = 1000;
    // opens file
    ofstream ofs;
    string infile = "cosine_integration_out.txt";
    ofs.open(infile);
    // ofs << "npts\tmean\terr\tmax\terr"<<endl;
    //calls the function.
    cosIntegrator(N1,ofs);
    cosIntegrator(N2,ofs);
    cosIntegrator(N3,ofs);
    cosIntegrator(N4,ofs);
    ofs << "npts mean err max err "<< endl;
    ofs << N1 << "\t" << meanError1 << "\t" << maxError1<<endl;
    ofs << N2 << "\t" << meanError2 << "\t" << maxError2<<endl;
    ofs << N3 << "\t" << meanError3 << "\t" << maxError3<<endl;
    ofs << N4 << "\t" << meanError4 << "\t" << maxError4<<endl;




   // ofs << "i x[i] sin(x) est(sin(x)) error" << endl;

    ofs.close();

    return 0;
}
