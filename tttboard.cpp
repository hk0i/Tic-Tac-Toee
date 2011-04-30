#include <iostream>
#include "tttboard.h"


TTTBoard::TTTBoard(void)
		 :isOver(false),
		  myCurrentPlayer(PLAYER_X),
		  myMoves(0)
{
	reset();
}

void TTTBoard::reset(void)
{
	for (int i = 0; i < 9; ++i)
		myBoard[i] = GRID_TYPE_NONE;
	myCurrentPlayer = PLAYER_X;
	myMoves = 0;
	this->isOver = false;
}

void TTTBoard::setCell(int id, int type)
{
	if (id < 0 || id > 9)
		return;
	if (type < 0 || type > GRID_TYPE_X)
		return;
	myBoard[id] = type;

}

void TTTBoard::turn(int id)
{
	if (this->isOver)
		return;

	this->setCell(id, myCurrentPlayer);
	if (myCurrentPlayer == PLAYER_O)
		myCurrentPlayer = PLAYER_X;
	else
		myCurrentPlayer = PLAYER_O;
	myMoves++;
}

void TTTBoard::printBoard(void)
{
	for (int i = 0; i < 9; ++i)
		if ((i+1) % 3 == 0)
			std::cout << myBoard[i] << std::endl;
		else
			std::cout << myBoard[i] << ' ';
	//std::cout << std::endl;
}

int TTTBoard::getCell(int pos) const
{
	return myBoard[pos];
}

int TTTBoard::gameOver(void)
{
	// check rows
	if ( myBoard[0] == myBoard[1] &&
		 myBoard[0] == myBoard[2] &&
		 myBoard[0] > 0)
	{
		this->isOver = true;
		return myBoard[0];
	}
	if (myBoard[3] == myBoard[4] &&
		myBoard[3] == myBoard[5] &&
		myBoard[3] > 0)
	{
		this->isOver = true;
		return myBoard[3];
	}
	if (myBoard[6] == myBoard[7] &&
		myBoard[6] == myBoard[8] &&
		myBoard[6]  > 0)
	{
		this->isOver = true;
		return myBoard[6];
	}

	// check columns
	if (myBoard[0] == myBoard[3] &&
		myBoard[0] == myBoard[6] &&
		myBoard[0]  > 0)
	{
		this->isOver = true;
		return myBoard[0];
	}
	if (myBoard[1] == myBoard[4] &&
		myBoard[1] == myBoard[7] &&
		myBoard[1] > 0)
	{
		this->isOver = true;
		return myBoard[1];
	}
	if (myBoard[2] == myBoard[5] &&
		myBoard[2] == myBoard[8] &&
		myBoard[2]  > 0)
	{
		this->isOver = true;
		return myBoard[2];
	}

	// check diagonals
	if (myBoard[0] == myBoard[4] &&
		myBoard[0] == myBoard[8] &&
		myBoard[0] > 0)
	{
		this->isOver = true;
		return myBoard[0];
	}
	if (myBoard[2] == myBoard[4] &&
		myBoard[2] == myBoard[6] &&
		myBoard[2] > 0)
	{
		this->isOver = true;
		return myBoard[2];
	}

	// check for stalemate by checking maximum moves
	if (myMoves == 9)
	{
		this->isOver = true;
		return PLAYER_NOBODY;
	}

	return 0;
}

int TTTBoard::getCurrentPlayer(void) const
{
	return myCurrentPlayer;
}
