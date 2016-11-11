#include <iostream>
#include <string>
#include <vector>

typedef unsigned int uint;

std::vector<uint> prefix_func(std::string str) {
	uint n = str.size();
	std::vector<uint> res(n);
	for (uint i = 1; i < n; ++i) {
		int j = res[i - 1];
		while (j > 0 && str[i] != str[j])
			j = res[j - 1];
		if (str[i] == str[j])  
			++j;
		res[i] = j;
	}
	return res;
}

int main(){
	
	std::string inp;
	
	std::cin >> inp;
	uint len_inp = inp.size();
	
	std::vector<uint> pi_inp = prefix_func(inp);
	
	uint len = 0;
	
	for (uint i = 0; i < len_inp; ++i) {
		if (pi_inp[i] != 0) {
			if (pi_inp[i - 1] == 0)
				len = i;
			while (i < len_inp && pi_inp[i - 1] < pi_inp[i])
				++i;
			if (i < len_inp && pi_inp[i] == 0) {
				len = i + 1;
				continue;
			}
			if (i < len_inp && pi_inp[i - 1] >= pi_inp[i])
				len = i;
		}
	}
	
	if (len == 0) len = len_inp;
	
	std::cout << len << std::endl;
	
	return 0;
}
