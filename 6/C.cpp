#include <iostream>

typedef unsigned int uint;

int main(){
	
    uint N, M;
    
    std::cin >> N >> M;
    
    uint mass1[N], mass2[M];
	
    for (uint i = 0; i < N; ++i) {
        std::cin >> mass1[i];
    }
    for (uint i = 0; i < M; ++i) {
        std::cin >> mass2[i];
    }
    
    uint d[N + 1][M + 1];
    for (uint i = 0; i <= N; ++i) {
        d[i][0] = 0;
    }
    for (uint i = 0; i <= M; ++i) {
        d[0][i] = 0;
    }
    
    for (uint i = 1; i <= N; ++i) {
        for (uint j = 1; j <= M; ++j) {
            if (mass1[i - 1] == mass2[j - 1])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = std::max(d[i - 1][j], d[i][j - 1]);
			
            if (d[i][j] == M) {
                std::cout << "yes";
                return 0;
            }
        }
    }
    std::cout << "no";
	
    return 0;
}
