#include <iostream>
#include "../tttboard.h"

int main(int argc, char **argv)
{
	TTTBoard game;

	game.printBoard();
	std::cout << std::endl;


	/*game.setCell(TTTBoard::BP_TOPLEFT, TTTBoard::GRID_TYPE_X);
	game.setCell(TTTBoard::BP_CENTERCENTER, TTTBoard::GRID_TYPE_O);*/

	game.turn(TTTBoard::BP_TOPLEFT);
	game.turn(TTTBoard::BP_CENTERCENTER);
	game.turn(TTTBoard::BP_BOTTOMCENTER);

	game.printBoard();
	std::cout << std::endl;

	for (int i = 0; i < 9; ++i)
		if ((i+1) % 3 == 0)
			std::cout << game.getCell(i) << std::endl;
		else
			std::cout << game.getCell(i) << ' ';

	return 0;
}
