/*
uva 10131
Is Bigger Smarter?
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

int i , dp[1001][1001];
ii e[1005];
map<ii, int> mpp;

bool cmp(ii &x , ii &y) {
      return x.sec > y.sec;
}

int LIS(int id , int prev = i) {
      if(id == i)
            return dp[id][prev] = 0;

      if(dp[id][prev] != -1)
            return dp[id][prev];

      int c1 = LIS(id+1 , prev);
      int c2 = 0;
      if(prev == i || e[id].fs > e[prev].fs && e[id].sec != e[prev].sec)
            c2 = LIS(id+1 , id) + 1;
      
      return dp[id][prev] = max(c1 , c2);
}

void build(int id , int prev = i) {
      if(id == i)
            return;
      if(dp[id+1][prev] != -1 && dp[id][prev] == dp[id+1][prev])
            build(id+1 , prev);

      else if(dp[id+1][prev] != -1 && dp[id][prev] == dp[id+1][prev]+1) {
            printf("%d\n" , mpp[mp(e[id].fs , e[id].sec)]+1);
            build(id+1 , id);
      }
}

int main() {
      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif

      while(cin >> e[i].fs >> e[i].sec) ++i;
      
      for(int j = 0; j < i; ++j) 
            mpp[mp(e[j].fs , e[j].sec)] = j;
      
      sort(e , e + i , cmp); 
      memset(dp , -1 , sizeof dp);

      cout << LIS(0) << endl;
      build(0);
      return 0;

}
