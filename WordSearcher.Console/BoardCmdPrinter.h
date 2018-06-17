#pragma once
#include "stdafx.h"
#include "LetterCoordinates.h"
#include "LetterBoard.h"

class BoardCmdPrinter
{
public:
	BoardCmdPrinter();
	std::ostream& AddSearchPatternToStream(std::ostream & str, LetterBoard board, std::vector<LetterCoordinates> letterCoordinates);
	std::ostream& AddBoardToStream(std::ostream & str, LetterBoard board);
	~BoardCmdPrinter();

private:
	void AddRectangleToStream(std::ostream & str, int xMax, int yMax, char(*GetSymbol)(int x, int y));
	static int GetLetterCoorIndex(int x, int y, std::vector<LetterCoordinates> letterCoordinates);
	std::ostream& AddRepeatedly(std::ostream & str, char element, int count);
};

