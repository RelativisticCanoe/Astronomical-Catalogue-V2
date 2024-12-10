#ifndef STELLARTYPES_HH
#define STELLARTYPES_HH

//STL Headers
#include <iostream>
#include <string>
#include <vector>

namespace astrocat
{
    enum class StellarType
    {
        Unassigned, O, B, A, F, G, K, M,
    };

    std::vector<std::string> StelTypeString
    {
        "Unassigned", "O", "B", "A", "F", "G", "K", "M",
    };
    
    std::ostream& operator<<(std::ostream& os, StellarType steltype)
    {
        os << StelTypeString[int(steltype)];
    }

    enum class LuminosityClass
    {
        Unassigned, Zero, IaPlus, Ia, Iab, Ib, II, III, IV, V, VI, VII, Undefined,
    };

    std::vector<std::string> LumClassString
    {
        "Unassigned", "0", "Ia+", "Ia", "Iab", "Ib", "II", "III", "IV", "V", "VI", "VII", "Undefined",
    };

    std::ostream& operator<<(std::ostream& os, LuminosityClass lumclass)
    {
        os << LumClassString[int(lumclass)];
    }
}

#endif