
#include "Pose2d.h"
#include "Angle.h"
#include "Point2d.h"

#include <gtest/gtest.h>

namespace {

using starsky::Pose2d;

TEST(Pose2dTest, Constructors) {
  // default constructor
  Pose2d p;
  EXPECT_FLOAT_EQ(0.0f, p.getX());
  EXPECT_FLOAT_EQ(0.0f, p.getY());
  EXPECT_FLOAT_EQ(0.0f, p.getTheta());

  // setting constructor
  Pose2d p1(1.0f, 2.0f, 3.0f);
  EXPECT_FLOAT_EQ(1.0f, p1.getX());
  EXPECT_FLOAT_EQ(2.0f, p1.getY());
  EXPECT_FLOAT_EQ(3.0f, p1.getTheta());

  // copy constructor
  Pose2d p2(p1);
  EXPECT_FLOAT_EQ(1.0f, p2.getX());
  EXPECT_FLOAT_EQ(2.0f, p2.getY());
  EXPECT_FLOAT_EQ(3.0f, p2.getTheta());

  starsky::Point2d a(1.0f, 1.0f);
  starsky::Angle theta(2.0f);
  Pose2d p3(a, theta);
  EXPECT_FLOAT_EQ(1.0f, p3.getX());
  EXPECT_FLOAT_EQ(1.0f, p3.getY());
  EXPECT_FLOAT_EQ(2.0f, p3.getTheta());

  // assignment operator
  p = p2;
  EXPECT_FLOAT_EQ(1.0f, p.getX());
  EXPECT_FLOAT_EQ(2.0f, p.getY());
  EXPECT_FLOAT_EQ(3.0f, p.getTheta());
}

TEST(Pose2dTest, Comparision) {
  Pose2d a(1.0f, 2.0f, 0.0f), b(2.0f, 3.0f, 0.0f);
  EXPECT_NE(a, b);

  b = a;
  EXPECT_EQ(a, b);
}

}  // anonymous namespace
