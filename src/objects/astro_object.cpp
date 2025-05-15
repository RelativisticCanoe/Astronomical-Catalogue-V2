//STL Headers
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <memory>

//Project Headers
#include "object_enums\astro_types.h"
#include "containers\catalogue.h"
#include "containers\satellite.h"

namespace astrocat
{
    astro_object::astro_object(std::string name_input)
    {
        std::swap(this->obj_name, name_input);
    }

    astro_object::astro_object(std::string name_input, double z, double dist, double m, double omega)
    {
        this->obj_name = name_input;
        this->redshift = z;
        this->distance = dist;
        this->mass = m;
        this->rot_vel = omega;
    }

    astro_object::astro_object(const astro_object& obj)
    {
        this->obj_type = obj.obj_type;
        this->obj_name = obj.obj_name;
        this->redshift = obj.redshift;
        this->distance = obj.distance;
        this->mass = obj.mass;
        this->rot_vel = obj.rot_vel;
        this->sat_vector = obj.sat_vector;
        this->sat_no = obj.sat_no;
    }

    astro_object& astro_object::operator=(const astro_object& obj)
    {
        if(&obj == this){
            return *this;
        } else{
            this->obj_type = obj.obj_type;
            this->obj_name = obj.obj_name;
            this->redshift = obj.redshift;
            this->distance = obj.distance;
            this->mass = obj.mass;
            this->rot_vel = obj.rot_vel;
            this->sat_vector = obj.sat_vector;
            this->sat_no = obj.sat_no;
            return *this;            
        }
    }

    astro_object::astro_object(astro_object&& obj)
    {
        std::swap(this->obj_type, obj.obj_type);
        std::swap(this->obj_name, obj.obj_name);
        std::swap(this->redshift, obj.redshift);
        std::swap(this->distance, obj.distance);
        std::swap(this->mass, obj.mass);
        std::swap(this->rot_vel, obj.rot_vel);
        std::swap(this->sat_vector, obj.sat_vector);
        std::swap(this->sat_no, obj.sat_no);
    }

    astro_object& astro_object::operator=(astro_object&& obj)
    {
        std::swap(this->obj_type, obj.obj_type);
        std::swap(this->obj_name, obj.obj_name);
        std::swap(this->redshift, obj.redshift);
        std::swap(this->distance, obj.distance);
        std::swap(this->mass, obj.mass);
        std::swap(this->rot_vel, obj.rot_vel);
        std::swap(this->sat_vector, obj.sat_vector);
        std::swap(this->sat_no, obj.sat_no);
        return *this;
    }

    std::string astro_object::output_props()
    {
        /* Writes the properties shared by all astro_object instances to a string for output via cout.
           Calls an additional function to output class-specific properties within each derived class.
           Also writes the number of satellites (and eventually the names of the satellites) to the string.
           
           SI units for mass and distance are placeholders until I create astronomical unit classes with
           conditional output e.g. determining whether the output should be in AU, pc or km for distances.*/
        std::stringstream buffer{};
        buffer.precision(5); 
        buffer << "Name: " << this->obj_name << " \n"
            << "Type: " << this->obj_type << " \n"
            << "Mass: " << this->mass << " kg" << "\n"
            << "Rotational Velocity: " << this->rot_vel << "rads^-1" << "\n"
            << "Distance: " << this->distance << " km" << "\n"
            << "Redshift: " << this->redshift << " \n"
            << this->output_spec_props()
            << "No. Satellites: " << this->sat_no << " \n" //Insert some sort of satellite name-fetch here
            << "-------------------" << std::endl; //Helps to distingguish that the object's properties end here, like a receipt of sorts
        return buffer.str();
    }

    std::string astro_object::output_spec_props()
    {
        /* Returns derived-class-specific attributes via overrides in implementation. As this is the base class, 
           it has no specific attributes that the derived classes don't also have, so this function returns a
           newline unless overriden. */
        std::stringstream buffer{};
        buffer << std::endl;
        return buffer.str();
    }

    const satellite& astro_object::get_sat(int index)
    {
        /* NEEDS TO BE CAUGHT HIGHER IN THE MAIN PROGRAM IF BAD INPUT PROVIDED.
           THE THROW HERE IS A FAILSAFE IN CASE OF UNEXPECTED INT INPUTS.*/
        if(index >= this->sat_vector.size() || index < 0){
            throw index;
        } else{
            return sat_vector[index];
        }
    }

    const std::vector<satellite>& astro_object::get_all_sats()
    {
        return this->sat_vector;
    }
}