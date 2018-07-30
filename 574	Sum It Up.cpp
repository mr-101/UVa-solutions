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

int x, n, a[50];
vi v;
map<vi, bool> mpp;
void solve(int i, int k, int s, vi V) {
	if(s == x) {
		if(mpp[V]) return;
		mpp[V] = 1;
		for(int j = 0; j < k; ++j) 
			printf(j == k - 1? "%d" : "%d+", V[j]);
		puts("");
		return;
	}
	if(s > x || i == n) return;
	for(int j = i; j < n; ++j) {
		V.pb(a[j]);
		solve(j+1, k+1, s+a[j], V);
		V.pop_back();
	}
}
int main() { 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    while(cin >> x >> n) {
    	if(!n) break;
    	for(int i = 0; i < n; ++i)
    		cin >> a[i];
    	printf("Sums of %d:\n", x);
    	mpp.clear();
    	v.clear();
    	solve(0, 0, 0, v);
    	if(!sz(mpp))
    		puts("NONE");
    }

    return 0;   
}
