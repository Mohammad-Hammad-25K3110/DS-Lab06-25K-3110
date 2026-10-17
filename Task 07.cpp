#include <iostream>
using namespace std;

int arr[5] = {2, 3, 5, 6, 8};
int chosen[5] = {0, 0, 0, 0, 0};
int target = 9;

bool findSubset(int index, int sum) {
    if (sum == target) {
        return true;
    }
    if (index == 5 || sum > target) {
        return false;
    }
    chosen[index] = 1;
    if (findSubset(index + 1, sum + arr[index])) {
        return true;
    }
    chosen[index] = 0;
    return findSubset(index + 1, sum);
}

int main() {
    if (findSubset(0, 0)) {
        cout << "Subset with sum " << target << " : ";
        for (int i = 0; i < 5; i++) {
            if (chosen[i] == 1) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    } else {
        cout << "No subset with sum " << target << " exists" << endl;
    }
    return 0;
}
