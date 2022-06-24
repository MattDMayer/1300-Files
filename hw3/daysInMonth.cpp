#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter a year:"<<endl;
    int year;
    cin>> year;
    cout<< "Enter a month: "<<endl;
    int month;
    cin>>month;
    if(year<0||month<=0||month>12)
    {
        cout<<"Invalid month";
    }
    if(month ==1||month ==3||month==5||month==8||month==10||month==12)
    {
        cout<<"31 days";
    }
    else if(month==4||month==7||month==9||month==11||month==6)
    {
        cout<<"30 days";
    }
    else if (month==2)
    {
        int y=0;
        if((year%4==0&&year%100!=0)||(year%400==0)||(year<1582&&year%4==0))
        {
           y=1;
        }
          else if(year%100==0)
        {
           y=0;
        }
        else
        {
           y=0;
        }
        switch (y)
        {
            case 0:
            cout<<"28 days";
            break;
            case 1:
            cout<<"29 days";
            break;
        }
    }
    return 0;
}