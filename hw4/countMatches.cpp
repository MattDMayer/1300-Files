#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    string(searched);
    string(searching);
    cout<<"Enter the search string: "<<endl;
    cin>>searched;
    cout<<"Enter the substring to be searched: "<<endl;
    cin>>searching;
    int t=0;
    for(int i=0;i<searched.length();i++)
    {
        if(searching==searched.substr(i,searching.length()))
        {
            t++;
        }
    }
    cout<<"Number of occurrences: "<<t;
    return 0;
}