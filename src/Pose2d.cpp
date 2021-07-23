
#include "Pose2d.h"

namespace starsky {

Pose2d::Pose2d() : point_(), theta_() {}

Pose2d::Pose2d(float x, float y, float theta) : point_(x, y), theta_(theta) {}

Pose2d::Pose2d(const Point2d& rhs, const Angle& theta) : point_(rhs), theta_(theta) {}
Pose2d::Pose2d(const Pose2d& rhs) : point_(rhs.point_), theta_(rhs.theta_) {}

Pose2d&
Pose2d::operator=(const Pose2d& rhs) {
  point_ = rhs.getPoint();
  theta_ = rhs.getTheta();

  return *this;
}

bool
Pose2d::operator==(const Pose2d& rhs) const {
  return (point_ == rhs.point_) && (theta_ == rhs.theta_);
}

bool
Pose2d::operator!=(const Pose2d& rhs) const {
  return !(*this == rhs);
}

float
Pose2d::getX() const {
  return point_.getX();
}

float
Pose2d::getY() const {
  return point_.getY();
}

Angle
Pose2d::getTheta() const {
  return theta_;
}

Point2d
Pose2d::getPoint() const {
  return point_;
}

}  // namespace starsky
