#include <rtt/types/StructTypeInfo.hpp>
#include <ostream>
#include <istream>

#include "JointState.hpp"

namespace base
{

    JointState JointState::Position(double value)
    {
        JointState ret;
        ret.position = value;
        return ret;
    }

    JointState JointState::Speed(float value)
    {
        JointState ret;
        ret.speed = value;
        return ret;
    }

    JointState JointState::Effort(float value)
    {
        JointState ret;
        ret.effort = value;
        return ret;
    }

    JointState JointState::Raw(float value)
    {
        JointState ret;
        ret.raw = value;
        return ret;
    }

    JointState JointState::Acceleration(float value)
    {
        JointState ret;
        ret.acceleration = value;
        return ret;
    }

    bool JointState::hasPosition() const
    {
        return !isUnset(position);
    }

    bool JointState::hasSpeed() const
    {
        return !isUnset(speed);
    }

    bool JointState::hasEffort() const
    {
        return !isUnset(effort);
    }

    bool JointState::hasRaw() const
    {
        return !isUnset(raw);
    }

    bool JointState::hasAcceleration() const
    {
        return !isUnset(acceleration);
    }

    bool JointState::isPosition() const
    {
        return hasPosition() && !hasSpeed() && !hasEffort() && !hasRaw() && !hasAcceleration();
    }

    bool JointState::isSpeed() const
    {
        return !hasPosition() && hasSpeed() && !hasEffort() && !hasRaw() && !hasAcceleration();
    }

    bool JointState::isEffort() const
    {
        return !hasPosition() && !hasSpeed() && hasEffort() && !hasRaw() && !hasAcceleration();
    }

    bool JointState::isRaw() const
    {
        return !hasPosition() && !hasSpeed() && !hasEffort() && hasRaw() && !hasAcceleration();
    }

    bool JointState::isAcceleration() const
    {
        return !hasPosition() && !hasSpeed() && !hasEffort() && !hasRaw() && hasAcceleration();
    }

    double JointState::getField(int mode) const
    {
        switch (mode)
        {
        case POSITION:
            return position;
        case SPEED:
            return speed;
        case EFFORT:
            return effort;
        case RAW:
            return raw;
        case ACCELERATION:
            return acceleration;
        default:
            throw std::runtime_error("invalid mode given to getField");
        }
    }

    void JointState::setField(int mode, double value)
    {
        switch (mode)
        {
        case POSITION:
            position = value;
            return;
        case SPEED:
            speed = value;
            return;
        case EFFORT:
            effort = value;
            return;
        case RAW:
            raw = value;
            return;
        case ACCELERATION:
            acceleration = value;
            return;
        default:
            throw std::runtime_error("invalid mode given to getField");
        }
    }

    JointState::MODE JointState::getMode() const
    {
        if (isPosition())
            return POSITION;
        else if (isSpeed())
            return SPEED;
        else if (isEffort())
            return EFFORT;
        else if (isRaw())
            return RAW;
        else if (isAcceleration())
            return ACCELERATION;
        else if (hasPosition() || hasSpeed() || hasEffort() || hasRaw() || hasAcceleration())
            throw std::runtime_error("getMode() called on a JointState that has more than one field set");
        else
            return UNSET;
    }

    // Displaying
    std::ostream &operator<<(std::ostream &os, const JointState &js)
    {
        return os << "Position " << js.position
                  << ", Speed: " << js.speed
                  << ", Effort: " << js.effort
                  << ", Raw: " << js.raw
                  << ", Acceleration: " << js.acceleration;
    }

    // Reading :
    std::istream &operator>>(std::istream &is, JointState &js)
    {
        char c;
        return is >> c >> js.position >> c >> js.speed >> c >> js.effort >> c >> js.raw >> c >> js.acceleration;
    }

    // The 'true' argument means:  it has operator<< and operator>>
    JointStateTypeInfo::JointStateTypeInfo() : RTT::types::StructTypeInfo<JointState, true>("JointState")
    {
    }

} //end namespace base

using namespace base;
namespace boost
{
    namespace serialization
    {
        template <class Archive>
        void serialize(Archive &a, JointState &js, unsigned int)
        {
            using boost::serialization::make_nvp;
            a &make_nvp("position", js.position);
            a &make_nvp("speed", js.speed);
            a &make_nvp("effort", js.effort);
            a &make_nvp("raw", js.raw);
            a &make_nvp("acceleration", js.acceleration);
        }
    } // namespace serialization
} // namespace boost
