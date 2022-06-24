#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    cout<< "Enter the number of sushi:"<<endl;
    int sushi;
    cin>>sushi;
    double start_price = 1.99*sushi;
    double end_price;
    if(sushi<10)
    {
        end_price=start_price;
    }
    if(sushi<20&&sushi>9)
    {
        start_price=start_price-.1*start_price;
        end_price=start_price;
    }
    if(sushi<50&&sushi>19)
    {
        start_price=start_price-.15*start_price;
        end_price=start_price;
    }
    if(sushi>49&&sushi<100)
    {
        end_price=start_price*.8;
    }
    if(sushi>99)
    {
        end_price=start_price*.75;
    }
   
    if(sushi>0)
    {
        cout<<"Total price: $"<<fixed<<setprecision(2)<< end_price; 
    }
    else
    {
        cout<<"Invalid input";
    }
    return 0;
}