#include "space_age.h"

using namespace std;
namespace space_age
{

	float space_age::on_planet(string planet) const
	{
		return space_age_cache.at(planet);
	}

	float space_age::on_mercury() const
	{
		string planet = "Mercury";
		return on_planet(planet);
	}
	float space_age::on_venus() const
	{
		string planet = "Venus";
		return on_planet(planet);
	}
	float space_age::on_earth() const
	{
		string planet = "Earth";
		return on_planet(planet);
	}
	float space_age::on_mars() const
	{
		string planet = "Mars";
		return on_planet(planet);
	}
	float space_age::on_jupiter() const
	{
		string planet = "Jupiter";
		return on_planet(planet);
	}
	float space_age::on_saturn() const
	{
		string planet = "Saturn";
		return on_planet(planet);
	}
	float space_age::on_uranus() const
	{
		string planet = "Uranus";
		return on_planet(planet);
	}
	float space_age::on_neptune() const
	{
		string planet = "Neptune";
		return on_planet(planet);
	}
	long space_age::seconds() const
	{
		return (long)time;
	}
	space_age::space_age(float seconds)
	{
		time = seconds;
		for (auto planet : multipliers)
		{
			space_age_cache.insert({planet.first, time / 60 / 60 / 24 / 365.25 / multipliers.at(planet.first)});
		}
	}
} // namespace space_age
