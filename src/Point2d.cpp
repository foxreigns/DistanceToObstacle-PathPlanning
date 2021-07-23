#include "Point2d.h"

namespace starsky {

Point2d::Point2d() : x_(0.0f), y_(0.0f) {}

Point2d::Point2d(float x, float y) : x_(x), y_(y) {}

Point2d::Point2d(const Point2d& rhs) : x_(rhs.x_), y_(rhs.y_) {}

Point2d&
Point2d::operator=(const Point2d& rhs) {
  x_ = rhs.x_;
  y_ = rhs.y_;

  return *this;
}

float
Point2d::getX() const {
  return x_;
}

float
Point2d::getY() const {
  return y_;
}

float
Point2d::norm() const {
  return sqrt(x_ * x_ + y_ * y_);
}

bool
Point2d::operator==(const Point2d& rhs) const {
  return (x_ == rhs.x_) && (y_ == rhs.y_);
}

bool
Point2d::operator!=(const Point2d& rhs) const {
  return !(*this == rhs);
}

Point2d
operator+(const Point2d& p, const Point2d& p2) {
  return Point2d(p.getX() + p2.getX(), p.getY() + p2.getY());
}

Point2d
operator-(const Point2d& p, const Point2d& p2) {
  return Point2d(p.getX() - p2.getX(), p.getY() - p2.getY());
}

}  // namespace starsky
