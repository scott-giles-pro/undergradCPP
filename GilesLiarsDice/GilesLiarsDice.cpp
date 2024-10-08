/* Liar’s Dice Rules
On program start-up, it shall display the rules to the user as read from a text file submitted with the program. 
The user can then set up the game by entering the number of players. Any number below two shall ask the user to add more players. 
Once gameplay has started based on the game rules, there are a few main pieces to address. 
Rolling the die should be performed by randomly generating the side of the die displayed for all of the dice (five per player) using a random number generator. 
This rolling only happens once at the beginning of the game. On each player’s turn, the player should be able to view his/her dice only and enter their guess into the system. 
Continue playing until a player decides to call liar. Then show the full set of dice and determine if the last entered guess was correct. 
Display a message to the game winner (the player who made the guess if it was correct, the player that called liar if the guess was not correct). 
Liar’s Dice is a multiplayer dice game with a minimum of two players and no upper limit on the number of participants. 
The goal is to make a correct guess or correctly call another player a liar.

 The first player calls out two numbers: first, how many dice on the table he or she thinks have been rolled as a number between one and six. 
For example, player one could say “two fives,” which means he or she thinks there are at least two dice that are fives among all the players’ dice (including his or her own). 
o At this point, all players can accept what has been called out and move on to player two
or call player one out, which will end the round and result in a winner or loser for the
round.
 If player one calls out “two fives,” it does not matter whether player one has a five or not as bluffing is allowed in Liar’s Dice. 
It only matters if another player believes player one is bluffing and calls him or her out on it. In that instance, all dice must be revealed. 
If player one is correct, the player wins. If player one is wrong, then the player who called him/her out is the winner. The round is then over.
 If player one’s call is accepted, then player two calls out a number. The first number must be greater than what player one called. 
For example, if player one called out “two fives,” player two must call out three or higher for his or her first number, so “three fives,” “three fours,” or 
four twos” would all be acceptable. “One five” or “two sixes” would be unacceptable.
 Game play continues until someone is called out. */

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// global ints that track how many of each value are on the dice to compare to the final bid
int keyNum1s = 0;
int keyNum2s = 0;
int keyNum3s = 0;
int keyNum4s = 0;
int keyNum5s = 0;
int keyNum6s = 0;

// assigns a random integer value between 1 and 6
int rollDice()
{
	srand(time(NULL));
	int a = 1 + (rand() % 6);
	return a;
}

class Player // prompts the user to enter their name, and sets random values to each of 5 dice
{
public:
	string setPlayerName() // gets name from player
	{
		string playerName;
		cout << "Enter the player's name: " << endl;
		cin >> playerName;
		cout << "Welcome " << playerName << endl;
		return playerName;
	}

	int playerRoll() // sets random values to each of 5 dice, and increments the global values trackers accordingly
	{
		int playerDice1 = rollDice();
		switch (playerDice1)
		{
		case 1:
			++keyNum1s;
			break;
		case 2:
			++keyNum2s;
			break;
		case 3:
			++keyNum3s;
			break;
		case 4:
			++keyNum4s;
			break;
		case 5:
			++keyNum5s;
			break;
		case 6:
			++keyNum6s;
			break;
		}
		cout << "You rolled: " << playerDice1 << endl;
		
		
		int playerDice2 = rollDice();
		switch (playerDice2)
		{
		case 1:
			++keyNum1s;
			break;
		case 2:
			++keyNum2s;
			break;
		case 3:
			++keyNum3s;
			break;
		case 4:
			++keyNum4s;
			break;
		case 5:
			++keyNum5s;
			break;
		case 6:
			++keyNum6s;
			break;
		}
		cout << "You rolled: " << playerDice2 << endl;
		
		int playerDice3 = rollDice();
		switch (playerDice3)
		{
		case 1:
			++keyNum1s;
			break;
		case 2:
			++keyNum2s;
			break;
		case 3:
			++keyNum3s;
			break;
		case 4:
			++keyNum4s;
			break;
		case 5:
			++keyNum5s;
			break;
		case 6:
			++keyNum6s;
			break;
		}
		cout << "You rolled: " << playerDice3 << endl;
		
		int playerDice4 = rollDice();
		switch (playerDice4)
		{
		case 1:
			++keyNum1s;
			break;
		case 2:
			++keyNum2s;
			break;
		case 3:
			++keyNum3s;
			break;
		case 4:
			++keyNum4s;
			break;
		case 5:
			++keyNum5s;
			break;
		case 6:
			++keyNum6s;
			break;
		}
		cout << "You rolled: " << playerDice4 << endl;
		
		int playerDice5 = rollDice();
		switch (playerDice5)
		{
		case 1:
			++keyNum1s;
			break;
		case 2:
			++keyNum2s;
			break;
		case 3:
			++keyNum3s;
			break;
		case 4:
			++keyNum4s;
			break;
		case 5:
			++keyNum5s;
			break;
		case 6:
			++keyNum6s;
			break;
		}
		cout << "You rolled: " << playerDice5 << endl;
		return playerDice1;
		return playerDice2;
		return playerDice3;
		return playerDice4;
		return playerDice5;
	}
	
};



int main()
{
	// reads the rules from the text file and displays them to the console
	string gameRules;
	ifstream textFile("gamerules.txt");
	while (getline(textFile, gameRules))
		{
		cout << gameRules << endl;
		}

	// set number of players, will reject input that does not match between 2 and 10
	int numPlayers = 0;
	do
	{
		cout << "You may have between 2 and 10 players." << endl;
		cout << "Enter number of players: ";
		cin >> numPlayers;
	} while (numPlayers < 2 || numPlayers > 10);

	int i;
	for (i = 1; i <= numPlayers; i++)
	{
		cout << "Player" << i << endl;
		Player player;
		player.setPlayerName();
		player.playerRoll();
	}
	
	// gameplay loop for each turn
	bool calledLiar = false; // sets the boolean condition of whether or not the current player has called liar
	char calledLiarCheck; // gives a character for comparison of whether or not the current player called liar
	int bidNumber = 0; // sets the number of values for the bid
	int bidValue = 0; // sets the value of the faces for the bid
	int currentBidValue = 0;
	int currentBidNumber = 0;
	do 
	{
		cout << "The current bid is: " << currentBidNumber << " " << currentBidValue << "'s" << endl;
		cout << "Would you like to call liar?" << endl;
		cout << "enter y or n" << endl;
		cin >> calledLiarCheck;
		if (calledLiarCheck == 'y')
		{
			calledLiar = true;
			break;
		}

		else
		{
			cout << "The current bid is: " << currentBidNumber << " " << currentBidValue << "'s" << endl;
			cout << "Your new bid's count number must exceed the current bid count number." << endl;
			cout << "Enter the count number of your new bid: ";
			cin >> bidNumber;
			cout << "Enter the face value of your new bid: ";
			cin >> bidValue;
			if (bidNumber <= currentBidNumber)
			{
				cout << "Error" << endl;
			}
			else
			{
				currentBidNumber = bidNumber;
				currentBidValue = bidValue;
			}
		}
							
	} while (calledLiar == false);
	
	// when liar is called, outputs the values of the rolled pool and then checks whether the player that called liar was right
	if (calledLiar == true)
	{
		cout << "You called liar!" << endl;
		cout << "There are: " << endl;
		cout << keyNum1s << " Ones." << endl;
		cout << keyNum2s << " Twos." << endl;
		cout << keyNum3s << " Threes." << endl;
		cout << keyNum4s << " Fours." << endl;
		cout << keyNum5s << " Fives." << endl;
		cout << keyNum6s << " Sixes." << endl;

		// takes the current bid face value and compares the number in the bid to the number in the rolled pool and outputs loss or win
		switch (currentBidValue)
		{
		case 1:
			if (keyNum1s >= currentBidNumber)
			{
				cout << "You lose!" << endl;
				break;
			}
			else 
			{
				cout << "You win!" << endl;
				break;
			}

		case 2:
			if (keyNum2s >= currentBidNumber)
			{
				cout << "You lose!" << endl;
				break;
			}
			else
			{
				cout << "You win!" << endl;
				break;
			}

		case 3:
			if (keyNum3s >= currentBidNumber)
			{
				cout << "You lose!" << endl;
				break;
			}
			else
			{
				cout << "You win!" << endl;
				break;
			}

		case 4:
			if (keyNum4s >= currentBidNumber)
			{
				cout << "You lose!" << endl;
				break;
			}
			else
			{
				cout << "You win!" << endl;
				break;
			}

		case 5:
			if (keyNum5s >= currentBidNumber)
			{
				cout << "You lose!" << endl;
				break;
			}
			else
			{
				cout << "You win!" << endl;
				break;
			}

		case 6:
			if (keyNum6s >= currentBidNumber)
			{
				cout << "You lose!" << endl;
				break;
			}
			else
			{
				cout << "You win!" << endl;
				break;
			}
		}
			
	}
		
	return 0;
}

