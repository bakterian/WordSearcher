#pragma once
#include "stdafx.h"
#include "BoardHelperStats.h"
#include "LetterCoordinates.h"
#include "LetterBoard.h"

class BoardHelper
{
public:
	BoardHelper();

	virtual int getLenght(const char* letterPattern);

	virtual bool isWithinBounds(LetterBoard board, int x, int y);

	virtual std::vector<LetterCoordinates> getAllMatchingLetters(LetterBoard board, char searchedLetter);

	virtual std::vector<LetterCoordinates> getAllMatchLettersInNeighbourhood(LetterBoard board, LetterCoordinates coor, char searchedLetter);

	virtual void findMatchingPattern(LetterBoard board, LetterCoordinates startCoor, const char* searchedPattern, std::vector<LetterCoordinates>& prevLetters);

	virtual ~BoardHelper();

	virtual BoardHelperStats GetStats() const;
private:
	BoardHelperStats stats;
};

