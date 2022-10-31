// Estimating pi using Eulers series of PI^2/6 = 1 + 1/n^2 .... .
// Name:        Giovanni Medrano

/*  By utilizing Eurlers series of pi i will estimate how many iterations it takes to reach 7 decimal points
    I will be using the formula listed in this website: http://numbers.computation.free.fr/Constants/Pi/piSeries.html
    I chose to use eurlers series of pi estimation formula

*/
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;


double calculatePi(int N){
    long double  PI1 = 0;
    long double  PI2 = 0;
    long double  PI3 = 0;
    long double  PI4 = 0;
    long double  PI5 = 0;


    if(N==10){
        for (int i = 1; i <= N; i++){
            PI1 = (PI1 + (1/(pow(i,2))));

    }
    return PI1;
    }else if (N==100){
        for (int i = 1; i <= N; i++){
            PI2 = (PI2 + (1/(pow(i,2))));

    }return PI2;

    }else if (N==1000){
        for (int i = 1; i <= N; i++){
            PI3 = (PI3 + (1/(pow(i,2))));

    }return PI3;
    }else if (N==10000){
        for (int i = 1; i <= N; i++){
            PI4 = (PI4 + (1/(pow(i,2))));
    }
    }else{
        for (int i = 1; i <= N; i++){
            PI5 = (PI5 + (1/(pow(i,2))));

    }
    return PI5;
    }




}

int main(void)
{

    cout << "M_PI:            " << setprecision(2000)  << M_PI << endl;
    long double PI1 = calculatePi(10);
    long double PI2 = calculatePi(100);
    long double PI3 = calculatePi(1000);
    long double PI4 = calculatePi(10000);
    long double PI5 = calculatePi(900000);

    //cout << "N = 900000 gives a PI value of  "<< sqrt(PI5 * 6) << " The error is: " << M_PI - sqrt(PI5 * 6) << endl;

    cout << "N = 10 gives a PI value of  "<< setprecision(7) << sqrt(PI1*6) << " The error is: " << M_PI - sqrt(PI1*6) << endl;
    cout << "N = 100 gives a PI value of  "<< sqrt(PI2 * 6) << " The error is: " << M_PI - sqrt(PI2 * 6) << endl;
    cout << "N = 1000 gives a PI value of  "<< sqrt(PI3 * 6) << " The error is: " << M_PI - sqrt(PI3 * 6) << endl;
    cout << "N = 10000 gives a PI value of  "<< sqrt(PI4 * 6) << " The error is: " << M_PI - sqrt(PI4 * 6) << endl;
    cout << "N = 900000 gives a PI value of  "<< sqrt(PI5 * 6) << " The error is: " << M_PI - sqrt(PI5 * 6) << endl;

    cout << "It takes roughly 900,000 iterations to reach 7 digits of accurary using Eurlers formula" <<endl;

	return 0;
}



