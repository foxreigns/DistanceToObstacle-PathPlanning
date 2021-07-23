#ifndef STARSKY_GEOMETRY_VECTOR2D_H_
#define STARSKY_GEOMETRY_VECTOR2D_H_

namespace starsky
{

class Point2d;

class Vector2d
{
public:
  Vector2d(float x, float y);
  explicit Vector2d(const Point2d &start, const Point2d &end);

  Vector2d(const Vector2d &v);

  /**
   * @brief Does the dot product operation
   *
   * @param v
   * @return float
   */
  float dot(const Vector2d &v) const;

  /**
   * @brief Does the cross product operation and return scalar representation of
   * Z component.
   *
   * @param v
   * @return float
   */
  float cross(const Vector2d &v) const;

  /**
   * @brief gets the norm of the vector
   *
   * @return float
   */
  float norm() const;

  /**
   * @brief returns the x component of the vector
   *
   * @return float
   */
  float getX() const;

  /**
   * @brief returns the y component of the vector
   *
   * @return float
   */
  float getY() const;

  Vector2d operator-(Vector2d v);

  void operator*(const float &s);

  Vector2d &operator=(const Vector2d &v);

private:
  float x_ = 0;
  float y_ = 0;
};

} // namespace starsky

#endif // STARSKY_GEOMETRY_VECTOR2D_H_
