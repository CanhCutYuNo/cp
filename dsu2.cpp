#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define ll long long
 
const int MOD = 1e9+7;
const int N = 1e5+1;
 
vector<int> parent;
vector<int> res;
 
void make_set(int v){
	parent[v] = v;
}
 
int find_set(int v){
	if(v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
 
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b) 
		parent[b] = a;
}
 
void solve(){
	int n, m, cnt = 0;
	cin >> n >> m;
	
	parent.resize(n+1);
	
	for(int i = 1; i <= n; i++){
		make_set(i);
	}
	
	while(m--){
		int a, b;
		cin >> a >> b;
		union_set(a, b);
	}
	
	for(int i = 1; i <= n; i++){
		res.push_back(find_set(i));
		//cout << find_set(i) << endl;
	}
	
	bool check[n+1];
	memset(check, false, sizeof(check));
	
	vector<pair<int, int>> ans;
	
	for(int i = 1; i <= n; i++){
		if(!check[res[i-1]]){
			if(cnt > 0){
				if(i != 1) ans.push_back({i, i-1});
			}
			cnt++;
		}
		check[res[i-1]] = true;
	}
	
	cout << ans.size() << endl;
	for(auto x : ans){
		cout << x.first << " " << x.second << endl;
	}
}
 
signed main(){
    fastIO;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}