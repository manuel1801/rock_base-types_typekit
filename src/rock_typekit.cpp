
#include <rtt/types/StructTypeInfo.hpp>
#include <ostream>
#include <istream>
#include "rock_typekit.hpp"
#include "my_type.hpp"
// #include "Waypoint.hpp"

namespace App
{
    std::string RockTypekitPlugin::getName() { return "RockTypekit"; }

    bool RockTypekitPlugin::loadTypes()
    {
        // Tell the RTT the name and type of this struct
        RTT::types::Types()->addType(new ControlDataTypeInfo());
        // RTT::types::Types()->addType(new WaypointTypeInfo());
    }

    /** ...Add the other example code of this manual here as well... */
    bool RockTypekitPlugin::loadConstructors()
    {
        // ...
    }
    bool RockTypekitPlugin::loadOperators()
    {
        // ...
    }
} // namespace App

/** Register the class as a plugin */
ORO_TYPEKIT_PLUGIN(App::RockTypekitPlugin);