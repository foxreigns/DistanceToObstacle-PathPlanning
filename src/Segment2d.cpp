#include "Segment2d.h"
#include <algorithm>
#include <cmath>
#include <limits>
#include "FrenetPoint.h"

namespace starsky {

Segment2d::Segment2d(const Point2d& start, const Point2d& end)
    : vector_(start, end), start_(start), end_(end) {
  dx_ = vector_.getX();
  dy_ = vector_.getY();
  length_ = vector_.norm();
}

Vector2d
Segment2d::getVector() const {
  return vector_;
}

float Segment2d::norm() const { return length_; }

}  // namespace starsky
