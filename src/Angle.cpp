
#include "Angle.h"

namespace starsky {

Angle&
Angle::wrap() {
  theta_ = wrap(theta_, minValue_, maxValue_);
  return *this;
}

Angle::Angle() {}

Angle::Angle(float a, float minValue, float maxValue) {
  minValue_ = minValue;
  maxValue_ = maxValue;
  theta_ = wrap(a, minValue_, maxValue_);
}

Angle::Angle(const Angle& rhs)
    : theta_(rhs.theta_), minValue_(rhs.minValue_), maxValue_(rhs.maxValue_) {}

Angle&
Angle::operator=(const Angle& rhs) {
  theta_ = rhs.theta_;
  minValue_ = rhs.minValue_;
  maxValue_ = rhs.maxValue_;

  return *this;
}

bool
Angle::operator==(const Angle& rhs) const {
  return (theta_ == rhs.theta_);
}

bool
Angle::operator!=(const Angle& rhs) const {
  return !(*this == rhs);
}

Angle
Angle::operator+(const Angle& a2) const {
  return Angle(theta_ + a2.theta_).wrap();
}

Angle
Angle::operator-(const Angle& a2) const {
  return Angle(theta_ - a2.theta_).wrap();
}

Angle::operator float() {
  return theta_;
}

float
Angle::wrap(float angle, float minValue, float maxValue) {
  float range = maxValue - minValue;
  return angle - range * std::floor((angle - minValue) / range);
}

}  // namespace starsky
