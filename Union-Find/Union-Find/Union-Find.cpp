#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <numeric>
#include <iomanip>
using namespace std;
vector<int> times;
struct Two_d_index {
    Two_d_index(int row_in, int col_in) :row(row_in), col(col_in) {}
    int row;
    int col;
};
vector<int> aroundTest(int n, int pos) {
    vector<int> answers;
    if (pos + n < n*n) {
        answers.push_back(pos + n);
    }
    if (pos - n >= 0) {
        answers.push_back(pos - n);
    }
    if ((pos + 1) % n != 0) {
        answers.push_back(pos + 1);
    }
    if (pos % n != 0) {
        answers.push_back(pos - 1);
    }
    return answers;
}
class MyUnionFind {
public:
    MyUnionFind(int n) {
        root.resize(n);
        for (int i = 0; i < n; i++) root[i] = i;
    }
    int findRoot(int a) {
        while (root[a] != a) {
            a = root[a];
        }
        return a;
    }
    void u(int a, int b) {
        int pid = root[a];
        int qid = root[b];
        for (int i = 0; i < root.size(); i++)
            if (root[i] == pid) root[i] = qid;
    }
    bool c(int a, int b) {
        return findRoot(a) == findRoot(b);
    }
    /*int find(int a) {

    }
    int count() {

    }*/
private:
    vector<int> root;
};

class Grid {
public:
    Grid(int n) :_unionfind(n* n + 2), _n(n) {
        mygrid.resize(n * n);
        for (int i = 0; i < n; i++) {
            _unionfind.u(i, n*n);
            _unionfind.u(n * n - i - 1, n * n + 1);
        }
    }
    void printGrid() {
        for (int i = 0; i < mygrid.size(); i++) {
            if (i % _n == 0 && i != 0) {
                cout << endl;
            }
            cout << mygrid[i];
        }
        cout << endl;
    }
    void printRoot() {
        cout << _unionfind.findRoot(_n * _n) << endl;
        for (int i = 0; i < _n*_n; i++) {
            if (i % _n == 0 && i!=0) {
                cout << endl;
            }
            cout << setfill('0') << std::setw(2) << _unionfind.findRoot(i) << ", ";
        }
        cout << endl;
        cout << setfill('0') << std::setw(2) << _unionfind.findRoot(_n * _n + 1);
        cout << endl;
    }
    void randomFill() {
        int change;
        do {
            change = rand() % mygrid.size();
            if (mygrid[change] == 0) {
                mygrid[change] = 1;
                break;
            }
        } while (mygrid[change] == 1);
        Two_d_index an_index = get_2d_index(change);
        vector<int> poss = aroundTest(_n, change);
        for (int i = 0; i < poss.size(); i++) {
            if (mygrid[poss[i]] == 0) {
                continue;
            }
            //cout << "push " << poss[i] << "into " << change << endl;
            _unionfind.u(poss[i], change);
            if (_unionfind.c(mygrid.size(), mygrid.size() + 1) == true) {
                times.push_back(accumulate(mygrid.begin(), mygrid.end(), 0));
                return;
            }
        }

    }
    int get_grid_value(int row_id, int column_id) {
        return row_id * mygrid.size() + column_id;
    }
    Two_d_index get_2d_index(int one_d_pos) {
        int row = one_d_pos/_n;
        int col = one_d_pos%_n;
        return Two_d_index(row, col);
    }

private:
    vector<int> mygrid;
    MyUnionFind _unionfind;
    int _n;
};

void test_union_find() {
    MyUnionFind unionfind = MyUnionFind(10);
    unionfind.u(4, 3);
    unionfind.u(3, 8);
    unionfind.u(6, 5);
    unionfind.u(9, 4);
    unionfind.u(2, 1);
    if (unionfind.c(0, 7) != false)
        throw;
    if (unionfind.c(8, 9) != true)
        throw;
    unionfind.u(5, 0);
    unionfind.u(7, 2);
    unionfind.u(6, 1);
    unionfind.u(1, 0);
    if (unionfind.c(0, 7) != true)
        throw;
}

int main()
{
    srand(time(NULL));
    int n = 20;
    for (int run = 0; run < 100000; run++) {
        Grid testgrid(n);
        for (int i = 0; i < n*n; i++) {
            int timesBefore = times.size();
            testgrid.randomFill();
            //testgrid.printGrid();
            //testgrid.printRoot();
            //cout << endl;
            if (timesBefore - times.size() != 0) {
                break;
            }
        }
        if (run % 1000 == 0 && run != 0) {
            cout << double(double(run)/100000) << endl;
        }
        //cout << run << endl;
        //cout << "percolates" << endl;
    }
    double average;
    int sum = 0;
    for (int i = 0; i < times.size(); i++) {
        sum += times[i];
    }
    average = double(sum) / times.size();
    cout << "The average blocks that it takes to percolate is " << average << endl;
    cout << average / (n * n);

    //test_union_find();
}

