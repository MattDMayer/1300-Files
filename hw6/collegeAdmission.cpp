// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 6 - Problem 3

#include <iostream> 
#include <iomanip>  
#include <fstream>
using namespace std; 
//For this problem I just worked within the main function.
int main()
{
    //Here I call all of my arrays except math, and my control variables for going through the text file.
    ifstream file;
    string line;
    cout<<"Enter the file name: "<<endl;
    string fileName;
    string names[1000];
    double gpa[1000];
    double data[1000][7];
    cin>>fileName;
    int info=-1;
    bool first=true;
    int index=0;
    int last=0;
    string other;
    //Here I open up the file and have it display a message if the file that the user entered can't be opened.
    file.open(fileName);
    if(file.fail())
    {
        cout<<"Could not open file."<<endl;
    }
    else
    {
        //If it opens, it goes through this while loop, taking the first line, which is just saying what the data is
        //and using that to set the rest of the code in motion.
        while(getline(file, line))
        {
            if(line=="Student,SAT,GPA,Interest,High School Quality,Sem1,Sem2,Sem3,Sem4")
            {
                info =0;
            }  
            else if(line!="Student,SAT,GPA,Interest,High School Quality,Sem1,Sem2,Sem3,Sem4")
            {
                //This for loop goes for the length of the line of text, using each comma to assign the file to different data values
                //in the order of name, SAT, GPA, interest, school quality and the semesters.
                for(int i=0;i<line.length();i++)
                {
                    if(info==0&&line.substr(i,1)==",")
                    {
                        names[index]=line.substr(0,i);
                        info=1;
                        last=i+1;
                    }          
                    else if(info==1&&line.substr(i,1)==",")
                    {
                        data[index][0]=stod(line.substr(last,i-last));
                        info=2;
                        last=i+1;
                    } 
                    else if(info==2&&line.substr(i,1)==",")
                    {
                        gpa[index]=stod(line.substr(last,i-last));
                        info=3;
                        last=i+1;

                    }
                    else if(info==3&&line.substr(i,1)==",")
                    {
                        data[index][1]=stod(line.substr(last,i-last));
                        info =4;
                        last=i+1;
                    }
                    else if (info==4&&(line.substr(i,1)==","))
                    {
                        data[index][2]=stod(line.substr(last,i-last));
                        info=5;
                        last=i+1;
                    }
                    else if (info==5&&line.substr(i,1)==",")
                    {
                        data[index][3]=stod(line.substr(last,i-last));
                        info=6;
                        last=i+1;
                    }
                    else if(info==6&&line.substr(i,1)==",")
                    {
                        data[index][4]=stod(line.substr(last,i-last));
                        info=7;
                        last=i+1;
                    }
                    else if(info==7&&line.substr(i,1)==",")
                    {
                        data[index][5]=stod(line.substr(last,i-last));
                        info=8;
                        last=i+1;
                    }
                    else if(info==8)
                    {
                        data[index][6]=stod(line.substr(last,line.length()-last));
                        info=-1;
                    }
                }
                index++;
                info=0;
                last=0;
                //At the end of each for loop, the index is increased by one, and the control variables are set.
            }
        }
    }
    //Here I call my array math, which is used to calculate the score for each person in the file. It is looped for however many
    //times as there were lines that weren't the opening line in the file.
    double math[index];
    for(int i=0;i<index;i++)
    {
        math[i]=double(data[i][0]/160)*.3;
        math[i]+=(gpa[i]*2)*.4;
        math[i]+=data[i][1]*.1;
        math[i]+=data[i][2]*.2;
        //This series of if statments tests the score for each name against a set of conditions to give that name a tag.
        //If no tag applies, no tag is given, the first tag a name qualifies for is given only.
        if(math[i]>=6)
        {
            other=",score";
        }
        else if((data[i][1]==0||(2*gpa[i]>(2+double(data[i][0]/160))))&&math[i]>5)
        {
            other=",outlier";
        }
        else if(math[i]>=5&&((data[i][6]>data[i][5])&&(data[i][5]>data[i][4])&&(data[i][4]>data[i][3])))
        {
            other=",grade improvement";
        }
        else
        {
            other="";
        } 
        if(i==0)
        {
            //This if statment is used just to print "Results: one time since i chose to use the same loop for math as output.
            cout<<endl<<"Results:"<<endl;
        }
        //This is the final output for each name, pulling from the names array, the math array, and adding whatever tag applies.
        cout<<names[i]<<","<<setprecision(6)<<math[i]<<other<<endl;
    }
    //Here the file is closed and the main function ends.
    file.close();
    return 0;
}