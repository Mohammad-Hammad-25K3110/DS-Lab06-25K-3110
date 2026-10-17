#include <iostream>
using namespace std;

char chars[4] = {'A', 'B', 'C', 'D'};
char result[4];
bool used[4] = {false, false, false, false};
int count = 0;

void permute(int pos) {
    if (pos == 4) {
        count++;
        for (int i = 0; i < 4; i++) {
            cout << result[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!used[i]) {
            used[i] = true;
            result[pos] = chars[i];
            permute(pos + 1);
            used[i] = false;
        }
    }
}

int main() {
    cout << "-- All permutations --" << endl;
    permute(0);
    cout << "Total : " << count << endl;
    return 0;
}
