#include <bits/stdc++.h>
#include <vector>
#include <queue>
static long long MAXvalue = 100000005;
static int MAX_for_n = 5005;

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

vector <edge> g[5005];
bool visited[5005];
long long cost[5005];

void add_edge (int u, int v, int w) {
    g[u].push_back({v, w});
}

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> cost_pq;

void prim (int n, int m){
    long long result = 0;
    fill(cost, cost+5005, MAXvalue);

    cost_pq.push({0, 1});
    cost[1] = 0;
    visited[1] = true;
    for(auto &e : g[1]){
        int v = e.v;
        long long w = e.w;
        cost[v] = w;
        cost_pq.push({w, v});
    }

    while(!cost_pq.empty()){
        auto top = cost_pq.top();
        int u = top.second;
        long long cos = top.first;
        
        cost_pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        result += cos;

        // cout<<"--------------"<<endl;
        // cout<<"smallest cost now is "<<cos<<endl;
        // cout<<"the vertex is "<<u<<endl;
        // cout<<visited[u]<<endl;
        // cout<<"the RESULT is "<<result<<endl;
        // cout<<"------------------------"<<endl;

        for(auto &e : g[u]){
            int v = e.v;
            int w = e.w;
            if(!visited[v] && cost[v] > w){
                cost[v] = w;
                // cout<<"UPDATE: {"<< cost[v]<< ", "<< v <<"}"<< endl;
                cost_pq.push({cost[v], v});
            }
        }
    }
    cout<<result;
    return ;
}

int main()
{
    int n, m;
    cin >> n >> m ;
    for(int _=0; _<m; _++){
        int in_ver, out_ver, value;
        cin >> in_ver >> out_ver >> value;
        add_edge(in_ver, out_ver, value);
        add_edge(out_ver, in_ver, value);
    }

    prim(n, m);

    return 0;
}