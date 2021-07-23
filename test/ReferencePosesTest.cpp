
#include "ReferencePoses.h"
#include "Pose2d.h"
#include <gtest/gtest.h>

#include "FrenetPoint.h"

namespace
{

using ::boost::optional;
using ::starsky::FrenetPoint;
using ::starsky::Pose2d;
using ::starsky::ReferencePoses;

using namespace ::testing;

/**
 * @brief Class to test ReferencePoses.
 *
 */
class ReferencePosesTest : public ::testing::Test
{
public:
	ReferencePosesTest();
	~ReferencePosesTest();

protected:
	ReferencePoses *rp;
	Pose2d testPoint;
};

ReferencePosesTest::ReferencePosesTest() : testPoint(1.5f, 0.5f, 0.0f)
{
	std::vector<Pose2d> poses;

	poses.push_back(Pose2d(0.0f, 0.0f, 0.785f));
	poses.push_back(Pose2d(1.0f, 1.0f, 0.0f));
	poses.push_back(Pose2d(3.0f, 1.0f, 0.0f));
	rp = new ReferencePoses(poses);
}

ReferencePosesTest::~ReferencePosesTest()
{
	delete rp;
}

TEST_F(ReferencePosesTest, computeSDAfterExample_0)
{
	// create a point to receive the results
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testPoint, 0.0f);
	if (sdOptional)
	{
		sd = sdOptional.get();
		EXPECT_NEAR(sqrt(2.0f) + 0.5, sd.s, ReferencePoses::PRECISION);
		EXPECT_NEAR(0.5f, sd.d, ReferencePoses::PRECISION);
	}
	else
		EXPECT_TRUE(false);
}

TEST_F(ReferencePosesTest, computeSDAfterExample_1)
{
	// create a point to receive the results
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testPoint, 1.0f);
	if (sdOptional)
	{
		sd = sdOptional.get();
		EXPECT_NEAR(sqrt(2.0f) + 0.5, sd.s, ReferencePoses::PRECISION);
		EXPECT_NEAR(0.5f, sd.d, ReferencePoses::PRECISION);
	}
	else
		EXPECT_TRUE(false);
}

TEST_F(ReferencePosesTest, computeSDAfterExample_2)
{
	// create a point to receive the results
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testPoint, 2.0f);
	if (sdOptional)
	{
		EXPECT_FALSE(true);
	}
	else
		EXPECT_TRUE(true);
}

// obstacle to the left of the curve example
TEST_F(ReferencePosesTest, computeSDAfterCustomExample_0)
{
	std::vector<Pose2d> poses;
	poses.push_back(Pose2d(1.0f, 1.0f, -0.463f));
	poses.push_back(Pose2d(2.0f, 0.5f, 0.982f));
	poses.push_back(Pose2d(3.0f, 2.0f, -0.785f));
	poses.push_back(Pose2d(4.0f, 1.0f, 1.107f));
	poses.push_back(Pose2d(5.0f, 3.0f, 1.107f));
	rp = new ReferencePoses(poses);
	Pose2d testP(4.0f, 3.0f, 0.0f);
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testP, 1.0f);
	if (sdOptional)
	{
		sd = sdOptional.get();
		EXPECT_NEAR(sqrt(1.25) + sqrt(3.25) + sqrt(2) + sqrt(3.2), sd.s, ReferencePoses::PRECISION);
		EXPECT_NEAR(-sqrt(0.8), sd.d, ReferencePoses::PRECISION);
	}
	else
		EXPECT_TRUE(false);
}

// obstacle on the curve example
TEST_F(ReferencePosesTest, computeSDAfterCustomExample_1)
{
	std::vector<Pose2d> poses;
	poses.push_back(Pose2d(1.0f, 1.0f, -0.463f));
	poses.push_back(Pose2d(2.0f, 0.5f, 0.982f));
	poses.push_back(Pose2d(3.0f, 2.0f, -0.785f));
	poses.push_back(Pose2d(4.0f, 1.0f, 1.107f));
	poses.push_back(Pose2d(5.0f, 3.0f, 1.107f));
	rp = new ReferencePoses(poses);
	Pose2d testP(3.8f, 1.2f, 0.0f);
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testP, 1.0f);
	if (sdOptional)
	{
		sd = sdOptional.get();
		EXPECT_NEAR(sqrt(1.25) + sqrt(3.25) + 0.80 * (sqrt(2)), sd.s, ReferencePoses::PRECISION);
		EXPECT_NEAR(0.0, sd.d, ReferencePoses::PRECISION);
	}
	else
		EXPECT_TRUE(false);
}

// inactive reference distance constraint example
TEST_F(ReferencePosesTest, computeSDAfterCustomExample_2)
{
	std::vector<Pose2d> poses;
	poses.push_back(Pose2d(1.0f, 1.0f, -0.463f));
	poses.push_back(Pose2d(2.0f, 0.5f, 0.982f));
	poses.push_back(Pose2d(3.0f, 2.0f, -0.785f));
	poses.push_back(Pose2d(4.0f, 1.0f, 1.107f));
	poses.push_back(Pose2d(5.0f, 3.0f, 1.107f));
	rp = new ReferencePoses(poses);
	Pose2d testP(1.0f, 0.5f, 0.0f);
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testP, 0.0f);
	if (sdOptional)
	{
		sd = sdOptional.get();
		EXPECT_NEAR(sqrt(0.05), sd.s, ReferencePoses::PRECISION);
		EXPECT_NEAR(sqrt(0.2), sd.d, ReferencePoses::PRECISION);
	}
	else
		EXPECT_TRUE(false);
}

TEST_F(ReferencePosesTest, computeSDAfterCustomExample_3)
{
	std::vector<Pose2d> poses;
	poses.push_back(Pose2d(1.0f, 1.0f, -0.463f));
	poses.push_back(Pose2d(2.0f, 0.5f, 0.982f));
	poses.push_back(Pose2d(3.0f, 2.0f, -0.785f));
	poses.push_back(Pose2d(4.0f, 1.0f, 1.107f));
	poses.push_back(Pose2d(5.0f, 3.0f, 1.107f));
	rp = new ReferencePoses(poses);
	Pose2d testP(4.0f, 0.0f, 0.0f);
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testP, 1.5f);
	if (sdOptional)
	{
		sd = sdOptional.get();
		EXPECT_NEAR(sqrt(1.25) + sqrt(3.25) + sqrt(2), sd.s, ReferencePoses::PRECISION);
		EXPECT_NEAR(1.0, sd.d, ReferencePoses::PRECISION);
	}
	else
		EXPECT_TRUE(false);
}

// "invalid" reference distance example
TEST_F(ReferencePosesTest, computeSDAfterCustomExample_4)
{
	std::vector<Pose2d> poses;
	poses.push_back(Pose2d(1.0f, 1.0f, -0.463f));
	poses.push_back(Pose2d(2.0f, 0.5f, 0.982f));
	poses.push_back(Pose2d(3.0f, 2.0f, -0.785f));
	poses.push_back(Pose2d(4.0f, 1.0f, 1.107f));
	poses.push_back(Pose2d(5.0f, 3.0f, 1.107f));
	rp = new ReferencePoses(poses);
	Pose2d testP(2.5f, 1.0f, 0.0f);
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testP, 5.5f);
	if (sdOptional)
	{
		EXPECT_FALSE(true);
	}
	else
		EXPECT_TRUE(true);
}

// obstacle beyond the final point example
TEST_F(ReferencePosesTest, computeSDAfterCornerExample_1)
{
	std::vector<Pose2d> poses;
	poses.push_back(Pose2d(1.0f, 1.0f, -0.463f));
	poses.push_back(Pose2d(2.0f, 0.5f, 0.982f));
	poses.push_back(Pose2d(3.0f, 2.0f, -0.785f));
	poses.push_back(Pose2d(4.0f, 1.0f, 1.107f));
	poses.push_back(Pose2d(5.0f, 3.0f, 1.107f));
	rp = new ReferencePoses(poses);
	Pose2d testP(8.0f, 3.0f, 0.0f);
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testP, 1.0f);
	if (sdOptional)
	{
		sd = sdOptional.get();
		EXPECT_NEAR(sqrt(1.25) + sqrt(3.25) + sqrt(2) + sqrt(5), sd.s, ReferencePoses::PRECISION);
		EXPECT_NEAR(3, sd.d, ReferencePoses::PRECISION);
	}
	else
		EXPECT_TRUE(false);
}

// obstacle before the first point example
TEST_F(ReferencePosesTest, computeSDAfterCornerExample_2)
{
	std::vector<Pose2d> poses;
	poses.push_back(Pose2d(1.0f, 1.0f, -0.463f));
	poses.push_back(Pose2d(2.0f, 0.5f, 0.982f));
	poses.push_back(Pose2d(3.0f, 2.0f, -0.785f));
	poses.push_back(Pose2d(4.0f, 1.0f, 1.107f));
	poses.push_back(Pose2d(5.0f, 3.0f, 1.107f));
	rp = new ReferencePoses(poses);
	Pose2d testP(0.5f, 0.5f, 0.0f);
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testP, -1.0f);
	if (sdOptional)
	{
		sd = sdOptional.get();
		EXPECT_NEAR(0.0f, sd.s, ReferencePoses::PRECISION);
		EXPECT_NEAR(sqrt(0.5), sd.d, ReferencePoses::PRECISION);
	}
	else
		EXPECT_TRUE(false);
}

// obstacle equidistant from two segments example
TEST_F(ReferencePosesTest, computeSDAfterCornerExample_3)
{
	std::vector<Pose2d> poses;
	poses.push_back(Pose2d(1.0f, 1.0f, -0.463f));
	poses.push_back(Pose2d(2.0f, 1.0f, 0.982f));
	poses.push_back(Pose2d(3.0f, 2.0f, -0.785f));
	poses.push_back(Pose2d(4.0f, 1.0f, 1.107f));
	poses.push_back(Pose2d(5.0f, 3.0f, 1.107f));
	rp = new ReferencePoses(poses);
	Pose2d testP(3.0f, 1.0f, 0.0f);
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testP, 0.0f);
	if (sdOptional)
	{
		sd = sdOptional.get();
		EXPECT_NEAR(1.0 + (0.5 * sqrt(2)), sd.s, ReferencePoses::PRECISION);
		EXPECT_NEAR(0.5 * sqrt(2), sd.d, ReferencePoses::PRECISION);
	}
	else
		EXPECT_TRUE(false);
}

// different set of poses example-1
TEST_F(ReferencePosesTest, computeSDAfterSecondSeriesExample_1)
{
	std::vector<Pose2d> poses;
	poses.push_back(Pose2d(5.0f, 3.0f, -2.819f));
	poses.push_back(Pose2d(3.5f, 2.5f, -0.463f));
	poses.push_back(Pose2d(4.5f, 2.0f, 0.588f));
	poses.push_back(Pose2d(6.0f, 3.0f, 0.588f));

	rp = new ReferencePoses(poses);
	Pose2d testP(3.0f, 2.4f, 0.0f);
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testP, 1.0f);
	if (sdOptional)
	{
		sd = sdOptional.get();
		EXPECT_NEAR(sqrt(2.5), sd.s, ReferencePoses::PRECISION);
		EXPECT_NEAR(sqrt(0.26), sd.d, ReferencePoses::PRECISION);
	}
	else
		EXPECT_TRUE(false);
}

// different set of poses example-2 "invalid"
TEST_F(ReferencePosesTest, computeSDAfterSecondSeriesExample_2)
{
	std::vector<Pose2d> poses;
	poses.push_back(Pose2d(5.0f, 3.0f, -2.819f));
	poses.push_back(Pose2d(3.5f, 2.5f, -0.463f));
	poses.push_back(Pose2d(4.5f, 2.0f, 0.588f));
	poses.push_back(Pose2d(6.0f, 3.0f, 0.588f));

	rp = new ReferencePoses(poses);
	Pose2d testP(5.5f, 4.0f, 0.0f);
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testP, 1.0f);
	if (sdOptional)
	{
		EXPECT_FALSE(true);
	}
	else
		EXPECT_TRUE(true);
}

// obstacle beyond the final point example
TEST_F(ReferencePosesTest, computeSDAftere)
{
	std::vector<Pose2d> poses;
	poses.push_back(Pose2d(1.0f, 1.0f, -0.463f));
	poses.push_back(Pose2d(2.0f, 0.5f, 0.982f));
	poses.push_back(Pose2d(3.0f, 2.0f, -0.785f));
	poses.push_back(Pose2d(4.0f, 1.0f, 1.107f));
	poses.push_back(Pose2d(5.0f, 3.0f, 1.107f));
	rp = new ReferencePoses(poses);
	Pose2d testP(3.0f, 2.5f, 0.0f);
	FrenetPoint sd(0.0f, 0.0f);

	auto sdOptional = rp->computeSDAfter(testP, 1.0f);
	if (sdOptional)
	{
		sd = sdOptional.get();
		EXPECT_NEAR(sqrt(1.25) + sqrt(3.25), sd.s, ReferencePoses::PRECISION);
		EXPECT_NEAR(-0.5, sd.d, ReferencePoses::PRECISION);
	}
	else
		EXPECT_TRUE(false);
}

} // anonymous namespace
