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
const ll mod = 1000000007;

int t , n;
ll dp[65][65];
string s;
ll solve(int i , int j) {
      if(i == j)
            return dp[i][j] = 1;
      if(i+1 == j)
            return dp[i][j] = (2 + (s[i] == s[j]));
      if(dp[i][j] != -1)
            return dp[i][j];
      ll s4 = 0;
      if(s[i] == s[j])
            s4 = solve(i+1 , j-1) + 1;
      ll s1 = solve(i+1 , j);
      ll s2 = solve(i , j-1);
      ll s3 = solve(i+1 , j-1);
      return dp[i][j] = s1 + s2 - s3 + s4;
}

int main() {
      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif

      scanf("%d" , &t);
      while(t--) {
            memset(dp , -1 , sizeof dp);
            cin >> s;
            n = (int)s.size() - 1;
            printf("%lld\n" , solve(0 , n));   
      }
      return 0;

}
