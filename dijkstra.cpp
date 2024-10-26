#include <bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;


const int maxn = 100001;
const int mod = 1e9+7;
int n, m, s;
vector<pair<int, int>> adj[maxn];

void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; 
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
}

const int INF = 1e9;

void dijkstra(int s){
    vector<ll> d(n + 1, INF);
    vector<ll> cnt(n + 1, 0);
    vector<int> minEdges(n + 1, 0); 
    vector<int> maxEdges(n + 1, 0); 
    d[s] = 0;
    cnt[s] = 1;
    minEdges[s] = 0;
    maxEdges[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    while(!Q.empty()){
        pair<ll, ll> top = Q.top(); Q.pop();
        ll u = top.second;
        ll kc = top.first;
        
        if(kc > d[u]) continue;
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                cnt[v] = cnt[u];
                minEdges[v] = minEdges[u] + 1;
                maxEdges[v] = maxEdges[u] + 1;
                Q.push({d[v], v});
            }
            else if(d[v] == d[u] + w){
                cnt[v] = (cnt[v] + cnt[u]) % mod;
                minEdges[v] = min(minEdges[v], minEdges[u] + 1);
                maxEdges[v] = max(maxEdges[v], maxEdges[u] + 1);
            }
        }
    }
    
	cout << d[n] << " " << cnt[n] << " " << minEdges[n] << " " << maxEdges[n] << endl;
}

main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    nhap();
    dijkstra(1);
}
