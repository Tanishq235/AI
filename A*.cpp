#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // simple 3x3 grid (0 = free, 1 = block)
    int grid[3][3] = {
        {0, 0, 0},
        {1, 0, 1},
        {0, 0, 0}
    };

    int startX = 0, startY = 0;
    int goalX = 2, goalY = 2;

    int visited[3][3] = {0};

    int x = startX;
    int y = startY;

    cout << "Path:\n";

    while (!(x == goalX && y == goalY)) {

        visited[x][y] = 1;
        cout << "(" << x << "," << y << ") -> ";

        int bestX = x, bestY = y;
        int minF = 1000;

        // check 4 directions
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3 &&
                grid[nx][ny] == 0 && visited[nx][ny] == 0) {

                int g = 1; // simple cost
                int h = abs(nx - goalX) + abs(ny - goalY);
                int f = g + h;

                if (f < minF) {
                    minF = f;
                    bestX = nx;
                    bestY = ny;
                }
            }
        }

        x = bestX;
        y = bestY;
    }

    cout << "(" << goalX << "," << goalY << ")";

    return 0;
}
