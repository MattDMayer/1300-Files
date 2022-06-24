// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 1 - Problem 5


#include <iostream> 
#include <iomanip>  
using namespace std; 

/*
    This double function takes in two inputs and then immediatly runs them against a series of if statments. The first one checks to see
    if the sequences are of different lengths, if they are the function returns 0 as no further calculations can be done, the second 
    statement checks to see if the sequences both have a length of 0, as this would again cause a calculation error, if this fires, 
    the function will again return a 0. Finally if both inputs are the same length and aren't at length 0, a for loop is fired that in
    essence, goes through both string inputs, and compares them at each character using subsrtrings, if they don't have a match, it adds
    to hamming distance by one for each mismatch. Then finally it runs the calculation for calculating sim score, and the function outputs
    the solution for said calculation.
*/
double calcSimScore(string sequence_1,string sequence_2)
{
    double similarity_score=0;
    int hamming_distance=0;
    if(sequence_1.length()!=sequence_2.length())
    {
        return 0;
    }
    else if((sequence_1.length()==sequence_2.length())&& (sequence_1.length()==0))
    {
        return 0;
    }
    else if((sequence_1.length()==sequence_2.length())&& (sequence_1.length()!=0))
    {
        for(int i = 0; i<sequence_1.length();i++)
        {
            if(sequence_1.substr(i,1)!=sequence_2.substr(i,1))
            {
                hamming_distance ++;
            }
        }
        similarity_score=double(sequence_1.length()-hamming_distance);
        similarity_score=double(similarity_score/sequence_1.length());
    }
    return similarity_score;
}
/*
    The double function bellow takes in a genome and a sequence and will run the sequence through each individual set of its length in the genome
    for each iteration of checking the genome vs. the sequence, it will use the previous method to calculate the sim score. At the end this 
    function will output the highest sim score it got. This function also has a safety check where if the genome is shorter than the sequence
    the function will return a 0. If this safety check doesn't happen another is tested where if the sequence and genome are the same length
    it will just return a single iteration of calculating a sim score. If both of these checks are passed the function will then do the above
    described looping and checking each sim score for the genome inside the sequence.
*/
double findBestSimScore(string genome, string sequence)
{
    int index=0;
    double highScore = 0.0;
    if(sequence.length()>genome.length())
    {
        return 0;
    }
    else if(sequence.length()==genome.length())
    {
        highScore= calcSimScore(genome,sequence);
        return highScore;
    }
    else
    {
        for(int i=0;i<((genome.length()-sequence.length()))+1;i++)
        {
            if(calcSimScore(sequence, genome.substr(index,sequence.length()))>highScore)
            {
                highScore=calcSimScore(sequence, genome.substr(index,sequence.length()));
            }
            index++;
        }
    }
    return highScore;
}

/*
    The findMatchedGenome function takes in 4 strings, one for each genome and one for the sequence. First it checks to see if any
    genomes are empty, if one is empty the function outputs a print statement saying so. If none are empty it will check to make sure all genomes
    are the same length, if they aren't it will print out a message saying so. If both of these conditions aren't met, therfore meaning
    that the input has passed these checks a series of if statments are then run against each genome and sequence best sim score
    depending on which has the highest score or if there is a tie, the function will output which is the highest sim score. In the case of 
    a tie, it will output each individual genome with the best match, in numerical order. There are if statements for each possible winning
    case and tie. At the end of the function there is just a return statement since it is a void function.
*/
void findMatchedGenome(string one,string two,string three,string sequence)
{
    double one_score, two_score, three_score;
    if(sequence==""||one==""||two==""||three=="")
    {
        cout<<"Genomes or sequence is empty.";
    }
    else if(one.length()!=two.length()||two.length()!=three.length()||one.length()!=three.length())
    {
        cout<<"Lengths of genomes are different.";
    }
    else
    {
        one_score=findBestSimScore(one,sequence);
        two_score=findBestSimScore(two,sequence);
        three_score=findBestSimScore(three,sequence);
        if((one_score>two_score)&&(one_score>three_score))
        {
            cout<<"Genome 1 is the best match."<<endl;
        }
        else if((two_score>one_score)&&(two_score>three_score))
        {
            cout<<"Genome 2 is the best match."<<endl;
        }
        else if((three_score>one_score)&&(three_score>two_score))
        {
            cout<<"Genome 3 is the best match."<<endl;
        }
        else if((one_score==two_score)&&(two_score>three_score))
        {
            cout<<"Genome 1 is the best match."<<endl;
            cout<<"Genome 2 is the best match."<<endl;
        }
        else if((one_score==three_score)&&(three_score>two_score))
        {
            cout<<"Genome 1 is the best match."<<endl;
            cout<<"Genome 3 is the best match."<<endl;
        }
        else if((two_score==three_score)&&(two_score>one_score))
        {
            cout<<"Genome 2 is the best match."<<endl;
            cout<<"Genome 3 is the best match."<<endl;
        }
        else if((two_score==three_score)&&(two_score==one_score))
        {
            cout<<"Genome 1 is the best match."<<endl;
            cout<<"Genome 2 is the best match."<<endl;
            cout<<"Genome 3 is the best match."<<endl;
        }
    }
    return;
}

/*
    The main function in this algorithm is used to perpetually loop a menu that will give the user options to use the previouslly
    developed methods on an infinite loop until they deside to quit. The menu will properly give messages if inputs are wrong, and 
    when the user quits a good bye message is displayed. The menu runs on a switch statment each branch running one of the above methods
    and the deafult path being used to catch errors in inputs for the menu. For the most part the main function just displays the menu
    and calls the other functions with given inputs by the user.
*/
int main()
{
    int choice=0;
    string sequence_one,sequence_two, genome_one,genome_two,genome_three; 
    cout<<"Select a numerical option:"<<endl;
    cout<<"=== menu ==="<<endl;
    cout<<"1. Find similarity score"<<endl;
    cout<<"2. Find the best similarity score"<<endl;
    cout<<"3. Analyze the genome sequences"<<endl;
    cout<<"4. Quit"<<endl; 
    cin>>choice;
    while(choice!=4)
    {

        switch(choice)
        {
            default:
            cout<<"Invalid option."<<endl;
            break;

            case 1:
            cout<<"Enter sequence 1:"<<endl;
            cin>>sequence_one;
            cout<<"Enter sequence 2:"<<endl;
            cin>>sequence_two;
            cout<<"Similarity score: "<<calcSimScore(sequence_one,sequence_two)<<endl;
            break;

            case 2:
            cout<<"Enter genome:"<<endl;
            cin>>genome_one;
            cout<<"Enter sequence:"<<endl;
            cin>>sequence_one;
            cout<<"Best similarity score: "<<findBestSimScore(genome_one, sequence_one)<<endl;
            break;

            case 3:
            cout<<"Enter genome 1:"<<endl;
            cin>>genome_one;
            cout<<"Enter genome 2:"<<endl;
            cin>>genome_two;
            cout<<"Enter genome 3:"<<endl;
            cin>>genome_three;
            cout<<"Enter sequence:"<<endl;
            cin>>sequence_one;
            findMatchedGenome(genome_one,genome_two,genome_three,sequence_one);
            break;
        }
        cout<<"Select a numerical option:"<<endl;
        cout<<"=== menu ==="<<endl;
        cout<<"1. Find similarity score"<<endl;
        cout<<"2. Find the best similarity score"<<endl;
        cout<<"3. Analyze the genome sequences"<<endl;
        cout<<"4. Quit"<<endl; 
        cin>>choice;
    }
    cout<<"Good bye!";
	return 0;
}