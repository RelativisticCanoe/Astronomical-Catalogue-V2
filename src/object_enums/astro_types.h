#ifndef ASTROTYPES_HH
#define ASTROTYPES_HH

/* Defines the types of astronomical objects handled by the program as an enum class + strings for parsing.
   Useful for creating distinct boolean states to use in switch statements, as opposed to comparing strings. */

//STL Headers
#include <iostream>
#include <string>
#include <vector>

namespace astrocat
{
    enum class AstroType
    {
        Unassigned, 
        Galaxy, GalCluster, 
        Star, MainSequenceStar, RedGiantStar, DwarfStar, StelCluster, 
        StelSystem, Planet, TerrPlanet, GasPlanet, IcePlanet, DwarfPlanet, 
        Moon, Comet, Meteor, Asteroid, 
        StelRemnant, Supernova, WhtDwarfStar, NeutronStar, Pulsar, BlackHole, 
        IntStelMedium, Nebula,
        Satellite,
    };
    
    const std::vector<std::string> AsTypeStrings
    {
        "Unassigned",
        "Galaxy", "GalaxyCluster",
        "Star", "MainSequenceStar", "RedGiantStar", "DwarfStar", "StellarCluster",
        "StellarSystem", "Planet", "TerrestrialPlanet", "GasPlanet", "IcePlanet", "DwarfPlanet",
        "Moon", "Comet", "Meteor", "Asteroid",
        "StellarRemnant", "Supernova", "WhiteDwarfStar", "NeutronStar", "Pulsar", "BlackHole",
        "InterstellarMedium", "Nebula",
        "Satellite",
    };

    std::ostream& operator<<(std::ostream& os, AstroType astype)
    {
        os << AsTypeStrings[int(astype)];
    }
}

#endif