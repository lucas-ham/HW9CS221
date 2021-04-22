#include "cities.hh"
#include <iostream>
#include <fstream>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <random>
#include "cities.hh"

int main(int argc, char **argv){
	/////////////////////// Tests, to remove later 
	// auto fin = std::ifstream("five.tsv");
	// Cities citiestest;
	// fin >> citiestest;
	// Cities::permutation_t permtest = citiestest.random_permutation(10);
	// for (unsigned i: permtest){
	// 	std::cout<<i<<" ";
	// }
	// std::cout << "\n" << citiestest << "\n"; // added to check if getting the right output
	// std::cout << citiestest.total_path_distance({ 0, 1, 2, 3, 4 }) << "\n"; // Should be 48.8699
	// std::cout << citiestest.total_path_distance({ 3, 2, 4, 0, 1 }) << "\n"; // Should be 53.42.43
	// ///////////////////////
	
	assert(argc == 2); //make sure there are two command line arguments
	std::string filename;
	filename = argv[1]; //initialize and set filename to the name of the infile
	std::ifstream Infile(filename);
	std::ofstream Outfile("shortest.tsv");
	Cities cities;
	Infile>>cities;


	double shortest = -1;
	for (unsigned j = 0; j < 1000000; j++){
		Cities::permutation_t perm = cities.random_permutation(cities.cities_list_.size());
		double perm_dist = cities.total_path_distance(perm);
		if (perm_dist < shortest || shortest < 0){
			shortest = perm_dist;
			std::cout<<j << "	" << shortest << "\n";
			cities = cities.reorder(perm);	
		}
	}
	Outfile << cities;
	return 1;
}