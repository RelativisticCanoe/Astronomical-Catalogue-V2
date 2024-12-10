#ifndef STELLARSYSTEM_HH
#define STELLARSYSTEM_HH

//STL Headers
#include <memory>
#include <vector>

//Project Headers
#include "objects\astro_object.h"
#include "objects\stellar_objects.h"

namespace astrocat
{
    class stellar_system : public astro_object
    {
        private:
            std::vector<std::weak_ptr<star>> stars{};
            std::vector<float> barycntr_dist{};
    };
}
#endif