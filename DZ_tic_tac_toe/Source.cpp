#include<iostream>
#include<string>
#include<time.h>
using namespace std;

char board[9] = {};

void printfield() 
{	
	cout << endl;
	cout << "-" << board[0] << "-|-" << board[1] << "-|-" << board[2] << "-\n";
	cout << "-" << board[3] << "-|-" << board[4] << "-|-" << board[5] << "-\n";
	cout << "-" << board[6] << "-|-" << board[7] << "-|-" << board[8] << "-\n";
}

void clearfield()
{
	
	for (int i = 0; i < 9; i++)
		board[i] = char(i + 49);
}
bool isWinner(char who) {
	if (board[0] == who && board[1] == who && board[2] == who) return true;
	if (board[3] == who && board[4] == who && board[5] == who) return true;
	if (board[6] == who && board[7] == who && board[8] == who) return true;
	if (board[0] == who && board[3] == who && board[6] == who) return true;
	if (board[1] == who && board[4] == who && board[7] == who) return true;
	if (board[2] == who && board[5] == who && board[8] == who) return true;
	if (board[0] == who && board[4] == who && board[8] == who) return true;
	if (board[2] == who && board[4] == who && board[6] == who) return true;
	return false;
}

int botMove() {
	if (board[4] == '5') return 5;
	for (int i = 0; i < 9; i++)
		if (board[i] == char(i + 49)) {
			board[i] = 'O';
			if (isWinner('O'))
				return i + 1;
			else
				board[i] = char(i + 49);

			board[i] = 'X';
			if (isWinner('X'))
				return i + 1;
			else
				board[i] = char(i + 49);
		}
	for (int i = 0; i < 9; i++)
		if (board[i] == char(i + 49))
			return i + 1;
}

void print() 
{	
	printfield();
}

char play(int h) 
{
	int turn = 1; 
	int move;
	char a = 'X', b = 'O';
	if (h == 0) 
		swap(a, b);
	while (1) 
	{
		if (turn % 2 == h)
		{
			print();
			
			if (turn>1) 
			{
				
				cout << "Бот поставил " << b << " на " << move << endl;
			}
			
			cout << "Ваш ход:  ";
			cin >> move;
			while (move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
				print();				
				cout << "** Пожалуйста, введите коректное значение (1-9) **\n";				
				cout << "Ваш ход:  ";
				cin >> move;
			}
			board[move - 1] = a;
			if (isWinner(a)) {
				print();							
				cout << "X победил!\n";
				return a;
			}
		}
		else {
			print();			
			if (turn>1) 
			{				
				cout << "Вы поставили " << a << " на " << move << endl;
			}			
			cout << endl;
			move = botMove();
			board[move - 1] = b;
			if (isWinner(b)) {
				print();									
				cout << "О победил!\n";
				return b;
			}
		}
		turn++;
		if (turn == 10) {
			print();			
						
			cout << "Ничья!\n";
			return 'D';
		}
	}
}
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
	cout << "Ходы :" << endl;
	cout << "-7-|-8-|-9-" << endl;
	cout << "-4-|-5-|-6-" << endl;
	cout << "-1-|-2-|-3-" << endl;
	cout << endl;

	print_board();
	cout << "Ваш ход: ";

	int move;
	cin >> move;
	while (move > 9 || move < 1 || board[move - 1] != '-')
	{
		cout << "Введите правильный номер (1-9): " << endl;

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
				cout << "Игрок X выиграл!" << endl;
				return  'X';
			}
		}
		else
		{
			board[move - 1] = 'O';
			if (has_wonQ('O'))
			{
				cout << "Игрок О выиграл!" << endl;
				return  'O';
			}
		}
		turn++;
		if (turn == 10)
		{
			cout << "Ничья!" << endl;
			return 'D';
		}

	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Игра Крестики и Нолики!" << endl;
	int choice = 0;
	cout << "Выберите с кем играть: №1 - с компьютером или №2 - с другом. " << endl;
	cin >> choice;
	if (choice == 1)
	{
		srand(time(0));
		int p_wins, b_wins, draws;
		p_wins = b_wins = draws = 0; 
		char choice = 'y';
		int h = 0;
		while (choice == 'y') {
			clearfield();
			char winner;
			h = abs(h - 1);
			winner = play(h);
			if (winner == 'D') draws++;
			if (winner == 'X') {
				if (h == 1) p_wins++;
				else b_wins++;
			}
			if (winner == 'O') {
				if (h == 0) p_wins++;
				else b_wins++;
			}

			cout << "Вы выиграли " << p_wins << " раз\n";

			cout << "Компьютер выиграл " << b_wins << " раз\n";

			cout << "Ничья была " << draws << " раз\n\n";
		}
	}
	
	else if (choice == 2)
	{
		int x_wins = 0, o_wins = 0, ties = 0;	
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

		cout << "*Статистика игры*" << endl;
		cout << "Игрок X: " << x_wins << endl;
		cout << "Игрок O: " << o_wins << endl;
		cout << "Ничья: " << ties << endl;		
	}

	system("pause");
	return 0;
}