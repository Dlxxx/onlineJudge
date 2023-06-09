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

"""未成功！！！！"""
int main()
{
    int n, m, x;
    int s[100005], t[100005], a[100005];

    moneyLeft[0] = 0;
    fill(moneyLeft, moneyLeft+370, 0);
    cin >> n >> m >> x;

    for (int _ = 0; _ < m; _++){
        cin>>s[_]>>t[_]>>a[_];
    }
    
    for (int i = 1; i<=n; i++){
        moneyLeft[i] = moneyLeft[i-1] - x;
        if(moneyLeft[i]>=0)
            continue;

        for(int j = 0; j<m; j++){
            if(t[j]<=i )
                moneyLeft[i] = findMax(moneyLeft[s[j]-1] + a[j], moneyLeft[i]);
                // used[j] = true;
        }

        moneyLeft[i] = findMax(moneyLeft[i], moneyLeft[i-1]);//dai
        // cout<<"IN "<<i<<" th"<<endl;
        // cout<<"CHOOOOOOSE: "<<moneyLeft[i]<<endl;
        // cout<<"______________________________________"<<endl;
    }

    cout<<moneyLeft[n]<<endl;

    return 0;
}