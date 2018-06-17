#include "stdafx.h"
#include "LetterSearcherIntegrationTests.h"
#include "TestBoardGen.h"
#include "LetterSearcher.h"

LetterSearcherIntegrationTests::LetterSearcherIntegrationTests() 
{
}


bool LetterSearcherIntegrationTests::VectorsAreIdentical(std::vector<LetterCoordinates> expected, std::vector<LetterCoordinates> actual)
{
	auto areIdentical =  true;

	for (size_t i = 0; i < expected.size(); i++)
	{
		if (expected[i].Letter != actual[i].Letter)
		{
			areIdentical = false;
			ADD_FAILURE() << "The expected letter: " << expected[i].Letter << " does not match the actual: " << actual[i].Letter;
		}
		if (expected[i].X != actual[i].X)
		{
			areIdentical = false;
			ADD_FAILURE() << "Letter: " << expected[i].Letter << ". The expected X: " << expected[i].X << " does not match the actual X: " << actual[i].X;
		}
		if (expected[i].Y != actual[i].Y)
		{
			areIdentical = false;
			ADD_FAILURE() << "Letter: " << expected[i].Letter << ". The expected Y: " << expected[i].Y << " does not match the actual Y: " << actual[i].Y;
		}
	}

	return areIdentical;
}

LetterSearcherIntegrationTests::~LetterSearcherIntegrationTests()
{
}

TEST_P(LetterSearcherIntegrationTests, FindPatternOnBoard)
{
	BoardHelper boardHelper;
	auto boardUnderTest = std::get<0>(GetParam());
	auto searchedPattern = std::get<1>(GetParam());
	auto expectedResVector = std::get<2>(GetParam());

	LetterSearcher letterSearcher(boardHelper, boardUnderTest, searchedPattern);

	auto searchRes = letterSearcher.FindPattern();

	ASSERT_TRUE(searchRes);

	auto actualResVector = letterSearcher.GetCoordinates();

	ASSERT_EQ(expectedResVector.size(), actualResVector.size());

	ASSERT_TRUE(VectorsAreIdentical(expectedResVector, actualResVector));
};

INSTANTIATE_TEST_CASE_P(FindPatternIntegrationTest,
	LetterSearcherIntegrationTests,
	::testing::Values(
		TestBoardGen::GetBoardWithPattern(6, 6, "test", std::vector<LetterCoordinates> { LetterCoordinates('t', 0, 0), LetterCoordinates('e', 0, 1), LetterCoordinates('s', 0, 2), LetterCoordinates('t', 0, 3) }),
		TestBoardGen::GetBoardWithPattern(6, 6, "test", std::vector<LetterCoordinates> { LetterCoordinates('t', 1, 0), LetterCoordinates('e', 2, 0), LetterCoordinates('s', 3, 0), LetterCoordinates('t', 4, 0) }),
		TestBoardGen::GetBoardWithPattern(6, 6, "adidas", std::vector<LetterCoordinates> { LetterCoordinates('a', 3, 0), LetterCoordinates('d', 4, 0), LetterCoordinates('i', 5, 0), LetterCoordinates('d', 5, 1), LetterCoordinates('a', 5, 2), LetterCoordinates('s', 5, 3) }),
		TestBoardGen::GetBoardWithPattern(5, 6, "adidas", std::vector<LetterCoordinates> { LetterCoordinates('a', 3, 0), LetterCoordinates('d', 2, 0), LetterCoordinates('i', 1, 0), LetterCoordinates('d', 1, 1), LetterCoordinates('a', 1, 2), LetterCoordinates('s', 1, 3) }),
		TestBoardGen::GetBoardWithPattern(5, 6, "adidasyda", std::vector<LetterCoordinates> { LetterCoordinates('a', 3, 2), LetterCoordinates('d', 2, 2), LetterCoordinates('i', 1, 2), LetterCoordinates('d', 1, 1), LetterCoordinates('a', 1, 0), LetterCoordinates('s', 2, 0), LetterCoordinates('y', 2, 1), LetterCoordinates('d', 3, 1), LetterCoordinates('a', 3, 0)})
	));

