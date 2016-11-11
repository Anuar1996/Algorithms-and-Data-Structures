#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

typedef unsigned int uint;
typedef std::vector <std::pair <uint, char> > arr_t;

bool comparer(const std::pair<uint, char> &a, const std::pair<uint, char> &b) {
	if (a.first > b.first) {
		return true;
	}
	if (a.first == b.first) { 
		if (a.second <= b.second) {
			return true;
		}
	}
	return false;
}

int main(void) {
	std::string input_str;
	
	std::cin >> input_str;
	
	std::map<char, uint> map_freq;
	
	for (uint i = 0; i < input_str.size(); ++i) {
		++map_freq[input_str[i]];
	}
	
	arr_t vect_freq;
	
	for (std::map<char, uint>::iterator it = map_freq.begin(); it != map_freq.end(); ++it) {
		vect_freq.push_back(std::make_pair(it->second, it->first));
	}
	
	std::sort(vect_freq.begin(), vect_freq.end(), comparer);
	
	for (arr_t::iterator it = vect_freq.begin(); it != vect_freq.end(); ++it) {
		std::cout << it->second << " " << it->first << std::endl;
	}
	
	return 0;
}
