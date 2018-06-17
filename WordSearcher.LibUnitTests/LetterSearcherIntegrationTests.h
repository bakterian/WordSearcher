#pragma once
#include "gtest\gtest.h"
#include "LetterBoard.h"
#include "LetterCoordinates.h"

class LetterSearcherIntegrationTests : public ::testing::TestWithParam<std::tuple<LetterBoard,const char*,std::vector<LetterCoordinates>>>
{
public:

	LetterSearcherIntegrationTests();

	bool VectorsAreIdentical(std::vector<LetterCoordinates> expected, std::vector<LetterCoordinates> actual);

	~LetterSearcherIntegrationTests();
};

