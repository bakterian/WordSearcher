#include "stdafx.h"
#include "LetterSearcherTests.h"
#include "TestBoardGen.h"
#include "BoardHelperMock.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using ::testing::AtLeast;   
using ::testing::Return;
using ::testing::Invoke;
using ::testing::InSequence;
using ::testing::_;

std::vector<LetterCoordinates> ggPatternCoordinates;

LetterSearcherTests::LetterSearcherTests():
	gDummyBoard(NULL,0,0)
{

}

LetterSearcherTests::~LetterSearcherTests()
{
}

void LetterSearcherTests::SetUp()
{
	auto boardTestBundle = TestBoardGen::GetBoardWithPattern(6, 6, "test", std::vector<LetterCoordinates> { LetterCoordinates('t', 4, 0), LetterCoordinates('e', 4, 1), LetterCoordinates('s', 4, 2), LetterCoordinates('t', 4, 3) });
	gDummyBoard = std::get<0>(boardTestBundle);
	gDummyPattern = std::get<1>(boardTestBundle);
	ggPatternCoordinates = std::get<2>(boardTestBundle);
}

void LetterSearcherTests::TearDown()
{

}

void LetterSearcherTests::fillWithCorrectPattern(LetterBoard board, LetterCoordinates startCoor, const char * searchedPattern, std::vector<LetterCoordinates>& prevLetters)
{
	prevLetters = ggPatternCoordinates;
}

void LetterSearcherTests::fillWithIncorrectPattern(LetterBoard board, LetterCoordinates startCoor, const char * searchedPattern, std::vector<LetterCoordinates>& prevLetters)
{
	prevLetters = ggPatternCoordinates;
	prevLetters.resize(2);
}

TEST_F(LetterSearcherTests, ShouldAskAboutThePatternLenght)
{
	EXPECT_CALL(gBoardHelperMock, getLenght).Times(1);

	LetterSearcher letterSearcher(gBoardHelperMock, gDummyBoard, gDummyPattern);
}

TEST_F(LetterSearcherTests, ShouldNotStartTheSearchWhenPatternLengthIsZero)
{
	EXPECT_CALL(gBoardHelperMock, getLenght)
				.Times(1) //this can be actually inferred form the number of will once calls.
				.WillOnce(Return(0));

	LetterSearcher letterSearcher(gBoardHelperMock, gDummyBoard, gDummyPattern);

	EXPECT_CALL(gBoardHelperMock, getAllMatchingLetters).Times(0);

	auto wasPatternFound = letterSearcher.FindPattern();

	ASSERT_FALSE(wasPatternFound);
}

TEST_F(LetterSearcherTests, ShouldAskAboutThePossibleStartingPostions)
{
	EXPECT_CALL(gBoardHelperMock, getLenght).WillOnce(Return(4));

	LetterSearcher letterSearcher(gBoardHelperMock, gDummyBoard, gDummyPattern);

	std::vector<LetterCoordinates> emptyResult;
	char expectedStartChar = 't';
	EXPECT_CALL(gBoardHelperMock, getAllMatchingLetters(gDummyBoard, expectedStartChar)).Times(1).WillOnce(Return(emptyResult));

	auto wasPatternFound = letterSearcher.FindPattern();

	ASSERT_FALSE(wasPatternFound);
}


TEST_F(LetterSearcherTests, ShouldFindTheMatchingPattern)
{
	EXPECT_CALL(gBoardHelperMock, getLenght).WillOnce(Return(4));

	LetterSearcher letterSearcher(gBoardHelperMock, gDummyBoard, gDummyPattern);

	std::vector<LetterCoordinates> startingPostions = { LetterCoordinates('t',0,0), LetterCoordinates('t',1,0) , LetterCoordinates('t',1,1), LetterCoordinates('t', 4, 0) };
	char expectedStartChar = 't';

	EXPECT_CALL(gBoardHelperMock, getAllMatchingLetters(gDummyBoard, expectedStartChar)).WillOnce(Return(startingPostions));

	InSequence s;

	EXPECT_CALL(gBoardHelperMock, findMatchingPattern(gDummyBoard, LetterCoordinates('t', 0, 0), gDummyPattern, _));
	EXPECT_CALL(gBoardHelperMock, findMatchingPattern(gDummyBoard, LetterCoordinates('t', 1, 0), gDummyPattern, _)).WillOnce(Invoke(LetterSearcherTests::fillWithIncorrectPattern));
	EXPECT_CALL(gBoardHelperMock, findMatchingPattern(gDummyBoard, LetterCoordinates('t', 1, 1), gDummyPattern, _));
	EXPECT_CALL(gBoardHelperMock, findMatchingPattern(gDummyBoard, LetterCoordinates('t', 4, 0), gDummyPattern, _)).WillOnce(Invoke(LetterSearcherTests::fillWithCorrectPattern));

	auto wasPatternFound = letterSearcher.FindPattern();

	ASSERT_TRUE(wasPatternFound);
}