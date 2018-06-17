#include "stdafx.h"
#include "LetterSearcher.h"

LetterSearcher::LetterSearcher(BoardHelper& rBoardHelper, LetterBoard& rBoard, const char* letterPattern):
	gBoard(rBoard),
	gpLetterPattern(letterPattern),
	gBoardHelper(rBoardHelper)
{
	PatternLenght = rBoardHelper.getLenght(letterPattern);
}


bool LetterSearcher::FindPattern()
{
	bool foundPattern = false;
	if (PatternLenght > 0)
	{
		auto firstLetterCoordinates = gBoardHelper.getAllMatchingLetters(gBoard,gpLetterPattern[0]);

		for (int i = 0; i < (int)firstLetterCoordinates.size(); ++i)
		{
			std::vector<LetterCoordinates> matchedNeigbours;
			gBoardHelper.findMatchingPattern(gBoard, firstLetterCoordinates[i], gpLetterPattern, matchedNeigbours);

			if (matchedNeigbours.size() == PatternLenght)
			{
				foundPattern = true;
				gFoundCoordinates = matchedNeigbours;
				break;
			}
		}
	}

	return foundPattern;
}

bool LetterSearcher::FindPatternInTree()
{
	return false;
}

std::vector<LetterCoordinates> LetterSearcher::GetCoordinates() const
{
	return gFoundCoordinates;
}

LetterSearcher::~LetterSearcher()
{
}
