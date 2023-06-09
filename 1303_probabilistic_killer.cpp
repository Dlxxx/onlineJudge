#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

bool operator<(const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

double dist(const Point& a, const Point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

double closest_pair(vector<Point>& a) {
    int n = a.size();
    sort(a.begin(), a.end());

    double ans = 1e20;
    set<Point> st = {a[0]};
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j < i && a[i].x - a[j].x > ans) {
            st.erase(a[j]);
            j++;
        }

        for (auto it = st.lower_bound(Point(-1e9, a[i].y - ans)); 
             it != st.end() && it->y - a[i].y <= ans; ++it) {
            ans = min(ans, dist(*it, a[i]));
        }

        st.insert(a[i]);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    srand(1145147);
    for (int T = 1; T <= t; T++) {
        int n = rand() % 1000 + 2;
        vector<Point> a;
        set<pair<int, int>> st;
        for (int i = 1; i <= n; i++) {
            int x, y;
            do {
                x = rand() % 20001 - 10000;
                y = rand() % 20001 - 10000;
            } while (st.count(make_pair(x, y)));
            a.emplace_back(x, y);
            st.emplace(x, y);
        }

        double ans = closest_pair(a);
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i].x << " " << a[i].y << endl;
        }
    }
    return 0;
}
