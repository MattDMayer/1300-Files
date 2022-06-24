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
// Main here is just used to print the result of the fund best sim score function and to give that function specified inputs.
int main()
{
    cout<<findBestSimScore("TACGC", "ACT");
	return 0;
}