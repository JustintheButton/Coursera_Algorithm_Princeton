#include <random>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Percolation {
public:
    // creates n-by-n grid, with all sites initially blocked
    Percolation(int n) {
        vector<int> temp(n);
        grid.resize(n, temp);
    }

    // opens the site (row, col) if it is not open already
    void open(int row, int col) {
        grid[row - 1][col - 1] = 1;
    }

    // is the site (row, col) open?
    bool isOpen(int row, int col) {
        return grid[row - 1][col - 1];
    }

    // is the site (row, col) full?
    bool isFull(int row, int col) {
        
    }

    // returns the number of open sites
    int numberOfOpenSites() {
        int n = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == 1) {
                    n++;
                }
            }
        }
        return n;
    }

    // does the system percolate?
    bool percolates() {

    }
private:
    vector<vector<int> > grid;
};

int main()
{
    std::cout << "Hello World!\n";
}