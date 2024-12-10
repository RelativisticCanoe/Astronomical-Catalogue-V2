#ifndef ASTROOBJECT_HH
#define ASTROOBJECT_HH

/* Abstract Base Class for encapsulating data shared by all astronmical objects.
Also includes utilities for saving object to file. */

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
    class astro_object
    {   
        protected:
            //Class Attributes
            astrocat::AstroType obj_type{astrocat::AstroType::Unassigned};
            std::string obj_name{"Unassigned"};
            double redshift{0};
            double distance{0}; //create a custom distance class for pc & AU?
            double mass{0}; //again, create a mass class
            double rot_vel{0};
            
            //Pointer to parent object - used if instance is a satellite of another instance
            std::weak_ptr<astrocat::astro_object> parent_ptr{};

            //Satellite Attributes
            std::vector<astrocat::satellite> sat_vector{};
            int sat_no{0};

        public:
            //Allows catalogue to modify instances as needed given that it is a management class
            friend class astrocat::catalogue;
            
            //Constructors
            astro_object() = default;
            astro_object(std::string name_input);
            astro_object(std::string name_input, double z, double dist, double m, double omega);

            //Deep Copy Constructor and Assignment Operator
            astro_object(const astro_object& obj);
            virtual astro_object& operator=(const astro_object& obj);

            //Move Constructor and Assignment Operator
            astro_object(astro_object&& obj);
            virtual astro_object& operator=(astro_object&& obj);

            //Destructor - default is used as no raw ptrs are present, smart ptrs handle garbage collection
            ~astro_object();

            //Methods
            virtual void save_to_file(std::fstream& file_data);

            //Getters
            astrocat::satellite get_sat(int& index);
            std::vector<astrocat::satellite> get_all_sats();

            std::string get_name() const {return this->obj_name;}
            int get_sat_no() const {return this->sat_no;}

            void output_props(); //Change to sstream?
            virtual void output_spec_props() = 0;

            //Setters
            void add_satelliite(std::shared_ptr<astrocat::satellite> sat_ptr);
            void add_satelliite(std::shared_ptr<astrocat::satellite> sat_ptr, double orb_dist, double orb_tilt, double orb_ecc);

            virtual void set_props();
    };
};

#endif