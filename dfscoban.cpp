#include <iostream>
#include <cstring>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long

const int mod = 1e9+7;
const int N = 1e6;

void xuly(){
    freopen("CAU1.INP","r",stdin);
    freopen("CAU1.OUT","w",stdout);
}

int n, m, x1, x2, y1, y2; int a[1001][1001];
bool visited[1001][1001];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool dfs(int i, int j){
	visited[i][j] = true;
	if(i==x2 && j==y2) return true;
	for(int k = 0; k < 4; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == 0 && !visited[i1][j1]){
			if(dfs(i1, j1)) return true;
		}
	}
	return false;
}

void sol(){
	cin >> n >> m;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> a[i][j];	
		}
	}
	cin >> x1 >> y1 >> x2 >> y2;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0 && !visited[i][j]){
				dfs(i, j);
			}
		}
	}
	
}

int main(){
    fastIO;
    //xuly();
    
    sol();
    return 0;
}