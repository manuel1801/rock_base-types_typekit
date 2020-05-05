#ifndef __BASE_WAYPOINT_HH__
#define __BASE_WAYPOINT_HH__

#include <rtt/types/StructTypeInfo.hpp>

#include <base/Pose.hpp>
#include <base/Eigen.hpp>

#include <ostream>
#include <istream>

namespace base
{
    /**
     * Representation for a pose
     */
    struct Waypoint
    {
        base::Vector3d position;
        //heading in radians
        double heading;

        //tollerance of the position in m
        double tol_position;
        //tollerance of the heading in rad
        double tol_heading;

        // default: initializing with identity and zero
        Waypoint();

        // use base::Vector3d
        Waypoint(base::Vector3d const &_position, double _heading,
                 double _tol_position, double _tol_heading);
        // convenience: same for Eigen::Vector3d
        Waypoint(Eigen::Vector3d const &_position, double _heading,
                 double _tol_position, double _tol_heading);
    };
} // namespace base

namespace boost
{
    namespace serialization
    {
        // The helper function which you write yourself:
        template <class Archive>
        void serialize(Archive &a, base::Waypoint &cd, unsigned int);

    } // namespace serialization
} // namespace boost
// Displaying:
std::ostream &operator<<(std::ostream &os, const base::Waypoint &cd);
// Reading :
std::istream &operator>>(std::istream &is, base::Waypoint &cd);

// ...
// The 'true' argument means:  it has operator<< and operator>>
struct WaypointTypeInfo
    : public RTT::types::StructTypeInfo<base::Waypoint, true>
{
    WaypointTypeInfo();
};

#endif
