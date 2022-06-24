#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cout<<"Enter a positive number: "<<endl;
    cin>>n;
            cout<<n<<endl;
    while(n!=1)
    {
        if(n%2==0)
        {
            n=n/2;
        }

        else
        {
            n=3*n+1;
        }
        cout<<n<<endl;
    }
    return 0;
}