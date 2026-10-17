#include <iostream>
using namespace std;

int graph[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0}
};
int color[4] = {-1, -1, -1, -1};
char vertexName[4] = {'A', 'B', 'C', 'D'};
const char* colorName[3] = {"Red", "Green", "Blue"};

bool isSafe(int v, int c) {
    for (int i = 0; i < 4; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool colorGraph(int v) {
    if (v == 4) {
        return true;
    }
    for (int c = 0; c < 3; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (colorGraph(v + 1)) {
                return true;
            }
            color[v] = -1;
        }
    }
    return false;
}

int main() {
    if (colorGraph(0)) {
        cout << "Valid coloring found :" << endl;
        for (int i = 0; i < 4; i++) {
            cout << vertexName[i] << " -> " << colorName[color[i]] << endl;
        }
    } else {
        cout << "No valid coloring exists" << endl;
    }
    return 0;
}
