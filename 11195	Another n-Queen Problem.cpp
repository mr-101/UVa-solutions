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


int n, row[20], diagR[50], diagL[50], visC[20], x, p = 1, mx;
char g[20][20];

void solve(int r = 1) {
	if(r > n) {
		++x;
		return;
	}
	for(int c = 1; c <= n; ++c) {
		if(visC[c] || diagL[c+r] || diagR[c-r+mx] || g[r][c] != '.') continue;
		visC[c] = diagR[c-r+mx] = diagL[c+r] = 1;
		row[r] = c;
		solve(r+1);
		visC[c] = diagR[c-r+mx] = diagL[c+r] = 0;
	}
}

int main() { 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    while(cin >> n, n) {
    	for(int i = 1; i <= n; ++i)
    		for(int j = 1; j <= n; ++j)
    			cin >> g[i][j];
    	mx = n+1;
    	x = 0;
    	solve();
    	printf("Case %d: %d\n", p++, x);

    }

    return 0;   
}
