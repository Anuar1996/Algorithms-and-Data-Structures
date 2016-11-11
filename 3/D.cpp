#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <cmath>

typedef unsigned int uint;
typedef unsigned long long ull;


uint N, K, M, L;

void sort(std::vector<uint> & a){
	for (uint i = 0; i < 8; ++i) {
		std::vector<std::pair<std::vector<uint> , uint> > cnt(10);
		for (uint j = 0; j < N; ++j) {
			uint ind = (a[j] / ((uint)pow(10, i))) % 10;
			++(cnt[ind].second);
			cnt[ind].first.push_back(a[j]);
		}
		
		uint k = 0;
		for (uint j = 0; j < 10; ++j) {
			if (cnt[j].second != 0) {
				for (uint m = 0; m < cnt[j].second; ++m) {
					a[k] = cnt[j].first[m];
					++k;
				}
			}
		}
	}
}

int main() {
	
	std::cin >> N >> K >> M >> L;
	std::vector<uint> a(N);
	a[0] = K;
	for (uint i = 1; i < N; ++i) {
		a[i] = (uint)((a[i - 1] * (ull)M ) & 0xFFFFFFFFU) % L;
	}
	
	ull sum = 0;
	
	sort(a);
	
	for (uint i = 0; i < N; ++i) {
		if (!(i % 2)) sum += a[i];
	}
	
	std::cout << sum % L << std::endl;
	return 0;
}
