#include <iostream>
#include <fstream>
#include "cities.hh"

//find the distance between two coord_t objects
unsigned distance_between_coords(Cities::coord_t city_one,Cities::coord_t city_two){
	int xdist = (city_one.first - city_two.first);
	int ydist = (city_one.second - city_two.second);
	return sqrt(pow(xdist,2) + pow(ydist,2));
}
//Find the total path distance
double 
Cities::total_path_distance(const Cities::permutation_t& ordering) const{
	unsigned distance = 0;
	for (unsigned i = 0; i < ordering.size() - 2; i++){ //iterate through permutation vector, stopping at 2nd to last element
		unsigned nextstep = distance_between_coords(cities_list_[i],cities_list_[i+1]);
		distance += nextstep;
	}
	//add the distance from the last city to the first city in the permutation
	coord_t first_city = cities_list_[ordering[0]];
	coord_t last_city = cities_list_[ordering[ordering.size() - 1]];
	distance += distance_between_coords(first_city,last_city);
	return distance;
}
//overload >> operator
std::istream &operator>> (std::istream& input, Cities& cities) {
 	Cities::coord_t newcoord;
	input >> newcoord.first >> newcoord.second;
	cities.cities_list_.push_back(newcoord);
	return input;            
}
// overload << operator
std::ostream &operator<< (std::ostream& output, Cities& cities) { 
	// std::string outputstring;
     for (Cities::coord_t coords : cities.cities_list_){
     	output << coords.first << coords.second;
     }
     return output;            
}



int main(){
	return 1;
}