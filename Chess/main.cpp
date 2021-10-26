#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

#include "header/crucial level 1.h"
#include "header/crucial level 2.h"
#include "header/crucial level 3.h"

int main()
{
	vector<vector<std::string>> grid = {{"bR","bH","bB","bQ","bK","bB","bH","bR"},
										{"bP","bP","bP","bP","bP","bP","bP","bP"},
										{"  ","  ","  ","  ","  ","  ","  ","  "},
										{"  ","  ","  ","  ","  ","  ","  ","  "},
										{"  ","  ","  ","  ","  ","  ","  ","  "},
										{"  ","  ","  ","  ","  ","  ","  ","  "},
										{"wP","wP","wP","wP","wP","wP","wP","wP"},
										{"wR","wH","wB","wQ","wK","wB","wH","wR"}};

	vector<vector<int>> kingPos = {{7,4},{0,4}};

	crl1::display(grid,"White Goes First.");

	bool playing = true;
	char sides[2] = {'w','b'};
	int turn = 0;

	stack<pair<vector<vector<std::string>>, vector<vector<int>>>> previousSet;
	previousSet.push(make_pair(grid,kingPos));

	int rowFrom,colFrom;
	int rowTo,colTo;
	
	bool king_moved[2] = {false, false}; // 0 == white, 1 == black
	bool rook_moved[2][2] = {{false,false},	// 0,0 == white left rook, 0,1 == white right rook
							{false,false}}; // 1,0 == black left rook, 1,1 == black right rook
	while(playing)
	{ 
		cout<<"\nPlayer Turn: "<<(!turn? "WHITE" : "BLACK")<<"\n";
		playing = crl1::input(rowFrom,colFrom,rowTo,colTo);
	 
		if(!playing)
		{
			if(turn == 0) crl1::display(grid,"Player Black Wins!");
			else crl1::display(grid,"Player White Wins!");
			break;
		}

		if(!crl1::isValid(rowFrom,colFrom) || !crl1::isValid(rowTo,colTo)) continue;

		if(!crl3::move_was_made(grid,rowFrom,colFrom,rowTo,colTo,kingPos,sides[turn],king_moved[turn],rook_moved[turn]))
		{
			crl1::display(grid,"Invalid Input!");
			continue;
		}

		if(crl3::isKingInCheck(grid,sides[turn],kingPos))
		{
			grid[rowFrom][colFrom] =  previousSet.top().first[rowFrom][colFrom];
			grid[rowTo][colTo] =  previousSet.top().first[rowTo][colTo];
			kingPos[turn][0] =  previousSet.top().second[turn][0];
			kingPos[turn][1] =  previousSet.top().second[turn][1];

			crl1::display(grid,"Invalid input! King in Check!");
			continue;
		}
		
		crl1::display(grid," ");

		if(crl3::isKingInCheck(grid,sides[(turn+1)%2],kingPos))
		{
			crl1::display(grid,"King in Check!");
		}

		previousSet.pop();
		previousSet.push(make_pair(grid,kingPos));

		turn = (turn + 1)%2;
	}
	return 0;
}