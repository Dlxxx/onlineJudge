#include <bits/stdc++.h>
#include <vector>
using namespace std;

const long long INF = 1e18;

/* 
   NOTE:
   std::pow is for floating point numbers.
   For integers, it's better to implement one.
*/

// FIXME: reimplement with long long int
long long pow_2 (long long x) {
    return x * x;
}

struct point {
    int x, y;
    point (int _x, int _y) : x(_x), y(_y) {}
    long long distance_2 (const point & other) const {
        // TODO: implement distance_2
        return pow_2(x - other.x) + pow_2(y - other.y);
    }///
};

long long solve (vector <point> &a, int l, int r) {
    // TODO: implement solve    
    if (l+1 >= r){
        return INF;
    }
    int m = (l+r)/2;
    long long ret = min(solve(a, l, m), solve(a, m, r));
    vector<point> strip;
    for (int i=l; i<r; i++){
        if(pow_2(a.at(i).x-a.at(m).x) < ret){
            strip.push_back(a.at(i));
        }
    }
    sort(strip.begin(), strip.end(), [](auto &u, auto &v) {
        return u.y < v.y;//??
    });
    for (int i=0; i<strip.size(); i++){
        for (int j=i+1; j<strip.size(); j++){
            if(pow_2(strip.at(i).y-strip.at(j).y)>=ret){
                break;
            }
            ret = min(ret, strip.at(i).distance_2(strip.at(j)));
        }
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector <point> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(point(x, y));
    }
    sort(a.begin(), a.end(), [](auto &u, auto &v) {
        return u.x < v.x;
    });
    cout << solve (a, 0, n) << endl;
}