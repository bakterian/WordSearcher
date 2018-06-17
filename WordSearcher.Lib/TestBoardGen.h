#pragma once
#include "stdafx.h"
#include "LetterBoard.h"
#include "LetterCoordinates.h"

class TestBoardGen
{
public:
	static std::tuple<LetterBoard, const char*, std::vector<LetterCoordinates>> GetBoardWithPattern(int xMaxVal, int yMaxVal, const char* letterPattern, std::vector<LetterCoordinates> patternCoor);

	TestBoardGen();

	~TestBoardGen();

private:
	static void	FillBoardWithPattern(LetterBoard& board, std::vector<LetterCoordinates> coordinates);
	static void FillBoardWithDummyData(LetterBoard& board);
	static LetterBoard CreateTestBoard(int xMax, int yMin);
};

