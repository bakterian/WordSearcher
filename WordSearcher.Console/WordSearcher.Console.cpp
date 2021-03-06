// WordSearcher.Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestBoardGen.h"
#include "BoardCmdPrinter.h"
#include "BoardHelper.h"
#include "LetterSearcher.h"

int main()
{
	BoardCmdPrinter boardPrinter;
	BoardHelper boardHelper;

	auto testBoardTuple = TestBoardGen::GetBoardWithPattern(
		6, 6, "adidasyda", std::vector<LetterCoordinates>
	{ LetterCoordinates('a', 3, 2),
		LetterCoordinates('d', 2, 2),
		LetterCoordinates('i', 1, 2),
		LetterCoordinates('d', 1, 1),
		LetterCoordinates('a', 1, 0),
		LetterCoordinates('s', 2, 0),
		LetterCoordinates('y', 2, 1),
		LetterCoordinates('d', 3, 1),
		LetterCoordinates('a', 3, 0)});

	auto testBoard = std::get<0>(testBoardTuple);
	auto serchPattern = std::get<1>(testBoardTuple);
	auto patternCoorindates = std::get<2>(testBoardTuple);

	std::cout << "Searching for the pattern: " << serchPattern << std::endl;
	std::cout << std::endl << "Pattern placement in table: " << std::endl;
	boardPrinter.AddSearchPatternToStream(std::cout, testBoard, patternCoorindates);
	std::cout << "Filled table: " << std::endl;
	boardPrinter.AddBoardToStream(std::cout, testBoard);

	LetterSearcher letterSearcher(boardHelper, testBoard, serchPattern);

	auto foundPattern = letterSearcher.FindPattern();
	auto resCoordinates = letterSearcher.GetCoordinates();
	
	if (foundPattern)
	{
		std::cout << "Pattern was found !!!" << std::endl;
		boardPrinter.AddSearchPatternToStream(std::cout, testBoard, resCoordinates);
	}
	else
	{
		std::cout << "Pattern was not found !!!" << std::endl << std::endl;
	}
	std::cout << boardHelper.GetStats() << std::endl;

	system("pause");
    return 0;
}

