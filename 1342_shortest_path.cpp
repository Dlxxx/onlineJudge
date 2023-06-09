#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <climits>

int MAXvalue = 1000000005;
using namespace std;

struct edge {
    int v, w;
};

struct node {
    long long dis;
    int x;
    bool operator < (const node & other) const {
        return dis > other.dis;
    }
};

vector <edge> g[2505];
void add_edge (int u, int v, int w) {
    g[u].push_back({v, w});
}

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

int n, m, s, t;
// int in_ver[2505];
// int out_ver[2505];
// int values[6205];
long long dist[2505];
bool visited[2505];
long long final_result = 0;

void Dijkstra(int s, int t){

    fill(dist, dist+2505, MAXvalue);
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        // auto [dis, u] = pq.top();
        auto top = pq.top();
        int u = top.second;
        int dis = top.first;
        pq.pop(); 
        if (visited[u]) continue;
        visited[u] = true;
        if (u == t) {
            cout << dist[t] << endl;
            return;
        }
        for(auto& e : g[u]){
            int v = e.v;
            int w = e.w;
            if(!visited[v] && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}


int main()
{
    cin >> n >> m >> s >> t;
    for(int _=0; _<m; _++){
        int in_ver, out_ver, value;
        cin >> in_ver >> out_ver >> value;
        add_edge(in_ver, out_ver, value);
        add_edge(out_ver, in_ver, value);
    }

    Dijkstra(s, t);

    return 0;
}