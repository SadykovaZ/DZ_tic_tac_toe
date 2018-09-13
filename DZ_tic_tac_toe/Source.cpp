#include<iostream>
#include<string>
using namespace std;

char board[9] = {};

void clear()
{
	for (int i = 0; i < 1; i++)
	{
		cout << endl;
	}
}

void clearboard()
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = '-';
	}
}
bool has_wonQ(char player)
{
	int wins[][3] = {
	{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},
	{2,5,8},{0,4,8},{2,4,6} };

	for (int i = 0; i < 8; i++)
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (board[wins[i][j]] == player)
				count++;
		}
		if (count == 3)
		{
			return true;
		}
	}
	return false;
}
void print_board()
{
	cout << endl;

	cout << "-" << board[6] << "-|-" << board[7] << "-|-" << board[8] << "-\n";
	cout << "-" << board[3] << "-|-" << board[4] << "-|-" << board[5] << "-\n";
	cout << "-" << board[0] << "-|-" << board[1] << "-|-" << board[2] << "-\n";
}
int get_move()
{
	cout << "Move options :" << endl;
	cout << "-7-|-8-|-9-" << endl;
	cout << "-4-|-5-|-6-" << endl;
	cout << "-1-|-2-|-3-" << endl;
	cout << endl;

	print_board();
	cout << "Your move: ";

	int move;
	cin >> move;
	while (move > 9 || move < 1 || board[move - 1] != '-')
	{
		cout << "Enter a legal move (1-9): " << endl;

		cin >> move;
	}

	return move;

}

char play_and_get_winner()
{
	int turn = 1;
	while (!has_wonQ('X') && !has_wonQ('O'))
	{
		clear();
		int move = get_move();
		clear();
		if (turn % 2 == 1)
		{
			board[move - 1] = 'X';
			if (has_wonQ('X'))
			{
				cout << "Congradulations player X WON!" << endl;
				return  'X';
			}
		}
		else
		{
			board[move - 1] = 'O';
			if (has_wonQ('O'))
			{
				cout << "Congradulations player O WON!" << endl;
				return  'O';
			}
		}
		turn++;
		if (turn == 10)
		{
			cout << "It is a draw" << endl;
			return 'D';
		}

	}
}
int main()
{
	cout << "Welcome to tic-tac-toe!" << endl;
	string reply = "y";
	int x_wins = 0, o_wins = 0, ties = 0;
	while (reply == "y")
	{
		clear();
		clearboard();

		char winner = play_and_get_winner();

		print_board();
		switch (winner)
		{
		case 'X': x_wins++;
			break;
		case 'O': o_wins++;
			break;
		case 'D': ties++;
			break;
		}

		cout << "*Winner statistics*" << endl;
		cout << "Player X: " << x_wins << endl;
		cout << "Player O: " << o_wins << endl;
		cout << "Draws: " << ties << endl;
		cout << "Would you like to play again? (y/n)" << endl;;
		cin >> reply;
		while (reply != "y" && reply != "n")
		{
			cout << "PLease enter a valid reply (y/n)" << endl;
			cin >> reply;
		}
	}


	return 0;
}