#include <iostream>
#include <vector>

using namespace std;

              // RIGHT, DOWN, LEFT, UP
const int DX[4] = {0, 1, 0, -1};
const int DY[4] = {1, 0, -1, 0};

void build_spiral_rec(
    int x,
    int y,
    int number,
    int width,
    int side,
    int i,
    vector<vector<size_t>>& spiral)
{
    if (width == 0) {
        return;
    }

    if (side == 4) {
        build_spiral_rec(x, y, number, width, 0, 0, spiral);
        return;
    }

    if (i == width) {
        if (side == 0 || side == 2) {
            --width;
        }
        build_spiral_rec(x, y, number, width, side + 1, 0, spiral);
        return;
    }

    int nx = x + DX[side];
    int ny = y + DY[side];
    spiral[nx][ny] = number;
    build_spiral_rec(nx, ny, number + 1, width, side, i + 1, spiral);
}

vector<vector<size_t>> build_spiral(int n)
{
    vector<vector<size_t>> spiral(n, vector<size_t>(n, 0));

    build_spiral_rec(0, -1, 1, n, 0, 0, spiral);
    return spiral;
}

vector<vector<size_t>> build_spiral_iterative(int n)
{
    vector<vector<size_t>> spiral(n, vector<size_t>(n, 0));
    int x = 0;
    int y = -1;
    int number = 1;
    int width = n;
    for (int layer = 0; layer < (n + 1) / 2; ++layer) {
        for (int side = 0; side < 4; ++side) {
            for (int i = 0; i < width; ++i) {
                int nx = x + DX[side];
                int ny = y + DY[side];
                spiral[nx][ny] = number++;
                x = nx;
                y = ny;
            }
            if (side == 0 || side == 2) {
                --width;
            }
        }
    }

    return spiral;
}

void print_spiral(const vector<vector<size_t>>& spiral)
{
    for (const auto& line : spiral) {
        for (const auto& item : line) {
            cout << item << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    auto spiral = build_spiral(N);
    print_spiral(spiral);
    return 0;
}


