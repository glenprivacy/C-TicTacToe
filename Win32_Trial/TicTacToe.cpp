#include <iostream>
#include "TicTacToe.h"

// cerr output if necessary
inline void Game::instruct() const { std::cerr << "Select corresponding number from (1~9)" << std::endl; }
inline void Game::repeatedError() const { std::cerr << "No duplicated value plz" << std::endl; }
// print the next player who will move
inline void Game::turn() const { std::cout << "Player " << currentPlayer << "'s turn: "; }
// check if repeated block is selected by the player, provoked in Game::select()
inline bool Game::noRepeat(int i) const { return map[i] != 'A' && map[i] != 'B'; }
// refresh the command line, should be compatible in both linux and windows
inline void Game::refresh() const { if (system("CLS")) system("clear"); };

// init member variables
Game::Game()
{
	currentPlayer = 'A';
	for (int i = 0; i < 10; i++)
		map[i] = char(i) + '0';
	// null-terminator for safety
	map[10] = '\0';
}

// check result upon destruction
Game::~Game()
{
	if (currentPlayer == 'D')
		std::cout << "Draw!" << std::endl;
	else
		std::cout << "Player " << currentPlayer << " Won!" << std::endl;
	std::cout << "Game ended, back to terminal..." << std::endl;
}

// check if the game is ended by last instruction
bool Game::checkGame() const
{
	// horizontals
	for (int i = 1; i < 9; i += 3)
		if (map[i] == map[i + 1] && map[i] == map[i + 2])
			return true;

	// verticals
	for (int i = 1; i < 4; ++i)
		if (map[i] == map[i + 3] && map[i] == map[i + 6])
			return true;

	// diagonals
	if (map[1] == map[5] && map[1] == map[9])
		return true;
	if (map[3] == map[5] && map[3] == map[7])
		return true;

	return false;
}

// display formatted tictactoe
void Game::display() const
{
	std::cout << "-------------" << std::endl;
	for (int i = 1; i < 10; i += 3) {
		std::cout << "| " << map[i] << " | " << map[i + 1] << " | " << map[i + 2] << " |" << std::endl;
		std::cout << "-------------" << std::endl;
	}
}

// main driver
void Game::gameStart()
{
	instruct();
	for (int ctn = 0; ctn < 9; ++ctn)
	{
		display();
		turn();
		select();
		// early termination if winner is decided
		if (ctn >= 4 && checkGame()) 
		{
			// refresh & display so as to show the last move
			refresh();
			display();
			return;
		}		
		currentPlayer == 'A' ? currentPlayer = 'B' : currentPlayer = 'A';
		refresh();
	}
	// set the currentPlayer to 'D' if draw
	currentPlayer = 'D';
	// display so as to show the last move
	display();
	return;
}

// input legal value
void Game::select()
{
	short i = 0;
	while (true)
	{
		std::cin >> i;
		if (i > 0 && i < 10)
		{
			if (noRepeat(i))
			{
				map[i] = currentPlayer;
				break;
			}
			else
				repeatedError();
		}
		else
			instruct();
	}
}