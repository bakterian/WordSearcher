#pragma once
#include "stdafx.h"
#include "LetterCoordinates.h"
#include "LetterBoard.h"
#include "BoardHelper.h"

class LetterSearcher
{
public:
	int PatternLenght;

	LetterSearcher(BoardHelper& rBoardHelper, LetterBoard& rBoard, const char* letterPattern);

	// Direct pattern search
	//1. Search for first char.
	//2. When found add it to a std::vector<LetterCoordinate> coordiantes list.
	//3. move to new nodes if the are in range (x+1 || x-1 || y-1 || y+1) AND the new node must match letterPattern+1.
	//4  Ingore if the node is already a patr of the search tree
	//5. Add the coordinate to the list and repeat step 3 
	//6. Either we will find all letters or we run out of move options. If case of the latter go back to 1.
	bool FindPattern();

	// Tree Creation strategy
	//1. iterate starting from 0,0 (starting Node)
	//2. move to new nodes if the are in range (x+1 || x-1 || y-1 || y+1) and not alredy in the tree
	//3. Create a multpile linked list TreeNode { LetterCoordinates coor; std::vector<*TreeNode> NextNodes; }
	//4. Perform a depth search looking for coordiante match
	bool FindPatternInTree();

	std::vector<LetterCoordinates> GetCoordinates() const;

	~LetterSearcher();

private:
	BoardHelper& gBoardHelper; //!!! a refernce memeber must be used, as we access this one directly for checking statistics
	std::vector<LetterCoordinates> gFoundCoordinates;
	LetterBoard gBoard;
	const char* gpLetterPattern;
};

