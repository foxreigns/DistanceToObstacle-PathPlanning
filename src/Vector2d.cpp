#include "Vector2d.h"
#include <cmath>

#include "Point2d.h"

namespace starsky
{

Vector2d::Vector2d(float x, float y)
{
  x_ = x;
  y_ = y;
}

Vector2d::Vector2d(const Point2d &start, const Point2d &end)
{
  x_ = (end - start).getX();
  y_ = (end - start).getY();
}

Vector2d::Vector2d(const Vector2d &v)
{
  x_ = v.x_;
  y_ = v.y_;
}

float Vector2d::dot(const Vector2d &v) const
{
  return x_ * v.getX() + y_ * v.getY();
}

float Vector2d::cross(const Vector2d &v) const
{
  return x_ * v.getY() - y_ * v.getX();
}

float Vector2d::norm() const
{
  return hypot(x_, y_);
}

float Vector2d::getX() const
{
  return x_;
}

float Vector2d::getY() const
{
  return y_;
}

Vector2d
Vector2d::operator-(Vector2d v)
{
  return Vector2d(this->getX() - v.getX(), this->getY() - v.getY());
}

void
    Vector2d::operator*(const float &s)
{
  this->x_ *= s;
  this->y_ *= s;
}

Vector2d &
Vector2d::operator=(const Vector2d &v)
{
  this->x_ = v.x_;
  this->y_ = v.y_;
  return *this;
}

} // namespace starsky
