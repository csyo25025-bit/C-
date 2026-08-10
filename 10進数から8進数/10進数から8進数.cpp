#include<iostream>

using namespace std;

int main() {

	const int bit_num = 16;
	int dec;
	
	int oct[bit_num] = {

		0

	};
	
	int tmp, i;

	cout << "input decimal:";
	cin >> dec;
	tmp = dec;
	i = 0;

	while (tmp > 0 && i < bit_num) {
	
		oct[i] = tmp % 8;
		tmp /= 8;
		++i;
	
	}

	cout << "(" << dec << ")10=(";

	for (int j = bit_num - 1; j >= 0; --j) {
	
		cout << oct[j];
	
	}

	cout << ")8" << endl;
	return 0;

}