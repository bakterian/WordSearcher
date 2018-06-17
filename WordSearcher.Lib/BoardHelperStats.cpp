#include "stdafx.h"
#include "BoardHelperStats.h"


BoardHelperStats::BoardHelperStats():
gIsWithinBoundsCalls(0),
gGetNeigbourMatchesCalls(0),
gFindMatchingPatternCalls(0)
{
}

BoardHelperStats::BoardHelperStats(const BoardHelperStats& bh)
{
	CopyValues(bh);
}
BoardHelperStats & BoardHelperStats::operator=(const BoardHelperStats & bh)
{
	CopyValues(bh);
	return *this;
}


BoardHelperStats::~BoardHelperStats()
{
}

void BoardHelperStats::ResetStatistics()
{
	gIsWithinBoundsCalls = 0;
	gGetNeigbourMatchesCalls = 0;
	gFindMatchingPatternCalls = 0;
}

void BoardHelperStats::ReportCall(CallerFunction fromFunction)
{
	switch (fromFunction)
	{
		case isWithinBounds:
			gIsWithinBoundsCalls++;
			break;
		case getNeigbourMatche:
			gGetNeigbourMatchesCalls++;
			break;
		case findMatchingPatter:
			gFindMatchingPatternCalls++;
			break;
		default:
			break;
	}
}

void BoardHelperStats::CopyValues(const BoardHelperStats & bh)
{
	this->gIsWithinBoundsCalls = bh.gIsWithinBoundsCalls;
	this->gGetNeigbourMatchesCalls = bh.gGetNeigbourMatchesCalls;
	this->gFindMatchingPatternCalls = bh.gFindMatchingPatternCalls;
}

std::ostream & operator<<(std::ostream & str, BoardHelperStats const & bh)
{
	str << "Pattern searching statistics:" << std::endl;
	str << "Asked if the coordinate is within the bounds " << bh.gIsWithinBoundsCalls << " times." << std::endl;
	str << "Asked about matichng coordinate neighbours " << bh.gGetNeigbourMatchesCalls << " times." << std::endl;
	str << "Find matching patter was issued " << bh.gFindMatchingPatternCalls << " times." << std::endl;

	return str;
}
