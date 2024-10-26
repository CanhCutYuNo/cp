#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define int long long

const int MOD = 1e9+7;
const int N = 2e5+1;

int n, a[N], q;

class SegmentTree{
	private:
		int low[4*N], high[4*N], Min[4*N], leaf[N], Gcd[4*N], cnt[4*N], qi, qj;
		
		int Find_min(int id){
			if(qi > high[id] || qj < low[id]) return 1e10;
			if(qi <= low[id] && qj >= high[id]) return Min[id];
			return min(Find_min(id*2), Find_min(id*2+1));
		}
		
		int Find_gcd(int id){
			if(qi > high[id] || qj < low[id]) return 0;
			if(qi <= low[id] && qj >= high[id]) return Gcd[id];
			return __gcd(Find_gcd(id*2), Find_gcd(id*2+1));
		}
		
		int Find_cnt(int id, int g){
			if(qi > high[id] || qj < low[id]) return 0;
			if(qi <= low[id] && qj >= high[id]){
				return (Gcd[id] == g) ? cnt[id] : 0;
			}
			int left_count = Find_cnt(id*2, g);
			int right_count = Find_cnt(id*2+1, g);
			return left_count + right_count;
		}
    
	public:
		void Build(int id, int l, int r){
			low[id] = l;
			high[id] = r;
			if(l == r){
				Min[id] = a[l];
				Gcd[id] = a[l];
				cnt[id] = 1;
				leaf[l] = id;
				return;
			}
			Build(id*2, l, (l+r)/2);
			Build(id*2+1, (l+r)/2+1, r);
			Min[id] = min(Min[id*2], Min[id*2+1]);
			Gcd[id] = __gcd(Gcd[id*2], Gcd[id*2+1]);
			cnt[id] = 0;
				if(Gcd[id] == Gcd[id*2]) cnt[id] += cnt[id*2];
				if(Gcd[id] == Gcd[id*2+1]) cnt[id] += cnt[id*2+1];
		}
		
		int Query_min(int l, int r){
			qi = l;
			qj = r;
			return Find_min(1);
		}
		
		int Query_gcd(int l, int r){
			qi = l;
			qj = r;
			return Find_gcd(1);
		}
		
		int Query_cnt(int l, int r){
			qi = l;
			qj = r;
			int g = Query_gcd(l, r);
			return Find_cnt(1, g);
		}
		
		void Update(int id, int val){
			int pos = leaf[id];
			Min[pos] = val;
			Gcd[pos] = val;
			cnt[pos] = 1;
			for(pos /= 2; pos > 0; pos/=2){
				Min[pos] = min(Min[pos*2], Min[pos*2+1]);
				Gcd[pos] = __gcd(Gcd[pos*2], Gcd[pos*2+1]);
				cnt[pos] = 0;
				if(Gcd[pos] == Gcd[pos*2]) cnt[pos] += cnt[pos*2];
				if(Gcd[pos] == Gcd[pos*2+1]) cnt[pos] += cnt[pos*2+1];
			}
		}
}ST;

void solve(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	ST.Build(1, 1, n);
	
	while(q--){
		char query;
		int x, y;
		cin >> query >> x >> y;
		if(query == 'C') ST.Update(x, y);
		else if(query == 'M') cout << ST.Query_min(x, y) << endl;
		else if(query == 'G') cout << ST.Query_gcd(x, y) << endl;
		else cout << ST.Query_cnt(x, y) << endl;
	}	
}

signed main(){
    fastIO;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    
    cerr << "Time : " << 100 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
	return 0;
}

