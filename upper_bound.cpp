#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define int long long
#define fi first
#define se second

const int MOD = 1e9+7;
const int N = 2e5+1;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<pair<double, int>> v(n+1);
	int pre[n+1];
	pre[0] = 0;
	
	for(int i = 1; i <= n; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[i] = {sqrt(x*x + y*y), w};
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + v[i-1].se;
	//cout << v[i-1].fi << " " << v[i-1].se << endl;
	}
	
	while(q--) {
		int x; cin >> x;
		auto it = upper_bound(v.begin(), v.end(), make_pair(x, LLONG_MAX), 
            [](const pair<double, int>& a, const pair<double, int>& b) {
                return a.fi < b.fi;
            });
        int id = it - v.begin();
        cout << pre[id] << endl;
	}
	
}

signed main() {
    fastIO;
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    cerr << "Time : " << 100 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}