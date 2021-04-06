#include "space_age.h"

using namespace std;
namespace space_age
{
	space_age::space_age(float seconds): time(seconds) {}

	float space_age::on_planet(string planet) const
	{
		return space_age_cache.at(planet);
	}
	float space_age::calculate_age_on_planet(string planet, float time) const{
		return time / 60 / 60 / 24 / 365.25 / multipliers.at(planet);
	}
	float space_age::on_mercury() const
	{
		return on_planet("Mercury");
	}
	float space_age::on_venus() const
	{
		return on_planet("Venus");
	}
	float space_age::on_earth() const
	{
		return on_planet("Earth");
	}
	float space_age::on_mars() const
	{
		return on_planet("Mars");
	}
	float space_age::on_jupiter() const
	{
		return on_planet("Jupiter");
	}
	float space_age::on_saturn() const
	{
		return on_planet("Saturn");
	}
	float space_age::on_uranus() const
	{
		return on_planet("Uranus");
	}
	float space_age::on_neptune() const
	{
		return on_planet("Neptune");
	}
	long space_age::seconds() const
	{
		return (long)time;
	}

	} // namespace space_age
