#include "stdafx.h"
#include "TestBoardGen.h"


std::tuple<LetterBoard, const char*, std::vector<LetterCoordinates>> TestBoardGen::GetBoardWithPattern(int xSize, int ySize, const char* letterPattern, std::vector<LetterCoordinates> patternCoor)
{
	auto testBoard = CreateTestBoard(xSize, ySize);

	FillBoardWithDummyData(testBoard);

	FillBoardWithPattern(testBoard, patternCoor);

	auto res = std::make_tuple(testBoard, letterPattern, patternCoor);

	return res;
}

TestBoardGen::TestBoardGen()
{
}


TestBoardGen::~TestBoardGen()
{
}


void TestBoardGen::FillBoardWithPattern(LetterBoard& board, std::vector<LetterCoordinates> coordinates)
{
	for (size_t i = 0; i < coordinates.size(); i++)
	{
		auto coor = coordinates[i];
		board.LetterArray[coor.X][coor.Y] = coor.Letter;
	}
}

void TestBoardGen::FillBoardWithDummyData(LetterBoard& board)
{
	for (int y = 0; y <= board.MaxY; ++y)
	{
		for (int x = 0; x <= board.MaxX; ++x)
		{
			board.LetterArray[x][y] = (char)(97u + x);
		}
	}
}

LetterBoard TestBoardGen::CreateTestBoard(int xSize, int ySize)
{
	auto letterArray = new char*[xSize];

	for (int i = 0; i < xSize; i++)
	{
		letterArray[i] = new char[ySize];
	}

	LetterBoard res(letterArray, xSize - 1, ySize - 1);

	return res;
}