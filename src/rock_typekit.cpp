
#include <rtt/types/StructTypeInfo.hpp>

#include <rtt/types/TemplateTypeInfo.hpp>

#include <ostream>
#include <istream>
#include "rock_typekit.hpp"
#include "my_type.hpp"
#include "Waypoint.hpp"
#include "JointState.hpp"

// /** class has read-only members */
// class ControlClass
// {
//     const int joints;

// public:
//     // Mandatory !
//     ControlClass() : joints(-1) {}
//     // Mandatory !
//     ControlClass(const ControlClass &orig) : joints(orig.joints) {}

//     // ControlClass(int joints) : mjoints(joints) {}
//     // int getJoints() { return joints; }
// };
// // The RTT helper class for any class which has default constructor and copy constructor:

// struct ControlClassTypeInfo
//     : public RTT::types::TemplateTypeInfo<ControlClass>
// {
//     ControlClassTypeInfo()
//         : RTT::types::TemplateTypeInfo<ControlClass>("ControlClass")
//     {
//     }

//     // Note: you'll have to implement virtual functions here,
//     // as documented by the TypeInfo class.
// };

namespace App
{
    std::string RockTypekitPlugin::getName() { return "RockTypekit"; }

    bool RockTypekitPlugin::loadTypes()
    {
        // Tell the RTT the name and type of this struct
        RTT::types::Types()->addType(new ControlDataTypeInfo());
        RTT::types::Types()->addType(new WaypointTypeInfo());
        RTT::types::Types()->addType(new JointStateTypeInfo());

        //RTT::types::Types()->addType(new ControlClassTypeInfo());
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
