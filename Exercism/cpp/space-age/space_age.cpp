#include "space_age.h"

using namespace std;
namespace space_age {
	// std::map<std::string, float> planet_age_cache{{"Mercury", -1}, {"Venus", -1}, {"Earth", -1}, {"Mars", -1}, {"Jupiter", -1}, {"Saturn", -1}, {"Uranus", -1}, {"Neptune", -1}};
	// problem is, the variable belongs to the namespace, I need it to belong to the class object, ie unique map per space_age::object
	float space_age::on_planet(string planet, float time) const{
		if(space_age_cache.find(planet)==space_age_cache.end()){
			insert_planet_age(planet, time);
		}
		return space_age_cache.at(planet);
	}
	void space_age::insert_planet_age(std::string planet, float time) const{
		space_age_cache.insert({planet, time / 60 / 60 / 24 / 365.25 / multipliers.at(planet)});
	}
	float space_age::on_mercury() const{
		string planet = "Mercury";
		return on_planet(planet, time);
	}
		float space_age::on_venus() const{
		string planet = "Venus";
		return on_planet(planet, time);
	}
		float space_age::on_earth() const{
		string planet = "Earth";
		return on_planet(planet, time);
	}
		float space_age::on_mars() const{
		string planet = "Mars";
		return on_planet(planet, time);
	}
		float space_age::on_jupiter() const{
		string planet = "Jupiter";
		return on_planet(planet, time);
	}
		float space_age::on_saturn() const{
		string planet = "Saturn";
		return on_planet(planet, time);
	}
		float space_age::on_uranus() const{
		string planet = "Uranus";
		return on_planet(planet, time);
	}
		float space_age::on_neptune() const{
		string planet = "Neptune";
		return on_planet(planet, time);
	}
		long space_age::seconds() const{
			return (long) time;
		}
	space_age::space_age(float seconds){
		time = seconds;
	}
}  // namespace space_age
