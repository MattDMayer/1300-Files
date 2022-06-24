#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int choice=0;
    double sp,a,st;
    double hire;
    while(choice!=4)
    {
    cout<<"Select a numerical option: "<<endl;
    cout<<"=== menu ==="<<endl;
    cout<<"1. Fox"<<endl;
    cout<<"2. Bunny"<<endl;
    cout<<"3. Sloth"<<endl;
    cout<<"4. Quit"<<endl;
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter agility: "<<endl;
        cin>>a;
        cout<<"Enter strength: "<<endl;
        cin>>st;
        hire=(1.8*a)+(2.16*st);
        cout<<"Hire Score: "<<hire<<endl;
    }
      else if(choice==2)
      {
        cout<<"Enter agility: "<<endl;
        cin>>a;
        cout<<"Enter speed: "<<endl;
        cin>>sp;
        hire=(1.8*a)+(3.24*sp);
        cout<<"Hire Score: "<<setprecision(6)<<hire<<endl;
      }

      else if(choice==3)
      {
        cout<<"Enter strength: "<<endl;
        cin>>st;
        cout<<"Enter speed: "<<endl;
        cin>>sp;
        hire=(2.16*st)+(3.24*sp);
        cout<<"Hire Score: "<<hire<<endl;
      }
      else if (choice==4)
      {
        
      }
      
      else
      {
          cout<<"Invalid option"<<endl;
      }
    }
    cout<<"Good bye!";
    return 0;
}