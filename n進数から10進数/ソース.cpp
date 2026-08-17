#include<iostream>

using namespace std;

int main() {

	string X;
	long long dec = 0;
	int base;
	int num;

	cout << "何進数を入力しますか？" << endl;
	cin >> base;

	if (base < 2) {

		cout << "2以上の数字を入力してください" << endl;
		return -1;

	}

	cout << "変換したい数を入力してください" << endl;
	cin >> X;

	string tmp = X;

	int ex = X.length();

	for (int i = 0; i < ex; ++i) {

		if (X[i] >= '0' && X[i] <= '9') {
		
			num = X[i] - '0';
		
		}

		else if ((X[i] >= 'A' && X[i] <= 'Z')) {
		
			num = X[i] - 'A' + 10;
		
		}

		else if (X[i] >= 'a' && X[i] <= 'z') {
		
			num = X[i] - 'a' + 10;
		
		}
		
		else {
		
			cout << base << "進数以外の文字が入力されている" << endl;
			return 1;

		}

		if (num >= base) {
		
			cout << base << "進数には使えない文字(" << X[i] << ")が含まれている" << endl;
			return 1;
		
		}

		dec = dec * base + num;

	}

	cout << "(" << tmp << ")" << base << "=(" << dec << ")10";
	return 0;

}