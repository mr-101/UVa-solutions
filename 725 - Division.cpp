#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define fs first
#define sec second
#define sz(x) (int)x.size()
#define all(v) v.begin() , v.end()
#define N 100005
#define M 1000005
#define inf 4000000007
#define ld long double

using namespace std;

typedef pair<int,int> ii;
typedef pair<ll,ll> lii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef bitset<15> maskk;

int n, vis[15];
vi v;

void solve(int x = 0, int c = 0) {
	if(c == 5) {
		v.pb(x);
		return;
	}
	for(int i = 0; i < 10; ++i) {
		if(vis[i]) continue;
		vis[i] = 1;
		solve(x*10 + i, c+1);
		vis[i] = 0;
	}
}

int main() { 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    
    solve();
    bool f = 0;
    while(scanf("%d", &n), n) {
    	if(f) puts("");
    	f = 1;
    	bool ok = 0;
    	int msk = 0;
    	for(auto i : v) {
    		if(i*n > 98765) break;
    		if(i < 10000) msk = 1;
    		else msk = 0;
    		int t = i;
    		while(t) {
    			msk |= (1 << (t%10));
    			t/=10;
    		}
    		t = n*i;
    		while(t) {
    			msk |= (1 << (t%10));
    			t/=10;
    		}
    		if(msk == (1 << 10) - 1) {
    			ok = 1;
    			printf("%0.5d / %0.5d = %d\n", n*i, i, n);
    		}
    	}
    	if(!ok)
			printf("There are no solutions for %d.\n", n);
    }
    return 0;   
}
