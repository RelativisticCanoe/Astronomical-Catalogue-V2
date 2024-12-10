#ifndef CATALOGUE_HH
#define CATALOGUE_HH

/* Defines a container class that can contain and manage instances of astro_object-derived classes.
   Designed to be modifiable at run-time via usage of smart pointers, without worrying about memory management. */

//STL Headers
#include <memory>
#include <vector>

//Project Headers
#include "objects\astro_object.h"

namespace astrocat
{
    class catalogue
    {
        private:
            std::vector<std::shared_ptr<astro_object>> cat_objs{};
            int obj_count{};

            std::vector<std::shared_ptr<astro_object>>::iterator cat_begin{cat_objs.begin()};
            std::vector<std::shared_ptr<astro_object>>::iterator cat_end{cat_objs.end()};
            std::vector<std::shared_ptr<astro_object>>::iterator cat_pos{cat_objs.begin()};

            //pointer for subselect? - allows for modification of selected elements?

        public:
    };
}

#endif
