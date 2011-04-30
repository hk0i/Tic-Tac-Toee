#ifndef _TTT_BOARD
#define _TTT_BOARD

class TTTBoard
{
	public:
		TTTBoard(void);

		int getCell(int) const;					// returns the state of
												// specified cell position

		// turn: use current player's turn to claim a space for him/her.
		void turn(int id);
		// setCell: set specific cell to a specific value
		void setCell(int id, int type);

		void printBoard(void);					// prints game board to stdout.
		void reset(void);

		int gameOver(void);						// checks to see if we won yet
		int getCurrentPlayer(void) const;		// gets the current player

		enum {
			GRID_TYPE_NONE = 0,
			GRID_TYPE_O = 1,
			GRID_TYPE_X
		};

		enum {
			PLAYER_O = 1,
			PLAYER_X,
			PLAYER_NOBODY
		};

		enum {
			BP_TOPLEFT = 0,
			BP_TOPCENTER,
			BP_TOPRIGHT,
			BP_CENTERLEFT,
			BP_CENTERCENTER,
			BP_CENTERRIGHT,
			BP_BOTTOMLEFT,
			BP_BOTTOMCENTER,
			BP_BOTTOMRIGHT
		};


	private:

		bool isOver;							// if the game is over

		int myBoard[9];
		int myCurrentPlayer;					// which player's turn it is.
		// number of moves used (this will tell us quickly if the game is over
		// yet
		int myMoves;
};


#endif
