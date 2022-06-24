#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int prac1, prac2, prac3;
    cout<< "Enter practicum 1 score:"<<endl;
    cin>>prac1;
    cout<< "Enter practicum 2 score:"<<endl;
    cin>>prac2;
    cout<< "Enter practicum 3 score:"<<endl;
    cin>>prac3;
    double avg;
    avg=prac1+prac2+prac3;
    avg = (double)avg/3;
    cout<< "Practicum average: " << fixed<<setprecision(2)<<avg<<endl;
    if(avg>=67)
    {
        cout<<"You have a passing practicum average.";
    }
    else
    {
        cout<<"You can retake practicums during the final.";
    }
    return 0;
}