#include<iostream>

using namespace std;

int main() {
	
	const int bit_num = 16;
	
	int n, num, tmp = 0;
	char ANS[bit_num];

	int i = 0;

	cout << "何進数に変換しますか(2,3,4,5,6,7,8,9,16)?" << endl;
	cin >> n;

	cout << "10進数はなんですか?" << endl;
	cin >> num;
	tmp = num;


	switch (n) {

	case 2:

	case 3:

	case 4:

	case 5:

	case 6:

	case 7:

	case 8:

	case 9:

		do {

			ANS[i] = tmp % n;
			tmp /= n;
			++i;

		} while (tmp > 0 && i < bit_num);

		cout << "(" << num << ")10=(";

		for (int j = i - 1; j >= 0; --j) {

			ANS[j] += '0';
			cout << ANS[j];

		}

		cout << ")" << n << endl;
		break;

	case 16:

		do {

			ANS[i] = tmp % n;

			if (ANS[i] == 10) {

				ANS[i] = 'A';

			}

			else if (ANS[i] == 11) {

				ANS[i] = 'B';

			}

			else if (ANS[i] == 12) {

				ANS[i] = 'C';

			}

			else if (ANS[i] == 13) {

				ANS[i] = 'D';

			}

			else if (ANS[i] == 14) {

				ANS[i] = 'E';

			}

			else if (ANS[i] == 15) {

				ANS[i] = 'F';

			}

			else {

				ANS[i] += '0';
			}

			tmp /= n;
			++i;

		} while (tmp > 0 && i < bit_num);

		cout << "(" << num << ")10=(";

		for (int j = i - 1; j >= 0; --j) {

			cout << ANS[j];

		}

		cout << ")" << n << endl;
		break;

	default:

		cout << "まだその数は対応していない" << endl;
		return 1;

	}

	return 0;

}