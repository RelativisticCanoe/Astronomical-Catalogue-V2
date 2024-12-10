#ifndef STELLARREMNANTS_HH
#define STELLARREMNANTS_HH

#include "objects\astro_object.h"
#include "objects\stellar_objects.h"

namespace astrocat
{
    class stellar_remnant : public star
    {
        public:
            stellar_remnant() : star()
            {
                obj_type = AstroType::StelRemnant;
            }
    };

    class supernova : public stellar_remnant
    {
        public:
            supernova() : stellar_remnant()
            {
                obj_type = AstroType::Supernova;
            }
    };

    class white_dwarf : public stellar_remnant
    {
        public:
            white_dwarf() : stellar_remnant()
            {
                obj_type = AstroType::WhtDwarfStar;
                lum_class = LuminosityClass::VII;
            }
    };

    class neutron_star : public stellar_remnant
    {
        public:
            neutron_star() : stellar_remnant()
            {
                obj_type = AstroType::NeutronStar;
                lum_class = LuminosityClass::Undefined;
            }
    };

    class pulsar : public neutron_star
    {
        public:
            pulsar() : neutron_star()
            {
                obj_type = AstroType::Pulsar;
            }
    };

    class black_hole : public astro_object
    {
        /* This is not a star-derived class BUT it is considered a stellar remnant in astronomical terms.
           The reason why it is derived from the astro_object class is because black holes don't have
           luminosity classes, being strange brain-breaking objects we don't entirely understand. 
           Thus, they can't be plotted on a Hertzsprung-Russell diagram and are kind of their own separate thing.
           
           HOWEVER, they can still have a measured luminosity and tempearture, as with a star, due to the accretion
           of material/energy transfer around a given black hole, so those two attributes are re-implemented here. */

        protected:
            double luminosity{0.0};
            double eff_temp{3.0};
        
        public:
            black_hole() : astro_object()
            {
                obj_type = AstroType::BlackHole;
            }
    };
}

#endif