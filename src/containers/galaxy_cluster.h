#ifndef GALAXYCLUSTER_HH
#define GALAXYCLUSTER_HH

/* Defines a cluster of galaxies, as with the stellar_cluster class, but inherits from galaxy instead. 
   Mass of galaxy cluster can exceed the mass of individual galaxies due to intergalactic dark matter,
   but must not be lower than the sum of the masses of the constituent galaxies.
   
   Break into luminous_mass and dark_mass? Then ensure sum to total mass, or infer dark_mass
   from dark mass = total mass - luminous mass. */

//STL Header
#include <memory>
#include <vector>

//Project Headers
#include "objects\astro_object.h"
#include "objects\galaxy.h"

namespace astrocat
{
    class galaxy_cluster : public astro_object
    {
        private:
            std::vector<std::weak_ptr<galaxy>> galaxies{};
            std::vector<float> barycntr_dist{};
    };
}

#endif