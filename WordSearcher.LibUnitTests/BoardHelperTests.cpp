#include "stdafx.h"
#include "BoardHelperTests.h"
#include "BoardHelper.h"
#include <algorithm>


BoardHelperTests::BoardHelperTests() :
gDummyBoard(NULL,0,0),
gBoardHeight(6),
gBoardWidth(6),
gSearchPattern("test")
{

}

BoardHelperTests::~BoardHelperTests()
{
}

void BoardHelperTests::SetUp()
{
	gLetterArray = new char*[gBoardWidth];

	for (int i = 0; i < gBoardWidth; i++)
	{
		gLetterArray[i] = new char[gBoardHeight];
	}

	fillLetterBoard();

	gDummyBoard = LetterBoard(gLetterArray, gBoardWidth - 1, gBoardHeight - 1);
}

void BoardHelperTests::TearDown()
{
	for (int i = 0; i < gBoardHeight; i++)
	{
		delete[] gLetterArray[i];
	}

	delete[] gLetterArray;
}

void BoardHelperTests::fillLetterBoard()
{
	for (size_t i = 0; i < strlen(gSearchPattern); i++)
	{
		gPatternLettersMap[gSearchPattern[i]] = 0;
	}

	for (int i = 0; i < gBoardWidth; ++i)
	{
		auto pBoardCol = gLetterArray[i];

		auto swapIndex = i % std::min((int)strlen(gSearchPattern), gBoardHeight);
		auto swapLetter = gSearchPattern[swapIndex];

		for (int j = 0; j < gBoardHeight; ++j)
		{
			pBoardCol[j] = (j == swapIndex) ? swapLetter : (char)(97u + j);

			auto it = gPatternLettersMap.find(pBoardCol[j]);

			if (it != gPatternLettersMap.end())
			{
				gPatternLettersMap[pBoardCol[j]] = gPatternLettersMap[pBoardCol[j]] + 1;
			}
		}
	}
}

TEST_F(BoardHelperTests, ReturnsProperLength)
{
	const char* measuredCstring = "test";
	int expectedLength = 4;

	BoardHelper helper;

	auto actualLength = helper.getLenght(measuredCstring);

	ASSERT_EQ(actualLength, expectedLength);
}

TEST_F(BoardHelperTests, CheckBoundriesMethod)
{
	BoardHelper helper;

	EXPECT_FALSE(helper.isWithinBounds(gDummyBoard, 0, 8));
	EXPECT_FALSE(helper.isWithinBounds(gDummyBoard, 9, 0));
	EXPECT_FALSE(helper.isWithinBounds(gDummyBoard, 20, 20));

	EXPECT_FALSE(helper.isWithinBounds(gDummyBoard, -1, 0));
	EXPECT_FALSE(helper.isWithinBounds(gDummyBoard, 0, -8));
	EXPECT_FALSE(helper.isWithinBounds(gDummyBoard, -9, -8));

	EXPECT_TRUE(helper.isWithinBounds(gDummyBoard, 0, 0));
	EXPECT_TRUE(helper.isWithinBounds(gDummyBoard, 5, 5));
	EXPECT_TRUE(helper.isWithinBounds(gDummyBoard, 2, 4));
}

TEST_F(BoardHelperTests, ShouldReturnAllMatchingLettersFromBoard)
{
	BoardHelper helper;

	int paternLen = strlen(gSearchPattern);

	for (int i = 0; i < paternLen; i++)
	{
		auto searchedLetter = gSearchPattern[i];
		auto letterVec = helper.getAllMatchingLetters(gDummyBoard, searchedLetter);
		EXPECT_EQ(letterVec.size(), gPatternLettersMap[searchedLetter]);
	}
}

TEST_F(BoardHelperTests, ShouldReturnAllMatchingLettersInNeighbourhoodHorizontalPlacement)
{
	BoardHelper helper;

	gLetterArray[0][0] = gSearchPattern[0];
	gLetterArray[1][0] = gSearchPattern[1];
	gLetterArray[2][0] = gSearchPattern[2];
	gLetterArray[3][0] = gSearchPattern[3];

	auto paternLen = strlen(gSearchPattern);

	for (int i = 0; i < 3; i++)
	{
		LetterCoordinates coor(gSearchPattern[i], i, 0);
		auto letterVec = helper.getAllMatchLettersInNeighbourhood(gDummyBoard, coor, gSearchPattern[i+1]);
		EXPECT_EQ(1, letterVec.size());
	}
}

TEST_F(BoardHelperTests, ShouldReturnAllMatchingLettersInNeighbourhoodVertiacalPlacement)
{
	BoardHelper helper;

	gLetterArray[1][0] = gSearchPattern[0];
	gLetterArray[1][1] = gSearchPattern[1];
	gLetterArray[1][2] = gSearchPattern[2];
	gLetterArray[1][3] = gSearchPattern[3];

	auto paternLen = strlen(gSearchPattern);

	for (int i = 0; i < 3; i++)
	{
		LetterCoordinates coor(gSearchPattern[i], 1, i);
		auto letterVec = helper.getAllMatchLettersInNeighbourhood(gDummyBoard, coor, gSearchPattern[i + 1]);
		EXPECT_EQ(1, letterVec.size()) << "Failed in finding the neighbour: " << gSearchPattern[i + 1] << ", of: " << gSearchPattern[i];
	}
}

TEST_F(BoardHelperTests, ShouldReturnAllMatchingLettersInNeighbourhoodLshapedPlacement)
{
	BoardHelper helper;

	gLetterArray[0][0] = gSearchPattern[0];
	gLetterArray[1][0] = gSearchPattern[1];
	gLetterArray[1][1] = gSearchPattern[2];
	gLetterArray[1][2] = gSearchPattern[3];

	std::vector<std::tuple<int, int>> coorList;
	coorList.push_back(std::make_tuple(0, 0));
	coorList.push_back(std::make_tuple(1, 0));
	coorList.push_back(std::make_tuple(1, 1));
	coorList.push_back(std::make_tuple(1, 2));

	auto paternLen = strlen(gSearchPattern);

	for (int i = 0; i < ((int)coorList.size() - 1); i++)
	{
		auto coorTuple = coorList[i];		
		LetterCoordinates coor(gSearchPattern[i], std::get<1>(coorTuple), std::get<0>(coorTuple));
		auto letterVec = helper.getAllMatchLettersInNeighbourhood(gDummyBoard, coor, gSearchPattern[i + 1]);
		EXPECT_EQ(1, letterVec.size());
	}
}