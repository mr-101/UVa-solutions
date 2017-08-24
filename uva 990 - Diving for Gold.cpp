#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define fs first
#define sec second
#define N 100005
#define M 1000005
#define inf 1000000005
#define mod 1000000007
 
using namespace std;
 
typedef pair<int,int> ii;
typedef pair<ll,ll> lii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double pi = acos(-1);

int w , t , n , m;
int d[35] , g[35] , dp[35][10000];
vi v;

int solve(int i , int rem) {
      if(i == n)
            return dp[i][rem] = 0;

      if(dp[i][rem] != -1)
            return dp[i][rem];

      int s1 = solve(i + 1 , rem);
      int s2 = 0;
      if(rem >= (2*w*d[i]+w*d[i]))
            s2 = solve(i + 1 , rem - (2*w*d[i]+w*d[i])) + g[i];

      return dp[i][rem] = max(s1 , s2);
}
void build(int i , int rem) {
      if(i == n)
            return;

      int s1 = solve(i + 1 , rem);
      int s2 = 0;
      if(rem >= (2*w*d[i]+w*d[i]))
            s2 = solve(i + 1 , rem - (2*w*d[i]+w*d[i])) + g[i];

      if(dp[i][rem] == s1)
            build(i+1 , rem);

      else if(dp[i][rem] == s2) {
            m++;
            v.pb(i);
            build(i+1 , rem - (2*w*d[i]+w*d[i]));
      }
}
int main() {
      cin.tie(0);
      ios::sync_with_stdio(false);
      
      bool f = 0;
      while(cin >> t >> w) {
            if(f)  cout << endl;
            f = 1;
            v.clear();
            m = 0;
            memset(dp , -1 , sizeof dp);
            cin >> n;

            for(int id = 0; id < n; ++id)
                  cin >> d[id] >> g[id];

            int ans = solve(0 , t);
            build(0 , t);

            cout << ans << endl;
            cout << m << endl;
            for(int i = 0; i < m; ++i)
                  cout << d[v[i]] << " " << g[v[i]] << endl;
      }
      return 0;
}
