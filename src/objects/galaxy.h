#ifndef GALAXY_HH
#define GALAXY_HH

//Project Headers
#include "objects\astro_object.h"
#include "object_enums\hubble_types.h"

namespace astrocat
{   
    class galaxy : public astro_object
    {
        private:
            float lum_mass_frac{0.2};
            float dark_mass{(1-lum_mass_frac) * mass};

            astrocat::HubbleType hubble_type{};
            astrocat::deVacModifier deVac_mod{};
    };
}

#endif