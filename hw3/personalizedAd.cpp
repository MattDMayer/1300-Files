#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int ad;
    cout<<"How personalized should the ad be? (1-3)"<<endl;
    cin>> ad;
    string response;
    if(ad==1)
    {
        cout<<"Do you own a dog?"<<endl;
        cin>>response;
        if(response=="yes"||response=="Yes")
        {
            cout<<"Meat's the need of dogs like yours!"<<endl;
        }
        else
        {
            cout<<"Dirty mouth? Clean it up with new Orbit Raspberry Mint."<<endl;
        }
    }
    else if(ad==2)
    {
        int friends;
        cout<<"How many Facebook friends do you have?"<<endl;
        cin>>friends;
        if(friends>=500)
        {
            cout<<"Don't like cleaning up after your dog? Call Doody Free to sign up for backyard cleanup or dog walking service.";
        }
        else
        {
            cout<<"Who doesn't need another cat? Adopt a shelter pet right meow.";
        }
    }
    else if(ad==3)
    {
        int zip;
        cout<< "What is your zip code?"<<endl;
        cin>>zip;
        cout<<"What is your age?"<<endl;
        int age;
        cin>>age;
        if(zip>=80301&&zip<=80310&&age>=25)
        {
            cout<<"You are surrounded by professional athletes. Up your exercise game in the privacy of your home with a Peloton bike.";
        }
        else if(zip>=80301&&zip<=80310&&age<25)
        {
            cout<<"Looking for dinner that won't break the bank? Tacos. Come grab a $3 at Centro Latin Kitchen.";
        }
        else
        {
            cout<<"Feeling Uninspired? The Boulder Flatirons are calling. Come hike to inspiring views, delicious food, and enjoy the hospitality of Boulder, CO.";
        }
    }
    else 
    {
        cout<<"Invalid option.";
    }
    return 0;
}