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

int n, prime[35], vis[18], sol[18];

void solve(int x = 1) {
	if(x == n) {
		if(!prime[1+sol[n-1]])
			return;
		for(int i = 0; i < n; ++i) {
			if(i) cout << " ";
			cout << sol[i];
		}
		puts("");
		return;
	}
	for(int i = 2; i <= n; ++i) {
		if(vis[i] || !prime[i+sol[x-1]]) continue;
		vis[i] = 1;
		sol[x] = i;
		solve(x+1);
		vis[i] = 0; 
	}
}
int main() {     
    for(int i = 2; i < 33; ++i) {
    	int c = 0;
    	for(int j = i-1; j > 1; --j)
    		c += !(i%j);
    	if(!c) prime[i] = 1;
    }
    sol[0] = 1;
    int p = 1, f = 0;
    while(scanf("%d", &n) != EOF) {
    	if(f) 
    		puts("");
    	f = 1;
    	printf("Case %d:\n", p++);
    	solve();
    }
    return 0;
}
