/*
 * assignment2.cpp
 *
 *  Created on: Feb 13, 2020
 *  Author: Ezedine Kargougou
 *  Description:
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
using namespace std;

// This is making the signature beforehand
int Welcome();
int Game();
int Macro_Function();
int RandomInRange(int min, int max);
int IsEven(int number);
int RollDie(int sides);
int GameA(char*);
int GameB(char*);
int GameC();
int GameD(char*);

// defining the macros
#define sub_macro(a,b) (a - b)
#define cube_macro(a) (a * a * a)
#define min_macro(a, b) ((a < b) ? a : b)
#define odd_macro(a) ((a %2 == 0) ? 0 : 1)

// This is the main function
 int main(int argc, char* argv[])
 {

	Welcome(); // calls the welcome function that will runs everything
	return 0;
}

// This is the function that will welcome the player and prompt the menu
int Welcome()
{
	srand(time(0)); // This helps the games run smoothly. only needs to call it once, before the random generator function

	int userNumb = 0; // this is the variable that takes the user input
	cout << "Welcome to CSE240 Assignment 2!\nMenu:" << endl;
	cout << "1 - CSE240 Mini-Game Collection"
			"\n2 - Macros vs Functions Throw-down"
			"\n0 - Exit" << endl;
	cout << "Choose an option: ";
	cin >> userNumb;
	cout << userNumb << endl;
	while (userNumb != 0 && userNumb != 1 && userNumb != 2) {  // fail safe for when the user is silly
		cout << "This is not an option. Please select another!" << endl;
		cin >> userNumb;
	}
	if (userNumb == 0) {
		cout << "Program closed" << endl;
	} else if (userNumb == 1) {
		Game();
	} else if (userNumb == 2) {
		Macro_Function();
	}
	return 0;
}

// This function will return a random number
int RandomInRange(int min, int max)
{
	int genNumb;
	genNumb = (rand() % (max - min + 1)) + min;
	return genNumb;
}

// This method is for when option one was chosen. This is where the game will be played
int Game()
{
	char nameGetter[10]; // the char array
	char* opponentName = nameGetter; // setting it to a pointer
	int opponentScore = 0;
	int playerScore = 0;
	int numbOfGames = 0;
	int gameNumber = 1;



	int rand = RandomInRange(0, 100); // will access a random number between 0 and 100
	// the following code gets the name and stores it into the char
	ifstream ezeFile("random_name.txt");
	if(ezeFile.is_open()){
		for(int i=0; i < rand; i++){
			ezeFile >> nameGetter;
		}
	}

	// prompts the reader the following message
	cout << "\nWelcome to CSE240 Mini-Game Collection!" << endl;
	cout << "I am your opponent " << opponentName<< endl; // This is where it gets stuck
	cout << "How many rounds should we play? (Choose an odd number)\n> ";
	cin >> numbOfGames;

	// error loop for when the number of games is not even
	while (numbOfGames % 2 == 0) {
		cout << "Please choose an odd number!\n> ";
		cin >> numbOfGames;
	}

	int victory = (numbOfGames + 1) / 2;
	// for loop determines which games it will play
	for (int i = 0; i < numbOfGames; i++) {

		int chooser = RandomInRange(1, 4); // picks a game randomly

		 // takes the best out of however many games
		 if(playerScore >= victory || opponentScore >= victory){
			 break;
		 }
		if (chooser == 1) {
			int aTracker = GameA(opponentName);
			// this is the score board
			if(aTracker == 1){
				playerScore++;
				cout << "The score is: " << endl;
				cout << "Player: " << playerScore << "\n" << opponentName << ": " << opponentScore << endl;
			} else {
				opponentScore++;
				cout << "The score is: " << endl;
				cout << "Player: " << playerScore << "\n" << opponentName << ": " << opponentScore << endl;
			}
		gameNumber++; // increments game

		} else if (chooser == 2) {
			int bTracker = GameB(opponentName);
			// this is the score board
			if(bTracker == 1 ){ // if statement for when player wins
				playerScore++;
				cout << "The score is: " << endl;
				cout << "Player: " << playerScore << "\n" << opponentName << ": " << opponentScore << endl;
			} else if(bTracker == 0) { // if for when opponent wins
				opponentScore++;
				cout << "The score is: " << endl;
				cout << "Player: " << playerScore << "\n" << opponentName << ": " << opponentScore << endl;
			} else{ // if either wins
				cout << "The score is: " << endl;
				cout << "Player: " << playerScore << "\n" << opponentName << ": " << opponentScore << endl;
			}
			gameNumber++; // increments game

		} else if (chooser == 3) {
			int cTracker = GameC();
			// this is the score board
			if(cTracker == 1){ // if player wins
				playerScore++;
				cout << "The score is: " << endl;
				cout << "Player: " << playerScore << "\n" << opponentName << ": "
									<< opponentScore << endl;
			} else { // if opponent wins
				opponentScore++;
				cout << "The score is: " << endl;
				cout << "Player: " << playerScore << "\n" << opponentName << ": "
									<< opponentScore << endl;
			}
			gameNumber++; // increments game

		} else if (chooser == 4) {
			int dTracker = GameD(opponentName);
			// this is the score board
			if(dTracker == 1){ // player wins
				playerScore++;
				cout << "The score is: " << endl;
				cout << "Player: " << playerScore << "\n" << opponentName << ": " << opponentScore << endl;
			} else if(dTracker == 0) { // opponent wins
				opponentScore++;
				cout << "The score is: " << endl;
				cout << "Player: " << playerScore << "\n" << opponentName << ": " << opponentScore << endl;
			} else{
				cout << "The score is: " << endl;
				cout << "Player: " << playerScore << "\n" << opponentName << ": " << opponentScore << endl;
			}
			gameNumber++; // increments game
		}
	}

	// Winner decider
	if (playerScore >= victory){
				cout << "The winner is : PLayer" << endl;
			}
			else if(opponentScore >= victory){
				cout << "The winner is: " << opponentName << endl;
			}
	return 0;
}

// This function will drive the Even Odds game
int GameA(char* someName) {
	// making the variables
	char* oppName = someName;
	int userInput;
	int userGuess;
	int oppNumb = RandomInRange(0, 100);
	int comp;
	int returner;
	int bigNumb;
	char* guess;

	cout << "\nEven/Odd game!" << endl;
	cout << "Guess even or odd! (0 for even, 1 for odd): ";
	cin >> userGuess;
	cout << userGuess;

	// fail safe for when input is invalid
	while((userGuess != 0) && (userGuess != 1)){
		cout << "Invalid input. Please guess 0 for even and 1 for odd";
		cin >> userGuess;
	}

	cout << "Enter a number (between 0 and 100): " << flush;
	cin >> userInput;
	while(userInput > 100 || userInput < 0){
			cout << "Invalid input. Please between 0 and 100";
			cin >> userInput;
		}
	cout << oppName << " picked " << oppNumb << endl;

	// Figures out if the two numbers added together yields an even or an odd
	bigNumb = userInput + oppNumb;
	if (IsEven(bigNumb) == 1) {
		guess = "ODD!";
		comp = 1;
	} else {
		guess = "EVEN!";
		comp = 0;
	}
	// Outputs who won the game
	cout << userInput << "+" << oppNumb << " = " << bigNumb << " - " << guess
			<< endl;
	if (comp == userGuess) {
		cout << "Player wins the round!\n" << endl;
		returner = 1;
	} else {
		cout << oppName << " wins the round!\n" << endl;
		returner = 0;
	}
	return returner;
}
// This function will drive the Rock, Paper, Scissors game
int GameB(char* someName1) {
	// declaring the variables
	char* oppName = someName1;
	int returner = 0;
	int userPick;
	// how the computer picks rock, paper, or scissors
	int oppPick = RandomInRange(1, 3);
	cout << "\nRock, Paper, Scissors game!" << endl;
	cout << "Choose a throw!" << endl;
	cout << "1. Rock\n2.Paper\n3.Scissors\n>>" << endl;
	cin >> userPick;

	// fail safe for  invalid input
	while (userPick != 1 && userPick != 2 && userPick != 3) {
		cout << "Incorrect option. Please choose from the following:" << endl;
		cout << "1. Rock\n2.Paper\n3.Scissors " <<endl;
		cin >> userPick;
	}
	// draw decider
	if (oppPick == userPick) {
		cout << "It's a draw!" << endl;
		returner = 2;
	}
	// condition for player win
	else if ((oppPick == 1 && userPick == 2) || (oppPick == 3 && userPick == 1)
			|| (oppPick == 2 && userPick == 3)) {
		returner++;
		cout << "Player wins the round!" << endl;

	}
	// condition for machine win
	else if ((oppPick == 2 && userPick == 1) || (oppPick == 1 && userPick == 3)
			|| (oppPick == 3 && userPick == 2)) {
		cout << oppName << " wins the round!" << endl;
	} else {
		cout << "There must have been an incorrect input" << endl; // should never be outputed but just in case
	}

	return returner;
}
// This function will run the number guessing game
int GameC() {
	// declaring variables
	int returner = 0;
	int playerGuess;
	int oppGuess = RandomInRange(0, 500); // number player should guess
	int oppGuessLow = RandomInRange((oppGuess - 100), (oppGuess - 30)); // lowest number it could be
	int oppGuessHigh = RandomInRange((oppGuess + 30), (oppGuess + 100)); // highest number it ould be
	int numbOfGuess = 1;
	cout << "\nNumber Guessing game!" << endl;
	cout << "Player, I'm thinking of a number between " << oppGuessLow
			<< " and " << oppGuessHigh << " !\nYou have 5 guesses!" << endl;

	// for loop to itterate through the guesses
	for (int i = 0; i < 5; i++) {
		cout << "What's guess # " << numbOfGuess << " ?: ";
		cin >> playerGuess;

		// guides player to the right number
		if (playerGuess < oppGuess) {
			cout << "My number is higher!" << endl;
		} else if (playerGuess > oppGuess) {
			cout << "My number is lower!" << endl;
		} else if (playerGuess == oppGuess) {
			cout << "You guessed right!" << endl;
			returner++;
			break;
		}
		numbOfGuess++;
	}
	if (playerGuess != oppGuess) {
		cout << "You guessed wrong, my number was " << oppGuess << "\n" << endl;
	}
	return returner;
}

//
int GameD(char* someName2)
{
	// declaring variables
	char* oppName = someName2;
	int returner = 0;
	int sideNumb;
	int dieNumb;

	cout << "\nDice Roll Showdown!" << endl;
	cout << "How many sides do the dice have? (input a positive number): "
			<< flush;
	cin >> sideNumb;

	// Safety output for when the user's input is out of range
	while (sideNumb < 0) {
		cout << "Please input a positive number: " << flush;
		cin >> sideNumb;
	}
	RollDie(sideNumb);
	cout << "How many dice will each player roll? " << flush;
	cin >> dieNumb;

	// score board for player
	cout << "Player 1 Rolled: " << endl;
	int playerTotal = 0;
	int pScore = 0;
	int mScore = 0;

	// the for loop will iterate however many times the dieNumb is
	for (int i = 0; i < dieNumb; i++) {
		pScore = RollDie(sideNumb);
		cout << pScore << endl;
		playerTotal += pScore;

	}
	// output of the overall player score
	cout << "Total: " << playerTotal << endl;

	// score board for Machine
	cout << oppName << " Rolled: " << endl;
	int machineTotal = 0;

	// the for loop will iterate however many times the dieNumb is
	for (int i = 0; i < dieNumb; i++) {
		mScore = RollDie(sideNumb);
		cout << mScore << endl;
		machineTotal += mScore;
	}
	// output of the overall machine score
	cout << "Total: " << machineTotal << endl;

	// this code determines who the winner is
	if (playerTotal < machineTotal) {
		cout << oppName << " Wins!" << endl;
	} else if (playerTotal > machineTotal) {
		cout << " Player Wins!" << endl;
		returner++;
	} else if (playerTotal == machineTotal) {
		cout << "It's a tie!" << endl;
	}

	return returner;
}

// takes a number as a parameter and returns the result
int RollDie(int sides)
{

	int maxSide = sides; // sets the size to whatever value the parameter is
	int sideNumber = RandomInRange(1, maxSide);

	return sideNumber;
}
// This function is to figure out whether the number inputed is even or odd
int IsEven(int number) {
	// This is to figure out if the variable guess is going to be even or odd
	if ((number) % 2 == 0) {
		number = 0;
	} else {
		number = 1;
	}
	return number;
}
// returns the result of a - b
int subf(int a, int b)
{
	return a - b;
}

// returns the result of a cubed
int cubef(int a) {
	return a * a * a;
}
// returns the smallest value of the 2
int minf(int a, int b)
{
	if (a <= b) {
		return a;
	} else {
		return b;
	}

}
// returns whether a is odd or even
int oddf(int a)
{
	if (a % 2 == 0) {
		return 0;
	} else{
		return 1;
	}

}
// this function will
int Macro_Function()
{
	int userChoice;
	int num1 = 10, num2 = 17;
	cout << "Which operations would you like to compare:\n";
	cout << "1: Substitution\n2:Cube\n3:Min\n4:Odd/Even\n0:None\n> ";
	cin >> userChoice;
	while (userChoice != 0 && userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4) {
		cout << "Please choose from the following options:\n";
		cout << "1: Substitution\n2:Cube\n3:Min\n4:Odd/Even\n0:None\n> ";
		cin >> userChoice;
	}

	if(userChoice == 1)
	{
//  both returns the same value
	cout << "Function, subf(num1, num2) is: " << flush;
	cout << subf(num1, num2) << endl;
	cout << "Macro, sub_macro(num1, num2) is: " << flush;
	num1 = 10, num2 = 17;
	cout << sub_macro(num1, num2) << "\n" << endl;
//  both the returns the same value
	num1 = 10, num2 = 17;
	cout << "Function, subf(num1++, num2--) is: " << flush;
	cout << subf(num1++, num2--) << endl;
	num1 = 10, num2 = 17;
	cout << "Macro, sub_macro(num1++, num2--) is: " << flush;
	cout << sub_macro(num1++, num2--) << "\n" << endl;
	} else if	(userChoice == 2){ //  both returns the same value
	num1 = 10, num2 = 17;
	cout << "Function, cubef(num1) is: " << flush;
	cout << cubef(num1) << endl;
	num1 = 10, num2 = 17;
	cout << "Macro, cube_macro(num1) is: " << flush;
	cout << cube_macro(num1) << "\n" << endl;
/*  the return of the function is 729 because it multiplies (9*9*9)
    but the macro subtract before it starts making it (8*8*7) */
	num1 = 10, num2 = 17;
	cout << "Function, cubef(--num1) is: " << flush;
	cout << cubef(--num1) << endl;
	num1 = 10, num2 = 17;
	cout << "Macro, macro(--num1) is: " << flush;
	cout << cube_macro(--num1) << "\n"<< endl;
	} else if	(userChoice == 3){ //  both return the same value
	num1 = 10, num2 = 17;
	cout << "Function, minf(num1, num2) is: " << flush;
	cout << minf(num1, num2) << endl;
	num1 = 10, num2 = 17;
	cout << "Macro, min_macro(num1, num2) is: " << flush;
	cout << min_macro(num1, num2) << "\n"<< endl;
/*  the function returns 9 because it only subtract 1 from 10
 *  the macro is 8 because it subtract 1 beforehand and one more
 *  when it's about to out the result, so 8 */
	num1 = 10, num2 = 17;
	cout << "Function, minf(--num1, --num2) is: " << flush;
	cout << minf(--num1, --num2) << endl;
	num1 = 10, num2 = 17;
	cout << "Macro, min_macro(--num1, --num2) is: " << flush;
	cout << min_macro(--num1, --num2) << "\n"<< endl;
	} else if	(userChoice == 4){ //  both returns the same value
	num1 = 10, num2 = 17;
	cout << "Function, oddf(num1) is: " << flush;
	cout << oddf(num1) << endl;
	num1 = 10, num2 = 17;
	cout << "Macro, odd_macro(num1) is: " << flush;
	cout << odd_macro(num1) << "\n"<< endl;
/*  the function and macro spat out 0 because because it increments at the end.
 *  the numb1 of macro will be 11 by the end of it but gets reset back to 10*/
	num1 = 10, num2 = 17;
	cout << "Function, oddf(num1++) is: " << flush;
	cout << oddf(num1++) << endl;
	num1 = 10, num2 = 17;
	cout << "Macro, odd_macro(num1++) is: " << flush;
	cout << odd_macro(num1++) << endl;
	} else {
	num1 = 10, num2 = 17;
	cout << "Goodbye!";
	}

	return 0;
}



