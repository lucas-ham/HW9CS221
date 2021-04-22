#include <iostream>
#include <fstream>
#include "cities.hh"

std::istream &operator>> (std::istream& input, Cities& cities) { 
	input >> *cities;
	return input;            
//find the distance between two coord_t objects
unsigned distance_between_coords(Cities::coord_t city_one,Cities::coord_t city_two){
	int xdist = (city_one.first - city_two.first);
	int ydist = (city_one.second - city_two.second);
	return sqrt(pow(xdist,2) + pow(ydist,2));
}
//overload << operator
std::ostream &operator<< (std::ostream& output, Cities& cities) { 
     output << *cities;
     return output;            
}



int main(){
	Cities city = Cities();
	std::cout<<city;
	return 1;
}