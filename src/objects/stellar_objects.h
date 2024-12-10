#ifndef STELLAROBJECTS_HH
#define STELLAROBJECTS_HH

#include "objects\astro_object.h"
#include "object_enums\stellar_types.h"

namespace astrocat
{
    class star : public astro_object
    {
        protected:
            double luminosity{};
            double eff_temp{};

            StellarType stel_class{StellarType::G}; 
            int stel_digit{2}; //Indicates relative position within stellar class
            LuminosityClass lum_class{LuminosityClass::V};

            //Add magnitudes
        
        public:
            star() : astro_object()
            {
                obj_type = AstroType::Star;
            }
    };

    class main_sequence_star : public star
    {
        /* Represents a star within the Main Sequence - still fusing Hydrogen in its core
           to sustain itself. */
        public:
            main_sequence_star() : star()
            {
                obj_type = AstroType::MainSequenceStar;
                lum_class = LuminosityClass::V;
            }
    };

    class red_giant_star : public star
    {
        /* Represents a star OUTSIDE of the Main Sequence - Hydrogen core is depleted,
           so heavier elements up to Iron are fused to sustain pressure. */
        public:
            red_giant_star() : star()
            {
                obj_type = AstroType::RedGiantStar;
                lum_class = LuminosityClass::III;
            }
    };

    class dwarf_star : public main_sequence_star
    {
        /* Represents stars that, whilst on the Main Sequence, are low mass RELATIVE TO THE SUN 
        and thus unlikely to evolve to have a red giant phase before becoming a white dwarf.
        Most Main Sequence stars are "dwarfs" due to their small size compared to non-MS giant stars,
        BUT have comparable size and evolution to that of the Sun.
        
        White Dwarfs are their own class derived from the stellar_remnant class as they are 
        POST-MS objects that have no internal fusion, unlike red dwarfs. */
        
        public:
            dwarf_star() : main_sequence_star()
            {
                obj_type = AstroType::DwarfStar;
                lum_class = LuminosityClass::VI;
            }
    };
}

#endif