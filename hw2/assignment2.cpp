#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX_ROUNDS = 20;  // max rounds per game

enum Player { HUMAN, COMPUTER, TIE };   // players and winners
enum Thing  { ROCK, PAPER, SCISSORS };  // what each player chooses

Thing humanchoice(char h);
Thing computerchoice(char);
Player winner(enum Thing human, enum Thing computer);


void record_win(enum Player winner,int& human_wins,int& computer_wins,int& ties);

/***** Add more function declarations. *****/

/**
 * The main. Play a game consisting of MAX_ROUNDS.
 * Print the number of human player wins, computer wins, and ties.
 */
int main()
{
	int human_wins = 0;
	int computer_wins = 0;
	int ties = 0;
	int i;
	
	char choice ;
	
	for (i=0; i<MAX_ROUNDS; i++)
	{
	
	cout << "Your chioce?"<< endl;
	cin >> choice;
	
	Thing Humanchoice = humanchoice(choice);
	cout << "You chose "<< Humanchoice <<endl;
	
	Thing Computerchoice = computerchoice (0);
	cout << "The computer chose " << Computerchoice << endl;
	
	
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
	
	
	record_win(Winner,human_wins,computer_wins,ties );
	}
	
	cout << "Summary" << endl;
	cout << "-------" << endl;
	cout << "   Human wins: "<< human_wins <<endl;
	cout << "Computer wins: "<< computer_wins <<endl;
	
	
	return 0;
}

Thing humanchoice (char h)
{
	if ((h='S')||(h='s'))
	{
		return(SCISSORS);
	}
	
	else if ((h='P')||(h='p'))
	{
		return (PAPER);
	}
	
	else if ((h='R')||(h='r'))
	{
		return (ROCK);
	}
	
}

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
			return(COMPUTER);
		}
		if (computer == SCISSORS)
		{
			return (HUMAN);
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

/***** Define more functions. *****/
