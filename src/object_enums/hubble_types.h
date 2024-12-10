#ifndef HUBBLETYPES_HH
#define HUBBLETYPES_HH

//STL Headers
#include <iostream>
#include <string>
#include <vector>

namespace astrocat
{
    enum class HubbleType
    {
        Unassigned,
        E0, E1, E2, E3, E4, E5, E6, E7, S0,
        Sa, Sb, Sc,
        SBa, SBb, SBc,
        Irr,
    };

    const std::vector<std::string> HubbTypeString
    {
        "Unassigned",
        "E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "S0",
        "Sa", "Sb", "Sc",
        "SBa", "SBb", "SBc",
        "Irr",
    };

    std::ostream& operator<<(std::ostream& os, HubbleType hubtype)
    {
        os << HubbTypeString[int(hubtype)];
    }

    enum class deVacModifier
    {
        NoRing, Ring, Transition,
    };

    const std::vector<std::string> deVacString
    {
        "(s)", "(r)", "(rs)",
    };

    std::ostream& operator<<(std::ostream& os, deVacModifier dvmod)
    {
        os << deVacString[int(dvmod)];
    }
}

#endif