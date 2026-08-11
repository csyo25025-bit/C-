#include<iostream>

using namespace std;

int main() {

	const int bit_num = 16;
	int dec;

	char hex[bit_num] = {

		0

	};

	int tmp, i;

	cout << "input decimal:";
	cin >> dec;
	tmp = dec;
	i = 0;

	do{

		hex[i] = tmp % 16;

		if (hex[i] == 10) {
		
			hex[i] = 'A';
		
		}

		else if (hex[i] == 11) {
		
			hex[i] = 'B';

		}

		else if (hex[i] == 12) {

			hex[i] = 'C';

		}

		else if (hex[i] == 13) {

			hex[i] = 'D';

		}

		else if (hex[i] == 14) {

			hex[i] = 'E';

		}

		else if (hex[i] == 15) {

			hex[i] = 'F';

		}

		else {

			hex[i] += '0';
		}
		
		

		tmp /= 16;
		++i;

	} while (tmp > 0 && i < bit_num);

	cout << "(" << dec << ")10=(";

	for (int j = i-1; j >= 0; --j) {

		cout << hex[j];

	}

	cout << ")16" << endl;
	return 0;

}