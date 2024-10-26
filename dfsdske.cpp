#include <iostream>
#include <vector>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long

const int MOD = 1e9+7;
const int MAX = 1e6;

int n, m, cnt = 0, Max = 0;
bool visited[MAX];
vector<int> adj[MAX];

void dfs(int u){
	visited[u] = true;
	cnt++;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	} 
}

void lienthong(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			res++;
			dfs(i);
			if(cnt > Max) Max = cnt;
			cnt = 0;
		}
	}
	cout << res << "\n" << Max;
}
 
signed main(){
	fastIO;
	lienthong();

	return 0;
}
