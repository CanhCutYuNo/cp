#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
    
    if (A.size() > B.size()) {
        return findMedianSortedArrays(B, A);
    }

    int n = A.size();
    int m = B.size();
    int imin = 0, imax = n, half_len = (n + m + 1) / 2;

    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = half_len - i;

        if (i < n && B[j - 1] > A[i]) {
            imin = i + 1;
        }
        else if (i > 0 && A[i - 1] > B[j]) {
            imax = i - 1;
        }
        else {
            int max_of_left;
            if (i == 0) {
                max_of_left = B[j - 1];
            } else if (j == 0) {
                max_of_left = A[i - 1];
            } else {
                max_of_left = max(A[i - 1], B[j - 1]);
            }

            if ((n + m) % 2 == 1) {
                return max_of_left;
            }

            int min_of_right;
            if (i == n) {
                min_of_right = B[j];
            } else if (j == m) {
                min_of_right = A[i];
            } else {
                min_of_right = min(A[i], B[j]);
            }

            return (max_of_left + min_of_right) / 2.0;
        }
    }

    return 0.0;
}

void make_set(int n){
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		Size[i] = 1;
	}
}

int find(int v){
	if(v == parent[v]) 
		return v;
	
	return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int powerMod(int a, int b) {
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

int modInverse(int a) {
    return powerMod(a, MOD - 2);
}

long long multiply_mod(long long a, long long b, long long m) {
    long long result = 0;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result + a) % m;
        }
        a = (a * 2) % m;
        b /= 2;
    }
    return result;
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
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
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



void solve(){
	cin >> n >> m;
	make_set(n);
	while(m--){
		int a, x, y;
		cin >> a >> x >> y;
		if(a==1){
			Union(x, y);
		}
		else{
			if(find(x) == find(y)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
}

signed main(){
    fastIO;
    
    int t = 1;
	//cin >> t;
    while(t--) 
		solve();
    
	return 0;
}
