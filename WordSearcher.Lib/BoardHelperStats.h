#pragma once

typedef enum
{
	isWithinBounds,
	getNeigbourMatche,
	findMatchingPatter,
	other
}CallerFunction;

class BoardHelperStats
{
public:
	BoardHelperStats();
	BoardHelperStats(const BoardHelperStats& bh);
	BoardHelperStats& operator=(const BoardHelperStats& bh);
	~BoardHelperStats();
	void ResetStatistics();
	void ReportCall(CallerFunction fromFunction);
	friend std::ostream& operator<<(std::ostream & str, BoardHelperStats const & bf);

private:
	void CopyValues(const BoardHelperStats& bh);
	int gIsWithinBoundsCalls;
	int gGetNeigbourMatchesCalls;
	int gFindMatchingPatternCalls;
};

