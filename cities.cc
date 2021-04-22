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
		unsigned nextstep = distance_between_coords(cities_list[i],cities_list[i+1]);
		distance += nextstep;
	}
	return distance;
}

// std::istream &operator>> (std::istream& input, Cities& cities) { 
// 	input >>;
// 	return input;            
// }
//overload << operator
std::ostream &operator<< (std::ostream& output, Cities& cities) { 
	// std::string outputstring;
     for (Cities::coord_t coords : cities.cities_list){
     	output << coords.first << coords.second;
     }
     return output;            
}



int main(){
	Cities city = Cities();
	std::cout<<city;
	return 1;
}