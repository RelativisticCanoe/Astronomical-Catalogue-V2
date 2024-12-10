#ifndef DEEPSKYOBJECTS_HH
#define DEEPSKYOBJECTS_HH

/* Defines assorted non-luminous (i.e. non-stellar in origin) objects commonly found in
   astronomical observations, with the exception of black holes (majority stellar remnants). */

//Project Headers
#include "objects\astro_object.h"

namespace astrocat
{
    class planet : public astro_object
    {
        public:
            planet() : astro_object()
            {
                obj_type = AstroType::Planet;
            }
    };

    class terrestrial_planet : public planet
    {
        public:
            terrestrial_planet() : planet()
            {
                obj_type = AstroType::TerrPlanet;
            }
    };

    class gas_planet : public planet
    {
        public:
            gas_planet() : planet()
            {
                obj_type = AstroType::GasPlanet;
            }
    };

    class ice_planet : public planet
    {
        public:
            ice_planet() : planet()
            {
                obj_type = AstroType::IcePlanet;
            }
    };
    
    class dwarf_planet : public planet
    {
        public:
            dwarf_planet() : planet()
            {
                obj_type = AstroType::DwarfPlanet;
            }
    };

    class moon : public astro_object
    {
        public:
            moon() : astro_object()
            {
                obj_type = AstroType::Moon;
            }
    };

    class comet : public astro_object
    {
        public:
            comet() : astro_object()
            {
                obj_type = AstroType::Comet;
            }
    };

    class meteor : public astro_object
    {
        public:
            meteor() : astro_object()
            {
                obj_type = AstroType::Meteor;
            }
    };

    class asteroid : public astro_object
    {
        public:
            asteroid() : astro_object()
            {
                obj_type = AstroType::Asteroid;
            }
    };

    class interstellar_medium : public astro_object
    {
        public:
            interstellar_medium() : astro_object()
            {
                obj_type = AstroType::IntStelMedium;
            }
    };

    class nebula : public interstellar_medium
    {
        /* Nebula inherits from interstellar_medium because nebulae are a subset of
        ISM which is notably luminous/dense, indicating stellar formation. HOWEVER,
        nebulae are not stellar objects themselves, so are placed in this header. */
        public:
            nebula() : interstellar_medium()
            {
                obj_type = AstroType::Nebula;
            }
    };
}

#endif