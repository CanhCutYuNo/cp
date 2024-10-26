#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define int long long
#define fi first
#define se second

const int MOD = 1e9+7;
const int N = 1e5+1;

long long multiply_mod(long long a, long long b, long long m) {
    long long res = 0;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res + a) % m;
        }
        a = (a * 2) % m;
        b /= 2;
    }
    return res;
}

class Matrix {
public:
    int X[2][2];
    Matrix() {
        X[0][0] = 1;
        X[0][1] = 1;
        X[1][0] = 1;
        X[1][1] = 0;
    }

    friend Matrix operator*(Matrix a, Matrix b) {
        Matrix C;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++) {
                C.X[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    C.X[i][j] = (C.X[i][j] + multiply_mod(a.X[i][k], b.X[k][j], MOD)) % MOD;
                }
            }
        return C;
    }

    Matrix power(Matrix A, int n) {
        if (n == 1)
            return A;
        Matrix tmp = power(A, n / 2);
        if (n % 2 == 0)
            return tmp * tmp;
        return tmp * tmp * A;
    }
};

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    Matrix M;
    M = M.power(M, n); 
    return M.X[0][1]; 
}


void solve() {
	cout << fibonacci(15);
	
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