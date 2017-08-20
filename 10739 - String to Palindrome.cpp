/*
    uva 10739 - String to Palindrome
*/

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

int t , n , p = 1 , dp[1005][1005];
string s;

int solve(int i , int j) {
      if(i >= j)
            return dp[i][j] = 0;
      if(dp[i][j] != -1)
            return dp[i][j];
      if(s[i] == s[j])
            return dp[i][j] =  solve(i+1 , j-1);
      int s1 = 0 , s2 = 0 , s3 = 0;
      if(s[i] != s[j]) {
            s1 = solve(i+1 , j-1) + 1;
            s2 = solve(i+1 , j) + 1;
            s3 = solve(i , j-1) + 1;
      }
      return dp[i][j] = min(s1 , min(s2 , s3));
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
            n = (int)s.size()-1;
            printf("Case %d: %d\n" , p++ , solve(0 , n));
      }
      
      return 0;

}
