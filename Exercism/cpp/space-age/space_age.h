#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H
#include "string"
#include "map"
#include "vector"
#include "algorithm"

namespace space_age {
	class space_age{
		public:
		// ctor
		space_age(float time);
		// data members
		const float time;
		// member methods
		float on_mercury() const;	
		float on_venus() const;
		float on_earth() const;
		float on_mars() const;
		float on_jupiter() const;
		float on_saturn() const;
		float on_uranus() const;
		float on_neptune() const;
		float on_planet(std::string planet) const;
		float calculate_age_on_planet(std::string planet, float time) const;
		long seconds() const;
		private:
		// data elements
		const std::map<std::string, float> multipliers{{"Mercury", 0.2408467}, 
														{"Venus", 0.61519726}, 
														{"Earth", 1.0}, 
														{"Mars", 1.8808158}, 
														{"Jupiter", 11.862615}, 
														{"Saturn", 29.447498}, 
														{"Uranus", 84.016846}, 
														{"Neptune", 164.79132}
														};	
	
		const std::map<std::string, float> space_age_cache{{"Mercury", calculate_age_on_planet("Mercury", time)}, 
															{"Venus", calculate_age_on_planet("Venus", time)}, 
															{"Earth", calculate_age_on_planet("Earth", time)}, 
															{"Mars", calculate_age_on_planet("Mars", time)}, 
															{"Jupiter", calculate_age_on_planet("Jupiter", time)}, 
															{"Saturn", calculate_age_on_planet("Saturn", time)}, 
															{"Uranus", calculate_age_on_planet("Uranus", time)}, 
															{"Neptune", calculate_age_on_planet("Neptune", time)}
															};
	};
}  // namespace space_age

#endif // SPACE_AGE_H