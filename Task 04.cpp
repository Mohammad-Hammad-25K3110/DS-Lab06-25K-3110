#include <iostream>
using namespace std;

int amountOnDay(int n) {
    if (n == 1) {
        return 10;
    }
    return 2 * amountOnDay(n - 1);
}

int main() {
    int n;
    cout << "Enter number of days : ";
    cin >> n;
    cout << "Amount on Day " << n << " : Rs. " << amountOnDay(n) << endl;
    return 0;
}
