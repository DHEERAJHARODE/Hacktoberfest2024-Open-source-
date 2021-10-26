#pragma once

namespace crl2{
	bool path_blocked_side(const std::vector<std::vector<std::string>> &grid, const int &rowFrom, const int &colFrom, const int &rowTo, const int &colTo)
	{
		if(rowTo == rowFrom)
		{
			for(int i = colFrom+1; i<colTo; i++)
				if(grid[rowTo][i] != "  ") return true;
			
			for(int i = colFrom-1; i>colTo; i--)
				if(grid[rowTo][i] != "  ") return true;
		}
		else if(colTo == colFrom)
		{
			for(int i = rowFrom+1; i<rowTo; i++)
				if(grid[i][colTo] != "  ") return true;
			
			for(int i = rowFrom-1; i>rowTo; i--)
				if(grid[i][colTo] != "  ") return true;
		}
		return false;
	}

	bool path_blocked_diag(const std::vector<std::vector<std::string>> &grid, const int &rowFrom,const int &colFrom, const int &rowTo, const int &colTo, char playerSide)
	{
		int i = rowFrom+1;
		int j = colFrom+1;
		bool valid = true;

		while(i<rowTo && j<colTo && crl1::isValid(i,j))
		{
			if(((grid[i++][j++]))[0] != ' ')
			{
				valid = false;
				break;
			}
		}

		if(i==rowTo && j==colTo && (grid[i][j])[0] != (grid[rowFrom][colFrom])[0] && valid) return false;

		i = rowFrom-1;
		j = colFrom-1;

		while(i>rowTo && j>colTo && crl1::isValid(i,j))
		{
			if(((grid[i--][j--]))[0] != ' ')
			{
				valid = false;
				break;
			}
		}
		if(i==rowTo && j==colTo && (grid[i][j])[0] != (grid[rowFrom][colFrom])[0] && valid) return false;

		i = rowFrom+1;
		j = colFrom-1;

		while(i<rowTo && j>colTo && crl1::isValid(i,j))
		{
			if((grid[i++][j--])[0] != ' ')
			{
				valid = false;
				break;
			}
		}
		if(i==rowTo && j==colTo && (grid[i][j])[0] != (grid[rowFrom][colFrom])[0] && valid) return false;

		i = rowFrom-1;
		j = colFrom+1;

		while(i>rowTo && j<colTo && crl1::isValid(i,j))
		{
			if(((grid[i--][j++]))[0] != ' ')
			{
				valid = false;
				break;
			}
		}

		if(i==rowTo && j==colTo && (grid[i][j])[0] != (grid[rowFrom][colFrom])[0] && valid) return false;
		return true;
	}
}