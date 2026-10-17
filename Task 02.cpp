#include <iostream>
using namespace std;

void printAscending(int n) {
    if (n == 0) {
        return;
    }
    printAscending(n - 1);
    cout << n << " ";
}

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    cout << "Sequence : ";
    printAscending(n);
    cout << endl;
    return 0;
}
