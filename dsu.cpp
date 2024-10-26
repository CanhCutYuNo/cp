#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long

const int mod = 1e9+7;
const int N = 1e5+1;

int n, m;
int parent[N], Size[N];

/*
          __ __
        ,;::\::\
      ,'/' `/'`/
  _\,: '.,-'.-':.
 -./"'  :    :  :\/,
  ::.  ,:____;__; :-
  :"  ( .`-*'o*',);
   \.. ` `---'`' /
    `:._..-   _.'
    ,;  .     `.
   /"'| |       \
  ::. ) :        :
  |" (   \       |
  :.(_,  :       ;
   \'`-'_/      /
    `...   , _,'
     |,|  : |
     |`|  | |
     |,|  | |
 ,--.;`|  | '..--.
/;' "' ;  '..--. ))
\:.___(___   ) ))'
          `-'-''

*/

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