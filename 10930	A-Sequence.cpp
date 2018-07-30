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

int x, n, m, p = 1, a[50];
vi v;
bool ok;
void solve(int i, int k, int s, vi V) {
	if(s == x) {
		ok = 0;
		return;
	}
	if(s > x || i == m) return;
	for(int j = i; j < m; ++j) 
		solve(j+1, k+1, s+a[j], V);
}

int main() { 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    while(cin >> n) {
    	printf("Case #%d:", p++);
    	for(int i = 0; i < n; ++i) {
    		cin >> a[i];
    		cout << " " << a[i];
    	}
    	puts("");
    	ok = 1;
    	for(int i = 0; i < n-1; ++i)
    		if(a[i] >= a[i+1] || a[i] < 1) 
    			ok = 0;
    	for(int i = 2; i < n; ++i) {
    		m = i;
    		x = a[i];
    		solve(0, 0, 0, v);
    		if(!ok)
    			break;
    	}
    	puts(ok?"This is an A-sequence.":"This is not an A-sequence.");
    }

    return 0;   
}
