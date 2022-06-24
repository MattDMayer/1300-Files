#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout<<"Enter a positive number: "<<endl;
    int num;
    cin>>num;
    int sum=0;
    int total=0;
    while(sum<num)
    {
        if(sum%2==0)
        {
            total=total+sum;
        }
        sum++;
    }
    if(num%2==0)
    {
    total=total+num;
    }

    cout<<"Sum: "<< total;
    return 0;
}