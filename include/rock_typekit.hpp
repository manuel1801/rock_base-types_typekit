#ifndef ORO_ROCK_TYPEKIT_HPP
#define ORO_ROCK_TYPEKIT_HPP

#include <rtt/types/Types.hpp>
#include <rtt/types/TypekitPlugin.hpp>

namespace App
{
    /**
     * This interface defines the types of my application
     */
    class RockTypekitPlugin
        : public RTT::types::TypekitPlugin
    {
    public:
        virtual std::string getName();

        virtual bool loadTypes();
        virtual bool loadConstructors();
        virtual bool loadOperators();
    };
} // namespace App
#endif