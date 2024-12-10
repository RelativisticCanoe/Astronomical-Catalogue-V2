#ifndef STELLARCLUSTER_HH
#define STELLARCLUSTER_HH

/* Defines a container class designed to represent a cluster of stars via star-derived objects. 
    As part of the program's design allows all objects to be accessed and managed at runtime,
    this is not meant to be a unique object as we want access to each star individually.
    Hence, it makes sense to make a container inheriting from astro_object so that the cluster
    can be represented within the catalogue as a whole whilst allowing each star to be its own object. 
    
    The masses, luminosity etc. will need to be updated from summing constituent parts.*/

//STL Headers
#include <memory>
#include <vector>

//Project Headers
#include "objects\astro_object.h"
#include "objects\stellar_objects.h"
#include "containers\stellar_system.h"

namespace astrocat
{
    class stellar_cluster : public stellar_system
    {
       /* Meant to represent a group of many stars without planets, as they are a subset of stellar systems.
          "Classical" stable stellar systems are usually singular or binary, but there is no limit on the
          number of stars the could be contained. This is just meant to make the differentiation between
          star-only systems and stars with non-stellar orbital bodies easier. */
    };
}

#endif