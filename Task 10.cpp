#include <iostream>
using namespace std;

char grid[4][4] = {
    {'D', 'O', 'G', 'S'}, //making a character grid of 4x4
    {'C', 'A', 'T', 'E'},
    {'B', 'X', 'R', 'N'},
    {'M', 'P', 'L', 'K'}
};
bool visited[4][4] = {false};
char word[] = "CAT";

bool search(int r, int c, int index) {
    if (r < 0 || r >= 4 || c < 0 || c >= 4) {
        return false;
    }
    if (visited[r][c] || grid[r][c] != word[index]) {
        return false;
    }
    if (word[index + 1] == '\0') {
        return true;
    }
    visited[r][c] = true;
    bool found = search(r + 1, c, index + 1) ||
                 search(r - 1, c, index + 1) ||
                 search(r, c + 1, index + 1) ||
                 search(r, c - 1, index + 1);
    visited[r][c] = false;
    return found;
}

int main() {
    bool found = false;
    for (int i = 0; i < 4 && !found; i++) {
        for (int j = 0; j < 4 && !found; j++) {
            if (search(i, j, 0)) {
                found = true;
            }
        }
    }

    if (found) {
        cout << "Word " << word << " exists in the grid" << endl;
    } else {
        cout << "Word " << word << " does not exist in the grid" << endl;
    }
    return 0;
}
