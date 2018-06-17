#pragma once
struct LetterCoordinates
{
	char Letter;
	int X;
	int Y;

	LetterCoordinates():
		Letter('X'),
		X(0),
		Y(0)
	{
	}

	LetterCoordinates(char letter, int x, int y) :
	Letter(letter),
	X(x),
	Y(y)
	{
	}

	~LetterCoordinates() { };

	friend bool operator== (const LetterCoordinates &c1, const LetterCoordinates &c2)
	{
		return ((c1.Letter == c2.Letter) && (c1.X == c2.X) && (c1.Y == c2.Y));
	}
	friend bool operator!= (const LetterCoordinates &c1, const LetterCoordinates &c2)
	{
		return !(c1 == c2);
	}
};

