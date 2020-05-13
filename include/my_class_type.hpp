#include <rtt/types/StructTypeInfo.hpp>

#include <ostream>
#include <istream>

/** class has read-only members */
class ControlClass
{
    const int joints;

public:
    // Mandatory !
    ControlClass();
    // Mandatory !
    ControlClass(const ControlClass &orig);

    ControlClass(int joints);
};

// Displaying:
std::ostream &operator<<(std::ostream &os, const ControlData &cd);
// Reading :
std::istream &operator>>(std::istream &is, ControlData &cd);

// ...
// The 'true' argument means:  it has operator<< and operator>>
struct ControlDataTypeInfo
    : public RTT::types::StructTypeInfo<ControlData, true>
{
    ControlDataTypeInfo();
};

namespace boost
{
    namespace serialization
    {
        // The helper function which you write yourself:
        template <class Archive>
        void serialize(Archive &a, ControlData &cd, unsigned int);

    } // namespace serialization
} // namespace boost
