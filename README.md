## Traveling Salesperson Problem

#### Part 1: Randomized Search

##### Lucas Hamilton and Harrison Nicholls

##### cities.cc

- To overload the >> operator, we looped through the whole infile, and used operator chaining to make each line into a `coord_t`. Then we put this into the `Cities` object's `cities_list_` data member using `push_back`. 
- To overload the << operator, we looped through the given `Cities` object's city list data member, and again used operator chaining, this time to put the first and second attributes of each `coord_t` object into the outfile, separated by a tab character.
  - Both of the operator overloads were implemented as friend functions
- For `total_path_distance` we looped through the permutation vector, adding the distance between each pair of cities to a local variable called `distance`. We then added the distance between the first and last cities in the permutation to result in the total distance of the path.
  - We wrote a function called `distance_between_coords` that takes in two `coord_t` and returns their distance. This is used by `total_path_distance`
- 	`reorder` simply takes a permutation, and creates a new `std::vector<coord_t>`, to which it appends the cities in the appropriate order. It then constructs a new `Cities` object with this vector, and returns it.
- 	`random_permutation` starts by creating a `std::random_device`, to use as a seed. It then creates a `std::mt19937`, which is an implementation of a mersenne twister. This is passed the seed created in the previous step. It then creates a vector of consecutive unsigned ints and calls `std::shuffle` on the vector with the mersenne twiste as the last argument.

#####  tsp.cc

- In tsp.cc we just have a main function. We start by using `operator>>` to read the infile given as a command argument into a `Cities` object. We then have a loop that repeats 1,000,000 times, creating a new permutation of cities, and checking if the new permutation beats the previous best distance. If it does, it calls `reorder` on the cities object with the permutation that had the new lowest distance. Finally, we used the << operator to store the data of the cities object (now with the shortest permutation of cities found) into the outfile, which we specified will have the name shortest.tsv.
