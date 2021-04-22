#include "cities.hh"

//Constructor for Cities
Cities::Cities(){

}

//Constructor for Cities that takes parameter for cities_list
Cities::Cities(std::vector<coord_t> citiesvector){
	cities_list_ = citiesvector;
}

//find the distance between two coord_t objects
double distance_between_coords(Cities::coord_t city_one,Cities::coord_t city_two){
	double xdist = (city_one.first - city_two.first);
	double ydist = (city_one.second - city_two.second);
	return sqrt(pow(xdist,2) + pow(ydist,2));
}

//Find the total path distance
double
Cities::total_path_distance(const Cities::permutation_t& ordering) const{
	double distance = 0;
	for (unsigned i = 0; i < cities_list_.size() - 1; i++){ //iterate through permutation vector, stopping at 2nd to last element
		double nextstep = distance_between_coords(cities_list_[ordering[i]],cities_list_[ordering[i+1]]);
		distance += nextstep;
	}
	//add the distance from the last city to the first city in the permutation
	coord_t first_city = cities_list_[ordering[0]];
	coord_t last_city = cities_list_[ordering.back()];
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
 	while (!input.eof()){
	 	Cities::coord_t newcoord;
		input >> newcoord.first >> newcoord.second;
		cities.cities_list_.push_back(newcoord);
	}
	cities.cities_list_.pop_back(); //remove extra last city
	return input;
}

// overload << operator
std::ostream
&operator<< (std::ostream& output, Cities& cities) {
	// std::string outputstring;
     for (Cities::coord_t coords : cities.cities_list_){
     	output << coords.first << "	" << coords.second << std::endl;
     }
     return output;
}

//Generate a random permutation from 0 to n-1
Cities::permutation_t
Cities::random_permutation(unsigned len){
	std::random_device rd;				// this returns an object that will be passed as a seed to g
	std::mt19937 g(rd());					// returns g which, using rd to generate a seed value, computes a random number using a mersenne twister


	std::vector<unsigned> to_shuffle;
	for (unsigned i=0; i < len; ++i){
		to_shuffle.push_back(i); //create a vector, not shuffled
	}
	// using built-in random generator:
	std::shuffle(to_shuffle.begin(), to_shuffle.end(), g); //shuffle uses this random generator to choose indices at which to swap elements in the vector
	return to_shuffle;
}
