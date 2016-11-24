#include <iostream>
#include <string>

typedef unsigned int uint;

int main(){
	
	std::string str1, str2;
	std::cin >> str1;
	std::cin >> str2;
	
	uint n = str1.size();
	uint m = str2.size();
	
	uint d[n + 1][m + 1];
	for (uint i = 0; i <= n; ++i) {
		d[i][0] = i;
	}
	for (uint i = 0; i <= m; ++i) {
		d[0][i] = i;
	}
	d[0][0] = 0;
	
	for (uint i = 1; i <= n; ++i) {
		for (uint j = 1; j <= m; ++j) {
			if (str1[i - 1] == str2[j - 1])
				d[i][j] = std::min(d[i][j - 1] + 1, 
							std::min(d[i - 1][j] + 1,
									d[i - 1][j - 1]));
			else
				d[i][j] = std::min(d[i][j - 1] + 1, 
							std::min(d[i - 1][j] + 1,
									d[i - 1][j - 1] + 1));
		}
	}
	
	std::cout << d[n][m];
	
	return 0;
}
