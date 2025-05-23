#ifndef SATELLITE_HH
#define SATELLITE_HH

/* Defines a container that can point to an instance of a astro_object-derived class. 
   Used to track relationships between astronomical objects, including orbital data relative to parent. */

//STL Headers
#include <memory>

//Project Headers
#include "objects\astro_object.h"


namespace astrocat
{
    class satellite
    {
        private:
            //Class Attributes
            std::weak_ptr<astrocat::astro_object> child_ptr{};
            double orbit_dist{0.0};
            double orbit_tilt{0.0};
            double orbit_ecc{0.0};
            bool enabled{false};
        
        public:
            satellite() = default;
            satellite(bool enable){enabled = enable;}
            ~satellite();

            //Getter returns basic type -> not worth reference given that return will be out of scope quickly
            const bool get_enabled(){return enabled;}
    };
};

#endif