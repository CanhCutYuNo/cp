#include <iostream>
#include <cmath>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define float double

float f(float a){
    return sin(a)/a;
}

float tichphan(float (*f)(float), float a, float b, int n){
    float res = 0;
    float h = (b-a)/n;
    for(int i = 1; i < n; i++){
        res += f(a+i*h);
    }
    return h/2*(f(a)+f(b)+2*res);
}

signed main(){
    fastIO;
    int n;
    cin >> n;
    while(n--){
        float a, b;
        cin >> a >> b;
        cout << tichphan(f, a, b, 1000) << endl;
    }

    return 0;
}
