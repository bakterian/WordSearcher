#pragma once
struct LetterBoard
{
	char** LetterArray;
	int MaxX;
	int MaxY;

	LetterBoard(char** letterArray, int maxX, int maxY) :
		LetterArray(letterArray),
		MaxX(maxX),
		MaxY(maxY)
	{
	}

	friend bool operator== (const LetterBoard &b1, const LetterBoard &b2)
	{
		return LetterBoard::AreTheSameBoards(b1,b2);
	}

	friend bool operator!= (const LetterBoard &b1, const LetterBoard &b2)
	{
		return !(b1 == b2);
	}

	bool static AreTheSameBoards(const LetterBoard &b1, const LetterBoard &b2)
	{
		bool isTheSame = false;

		if ((b1.MaxX == b2.MaxX) && (b1.MaxY == b1.MaxY))
		{
			bool isTheSameArray = true;
			for (int x = 0; x <= b1.MaxX; ++x)
			{
				for (int y = 0; y <= b1.MaxY; ++y)
				{
					if (b1.LetterArray[x][y] != b2.LetterArray[x][y])
					{
						isTheSameArray = false;
						break;
					}
				}
			}
			isTheSame = isTheSameArray;
		}

		return isTheSame;
	}

};

