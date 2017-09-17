#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<map>
#include<cstring>
#include<set>
#include<queue>
#include<climits>
#include<iomanip> 
using namespace std;
#define uii long long int
#define it(a)  ::iterator a
#define sd(a) double a;scanf("%lf",&a);
#define slld(a) uii a;scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define plld(a) printf("%lld",a)
#define INF LLONG_MAX
#define MOD 1000000007
#define powOf2(a) !(a&a-1)
#define mod(a) (a>0 ? a : (-1*a))
#define tc(a) uii a; for(scanf("%lld",&a);a--;)
#define swap(a,b) a = a^b; b = a^b;a = a^b;
#define rep(i,n) for(uii i = 0;i<n;i++)
#define set(n,x) x |= (1 << n)
#define unset(n,x) x &= ~(1<<n)
#define check(n,x) (x & 1 << n) != 0
#define ppi pair<uii, pair<uii, uii> >

class Fenwick{
	private:
		uii *tree;
		uii N;

	
	public:
		Fenwick(uii n){
			N = n;
			tree = new uii[N]();
			for(uii i = 0;i<=N;i++) tree[i] = 0;
		}
		
		void update(uii j, uii delta){
			for(uii i = j;i<=N;i+=(i&-i))
				tree[i]+=delta; 
		}

		uii query(uii j){
			uii res = 0;
			for(uii i = j;i>0;i-=(i&-i))
				res += tree[i];
			return res;
		}

		uii queryRange(uii l, uii r){
			return query(r)-query(l-1);
		}
};



int main(){
	uii N = 100;
	Fenwick fen(N);
	fen.update(1, 19);
	fen.update(51,19);
	fen.update(100,20);
	cout<<fen.query(50)<<endl;
	cout<<fen.query(52)<<endl;
  	cout<<fen.query(100)<<endl;
	return 0;
}


