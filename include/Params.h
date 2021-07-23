#ifndef STARSKY_GEOMETRY_PARAMS_H_
#define STARSKY_GEOMETRY_PARAMS_H_

namespace starsky
{

/**
 * @brief Basic struct to hold the parameters related to a reference pose line segment and the obstacle
 *
 */
struct Params
{
  float perpDist_;
  float euclidDist_;
  float projDist_;
  bool bLyingOut_; // flag to check if the perpendicular from the obstacle intersects the line segment outside
};

} // namespace starsky

#endif // STARSKY_GEOMETRY_PARAMS_H_
