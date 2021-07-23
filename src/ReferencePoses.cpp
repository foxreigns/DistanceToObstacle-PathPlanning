#include "ReferencePoses.h"

#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <math.h>
#include "FrenetPoint.h"
#include "Segment2d.h"
#include "Vector2d.h"
#include "Params.h"
#include "float.h"

namespace starsky
{

ReferencePoses::ReferencePoses(const std::vector<Pose2d> &poses) : referencePoses_(poses)
{
}

ReferencePoses::~ReferencePoses() {}

Params calculateParams(const Pose2d &startPose, const Pose2d &endPose, const Pose2d &testPose)
{
	Vector2d p1p2(startPose.getPoint(), endPose.getPoint());
	Vector2d p1p(startPose.getPoint(), testPose.getPoint());
	Vector2d p2p(endPose.getPoint(), testPose.getPoint());
	Vector2d p1pclosest(p1p2); // vector from startPose to the closest point on the line segment from the obstacle using copy constructor
	p1pclosest *(p1p.dot(p1p2) / (pow(p1p2.norm(), 2)));

	Params ret;
	ret.perpDist_ = (p1p - p1pclosest).norm();
	ret.euclidDist_ = p1p2.norm();
	ret.projDist_ = p1pclosest.norm();
	ret.bLyingOut_ = false;
	float remDist = (p2p - (p1p - p1pclosest)).norm();

	if (ret.projDist_ > ret.euclidDist_ || remDist > ret.euclidDist_)
	{
		
		if (p1p.norm() < p2p.norm())
		{
			ret.perpDist_ = p1p.norm();
			ret.projDist_ = 0;
		}
		else
		{
			ret.bLyingOut_ = true;
			ret.perpDist_ = p2p.norm();
			ret.projDist_ = ret.euclidDist_;
		}
	}

	return ret;
}

boost::optional<FrenetPoint>
ReferencePoses::computeSDAfter(const Pose2d &p, float referenceDistance) const
{
	float cumSum = 0.0; // cumulative euclidean distances
	float closestDist = FLT_MAX;
	int currFrenetIdx = 0; // index of the candidate Frenet point
	float currentS = -1.0; // distance along the curve for the current iteration
	float S = -1.0;
	float D = -1.0;
	bool bFound = false;
	bool bLyingOut = false;
	for (int i = 0; i < referencePoses_.size() - 1; i++)
	{
		Params currParams = calculateParams(referencePoses_[i], referencePoses_[i + 1], p);		
		if (currParams.perpDist_ < closestDist)
		{
			bLyingOut = currParams.bLyingOut_;
			closestDist = currParams.perpDist_;
			currFrenetIdx = i;
			S = cumSum + currParams.projDist_;
			D = currParams.perpDist_;
			bFound = true;
		}
			
		cumSum += currParams.euclidDist_;
	}

	boost::optional<FrenetPoint> val;
	if (bFound && S > referenceDistance)
	{	
		
		if (bLyingOut && currFrenetIdx != referencePoses_.size()-1)
			currFrenetIdx += 1;

		// switching the sign of D if it is to the left of the curve
		if (atan2(p.getY() - referencePoses_[currFrenetIdx].getY(), p.getX() - referencePoses_[currFrenetIdx].getX()) - referencePoses_[currFrenetIdx].getTheta() > 0.0)
			D = -1 * D;

		val = FrenetPoint(S, D);
	}

	return val;
}

} // namespace starsky
