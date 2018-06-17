#pragma once
#include "gtest/gtest.h"
#include "LetterBoard.h"
#include <map>

class BoardHelperTests : public ::testing::Test
{
public:
	BoardHelperTests();

	~BoardHelperTests();

	virtual void SetUp();

	virtual void TearDown();

protected:
	const char* gSearchPattern;
	int gBoardWidth;
	int gBoardHeight;
	char** gLetterArray;
	std::map<char, int> gPatternLettersMap;
	LetterBoard gDummyBoard;
	void fillLetterBoard();
};

