#pragma once
#include "LetterSearcher.h"
#include "BoardHelperMock.h"
#include "gtest/gtest.h"

class LetterSearcherTests : public testing::Test
{
public:
	LetterSearcherTests();
	~LetterSearcherTests();
	virtual void SetUp();
	virtual void TearDown();
	static void fillWithCorrectPattern(LetterBoard board, LetterCoordinates startCoor, const char* searchedPattern, std::vector<LetterCoordinates>& prevLetters);
	static void fillWithIncorrectPattern(LetterBoard board, LetterCoordinates startCoor, const char* searchedPattern, std::vector<LetterCoordinates>& prevLetters);
protected:
	BoardHelperMock gBoardHelperMock;
	const char* gDummyPattern;
	LetterBoard gDummyBoard;
};

