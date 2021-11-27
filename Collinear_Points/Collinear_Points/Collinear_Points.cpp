#include <bits/stdc++.h>
using namespace std;
class Point;
class Point {
public:
    Point() {
        _x = 0;
        _y = 0;
    }
    Point(int x, int y) {
        _x = x;
        _y = y;
    }
    string toString() {
        auto xString = to_string(_x);
        auto yString = to_string(_y);
        return "(" + xString + ", " + yString + ")";
    }
    int compareTo(Point that) {
        if (that._y > _y) {
            return -1;
        }
        if (_y > that._y) {
            return 1;
        }
        if (that._x > _x) {
            return -1;
        }
        return 1;
    }
    double slopeTo(Point that) {
        if (_x - that._x == 0 && _y - that._y != 0) {
            return numeric_limits<double>::infinity();
        }
        if (_x - that._x == 0 && _y - that._y == 0) {
            return -1 * numeric_limits<double>::infinity();
        }
        return ((double(_y) - double(that._y)) / (double(_x) - double(that._x)));
    }
    int slopeOrder(Point a, Point b) {
        double slopeA = this->slopeTo(a);
        double slopeB = this->slopeTo(b);
        if (slopeA > slopeB) { return 1; }
        if (slopeA < slopeB) { return -1; }
        else { return 0; }
    }
private:
    int _x;
    int _y;
};
int numberOfSegments(const vector<double> &slopes) {
    int ans = 0;
    int streak = 1;
    bool reset = true;
    double latest = numeric_limits<double>::max();
    for (int i = 0; i < slopes.size(); i++) {
        if (slopes[i] == -1*numeric_limits<double>::infinity()) {
            continue;
        }
        if (i == 0 || reset == true) {
            latest = slopes[i];
        }
        if (slopes[i] == latest) {
            reset = false;
            streak++;
        }
        else {
            if (streak >= 3) {
                ans++;
                cout << latest << endl;
                streak = 1;
                reset = true;
            }
            else {
                reset = true;
                streak = 1;
            }
            latest = slopes[i];
        }
    }
    if (streak >= 3) {
        cout << latest << endl;
        ans++;
    }
    return ans;
}
void FastCollinearPoints(vector<Point> points, int num) {
    Point p = points[num];
    vector<double> slopes(points.size());
    for (int i = 0; i < slopes.size(); i++) {
        double slope = p.slopeTo(points[i]);
        slopes[i] = slope;
    }
    sort(slopes.begin(), slopes.end());
    int seg = numberOfSegments(slopes);
    cout << seg;
}
int main()
{
    vector<Point> points(14);
    ifstream infile("data.txt");
    for (int i = 0; i < 14; i++) {
        int a;
        int b;
        char c;
        infile >> a >> c >> b;
        Point p(a, b);
        points[i] = p;
    }
    string str = points[7].toString();
    cout << str << endl;
    FastCollinearPoints(points, 7);

}
