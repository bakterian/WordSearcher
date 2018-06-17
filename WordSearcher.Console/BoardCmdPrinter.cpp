#include "stdafx.h"
#include "BoardCmdPrinter.h"

LetterBoard gBoard(NULL,0,0);
std::vector<LetterCoordinates> gSearchPattern;

char test(int x, int y)
{
	return 'x';
}

int GetLetterCoorIndex(int x, int y, std::vector<LetterCoordinates> letterCoordinates)
{
	int index = -1;

	for (size_t i = 0; i < letterCoordinates.size(); ++i)
	{
		if ((letterCoordinates[i].X == x) && (letterCoordinates[i].Y == y))
		{
			index = i;
			break;
		}
	}

	return index;
}

char GetLetterFromBoard(int x, int y)
{
	return gBoard.LetterArray[x][y];
}

char GetLetterFromPattern(int x, int y)
{
	auto patternId = GetLetterCoorIndex(x, y, gSearchPattern);
	auto let = (patternId != -1) ? gSearchPattern[patternId].Letter : '_';
	return let;
}


BoardCmdPrinter::BoardCmdPrinter()
{
}

std::ostream & BoardCmdPrinter::AddSearchPatternToStream(std::ostream & str, LetterBoard board, std::vector<LetterCoordinates> letterCoordinates)
{
	gSearchPattern = letterCoordinates;
	AddRectangleToStream(str, board.MaxX, board.MaxY, &GetLetterFromPattern);
	return str;
}

std::ostream & BoardCmdPrinter::AddBoardToStream(std::ostream & str, LetterBoard board)
{
	gBoard = board;
	AddRectangleToStream(str, board.MaxX, board.MaxY, &GetLetterFromBoard);
	return str;
}


BoardCmdPrinter::~BoardCmdPrinter()
{
}

void BoardCmdPrinter::AddRectangleToStream(std::ostream & str, int xMax, int yMax, char(*GetSymbol)(int x, int y))
{
	str << ' ';
	AddRepeatedly(str, '-', xMax + 1);
	str << std::endl;
	for (int y = 0; y <= yMax; ++y)
	{
		str << '|';
		for (int x = 0; x <= xMax; ++x)
		{
			str << GetSymbol(x, y);
		}
		str << '|' << std::endl;
	}
	str << ' ';
	AddRepeatedly(str, '-', xMax + 1);
	str << std::endl << std::endl;
}

std::ostream & BoardCmdPrinter::AddRepeatedly(std::ostream & str, char element, int count)
{
	for (int i = 0; i < count; i++)
	{
		str << element;
	}
	
	return str;
}


