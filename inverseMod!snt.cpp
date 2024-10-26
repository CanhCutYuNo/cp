#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define int long long
#define fi first
#define se second
 
const int MOD = 2e9 + 14;
const int N = 1e6+1;

int fact[N];

void factorial() {
	fact[0] = 1;
	for(int i = 1; i < N; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
}

int powerMod(int a, int b, int MOD) {
    int res = 1;
    a = a % MOD;
    while(b > 0) {
        if(b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int eulerPhi(int MOD) {
    int res = MOD;
    for(int i = 2; i * i <= MOD; i++) {
        if(MOD % i == 0) {
            while(MOD % i == 0) {
                MOD /= i;
            }
            res -= res / i;
        }
    }
    if(MOD > 1) {
        res -= res / MOD;
    }
    return res;
}

int modInverse(int a) {
    int phiMOD = eulerPhi(MOD);
    return powerMod(a, phiMOD - 1, MOD);
}


void solve() {
	int n, m, res = 1;
	cin >> n;
	int a[n];
	for(int &x : a) cin >> x;
	cin >> m;
	
	for(int x : a) res = (res * fact[x]) % MOD;
	
	res = (res * modInverse(fact[m])) % MOD;
	
	cout << res << endl;
}
 
signed main() {
    fastIO;
    factorial();
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
 
    cerr << "Time : " << 100 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}