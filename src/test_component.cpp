#include <rtt/TaskContext.hpp>
#include <rtt/Port.hpp>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>
#include <rtt/Component.hpp>
#include <std_srvs/Empty.h>
#include <rtt/scripting/Scripting.hpp>
#include <ros/ros.h>

#include "Waypoint.hpp"
#include "my_type.hpp"

using namespace RTT;

class TestComponent : public RTT::TaskContext
{
private:
  OutputPort<ControlData> cd_out;
  OutputPort<Waypoint> wp_out;

  ControlData cd;
  Waypoint wp;

public:
  TestComponent(const std::string &name) : TaskContext(name),
                                           cd_out("cd_out"), wp_out("wp_out")

  {
    this->ports()->addPort(cd_out).doc("cd_out port");
    this->ports()->addPort(wp_out).doc("wp_out port");
  }

  // bool configureHook()
  // {

  //   return true;
  // }

private:
  void updateHook()
  {
    cd.x = 1.0;
    cd.y = 2.0;
    cd.z = 3.0;
    // std::cout << "writing control data: " << cd << std::endl;
    cd_out.write(cd);

    wp.position[0] = 0.0;
    wp.position[1] = 1.0;
    wp.position[2] = 2.0;
    wp.heading = 3.0;
    wp.tol_position = 2.0;
    wp.tol_heading = 1.0;

    // std::cout << "writing waipoint: " << wp << std::endl;
    wp_out.write(wp);
  }
};
ORO_CREATE_COMPONENT(TestComponent)
