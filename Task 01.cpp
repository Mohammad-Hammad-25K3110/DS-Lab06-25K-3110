#include <iostream>
using namespace std;

void printReverse(string s, int i) {
    if (i == s.length()) {
        return;
    }
    printReverse(s, i + 1);
    cout << s[i];
}

int main() {
    string s;
    cout << "Enter a string : ";
    cin >> s;

    cout << "Reversed string : ";
    printReverse(s, 0);
    cout << endl;
    return 0;
}
