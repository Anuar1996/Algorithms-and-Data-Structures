#include <iostream>
#include <algorithm>

std::string to_str(int a) {
	
	std::string res;
	
	for (;a > 0; a /= 10) res += a % 10 + '0';
	std::reverse(res.begin(), res.end());
	return res;
}

int main(){
	int N, K;
	
	std::cin >> N >> K;
	
	int cnt = 0;
	
	for (int i = 1; i <= N; ++i) {
		if (to_str(i) <= to_str(K))
			++cnt;
	}
	
	std::cout << cnt << std::endl;
	
	return 0;
}
