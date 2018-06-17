#pragma once
#include "BoardHelper.h"
#include "gmock\gmock.h"

class BoardHelperMock : public BoardHelper
{
public:
	BoardHelperMock();
	~BoardHelperMock();
	MOCK_METHOD1(getLenght, int(const char* letterPattern));
	MOCK_METHOD3(isWithinBounds, bool(LetterBoard board, int x, int y));
	MOCK_METHOD2(getAllMatchingLetters, std::vector<LetterCoordinates>(LetterBoard board, char searchedLetter));
	MOCK_METHOD3(getAllMatchLettersInNeighbourhood, std::vector<LetterCoordinates>(LetterBoard board, LetterCoordinates coor, char searchedLetter));
	MOCK_METHOD4(findMatchingPattern, void(LetterBoard board, LetterCoordinates startCoor, const char* searchedPattern, std::vector<LetterCoordinates>& prevLetters));
	MOCK_CONST_METHOD0(GetStats, BoardHelperStats());
};

