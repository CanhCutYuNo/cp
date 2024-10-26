#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long

const int MOD = 1e9+7;
const int MAX = 1e6;

int n, q;
int a[101], d[10001], m[10001];
bool visited[10001];
queue<int> sl;

int bfs(int u, int t, int n, int a[]){
	sl.push(u);
	d[u] = 0;
	visited[u] = true;
	while(!sl.empty()){
		int top = sl.front();
		sl.pop();
		if(u==t) return d[t];
		for(int i = 0; i < n; i++){
			int i1 = top + a[i];
			if(i1 >= 0 && i1 <= t && !visited[i1]){
				sl.push(i1);
				d[i1] = d[top] + 1;
				visited[i1] = true;
			}
		}
	}
	return -1;	
}

void inp(){
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int Max = 0;
	for(int i = 0; i < q; i++){
		cin >> m[i];
		if(Max < m[i]) Max = m[i];
	}
	bfs(0, Max, n, a);
	for(int i = 0; i < q; i++){
		if(d[m[i]]!=0) cout << d[m[i]] << endl;
		else cout << -1 << endl;
	}
}

signed main(){
	fastIO;
	inp();

	return 0;
}
