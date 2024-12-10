#ifndef CONTROL_HH
#define CONTROL_HH

/* Defines runtime user commands. Enum class allows for easier control of
   core logical loop via switch statements and easier modification/extension. */

//STL Headers
#include <vector>
#include <string>

namespace astrocat
{
    enum class UserCmd{};
    std::vector<std::string> usercmd_strings{};
}

#endif