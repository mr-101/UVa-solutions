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

int row[10], diagR[20], diagL[20], visC[15], x, p = 1;
vi sol[95];

void solve(int r = 1) {
	if(r == 9) {
		for(int i = 1; i < 9; ++i)
			sol[x].pb(row[i]);
		++x;
		return;
	}
	for(int c = 1; c < 9; ++c) {
		if(visC[c] || diagL[c+r] || diagR[c-r+9]) continue;
		visC[c] = diagR[c-r+9] = diagL[c+r] = 1;
		row[r] = c;
		solve(r+1);
		visC[c] = diagR[c-r+9] = diagL[c+r] = 0;
	}
}

int main() { 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    solve();
    int a[10];
    while(cin >> a[0]) {
    	for(int i = 1; i < 8; ++i)
    		cin >> a[i];
    	int ans = 100;
    	for(int i = 0; i < 92; ++i) {
    		int d = 0;
    		for(int j = 0; j < 8; ++j) 
    			d += sol[i][j] != a[j];
    		ans = min(ans , d);
    	}
    	printf("Case %d: %d\n", p++, ans);
    }
    return 0;   
}
