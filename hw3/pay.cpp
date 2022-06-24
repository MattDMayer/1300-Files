#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout<<"Enter the number of hours worked"<<endl;
    double hours_worked;
    double total_pay;
    double pay_rate;
    cin>>hours_worked;
    cout << "Enter an hourly pay rate"<<endl;
    cin>>pay_rate;
    if(hours_worked>40)
    {
        hours_worked=hours_worked-40;
        total_pay=(hours_worked*pay_rate*1.5)+(40*pay_rate);
    }
    else
    {
        total_pay=(hours_worked*pay_rate);
    }
    if(hours_worked>=0 && pay_rate>=0)
    {
        cout<<"Paycheck: "<<fixed<<setprecision(2)<<total_pay;
    }
    else
    {
        cout<< "Invalid input";
    }
    return 0;
}