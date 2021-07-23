
#include "Point2d.h"

#include <gtest/gtest.h>

namespace {

using starsky::Point2d;

TEST(Point2dTest, Constructors) {
  // default constructor
  Point2d p;
  EXPECT_FLOAT_EQ(0.0f, p.getX());
  EXPECT_FLOAT_EQ(0.0f, p.getY());

  // setting constructor
  Point2d p1(1.0f, 2.0f);
  EXPECT_FLOAT_EQ(1.0f, p1.getX());
  EXPECT_FLOAT_EQ(2.0f, p1.getY());

  // copy constructor
  Point2d p2(p1);
  EXPECT_FLOAT_EQ(1.0f, p2.getX());
  EXPECT_FLOAT_EQ(2.0f, p2.getY());

  // assignment operator
  p = p2;
  EXPECT_FLOAT_EQ(1.0f, p.getX());
  EXPECT_FLOAT_EQ(2.0f, p.getY());
}

TEST(Point2dTest, Comparision) {
  Point2d a(1.0f, 2.0f), b(2.0f, 3.0f);
  EXPECT_NE(a, b);

  b = a;
  EXPECT_EQ(a, b);
}

TEST(Point2dTest, Multiplication) {
  Point2d a(1.0f, 2.0f), b(2.0f, 4.0f);

  EXPECT_EQ(a * 2, b);
  EXPECT_EQ(2 * a, b);
}

TEST(Point2dTest, Sum) {
  Point2d a(1.0f, 2.0f), b(2.0f, 4.0f);

  EXPECT_EQ(a + a, b);
}

TEST(Point2dTest, Subtraction) {
  Point2d a(1.0f, 2.0f), b(2.0f, 4.0f);

  EXPECT_EQ(b - a, a);
}
}  // anonymous namespace
