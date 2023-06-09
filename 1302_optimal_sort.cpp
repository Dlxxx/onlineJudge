#include<iostream>
#include <cstdio>

using namespace std;

int a[1024 + 1];
int query(int x, int y);

void solve(int l, int r) { //l r 对应着left 与 right两个位置
    if (l >= r) return;
    if (r - l > 1) {
        printf("Sorry, %d numbers are too difficult!\n", r - l + 1);
        return;
    }
    if (query(a[l], a[r]) == 1) { // a[l] > a[r]
        swap(a[l], a[r]);
    }
}

void optimal_sort(int n) {
    for (int i = 1; i <= n; i++) a[i] = i;
    solve(1, n);
    for (int i = 1; i <= n; i++) printf("%d%c", a[i], i == n ? '\n' : ' ');
}

//_______________________________________________________________________________________//
int __qcnt = 0;
int __hidden_array[1024 + 1];
int query (int x, int y) {
    __qcnt ++;
    int d = __hidden_array[x] - __hidden_array[y];
    return d > 0 ? 1 : (d == 0 ? 0 : -1);
}
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> __hidden_array[i];
    optimal_sort(n);
    std::cout << "number of queries : " << __qcnt << std::endl;
}