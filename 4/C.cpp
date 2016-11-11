#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

struct coords {
	int x;
	int y;
	int R;
	coords() {
		x = y = R = 0;
	}
	coords(int _x, int _y, int _R) {
		x = _x;
		y = _y;
		R = _R;
	}
};

typedef std::map<std::string, std::vector<coords> > mobileoptype;

bool inCovering(int x, int y, coords mobile_station) {
	if ((x - mobile_station.x) * (x - mobile_station.x) + 
		(y - mobile_station.y) * (y - mobile_station.y) <= 
		mobile_station.R * mobile_station.R)
		return true;
	return false;
}

int cntStations(int x, int y, std::vector<coords> stations) {
	int cnt = 0;
	
	for (std::vector<coords>::iterator it = stations.begin(); it != stations.end(); ++it) {
		if (inCovering(x, y, *it))
			++cnt;
	}
	
	return cnt;
}

int main() {
	mobileoptype mobile_op;
	std::vector<std::string> mobile_op_names;
	
	int N;
	std::cin >> N;
	
	for (int i = 0; i < N; ++i) {
		std::string mobile_op_name;
		std::cin >> mobile_op_name;
		if (mobile_op.find(mobile_op_name) == mobile_op.end()) {
			mobile_op_names.push_back(mobile_op_name);
		}
		int x, y;
		int R;
		std::cin >> x >> y >> R;
		mobile_op[mobile_op_name].push_back(coords(x, y, R));
	}
	
	int x_user, y_user;
	std::cin >> x_user >> y_user;
	
	std::cout << mobile_op.size() << std::endl;
	
	for (std::vector<std::string>::const_iterator it = mobile_op_names.begin(); it != mobile_op_names.end(); ++it) {
		std::cout << *it << " ";
		std::cout << cntStations(x_user, y_user, mobile_op[*it]) << std::endl;
	}
	
	return 0;
}
