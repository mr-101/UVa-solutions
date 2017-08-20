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

int t , n , cnt[1005] , pr[1005] , mem[1005][1005];

int solve(int i , int prev) {
      if(i == n)
            return mem[i][prev] = 0;

      if(mem[i][prev] != -1)
            return mem[i][prev];
      int sum = 10;
      for(int j = prev; j <= i; ++j)
            sum += cnt[j];
      int s1 = solve(i+1 , i+1) + sum*pr[i];
      int s2 = 1e9;
      if(i != n-1)
            s2 = solve(i+1 , prev);
      return mem[i][prev] = min(s1 , s2);
}
int main() {
      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif
            
      scanf("%d" , &t);
      while(t--) {
            memset(mem , -1 , sizeof mem);
            scanf("%d" , &n);
            for(int i = 0; i < n; ++i) 
                  scanf("%d %d" , cnt + i , pr + i);

            printf("%d\n" , solve(0 , 0));
      }
      return 0;

}
