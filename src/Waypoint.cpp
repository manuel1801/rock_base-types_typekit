#include <rtt/types/StructTypeInfo.hpp>
#include <ostream>
#include <istream>
#include "Waypoint.hpp"

namespace base
{

    Waypoint::Waypoint() : position(base::Position::Identity()), heading(0), tol_position(0), tol_heading(0)
    {
    }

    Waypoint::Waypoint(const base::Vector3d &_position, double _heading, double _tol_position, double _tol_heading)
        : position(_position), heading(_heading), tol_position(_tol_position), tol_heading(_tol_heading)
    {
    }

    Waypoint::Waypoint(const Eigen::Vector3d &_position, double _heading, double _tol_position, double _tol_heading)
        : position(_position), heading(_heading), tol_position(_tol_position), tol_heading(_tol_heading)
    {
    }

    // Displaying
    std::ostream &operator<<(std::ostream &os, const Waypoint &wp)
    {
        return os << "(position[0]: " << wp.position[0]
                  << ", position[1]: " << wp.position[1]
                  << ", position[2]: " << wp.position[2]
                  << "), heading: " << wp.heading
                  << ", tol position: " << wp.tol_position
                  << ", tol heading: " << wp.tol_heading;
    }

    // Reading :
    std::istream &operator>>(std::istream &is, Waypoint &wp)
    {
        char c;
        return is >> c >> wp.position[0] >> c >> wp.position[1] >> c >> wp.position[2] >> c >> wp.heading >> c >> wp.tol_position >> c >> wp.tol_heading; // 'c' reads '(' ',' ',' ')' and ':'
    }

    // The 'true' argument means:  it has operator<< and operator>>
    WaypointTypeInfo::WaypointTypeInfo() : RTT::types::StructTypeInfo<Waypoint, true>("Waypoint")
    {
    }

} //end namespace base

using namespace base;
namespace boost
{
    namespace serialization
    {
        template <class Archive>
        void serialize(Archive &a, Waypoint &wp, unsigned int)
        {
            using boost::serialization::make_nvp;
            a &make_nvp("position", wp.position);
            a &make_nvp("heading", wp.heading);
            a &make_nvp("tol_position", wp.tol_position);
            a &make_nvp("tol_heading", wp.tol_heading);
        }
    } // namespace serialization
} // namespace boost
