#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

const int N = 100005;
using namespace std;

struct ver_with_time{
    int index;
    int finish_time;
};
struct cmp {
    bool operator()(const ver_with_time& a, const ver_with_time& b) {
        return a.finish_time < b.finish_time; 
    }
};

vector <int> g[N];
vector <int> g_r[N];
long long counter_piles[N];

void g_add_edge (int u, int v) {
    auto it = find(g[u].begin(), g[u].end(), v);
    if(it == g[u].end())
        g[u].push_back(v);
}
void gr_add_edge (int u, int v) {
    auto it = find(g_r[u].begin(), g_r[u].end(), v);
    if(it == g_r[u].end())
        g_r[u].push_back(v);
}

priority_queue<ver_with_time, vector<ver_with_time>, cmp> finish_time;
bool visited[N];
bool visited_[N];
int time_ = 0;
int n, m;

void gr_dfs (int u) {
    visited[u] = true;
    time_ ++;
    for (auto v : g_r[u]) {
        if (! visited[v]) {
            gr_dfs (v);
        }
    }
    time_++;
    finish_time.push({u, time_});
}

void g_r_traverse_the_graph () {
    fill (visited, visited + N + 1, false);
    for (int i = 1; i <= n; i++) {
        if (! visited[i]) {
            gr_dfs (i);
        }
    }
}


void g_dfs (int u, long long& counter) {
    visited_[u] = true;
    for (auto v : g[u]) {
        if (! visited_[v]) {
            counter++;
            g_dfs(v, counter);
        } 
    }
}

int id = 0;
long long result = 0;
void g_traverse_the_graph () {
    fill (visited_, visited_ + N + 1, false);
    while(!finish_time.empty()){
        auto top = finish_time.top();
        finish_time.pop();
        int u = top.index;
        int fi_time = top.finish_time;
        if(visited_[u]) continue;
        visited_[u] = true;
        g_dfs(u, counter_piles[id]);
        id++;
    }
    for (int i = 0; i<=n; i++){
        result += counter_piles[i]*(counter_piles[i]+1)/2;
    }
    cout<<result<<endl;
}


int main()
{
    cin >> n >> m;
    for(int _ = 0; _<m; _++){
        int u_, v_;
        cin >> u_ >> v_;
        if(u_ != v_){
            g_add_edge(u_, v_);
            gr_add_edge(v_, u_);
        }
    }
    g_r_traverse_the_graph();
    g_traverse_the_graph();
    return 0;
}