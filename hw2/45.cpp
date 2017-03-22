#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_ROUNDS = 20;  // max rounds per game

enum Player { HUMAN, COMPUTER, TIE };   // players and winners
enum Thing  { ROCK, PAPER, SCISSORS };  // what each player chooses


//Function declaration

Thing humanchoice(char h); 
Thing computerchoice(char);
Player winner(enum Thing human, enum Thing computer);


void record_win(enum Player winner,int& human_wins,int& computer_wins,int& ties);


/**
 * The main. Play a game consisting of MAX_ROUNDS.
 * Print the number of human player wins, computer wins, and ties.
 */
string printChoose(const Thing choose) //transfer the humanchoice result from int into word
{
	switch (choose)
	{
		case ROCK:
			return "ROCK";
		case PAPER:
			return "PAPER";
		default:
			return "SCISSORS";
	}
}

int main()
{
	int human_wins = 0;
	int computer_wins = 0;
	int ties = 0;
	int i;
	
	char choice ;
	
	for (i=0; i<MAX_ROUNDS; i++)
	{
	
	//input the human choice and output the result
	
	cout << "Round " << i+1 <<endl;
	cout << "Your chioce?"<< endl;
	cin >> choice;
	
	Thing Humanchoice = humanchoice(choice);
	cout << "You chose "<< printChoose(Humanchoice) <<endl;
	
	//random the computer choice
	
	Thing Computerchoice = computerchoice (0);
	cout << "The computer chose " << printChoose(Computerchoice) << endl;
	
	
	//compute and show the winner
	
	Player Winner = winner(Humanchoice, Computerchoice);
	if (Winner == HUMAN)
	{
		cout << "The winner is you" << endl;
		
	}
	
	if (Winner == COMPUTER)
	{
		cout << "The winner is the computer" << endl;
	}
	
	if (Winner == TIE)
	{
		cout << "TIE" << endl;
	}
	
	//record the times of winner and print summary
	
	record_win(Winner,human_wins,computer_wins,ties );
	}
	
	cout << "Summary" << endl;
	cout << "-------" << endl;
	cout << "   Human wins: "<< human_wins <<endl;
	cout << "Computer wins: "<< computer_wins <<endl;
    cout << "         Ties: "<< ties << endl;
	
	
	return 0;
}

//function 1 ,get the human player's choice

Thing humanchoice (char h)
{
	if ((h!='S')&&(h!='s')&&(h!='P')&&(h!='p')&&(h!='R')&&(h!='r'))
	{
		cout<< "*** ERROR: Valid choices are R, P, or S"<<endl;
		cout<< "Your choice?"<<endl;
		
		char k;
		cin >> k;
		
		return humanchoice(k);
	}
	
	else 
	{
	if ((h=='S')||(h=='s'))
		{
	
		return(SCISSORS);
		}
		
	if ((h=='P')||(h=='p'))
		{
		return (PAPER);
		}
	
	 if ((h=='R')||(h=='r'))
		{
		return (ROCK);
		}
	}
		
}

//function 2,get the computer's choice

Thing computerchoice(char c)
{
	
	srand(time(NULL));
	
	c =(rand()%3);
	if(c==0)
	{
		return(SCISSORS);
	}
	if (c==1)
	{
		return (PAPER);
	}
	if (c==2)
	{
		return (ROCK);
	}
}

//function 3, determine the winner

Player winner(enum Thing human, enum Thing computer)
{
	if (human==computer)
	{
		return (TIE);
	}
	if (human==SCISSORS)
	{
		if (computer==PAPER)
		{
			return(HUMAN);
		}
		if (computer == ROCK)
		{
			return (COMPUTER);
		}
	}
	if (human == PAPER)
	{
		if (computer==ROCK)
		{
			return(HUMAN);
		}
		if (computer == SCISSORS)
		{
			return (COMPUTER);
		}
	}
	if (human == ROCK)
	{
		if (computer==SCISSORS)
		{
			return(HUMAN);
		}
		if (computer == PAPER)
		{
			return (COMPUTER);
		}
	}
}

//function 4 record the winner of the round

void record_win(enum Player winner,int& human_wins,int& computer_wins,int& ties)
{
	if (winner== COMPUTER)
	{
		computer_wins++;
	}
	if (winner==HUMAN)
	{
		human_wins++;
	}
	if (winner ==TIE)
	{
		ties++;
	}
}


