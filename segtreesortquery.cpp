#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define int long long
#define fi first
#define se second

const int MOD = 1e9+7;
const int N = 1e5+1;

int n, a[N], q;

class SegmentTree {
    private:
        int low[N*4], high[N*4], qi, qj;
        vector<int> TNode[N*4];
    public:
        void Build(int id, int l, int r) {
            low[id] = l;
            high[id] = r;
            if(l == r) {
                TNode[id].push_back(a[l]);
                return;
            }
            int mid = (l+r)/2;
            Build(id*2, l, mid);
            Build(id*2+1, mid+1, r);
            TNode[id].resize(TNode[id*2].size() + TNode[id*2+1].size());
            merge(TNode[id*2].begin(), TNode[id*2].end(), TNode[id*2+1].begin(), TNode[id*2+1].end(), TNode[id].begin());
        }
        int Query(int l, int r, int x, int y) {
            qi = l;
            qj = r;
            return Find(1, x, y);
        }
        int Find(int id, int x, int y) {
            if(qi > high[id] || qj < low[id]) return 0;
            if(qi <= low[id] && qj >= high[id]) return upper_bound(TNode[id].begin(), TNode[id].end(), y)
                                                     - lower_bound(TNode[id].begin(), TNode[id].end(), x);
            return Find(id*2, x, y) + Find(id*2+1, x, y);
        }
};

void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    SegmentTree seg;
    seg.Build(1, 1, n);
    while(q--) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        cout << seg.Query(l, r, x, y) << endl;
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
