#pragma once

namespace crl3{
	//Returns true if King is in check
	bool isKingInCheck(std::vector<std::vector<std::string>> &grid, const char &side, std::vector<std::vector<int>> &kingPos)
	{
		if(crl1::kingUtil::util_diag_check_king(grid,side,kingPos)) return true;
		else if(crl1::kingUtil::util_sides_check_king(grid,side,kingPos)) return true;
		else if(crl1::kingUtil::util_horse_check_king(grid,side,kingPos)) return true;
		return false;
	}

	//Returns true if a Pawn move is done
	bool pawn(std::vector<std::vector<std::string>> &grid, const int &rowFrom, const int &colFrom, const int &rowTo, const int &colTo, char side)
	{
		if((grid[rowFrom][colFrom])[1] != 'P') return false;
		char opponent;
		if(side == 'w') opponent = 'b';
		else opponent = 'w';

		if((grid[rowFrom][colFrom])[0] == side)
		{
			cout<<"P\n";
			if(grid[rowTo][colTo] == "  " && colTo == colFrom)
			{
				if((side == 'w' && rowTo == rowFrom - 1) || (side == 'b' && rowTo == rowFrom + 1))
				{ 
					grid[rowTo][colTo] = grid[rowFrom][colFrom];
					grid[rowFrom][colFrom] = "  ";
					return true;
				}
			}
			else if(((grid[rowTo][colTo])[0] == opponent) && (colTo == colFrom+1 || colTo == colFrom-1))
			{
				if((side == 'w' && rowTo == rowFrom - 1) || (side == 'b' && rowTo == rowFrom + 1)) 
				{
					grid[rowTo][colTo] = grid[rowFrom][colFrom];
					grid[rowFrom][colFrom] = "  ";
					return true;
				}
			} 
		}
		return false;
	}

	//Returns true if a Rook move is done
	bool rook(std::vector<std::vector<std::string>> &grid, const int &rowFrom, const int &colFrom, const int &rowTo, const int &colTo, char side)
	{
		if((grid[rowFrom][colFrom])[1] != 'R') return false;

		char opponent;
		if(side == 'w') opponent = 'b';
		else opponent = 'w';
	
		if((rowTo == rowFrom || colTo == colFrom))
		{
			if(crl2::path_blocked_side(grid, rowFrom, colFrom, rowTo, colTo)) return false;

			if((grid[rowFrom][colFrom])[0] == side)
			{
				if(((grid[rowTo][colTo])[0] == opponent) || (grid[rowTo][colTo] == "  "))
				{
					grid[rowTo][colTo] = grid[rowFrom][colFrom];
					grid[rowFrom][colFrom] = "  ";
					return true;
				}
			}
		}
		return false;
	}

	//Returns true if a Knight move is done
	bool horse(std::vector<std::vector<std::string>> &grid, const int &rowFrom, const int &colFrom, const int &rowTo, const int &colTo, char side) //knight
	{
		if((grid[rowFrom][colFrom])[1] != 'H') return false;

		// int arr[] = {-1,+2,/**/ +1,-2,/**/ -1,-2,/**/ +1,+2};       //Improve
		// for(int i=0;i<8;i++)
		// {
		//     for(int j=1;j<8;j++)
		//     {
		//         if((rowTo == (rowFrom + arr[i])) && (colTo == (colFrom + arr[j])))
		//         {
		//             if((grid[rowFrom][colFrom])[0] == side)
		//             {
		//                 if((grid[rowTo][colTo])[0] !=  side)
		//                 {
		//                     grid[rowTo][colTo] = grid[rowFrom][colFrom];
		//                     grid[rowFrom][colFrom] = "  ";
		//                     return true;
		//                 }
		//             }
		//         }
		//     }
		// }

		int arr[8] = {1,2,-1,-2,-1,2,1,-2};
		for(int i = 0, j = 1 ; i<8 ; i+=2, j+=2)
		{
			if(((rowTo == (rowFrom + arr[i])) && (colTo == (colFrom + arr[j]))) || ((rowTo == (rowFrom + arr[j])) && (colTo == (colFrom + arr[i]))))
			{
				if((grid[rowFrom][colFrom])[0] == side && (grid[rowTo][colTo])[0] !=  side)
				{
					grid[rowTo][colTo] = grid[rowFrom][colFrom];
					grid[rowFrom][colFrom] = "  ";
					return true;
				}
			}
		}
		return false;
	}

	//Returns true if a Bishop move is done
	bool bishop(std::vector<std::vector<std::string>> &grid, const int &rowFrom, const int &colFrom, const int &rowTo, const int &colTo, char side) 
	{
		if((grid[rowFrom][colFrom])[1] != 'B') return false;

		if((grid[rowFrom][colFrom])[0] == side)
		{
			if(!crl2::path_blocked_diag(grid,rowFrom,colFrom,rowTo,colTo, side))
			{
				grid[rowTo][colTo] = grid[rowFrom][colFrom];
				grid[rowFrom][colFrom] = "  ";
				return true;
			}           
		}
		return false;
	}

	//Returns true if a Queen move is done
	bool queen(std::vector<std::vector<std::string>> &grid, const int &rowFrom, const int &colFrom, const int &rowTo, const int &colTo, char side)
	{
		if((grid[rowFrom][colFrom])[1] != 'Q') return false;
		
		if((grid[rowFrom][colFrom])[0] == side)
		{
			if(!crl2::path_blocked_diag(grid,rowFrom,colFrom,rowTo,colTo, side) || (!crl2::path_blocked_side(grid, rowFrom, colFrom,rowTo, colTo) && ((rowFrom == rowTo) || (colFrom == colTo)) && (grid[rowTo][colTo])[0] != side))
			{
					grid[rowTo][colTo] = grid[rowFrom][colFrom];
					grid[rowFrom][colFrom] = "  ";
					return true;
			}

		}
		return false;
	}

	//Returns true if a King move is done
	bool king(std::vector<std::vector<std::string>> &grid, const int &rowFrom, const int &colFrom, const int &rowTo, const int &colTo, std::vector<std::vector<int>> &kingPos, char side)
	{
		if((grid[rowFrom][colFrom])[1] != 'K') return false;

		int player = 0;
		if(side == 'b') player = 1;

		if((grid[rowFrom][colFrom])[0] == side && (grid[rowTo][colTo])[0] != side)
		{
			for(int i=-1;i<=1;i++)
			{   
				for(int j=-1;j<=1;j++)
				{   
					if((rowFrom + i == rowTo) && (colFrom + j == colTo))
					{
						grid[rowTo][colTo] = grid[rowFrom][colFrom];
						grid[rowFrom][colFrom] = "  ";
						kingPos[player][0] = rowTo;
						kingPos[player][1] = colTo;;
						return true;
					}
				}
			}
		}
		return false;
	}

	//Returns true if any move was made
	bool move_was_made(std::vector<std::vector<std::string>> &grid, const int &rowFrom, const int &colFrom, const int &rowTo, const int &colTo, std::vector<std::vector<int>> &kingPos, char side, bool &kingMoved, bool rookMoved[2])
	{
		if(crl3::pawn(grid,rowFrom,colFrom,rowTo,colTo,side)) return true;
		else if(crl3::rook(grid,rowFrom,colFrom,rowTo,colTo,side)) 
		{
			if(!rookMoved[0] && colFrom == 0 && (rowFrom == 0 || rowFrom == 7)) rookMoved[0] = true;
			else if(!rookMoved[1] && colFrom == 7 && (rowFrom == 0 || rowFrom == 7)) rookMoved[1] = true;
			return true;
		}
		else if(crl3::horse(grid,rowFrom,colFrom,rowTo,colTo,side)) return true;
		else if(crl3::bishop(grid,rowFrom,colFrom,rowTo,colTo,side)) return true;
		else if(crl3::queen(grid,rowFrom,colFrom,rowTo,colTo,side)) return true;
		else if(crl3::king(grid,rowFrom,colFrom,rowTo,colTo,kingPos,side))
		{
			if(!kingMoved && colFrom == 4 && (rowFrom == 0 || rowFrom == 7)) kingMoved = true;
			return true;
		}
		return false;
	}
}
