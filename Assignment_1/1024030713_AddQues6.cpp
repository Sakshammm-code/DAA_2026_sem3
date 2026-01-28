#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

// Simple sort for X coordinates
bool compareX(Point a, Point b) {
    return a.x < b.x;
}

// Simple sort for Y coordinates
bool compareY(Point a, Point b) {
    return a.y < b.y;
}

double getDistance(Point p1, Point p2) {
    long long dx = p1.x - p2.x;
    long long dy = p1.y - p2.y;

    return sqrt(dx * dx + dy * dy);
}

double bruteForce(vector<Point>& points, int start, int end) {
    double minDist = 1e18; 
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j < end; j++) {
            double d = getDistance(points[i], points[j]);
            if (d < minDist) {
                minDist = d;
            }
        }
    }
    return minDist;
}

double closestPair(vector<Point>& points, int start, int end) {
    if (end - start <= 3) {
        return bruteForce(points, start, end);
    }

    int mid = start + (end - start) / 2;
    Point midPoint = points[mid];

    double dLeft = closestPair(points, start, mid);
    double dRight = closestPair(points, mid, end);
    double d = min(dLeft, dRight);


    vector<Point> strip;
    for (int i = start; i < end; i++) {
        if (abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }


    sort(strip.begin(), strip.end(), compareY);
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++) {
            double ds = getDistance(strip[i], strip[j]);
            if (ds < d) {
                d = ds;
            }
        }
    }

    return d;
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter points as X Y:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), compareX);

    double result = closestPair(points, 0, n);

    cout << "Minimum Euclidean distance: " << result << endl;

    return 0;
}