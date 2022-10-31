//Estimating pi/4 using different iterations...
// Name:        Giovanni Medrano
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
int circleHit1 = 0;
int circleHit2 = 0;
int circleHit3 = 0;
int circleHit4 = 0;
double length1, length2, length3, length4;

int N1 = 10;
double X1[10];
double Y1[10];
int N2 = 100;
double X2[100];
double Y2[100];
int N3 = 1000;
double X3[1000];
double Y3[1000];
int N4 = 10000;
double X4[10000];
double Y4[10000];
double circle = M_PI / 4;

double circleHits(int N)
{
    if (N == 10)
    {
        srand(static_cast<unsigned int>(time(NULL)));
        for (int i = 0; i < N; i++)
        {
            //cout << float(rand()) / RAND_MAX << endl;
            X1[i] = float(rand()) / RAND_MAX;
        }
        for (const float number : X1)
        {
            cout << number << ',';
        }

        srand(5);
        for (int i = 0; i < N; i++)
        {

            //cout << (float(rand()) / RAND_MAX) * -1 << endl;
            Y1[i] = (float(rand()) * -1) / RAND_MAX;
        }
        cout << endl;
        for (const float number : Y1)
        {
            //cout << number << ',';
        }
        cout << endl;
        for (int i = 0; i < N; i++)
        {
            length1 = sqrt((X1[i] * X1[i]) + (Y1[i] * Y1[i]));
            if (length1 < circle)
            {
                circleHit1++;
            }
        }
    }
    else if (N == 100)
    {
        srand(static_cast<unsigned int>(time(NULL)));
        for (int i = 0; i < N; i++)
        {
            //cout << float(rand()) / RAND_MAX << endl;
            X2[i] = float(rand()) / RAND_MAX;
        }
        for (const float number : X2)
        {
            //cout << number << ',';
        }

        srand(100);
        for (int i = 0; i < N; i++)
        {

            //cout << (float(rand()) / RAND_MAX) * -1 << endl;
            Y2[i] = (float(rand()) * -1) / RAND_MAX;
        }
        cout << endl;
        for (const float number : Y2)
        {
            //cout << number << ',';
        }
        cout << endl;
        for (int i = 0; i < N; i++)
        {
            length2 = sqrt((X2[i] * X2[i]) + (Y2[i] * Y2[i]));
            if (length2 < circle)
            {
                circleHit2++;
            }
        }
    }
    else if(N==1000)
    {
        srand(static_cast<unsigned int>(time(NULL)));
        for (int i = 0; i < N; i++)
        {
            //cout << float(rand()) / RAND_MAX << endl;
            X3[i] = float(rand()) / RAND_MAX;
        }
        for (const float number : X3)
        {
            //cout << number << ',';
        }

        srand(1000);
        for (int i = 0; i < N; i++)
        {

            //cout << (float(rand()) / RAND_MAX) * -1 << endl;
            Y3[i] = (float(rand()) * -1) / RAND_MAX;
        }
        //cout << endl;
        for (const float number : Y3)
        {
            //cout << number << ',';
        }
        cout << endl;
        for (int i = 0; i < N; i++)
        {
            length3 = sqrt((X3[i] * X3[i]) + (Y3[i] * Y3[i]));
            if (length3 < circle)
            {
                circleHit3++;
            }
        }
    }else{
        srand(static_cast<unsigned int>(time(NULL)));
        for (int i = 0; i < N; i++)
        {
            //cout << float(rand()) / RAND_MAX << endl;
            X4[i] = float(rand()) / RAND_MAX;
        }
        for (const float number : X4)
        {
            //cout << number << ',';
        }

        srand(10000);
        for (int i = 0; i < N; i++)
        {

            //cout << (float(rand()) / RAND_MAX) * -1 << endl;
            Y4[i] = (float(rand()) * -1) / RAND_MAX;
        }
        cout << endl;
        for (const float number : Y4)
        {
            //cout << number << ',';
        }
        cout << endl;
        for (int i = 0; i < N; i++)
        {
            length4 = sqrt((X4[i] * X4[i]) + (Y4[i] * Y4[i]));
            if (length4 < circle)
            {
                circleHit4++;
            }
        }
    }
}
int main(void)
{

    circleHits(N1);
    circleHits(N2);
    circleHits(N3);
    circleHits(N4);

    cout << "Number of circles hit1 = " << circleHit1 << endl;

    // table
    cout << " n hits ratio est(pi) error" << endl;
    cout << N1 << "     " << circleHit1 << "      " << float(circleHit1) / N1 << "       " << length1 * 4 << "     " << M_PI - (length1 * 4) << endl;
    cout << N2 << "     " << circleHit2 << "      " << float(circleHit2) / N2 << "       " << length2 * 4 << "     " << M_PI - (length2 * 4) << endl;

    cout << N3 << "     " << circleHit3 << "      " << float(circleHit3) / N3 << "       " << length3 * 4 << "     " << M_PI - (length3 * 4) << endl;
    cout << N4 << "     " << circleHit4 << "      " << float(circleHit4) / N4 << "       " << length4 * 4 << "     " << M_PI - (length4 * 4) << endl;
    cout <<"It takes around 100000 iterations to reach 5 levels of significance";
    return 0;
}
