#include <iostream>

using namespace std;

int main() {

    const int bit_num = 32;
    const char digits[] = "0123456789ABCDEF";

    int n, num, tmp;
    char ANS[bit_num];
    int i = 0;

    cout << "何進数に変換しますか(2-16)?" << endl;
    cin >> n;

    if (n < 2 || n > 16) {

        cout << "2から16の範囲で入力してください。" << endl;
        return 1;

    }

    cout << "10進数はなんですか?" << endl;
    cin >> num;
    tmp = num;

    do {

        ANS[i] = digits[tmp % n];
        tmp /= n;
        ++i;
    
    } while (tmp > 0 && i < bit_num);

    cout << "(" << num << ")10=(";

    for (int j = i - 1; j >= 0; --j) {
    
        cout << ANS[j];
    
    }
    
    cout << ")" << n << endl;
    return 0;
}