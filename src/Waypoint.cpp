#include <rtt/types/StructTypeInfo.hpp>
#include <ostream>
#include <istream>
#include "Waypoint.hpp"

namespace base
{

    Waypoint::Waypoint() : position(Position::Identity()), heading(0), tol_position(0), tol_heading(0)
    {
    }

    Waypoint::Waypoint(const Vector3d &_position, double _heading, double _tol_position, double _tol_heading)
        : position(_position), heading(_heading), tol_position(_tol_position), tol_heading(_tol_heading)
    {
    }

    Waypoint::Waypoint(const Eigen::Vector3d &_position, double _heading, double _tol_position, double _tol_heading)
        : position(_position), heading(_heading), tol_position(_tol_position), tol_heading(_tol_heading)
    {
    }

} //end namespace base

namespace boost
{
    namespace serialization
    {
        // The helper function which you write yourself:
        template <class Archive>
        void serialize(Archive &a, base::Waypoint &cd, unsigned int)
        {
            using boost::serialization::make_nvp;
            a &make_nvp("position", cd.position);
            a &make_nvp("heading", cd.heading);
            a &make_nvp("tol_position", cd.tol_position);
            a &make_nvp("tol_heading", cd.tol_heading);
        }
    } // namespace serialization
} // namespace boost

// Displaying:
std::ostream &operator<<(std::ostream &os, const base::Waypoint &cd)
{
    return os << 'position: ' << cd.position << ', heading: ' << cd.heading << ', tol_position: ' << cd.tol_position << 'tol_heading: ' << cd.tol_heading;
}

// Reading :
std::istream &operator>>(std::istream &is, base::Waypoint &cd)
{
    char c;
    return is >> c >> cd.position >> c >> cd.heading >> c >> cd.tol_position >> c >> cd.tol_heading; // 'c' reads '(' ',' ',' ')' and ':'
}
// ...
// The 'true' argument means:  it has operator<< and operator>>

WaypointTypeInfo::WaypointTypeInfo() : RTT::types::StructTypeInfo<base::Waypoint, true>("Waypoint")
{
}