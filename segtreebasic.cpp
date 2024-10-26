int n, a[N], q;
 
class SegmentTree{
	private:
		int low[4*N], high[4*N], TNode[4*N], leaf[N], qi, qj;
		
		int Find(int id){
			if(qi > high[id] || qj < low[id]) return 1e9;
			if(qi <= low[id] && qj >= high[id]) return TNode[id];
			return min(Find(id*2), Find(id*2+1));
		}
	public:
		void Build(int id, int l, int r){
			low[id] = l;
			high[id] = r;
			if(l == r){
				TNode[id] = a[l];
				leaf[l] = id;
				return;
			}
			Build(id*2, l, (l+r)/2);
			Build(id*2+1, (l+r)/2+1, r);
			TNode[id] = min(TNode[id*2], TNode[id*2+1]);
		}
		
		int Query(int l, int r){
			qi = l;
			qj = r;
			return Find(1);
		}
		
		void Update(int id, int val){
			int pos = leaf[id];
			TNode[pos] = val;
			for(pos /= 2; pos > 0; pos/=2) TNode[pos] = min(TNode[pos*2], TNode[pos*2+1]);
		}
}ST; 
