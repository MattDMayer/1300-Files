#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    string alphabet="abcdefghijklmnopqrstuvwxyz";
    cout<<"Enter the height: "<<endl;
    int height;
    cin>>height;
    string line;
    int index=0;
    int other=0;
    int width=height;
    for(int i=0;i<height;i++)
    {
      line=alphabet.substr(index,width);
      index+=line.length();
      if(index-26<0)
      {
        cout<<line<<endl;
      }
      if(index-26>=0)
      {
        cout<<line;
        index=0;
        line=alphabet.substr(index,(width-line.length()));
        index+=line.length();
        cout<<line<<endl;
      }
      other+=line.length();
      width--;
    }
    return 0;
}