# Simple Path Planning Challenge


For self driving and robotics in general, it's often helpful to describe a position in relative to a reference curve. This relative position can be used to map vehicles to a lane line or identify possible obstacles in the robot's path.

This code implements a class that defines that reference curve
(described by a series of poses in 2d space), and computes `S`: the distance along the curve to the closest point to the obstacle on the curve and `D`: smallest distance from the obstacle to the curve, right of the curve being positive, after a minimum S_reference distance.

![Example](/images/example.png)

For example in the image above we want the S and D of the blue point. This would depend on the reference S distance since we want the S value after this reference.

**Case1**
Reference distance = 0
S = sqrt(2) + 0.5
D = 0.5

**Case2**
Reference distance = 1
S = sqrt(2) + 0.5
D = 0.5

**Case3**
Reference distance = 2
S = Invalid 
D = Invalid 

The following are some assumptions I made for this implementation:
- The obstacle can be represented by a point in space.
- The curve can be represented by a series of line segments
- A minimum of two poses or one segment are/is required 
- If the obstacle is equidistant from two segments, the results are computed for the segment in the series that comes first
- If the obstacle is equidistant from first and last points in the series, the results are computed from the last point
- If the obstacle is beyond the ultimate point and on the line or vector (not line segment) formed by ultimate and the penultimate points i.e neither left nor right, D is assumed to be positive 
- The above assumption is extended to a similar case when the obstacle is before the first point and on the line or vector (not line segment) formed by the first and second points
- If in a series of 5 segments, the obstacle is initially closest to, say, segment 3, and the minimum Sreference distance is greater than the S in this case, this S and the corresponding Frenet point are rejected. Then, the S and D are computed for the next closest segment to the obstacle in the series which satisfies the minimum Sreference distance.


## Helpful Classes

Some classes that may be useful when implementing the ReferencePoses class and functions:

* Angle : Angle in a fixed range (e.g. +- PI)
* FrenetPoint : 2D point in S and D space
* Point2d : 2D point in metric (x/y) space
* Pose2d : 2D point with orientation
* Segment2d : Line segment between two points
* Vector2d : Vector in metric space
* Params : Required distance parameters
* Copy constructor in Vector2d
* Operator overloading for '-','*','='in Vector2d

* This project should be building in Linux. For it, just do:
```
mkdir build
cd build && cmake ..
make
```
* You need to have gtest and cmake installed.  To check if it's working, run `./build/runUnitTests`. It should fail only the computeSDAfterExample_0, computeSDAfterExample_1, computeSDAfterExample_2, as those tests were provided as example.
