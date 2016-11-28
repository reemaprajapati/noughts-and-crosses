
#include <iostream>
#include<windows.h>

class Board
{
    char cell[9];
    bool turn;
    int moves;
public:
    Board(bool t = true):
    	cell{'0','1','2','3','4','5','6','7','8'},
    	turn(t),
    	moves(0)
    	{}
	int plot(unsigned int x)
	{
		if ( cell[x] != 'O' && cell[x] != 'X')
		{

			if(turn)
			{
				cell[x] = 'O';
			}
			else
			{
                cell[x] = 'X';
			}
			int ret = checkWin();

			if(ret > 0)
			{
				return int(turn)+1;
			}
			else if(ret < 0)
			{
				return -2;
			}

			turn = !turn;
			return 0;
		}
		else
		{
            return -1;
		}
	}
	int checkWin()
	{
		moves++;
		//win requires more than 4 moves
		if(moves > 4)
		{
			//top row
			if (cell[0] == cell[1] && cell[1] == cell[2])
					return 1;
			//middle row
			else if (cell[3] == cell[4] && cell[4] == cell[5])
				return 1;
			// bottom row
			else if (cell[6] == cell[7] && cell[7] == cell[8])
				return 1;
            //left column
			else if (cell[0] == cell[3] && cell[3] == cell[6])
				return 1;
			//middle column
			else if (cell[1] == cell[4] && cell[4] == cell[7])
				return 1;
			//right column
			else if (cell[2] == cell[5] && cell[5] == cell[8])
				return 1;
            //backward diagonal
			else if (cell[0] == cell[4] && cell[4] == cell[8])
				return 1;
			//foreward diagonal
			else if (cell[2] == cell[4] && cell[4] == cell[6])
				return 1;
			//all slots full but no win = draw
			else if(moves == 9)
				return -1;
			//no win but moves left = playing
			else
				return 0;
		}
		return 0;
	}
	void draw()
	{
		using namespace std;
		cout<<"\n\n";
		cout << "     |     |     " << endl;
		cout << "  " << cell[0] << "  |  " << cell[1] << "  |  " << cell[2] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << cell[3] << "  |  " << cell[4] << "  |  " << cell[5] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << cell[6] << "  |  " << cell[7] << "  |  " << cell[8] << endl;

		cout << "     |     |     " << endl << endl;
	}
	char whoseTurn()
	{
		if(turn)
			return 'O';
		else
			return 'X';

	}

};


int main()
{
	SetConsoleTitle("NOUGHTS AND CROSSES");
	std::cout<<"\n\nNOUGHTS AND CROSSES"<<std::endl;
	std::cout<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<std::endl;
	Board board;
	while(1)
	{

		board.draw();
		std::cout << "TURN::  " << board.whoseTurn() << std::endl;
		std::cout << "\nENTER THE CELL YOU WANT TO MARK:: ";
		int in;
        std::cin >> in;
        if(in>8 || in<0)
        {
        	std::cout<<"\nInvalid Move!!! Enter from (0-8) only! "<<std::endl;
			continue;
   		}
       	 int win = board.plot(in);
			if( win > 0)
			{
			std::cout<<"--------------------------------------";
			std::cout<< "\n\n       CONGRATS!!!!!  WINNER IS = "  << board.whoseTurn()<<"   !!!!!!!!!!!!!"<<std::endl;
			board.draw();
			break;
			}
			else if(win == -1)
			{
				std::cout<< "\nInvalid move. Move again." << std::endl;
			}
			else if(win == -2)
			{
		  	  std::cout<<"--------------------------------------";
	    		std::cout<< std::endl << "\n                 DRAW!" << std::endl;
				board.draw();
				return 0;
			}


	}


    return 0;
}
