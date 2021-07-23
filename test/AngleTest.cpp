
#include "Angle.h"

#include <gtest/gtest.h>

namespace {

TEST(AngleTest, wrapAngle) {
  EXPECT_FLOAT_EQ(0.0, starsky::Angle::wrap(0.0));
  EXPECT_FLOAT_EQ(1.5, starsky::Angle::wrap(1.5));
  EXPECT_FLOAT_EQ(0.0, starsky::Angle::wrap(2 * M_PI));

  EXPECT_FLOAT_EQ(1.0, starsky::Angle::wrap(2 * M_PI + 1.0));
  EXPECT_FLOAT_EQ(-1.0, starsky::Angle::wrap(-1.0));
  EXPECT_FLOAT_EQ(-1.0, starsky::Angle::wrap(2 * M_PI - 1.0));

  EXPECT_FLOAT_EQ(float(-M_PI + 1.0f), starsky::Angle::wrap(M_PI + 1.0));
  EXPECT_FLOAT_EQ(float(M_PI + 1.0f), starsky::Angle::wrap(M_PI + 1.0, 0.0, 2 * M_PI));
  EXPECT_FLOAT_EQ(1.0, starsky::Angle::wrap(2 * M_PI + 1.0, 0.0, 2 * M_PI));

  EXPECT_FLOAT_EQ(370.0f, starsky::Angle::wrap(370.0f, 0.0f, 720.0f));
  EXPECT_FLOAT_EQ(10.0f, starsky::Angle::wrap(370.0f, 0.0f, 360.0f));
  EXPECT_FLOAT_EQ(350.0f, starsky::Angle::wrap(-10.0f, 0.0f, 360.0f));
}

TEST(AngleTest, constructor) {
  EXPECT_FLOAT_EQ(0.0, starsky::Angle(0.0));
  EXPECT_FLOAT_EQ(1.5, starsky::Angle(1.5));
  EXPECT_FLOAT_EQ(0.0, starsky::Angle(2 * M_PI));

  EXPECT_FLOAT_EQ(1.0, starsky::Angle(2 * M_PI + 1.0));
  EXPECT_FLOAT_EQ(-1.0, starsky::Angle(-1.0));
  EXPECT_FLOAT_EQ(-1.0, starsky::Angle(2 * M_PI - 1.0));
}

TEST(AngleTest, scalarMultiplication) {
  EXPECT_FLOAT_EQ(0.0, 2.0 * starsky::Angle(0.0));
  EXPECT_FLOAT_EQ(3.0, 2.0 * starsky::Angle(1.5));
  EXPECT_FLOAT_EQ(0.0, starsky::Angle(2 * M_PI) * 2.0d);

  EXPECT_FLOAT_EQ(2.0, starsky::Angle(2 * M_PI + 1.0) * 2.0);
  EXPECT_FLOAT_EQ(-2.0, starsky::Angle(-1.0) * 2);
  EXPECT_FLOAT_EQ(-2.0, 2.0 * starsky::Angle(2 * M_PI - 1.0));
}

}  // anonymous namespace
