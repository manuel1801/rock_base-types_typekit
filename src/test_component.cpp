#include <rtt/TaskContext.hpp>
#include <rtt/Port.hpp>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>
#include <rtt/Component.hpp>
#include <std_srvs/Empty.h>
#include <rtt/scripting/Scripting.hpp>
#include <ros/ros.h>

using namespace RTT;

class TestComponent : public RTT::TaskContext
{
private:
  InputPort<std_msgs::String> inport;
  InputPort<std_msgs::String> outport;

public:
  TestComponent(const std::string &name) : TaskContext(name),
                                           inport("inport"), outport("outport")

  {
    this->ports()->addPort(outport).doc("output port");
    this->ports()->addPort(inport).doc("input port");
  }

  bool configureHook()
  {
    return true;
  }

private:
  void updateHook()
  {
  }
};
ORO_CREATE_COMPONENT(TestComponent)
