//STL Headers
#include <vector>
#include <string>
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
}