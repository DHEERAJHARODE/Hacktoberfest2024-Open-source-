#pragma once

#ifdef _WIN32
	#include<windows.h>
#elif unix
	#include<unistd.h>
#endif

namespace crl1{
	void clearScreen()
	{
		#ifdef _WIN32
			system("CLS");
		#elif unix
			system("clear");
		#else
			cout<<"\033[2J\033[1;1H";
		#endif
	}

	bool input(int &rowFrom, int &colFrom, int &rowTo, int &colTo)
	{
		char aFrom,bFrom;
		char aTo,bTo;

		cout<<"Enter move: ";
		cin>>aFrom>>bFrom>>aTo>>bTo;

		if(aFrom=='d' && bFrom=='r' && aTo=='a' && bTo=='w') return false;
		else if(aFrom=='e' && bFrom=='x' && aTo=='i' && bTo=='t') return false;

		if(aFrom >= 'a' && aFrom <= 'h') 
		{
			rowFrom = (aFrom - 'a');
			colFrom = (bFrom - '1');
		}
		else if(aFrom >= '1' && aFrom <= '1')
		{
			rowFrom = (bFrom - 'a');
			colFrom = (aFrom - '1');
		}
		
		if(aTo >= 'a' && aTo <= 'h') 
		{
			rowTo = (aTo - 'a');
			colTo = (bTo - '1');
		}
		else if(aTo >= '1' && aTo <= '1')
		{
			rowTo = (bTo - 'a');
			colTo = (aTo - '1');
		}

		return true;
	}

	void display(vector<vector<std::string>> &board, const std::string &massage)
	{
		clearScreen();
		cout<<"\n\t\t Type \"draw\" or \"exit\" to end the match!\n\n";
		cout<<"  ";
		for(int i=0;i<8;i++) cout<<"     "<<i+1<<"    ";
		cout<<"\t\tPrompt: "<<massage<<"\n";
		
		int row = 0, col = 0;

		for(char i='a';i<='h';i++)
		{   cout<<"  ";
			for(int i=0;i<8;i++) cout<<"+---------";
			cout<<"+\n  ";

			for(int i=0;i<8;i++) cout<<"|         ";
			cout<<"|\n"<<i<<" ";

			for(int i=0;i<8;i++) cout<<"|    "<<board[row][col++]<<"   ";
			cout<<"|  "<<i<<"\n  ";

			for(int i=0;i<8;i++) cout<<"|         ";
			cout<<"|\n";
			row++;
			col=0;
		}
		cout<<"  ";
		for(int i=0;i<8;i++) cout<<"+---------";
		cout<<"+\n";
		cout<<"  ";
		for(int i=0;i<8;i++) cout<<"     "<<i+1<<"    ";
		cout<<"\n";
	}

	bool isValid(const int &row, const int &col)
	{
		if(row<0 || row>7 || col<0 || col>7) return false;
		return true;
	}

	namespace kingUtil{   

		//Function to check if the king is in check diagonally
		bool util_diag_check_king(vector<vector<std::string>> &grid,const char &side, vector<vector<int>> &kingPos)
		{
			char opponent;
			int currRow,currCol;
		// cout<<"a\n";

			if(side == 'w') 
			{
				opponent = 'b';
				currRow  = kingPos[0][0];
				currCol = kingPos[0][1];
			}
			else 
			{
				opponent = 'w';
				currRow  = kingPos[1][0];
				currCol = kingPos[1][1];
			}

			int i = currRow;
			int j = currCol;
			
			while(isValid(++i,++j))
			{
				if((grid[i][j])[0] == side) break;
				else if((grid[i][j])[0] == opponent && ((grid[i][j])[1] == 'B' || (grid[i][j])[1] == 'Q')) return true;
			}

			i = currRow; j = currCol;
			while(isValid(--i,++j))
			{
				if((grid[i][j])[0] == side) break;
				else if((grid[i][j])[0] == opponent && ((grid[i][j])[1] == 'B' || (grid[i][j])[1] == 'Q')) return true;
			}
			
			i = currRow; j = currCol;
			while(isValid(++i,--j))
			{
				if((grid[i][j])[0] == side) break;
				else if((grid[i][j])[0] == opponent && ((grid[i][j])[1] == 'B' || (grid[i][j])[1] == 'Q')) return true;
			}
			
			i = currRow; j = currCol;
			while(isValid(--i,--j))
			{
				if((grid[i][j])[0] == side) break;
				else if((grid[i][j])[0] == opponent && ((grid[i][j])[1] == 'B' || (grid[i][j])[1] == 'Q')) return true;    
			}
			return false;
		}

		//Function to check if the king is in check sidewise
		bool util_sides_check_king(vector<vector<std::string>> &grid, const char &side, vector<vector<int>> &kingPos)
		{
			char opponent;
			int currRow,currCol;
		//  cout<<"b\n";

			if(side == 'w') 
			{
				opponent = 'b';
				currRow  = kingPos[0][0];
				currCol = kingPos[0][1];
			}
			else 
			{
				opponent = 'w';
				currRow  = kingPos[1][0];
				currCol = kingPos[1][1];
			}

			int i = currRow;
			int j = currCol;

			while(isValid(i,++j))
			{
				if((grid[i][j])[0] == side) break;
				else if((grid[i][j])[0] == opponent && ((grid[i][j])[1] == 'R' || (grid[i][j])[1] == 'Q')) return true;
			}

			j = currCol;
			while(isValid(++i,j))
			{
				if((grid[i][j])[0] == side) break;
				else if((grid[i][j])[0] == opponent && ((grid[i][j])[1] == 'R' || (grid[i][j])[1] == 'Q')) return true;
			}
			// cout<<"M\n";

			i = currRow; 
			while(isValid(i,--j))
			{
				if((grid[i][j])[0] == side) break;
				else if((grid[i][j])[0] == opponent && ((grid[i][j])[1] == 'R' || (grid[i][j])[1] == 'Q')) return true;
			}

			j = currCol; 
			while(isValid(--i,j))
			{
				if((grid[i][j])[0] == side) break;
				else if((grid[i][j])[0] == opponent && ((grid[i][j])[1] == 'R' || (grid[i][j])[1] == 'Q')) return true;
			}

			return false;
		}

		//Function to check if the king is in check by a horse
		bool util_horse_check_king(vector<vector<std::string>> &grid,const char &side, vector<vector<int>> &kingPos)
		{
			char opponent;
			int currRow,currCol;
		//  cout<<"c\n";

			if(side == 'w') 
			{
				opponent = 'b';
				currRow  = kingPos[0][0];
				currCol = kingPos[0][1];
			}
			else 
			{
				opponent = 'w';
				currRow  = kingPos[1][0];
				currCol = kingPos[1][1];
			}

			int i = currRow;
			int j = currCol;

			int arr[8] = {1,2,-1,-2,-1,2,1,-2};
			for(int k = 0, l = 1 ; k<8 ; k += 2,l += 2)
			{
				if(isValid(i+arr[k],j+arr[l]) && (grid[i+arr[k]][j+arr[l]])[1] == 'H' && (grid[i+arr[k]][j+arr[l]])[0] == opponent) return true;
				else if(isValid(i+arr[l],j+arr[k]) && (grid[i+arr[l]][j+arr[k]])[1] == 'H' && (grid[i+arr[l]][j+arr[k]])[0] == opponent) return true;
			}

			return false;
		}
	}
}
