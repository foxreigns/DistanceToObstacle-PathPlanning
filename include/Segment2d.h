#ifndef STARSKY_GEOMETRY_SEGMENT2D_H_
#define STARSKY_GEOMETRY_SEGMENT2D_H_

#include "Point2d.h"
#include "Vector2d.h"
#include "FrenetPoint.h"

namespace starsky {

/**
 * @brief Defining an segment class based on the Vector class.
 * This is not very sound from a mathematical perspective, but allowed
 * some reuse of code. Please be aware when using this Class.
 *
 */
class Segment2d {
 public:
  Segment2d(const Point2d& start, const Point2d& end);

  Vector2d getVector() const;

  /**
   * @brief gets the norm of the segment
   *
   * @return float
   */
  float norm() const;
  
 private:
  Point2d start_;
  Point2d end_;

  float dx_ = 0;
  float dy_ = 0;

  Vector2d vector_;

  float length_ = 0.0f;
};

}  // namespace starsky

#endif  // STARSKY_GEOMETRY_SEGMENT2D_H_
