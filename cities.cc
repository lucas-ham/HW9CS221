#include <iostream>
#include <fstream>
#include "cities.hh"

std::istream &operator>> (std::istream& input, Cities& cities) { 
	input >> *cities;
	return input;            
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