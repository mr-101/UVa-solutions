#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define fs first
#define sec second
#define N 100005
#define M 1000005
#define inf 1000000005
 
using namespace std;
 
typedef pair<int,int> ii;
typedef pair<ll,ll> lii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double pi = acos(-1);


int n , w[1005] , mw[1005] , dp[1005][3005];

int solve(int id , int rem) {
      if(id == n) 
            return 0;
      if(dp[id][rem] != -1)
            return dp[id][rem];

      int s1 = solve(id+1 , rem);
      int s2 = 0;

      if(w[id] <= rem)
            s2 = solve(id+1 , min(rem - w[id] , mw[id])) + 1;

      return dp[id][rem] = max(s1 , s2);
}
int main() {
      cin.tie(0);
      ios::sync_with_stdio(false);

      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif

      while(cin >> n , n) {
            for(int i = 0; i < n; ++i)
                  cin >> w[i] >> mw[i];
            int ans = 1;
            memset(dp , -1 , sizeof dp);
            for(int i = 0; i < n-1; ++i) 
                  ans = max(ans , solve(i+1 , mw[i])+1);
            
            cout << ans << endl;
      }
      return 0;
}
