#include <iostream>
#include <algorithm>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long

const int MOD = 1e9+7;
const int MAX = 1e6;

int prime[MAX + 1];

//	don do thi vo huong: G=<V, E> gom V la cac tap dinh, E la cac canh
//	da do thi vo huong: giua 2 dinh ton tai > 1 canh
//	gia do thi vo huong: canh bat dau tai 1 dinh va end tai dinh do -> khuyên

//	don do thi co huong: G=<E, V> gom V la cac tap dinh, E la cac canh co thu tu -> cung
//	da do thi co huong: ...

//	dinh ke, canh lien thuoc: 2 dinh ke neu ton tai canh do thi noi giua chung, canh do -> canh lien thuoc

//	bac cua dinh tren do thi vo huong (deg(u)): La so canh lien thuoc cua dinh (do thi vo huong)
// bac 0: Dinh co lap
// bac 1: dinh treo
// tong cac bac dinh bang 2 lan so canh	

//	ban bac vao cua dinh tren do thi co huong: ban bac ra cua dinh la so cung di ra khoi dinh, vao thi nguoc lai, ki hieu: (ra, vao)
// tong ban bac ra va ban bac vao = nhau va = so canh

//	duong di: co canh noi 
// duong di don: cac dinh tren duong di phan biet voi nhau

//	chu trinh: la duong di ma co dinh dau trung dinh cuoi
// chu trinh don: chi co dinh dau va cuoi trung nhau

//	lien thong: Mot do thi coi la lien thong neu luon tim dc duong di giua hai dinh do thi
//	thanh phan lien thong: do thi vo huong ko lien thong chia thanh cac thanh phan lien thong, do thi lien thong co tplt = 1

//	lien thong manh yeu: Do thi co huong la lien thong manh neu giua 2 dinh bat ki luon co duong di
// do thi co huong lien thong yeu khi do thi vo huong cua no lien thong 	





signed main(){
	fastIO;

		

	return 0;
}
