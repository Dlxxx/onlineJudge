//a∨b=(¬a→b)∧(¬b→a)
//2 − visited_ver a t 2-sat2−sat问题主要是将→ \to→这一运算符的作用通过建图的方式进行表达，a → b a\to ba→b就将a aa向b bb连一条边。
//建图后使用t a r j a n tarjantarjan算法进行缩点，缩点后的i d idid是拓扑序的倒序
//若原变量a aa与反变量¬ a \neg a¬a不在同一强连通分量则有解。
//最后的取值与原变量a aa与反变量¬ a \neg a¬a的拓扑序有关，原变量的拓扑序在反变量拓扑序之前（原变量i d idid大)，取1，否则取0.

#include <bits/stdc++.h>
using namespace std;
//参考了https://blog.csdn.net/u011815404/article/details/84034034 的一部分实现思想
const int N = 2e6+10, M = N * 2, inf = 1e8;
int n, m;
int pre[N], neg_e[M], e[M], idx;
int finish_time[N], finishi_min[N], time_;
int id[N], num_scc, num_ver_in_scc[N];
stack<int> visited_ver;
bool if_in_vis[N];

void add(int a, int b){
    e[idx] = b, neg_e[idx] = pre[a], pre[a] = idx++;
}

void tarjan(int u){
    finish_time[u] = finishi_min[u] = ++time_;
    visited_ver.push(u); if_in_vis[u] = 1;
    for(int i = pre[u]; ~i; i = neg_e[i]){
        int j = e[i];
        if(!finish_time[j]){
            tarjan(j);
            finishi_min[u] = min(finishi_min[u], finishi_min[j]);
        }
        else if(if_in_vis[j]) finishi_min[u] = min(finishi_min[u], finish_time[j]);
    }
    if(finish_time[u] == finishi_min[u]){
        ++num_scc;
        int y;
        do{
            y = visited_ver.top(); 
            visited_ver.pop();
            if_in_vis[y] = 0;
            id[y] = num_scc;
            num_ver_in_scc[num_scc]++;
        }while(y != u);
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(pre, -1, sizeof(pre));
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int xi, xj, a, b;
        cin>>xi>>a>>xj>>b;
        xi--; xj--;
        add(2 * xi + !a, 2 * xj + b);
        add(2 * xj + !b, 2 * xi + a);
    }
    for(int i = 0; i < n * 2; i++) 
        if(!finish_time[i]) tarjan(i);
    for(int i = 0; i < n; i++)
        if(id[i * 2] == id[i * 2 + 1]) {
            cout<<"No"<<endl;
            return 0;
        }
    cout<<"Yes"<<endl;
    for(int i = 0; i < n; i++)
        if(id[2 * i] < id[2 * i + 1]) 
            cout<<"0 ";
        else 
            cout<<"1 ";
    return 0;
}