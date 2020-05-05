
#include <rtt/types/StructTypeInfo.hpp>

#include <ostream>
#include <istream>
#include "my_type.hpp"

ControlData::ControlData() : x(0), y(0), z(0), sample_nbr(0)
{
}

namespace boost
{
    namespace serialization
    {
        // The helper function which you write yourself:
        template <class Archive>
        void serialize(Archive &a, ControlData &cd, unsigned int)
        {
            using boost::serialization::make_nvp;
            a &make_nvp("x", cd.x);
            a &make_nvp("y", cd.y);
            a &make_nvp("z", cd.z);
            a &make_nvp("sample_nbr", cd.sample_nbr);
        }
    } // namespace serialization
} // namespace boost

// Displaying:
std::ostream &operator<<(std::ostream &os, const ControlData &cd)
{
    return os << '(' << cd.x << ',' << cd.y << ',' << cd.z << '): ' << cd.sample_nbr;
}

// Reading :
std::istream &operator>>(std::istream &is, ControlData &cd)
{
    char c;
    return is >> c >> cd.x >> c >> cd.y >> c >> cd.z >> c >> c >> cd.sample_nbr; // 'c' reads '(' ',' ',' ')' and ':'
}
// ...
// The 'true' argument means:  it has operator<< and operator>>

ControlDataTypeInfo::ControlDataTypeInfo() : RTT::types::StructTypeInfo<ControlData, true>("ControlData")
{
}

// Tell the RTT the name and type of this struct:
// RTT::types::Types()->addType(new ControlDataTypeInfo());
