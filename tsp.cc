#include "cities.hh"

int main(int argc, char **argv){

	assert(argc == 2); //make sure there are two command line arguments
	std::string filename;
	filename = argv[1]; //initialize and set filename to the name of the infile
	std::ifstream Infile(filename); // Open infile and outfile
	std::ofstream Outfile("shortest.tsv");
	Cities cities;
	Infile>>cities;

	double shortest = -1;
	for (unsigned i = 0; i < 1000000; i++){ //Do 1 million checks
		Cities::permutation_t perm = cities.random_permutation(cities.cities_list_.size()); //generate random permutation
		double perm_dist = cities.total_path_distance(perm); //check dist of that permutation
		if (perm_dist < shortest || shortest < 0){ //If it's the new shortest, replace the old
			shortest = perm_dist;
			std::cout << i << "	" << shortest << "\n";
			cities = cities.reorder(perm);
		}
	}
	Outfile << cities;
	return 1;
}
