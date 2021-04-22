#include <iostream>
#include <fstream>
#include "cities.hh"

//Constructor for Cities
Cities::Cities(){

}

//Constructor for Cities that takes parameter for cities_list
Cities::Cities(std::vector<coord_t> citiesvector){
	cities_list_ = citiesvector;
}

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

//Make a reordered cities object based on permutation
Cities
Cities::reorder(const Cities::permutation_t& ordering) const{
	std::vector<coord_t> cities_reordered;
	for (unsigned i: ordering){
		cities_reordered.push_back(cities_list_[i]);
	}
	Cities new_cities_object = Cities(cities_reordered); //Construct Cities object with the reordered cities list
	return new_cities_object;
}
//overload >> operator
std::istream 
&operator>> (std::istream& input, Cities& cities) {
 	Cities::coord_t newcoord;
	input >> newcoord.first >> newcoord.second;
	cities.cities_list_.push_back(newcoord);
	return input;            
}

// overload << operator
std::ostream 
&operator<< (std::ostream& output, Cities& cities) { 
	// std::string outputstring;
     for (Cities::coord_t coords : cities.cities_list_){
     	output << coords.first << coords.second;
     }
     return output;            
}



int main(){
	auto fin = std::ifstream("five.tsv");
	Cities cities;
	fin >> cities;
	std::cout << cities.total_path_distance({ 0, 1, 2, 3, 4 }) << "\n"; // Should be 48.8699
	std::cout << cities.total_path_distance({ 3, 2, 4, 0, 1 }) << "\n"; // Should be 53.42.43
	return 1;
}