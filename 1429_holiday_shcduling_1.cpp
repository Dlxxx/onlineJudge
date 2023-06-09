#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long moneyLeft [370];

long long findMax(long long a, long long b){
    if(a>b) return a;
    else return b;
}


int main()
{
    int n, m, xx;
    static long long x = 1000000000;
    static int a_i = 1;
    int s[100005], t[100005], a[100005];

    moneyLeft[0] = 0;
    fill(moneyLeft, moneyLeft+370, 0);
    cin >> n >> m >> xx;

    for (int _ = 0; _ < m; _++){
        cin>>s[_]>>t[_]>>a[_];
    }
    
    for (int i = 1; i<=n; i++){
        moneyLeft[i] = findMax(moneyLeft[i-1] - x, 0);
        for(int j = 0; j<m; j++){
            if(t[j]<=i)
                moneyLeft[i] = findMax(moneyLeft[s[j]-1] + a_i, moneyLeft[i]);
        }

        moneyLeft[i] = findMax(moneyLeft[i], moneyLeft[i-1]);

        // cout<<"CHOOOOOOSE: "<<moneyLeft[i]<<endl;
        // cout<<"______________________________________"<<endl;
    }

    cout<<moneyLeft[n]<<endl;

    return 0;
}