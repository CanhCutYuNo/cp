#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define int long long
#define fi first
#define se second

const int MOD = 1e9+7;
const int N = 1e3+1;

int n, a[N], q;

class SegmentTree {
private:
    int low[N * 4], high[N * 4], TNode[N * 4], lazy[N * 4], qi, qj;

    void propagate(int id) {
        if(lazy[id] != 0) {
            TNode[id] += lazy[id] ;
            if(low[id] != high[id]) {
                lazy[id * 2] += lazy[id];
                lazy[id * 2 + 1] += lazy[id];
            }
            lazy[id] = 0;
        }
    }

    int Find(int id) {
        propagate(id); 
        if(qi > high[id] || qj < low[id]) return -1e18;
        if(qi <= low[id] && qj >= high[id]) return TNode[id];
        return max(Find(id * 2), Find(id * 2 + 1));
    }

public:
    void Build(int id, int l, int r) {
        low[id] = l;
        high[id] = r;
        lazy[id] = 0;
        if(l == r) {
            TNode[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        Build(id * 2, l, mid);
        Build(id * 2 + 1, mid + 1, r);
        TNode[id] = max(TNode[id * 2], TNode[id * 2 + 1]);
    }

    int Query(int l, int r) {
        qi = l;
        qj = r;
        return Find(1);
    }

    void RangeUpdate(int l, int r, int val) {
        qi = l;
        qj = r;
        Update(1, val);
    }

    void Update(int id, int val) {
        propagate(id);
        if(qi > high[id] || qj < low[id]) return;
        if(qi <= low[id] && qj >= high[id]) {
            lazy[id] += val;
            propagate(id);
            return;
        }
        Update(id * 2, val);
        Update(id * 2 + 1, val);
        TNode[id] = max(TNode[id * 2], TNode[id * 2 + 1]);
    }
};

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    SegmentTree seg;
    seg.Build(1, 1, n);
    while(q--) {
        int Q, l, r, val;
        cin >> Q >> l >> r;
        if(Q == 1) {
            cin >> val;
            seg.RangeUpdate(l, r, val); 
        } 
        else {
            cout << seg.Query(l, r) << endl; 
        }
    }
}

signed main() {
    fastIO;
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
