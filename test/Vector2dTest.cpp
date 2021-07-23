
#include "Vector2d.h"
#include "Point2d.h"

#include <gtest/gtest.h>

namespace {

using starsky::Point2d;
using starsky::Vector2d;

TEST(Vector2dTest, constructors) {
  Point2d p0(0.0f, 0.0f);
  Point2d p1(1.0f, 1.0f);

  Vector2d v(p0, p1);
  EXPECT_FLOAT_EQ(1.0f, v.getX());
  EXPECT_FLOAT_EQ(1.0f, v.getY());

  Point2d p2(-1.0f, 0.0f);
  Point2d p3(-2.0f, 1.0f);

  Vector2d v2(p2, p3);
  EXPECT_FLOAT_EQ(-1.0f, v2.getX());
  EXPECT_FLOAT_EQ(1.0f, v2.getY());
}

TEST(Vector2dTest, norm) {
  Vector2d v(Point2d(0.0f, 0.0f), Point2d(1.0f, 1.0f));
  EXPECT_FLOAT_EQ(sqrt(2.0f), v.norm());

  Vector2d v2(Point2d(-1.0f, 0.0f), Point2d(-4.0f, 4.0f));
  EXPECT_FLOAT_EQ(5.0f, v2.norm());

  Vector2d v3(Point2d(1.0f, 1.0f), Point2d(2.0f, 0.0f));
  EXPECT_FLOAT_EQ(sqrt(2.0f), v3.norm());
}

TEST(Vector2dTest, dot1) {
  Vector2d v(Point2d(0.0f, 0.0f), Point2d(1.0f, 0.0f));
  Vector2d v2(Point2d(0.0f, 0.0f), Point2d(0.0f, 1.0f));
  EXPECT_FLOAT_EQ(0.0f, v.dot(v2));
}

TEST(Vector2dTest, dot2) {
  Vector2d v(Point2d(0.0f, 0.0f), Point2d(1.0f, 0.0f));
  Vector2d v2(Point2d(0.0f, 0.0f), Point2d(1.0f, 1.0f));
  EXPECT_FLOAT_EQ(1.0f, v.dot(v2));
}

TEST(Vector2dTest, dot3) {
  Vector2d v(Point2d(0.0f, 0.0f), Point2d(0.707f, 0.707f));
  Vector2d v2(Point2d(0.0f, 0.0f), Point2d(0.5f, 0.866025f));
  EXPECT_FLOAT_EQ(0.96577966f, v.dot(v2));
}

TEST(Vector2dTest, dot4) {
  Vector2d v(Point2d(0.0f, 0.0f), Point2d(1.0f, 1.0f));
  Vector2d v2(Point2d(0.0f, 0.0f), Point2d(2.0f, 0.0f));
  EXPECT_FLOAT_EQ(2.0f, v.dot(v2));
}

TEST(Vector2dTest, dot5) {
  Vector2d v(Point2d(0.0f, 0.0f), Point2d(1.0f, 1.0f));
  Vector2d v2(Point2d(0.0f, 0.0f), Point2d(0.0f, 2.0f));
  EXPECT_FLOAT_EQ(2.0f, v.dot(v2));
}

TEST(Vector2dTest, cross1) {
  Vector2d v(Point2d(0.0f, 0.0f), Point2d(1.0f, 0.0f));
  Vector2d v2(Point2d(0.0f, 0.0f), Point2d(0.0f, 1.0f));
  EXPECT_FLOAT_EQ(1.0f, v.cross(v2));
}

TEST(Vector2dTest, cross2) {
  Vector2d v(Point2d(0.0f, 0.0f), Point2d(1.0f, 0.0f));
  Vector2d v2(Point2d(0.0f, 0.0f), Point2d(1.0f, 1.0f));
  EXPECT_FLOAT_EQ(1.0f, v.cross(v2));
}

TEST(Vector2dTest, cross3) {
  Vector2d v(Point2d(0.0f, 0.0f), Point2d(0.707f, 0.707f));
  Vector2d v2(Point2d(0.0f, 0.0f), Point2d(0.5f, 0.866025f));
  EXPECT_FLOAT_EQ(0.25877964, v.cross(v2));
}

TEST(Vector2dTest, cross4) {
  Vector2d v(Point2d(0.0f, 0.0f), Point2d(1.0f, 0.0f));
  Vector2d v2(Point2d(0.0f, 0.0f), Point2d(1.0f, 0.0f));
  EXPECT_FLOAT_EQ(0.0f, v.cross(v2));
}

TEST(Vector2dTest, cross5) {
  Vector2d v(Point2d(0.0f, 0.0f), Point2d(1.0f, 1.0f));
  Vector2d v2(Point2d(0.0f, 0.0f), Point2d(1.0f, 0.0f));

  EXPECT_FLOAT_EQ(-1.0f, v.cross(v2));
}

}  // anonymous namespace
