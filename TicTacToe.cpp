// Raghubir Chimni
// TicTacToe.cpp
// Date: 7/2/2020

#include <iostream>
using namespace std;

void ticTacToString(int n)
{
	if(n == 1)
		cout << "Player 1 is the winner!";
	else if(n == 2)
		cout << "Player 2 is the winner!";
	else
		cout << "Tie!";
	
	cout << endl;
}

string getWinner(string a[], string p1, string p2)
{
	
	// straight down/up checker
	for(int i = 0; i < 3; i++)
	{
		if(a[i] == a[i+3] && a[i] == a[i+6])
		{
			if(a[i] == p1)
				return "Player 1";
			else
				return "Player 2";
		}
	}

	// for side-to-side
	for(int i = 0; i < 9; i+=3)
	{
		if(a[i] == a[i+1] && a[i] == a[i+2])
		{
			if(a[i] == p1)
				return "Player 1";
			else
				return "Player 2";
		}
	}

	// for diagonal
	if(a[0] == a[4] && a[0] == a[8]) 
	{
		if(a[0] == p1)
			 return "Player 1"; 
		 return "Player 2"; 
	}
	else if(a[2] == a[4] && a[2] == a[6])
	{
		if(a[2] == p1)
			 return "Player 1"; 
		 return "Player 2"; 
		
	}

	bool prog = false;

	for(int i = 0; i < 9; i++) 
	{
		if(a[i] != p1 && a[i] != p2)
		{
			prog = true;
			break;
		}
	}

	if(prog)
		return "Still In Progress";
	else
		return "Tie";

}

int isGameDone(string a[], string p1, string p2)
{
	string w = getWinner(a, p1, p2);

	if(w == "Player 1")
		return 1;
	else if(w == "Player 2")
		return 2;
	else if(w == "Tie")
		return 0;
	
	return -1;	
}


void drawBoard(string a[], string p1, string p2)
{
	cout << "Player 1: " << p1 << "\tPlayer 2: " << p2 << endl;
	
	cout << endl;

	int fart = 0;

	for(int k = 0; k < 3; k++)	
	{
		cout << "\t";

		for(int i = 0; i < 3; i++)
		{
			cout << a[fart++];

			if(i != 2)
				cout << " | ";
			else
				cout << endl;

		}	
		
		if(k != 2)
			cout << "\t----------" << endl;
		 
	}
}

void playTicTacToe(string b[], string p1, string p2)
{
	bool win = false;
	int a = 0, num = 0, round = 1;
	string c = "";

	cout << "Enter a number to put your character there" << endl << endl;
	
	while(!win)
	{
		cout << "---------------------------------------------------\nRound: " << round++ << endl; 
		cout << "---------------------------------------------------" << endl;
	
	
		drawBoard(b, p1, p2);

		cout << endl;	
		
		if(a++ % 2 == 0)
		{
			c = p1;
			cout << "Player 1 it is your turn, enter a number: ";	
		}
		else
		{
			c = p2;
			cout << "Player 2 it is your turn, enter a number: ";
		}
		
		cin >> num;
		
		b[num-1] = c; 
		
		num = isGameDone(b, p1, p2);
		
		if(num != -1)
			break;

		cout << endl;
	}
	
	cout << endl;
	
	drawBoard(b, p1, p2);
	ticTacToString(num);
	
}

int main()
{
	string player1; // holds their character 
	string player2; // holds their character
	
	string ans; // for players to put their character or to see if they want to play again
	
	string winner; // holds the winner
	
	string board[9];

	bool valid = true;
	bool play = true;

	while(play)
	{
		for(int i = 0; i < 9; i++)
		{
			board[i] = to_string(i+1);
		}

		cout << endl << "Welcome to TicTacToe!" << endl << endl;
	
		cout << "Player 1, what character do you want? Enter Here: ";
		cin >> player1;
		
		cout << endl << "Player 2, what character do you want? Enter Here: "; 
		cin >> player2;
		
		cout << endl << endl;
		
		playTicTacToe(board, player1, player2);

		// Ask if want to play again
		
		cout << endl;

		while(valid)
		{
			cout << "Would you like to play again? (Y/N): ";
			cin >> ans;
	
			if(ans != "Y" && ans != "N")
				cout << "Please put a valid answer." << endl;
			else if(ans == "N")
			{
				play = false;
				break;	
			}
			else if(ans == "Y")
			{	
				cout << "---------------------------------------------------" << endl;
				break;
			}
		}
	}
	
	cout << "\nThank you for playing!\n" << endl;

	return 0;


}
