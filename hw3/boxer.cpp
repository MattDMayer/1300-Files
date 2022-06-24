#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    cout<< "Enter boxers' weights"<<endl;
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    if(a>b&&b>c)
    {
        cout<<"Descending order";
    }
    else if(a<b&&b<c)
    {
        cout<<"Ascending order";
    }
    else
    {
        cout<<"Neither";
    }
    
    return 0;
}