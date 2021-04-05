#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H
#include "string"
#include "map"
namespace space_age {
	class space_age{
		private:
		std::map<std::string, float> multipliers{{"Mercury", 0.2408467}, {"Venus", 0.61519726}, {"Earth", 1.0}, {"Mars", 1.8808158}, {"Jupiter", 11.862615}, {"Saturn", 29.447498}, {"Uranus", 84.016846}, {"Neptune", 164.79132}};		
		std::map<std::string, float> space_age_cache{};
		public:
		float time;
		space_age(float time);
		float on_mercury() const;	
		float on_venus() const;
		float on_earth() const;
		float on_mars() const;
		float on_jupiter() const;
		float on_saturn() const;
		float on_uranus() const;
		float on_neptune() const;
		float on_planet(std::string planet, float time) const;
		void insert_planet_age(std::string planet, float time) const;
		long seconds() const;
	};
}  // namespace space_age

#endif // SPACE_AGE_H