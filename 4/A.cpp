#include <stdio.h>
#include <cmath>

int main() {
	int N;
	scanf("%d", &N);
	int inp[N][N];
	
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &inp[i][j]);
		}
	}
	
	int x;
	scanf("%d", &x);
	
	for (int i = 0; i < N; ++i) {
		int left = 0;
		int right = N - 1;
		if (x > inp[i][right] || x < inp[i][left])
			continue;
		while(left < right) {
			int middle = (left + right) / 2;
			if (inp[i][middle] >= x)
				right = middle;
			else 
				left = middle + 1;
		}
		if (inp[i][right] == x) {
			printf("yes\n");
			return 0;
		}
	}
	
	printf("no\n");
	
	return 0;
}
