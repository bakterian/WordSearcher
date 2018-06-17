#include "stdafx.h"
#include "BoardHelper.h"

BoardHelper::BoardHelper()
{
}

BoardHelper::~BoardHelper()
{
}

int BoardHelper::getLenght(const char * letterPattern)
{
	return strlen(letterPattern);
}

bool BoardHelper::isWithinBounds(LetterBoard board, int x, int y)
{
	stats.ReportCall(CallerFunction::isWithinBounds);
	return  ((x >= 0) && (x <= board.MaxX) && (y >= 0) && (y <= board.MaxY));
}

std::vector<LetterCoordinates> BoardHelper::getAllMatchingLetters(LetterBoard board, char searchedLetter)
{
	stats.ResetStatistics();
	std::vector<LetterCoordinates> matches;

	for (int x = 0; x <= board.MaxX; x++)
	{
		for (int y = 0; y <= board.MaxY; y++)
		{
			if (board.LetterArray[x][y] == searchedLetter)
			{
				LetterCoordinates newCoor(searchedLetter, x, y);
				matches.push_back(newCoor);
			}
		}
	}

	return matches;
}

std::vector<LetterCoordinates> BoardHelper::getAllMatchLettersInNeighbourhood(LetterBoard board, LetterCoordinates coor, char searchedLetter)
{
	stats.ReportCall(CallerFunction::getNeigbourMatche);

	std::vector<LetterCoordinates> neighbourMatches;
	if (this->isWithinBounds(board, coor.X + 1, coor.Y ) && (board.LetterArray[coor.X + 1][coor.Y] == searchedLetter))
	{
		LetterCoordinates newCoor(searchedLetter, coor.X + 1, coor.Y);
		neighbourMatches.push_back(newCoor);
	}
	if (this->isWithinBounds(board, coor.X - 1, coor.Y) && (board.LetterArray[coor.X - 1][coor.Y] == searchedLetter))
	{
		LetterCoordinates newCoor(searchedLetter, coor.X - 1, coor.Y);
		neighbourMatches.push_back(newCoor);
	}
	if (this->isWithinBounds(board, coor.X, coor.Y + 1) && (board.LetterArray[coor.X][coor.Y + 1] == searchedLetter))
	{
		LetterCoordinates newCoor(searchedLetter, coor.X, coor.Y + 1);
		neighbourMatches.push_back(newCoor);
	}
	if (this->isWithinBounds(board, coor.X, coor.Y - 1) && (board.LetterArray[coor.X][coor.Y - 1] == searchedLetter))
	{
		LetterCoordinates newCoor(searchedLetter, coor.X, coor.Y - 1);
		neighbourMatches.push_back(newCoor);
	}

	return neighbourMatches;
}

void BoardHelper::findMatchingPattern(LetterBoard board, LetterCoordinates startCoor, const char * searchedPattern, std::vector<LetterCoordinates>& prevLetters)
{
	stats.ReportCall(CallerFunction::findMatchingPatter);
	int startIndex = prevLetters.size();
	auto currLetters = prevLetters;
	currLetters.push_back(startCoor);
	auto patternLen = this->getLenght(searchedPattern);
	LetterCoordinates coor(startCoor);

	for (int i = startIndex; (i < patternLen - 1) && (currLetters.size() != patternLen); i++)
	{
		auto letterVec = this->getAllMatchLettersInNeighbourhood(board, coor, searchedPattern[i + 1]);

		if (letterVec.size() > 1 )
		{
			for (size_t j = 0; j < letterVec.size(); j++)
			{
				if (std::find(currLetters.begin(), currLetters.end(), letterVec[j]) != currLetters.end())
				{ //skip if alredy on the list
					continue;
				}

				this->findMatchingPattern(board, letterVec[j], searchedPattern, currLetters);

				if (currLetters.size() == patternLen)
				{//reached the end
					break;
				}
			}
		}
		else if ((letterVec.size() > 0) &&
			(std::find(currLetters.begin(), currLetters.end(), letterVec[0]) == currLetters.end()))
		{
			currLetters.push_back(letterVec[0]);
			coor = letterVec[0];
		}
		else
		{
			break;
		}
	}

	if (currLetters.size() == patternLen)
	{//reached the end, copy the vector
		prevLetters = currLetters;
	}
}


BoardHelperStats BoardHelper::GetStats() const
{
	return stats;
}