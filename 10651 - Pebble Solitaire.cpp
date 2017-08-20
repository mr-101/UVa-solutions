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
int dp[1<<12];
string s;

int setbit(int mask , int idx) {return (mask |= (1<<idx));}
int setbit0(int mask , int idx) {return (mask &= ~(1<<idx));}
int getbit(int mask , int idx) {return ((mask >> idx) & 1) == 1;}

int solve(int mask) {
      int &ret = dp[mask];
      if(~ret)
            return ret;
      ret = 0;
      int s1 = 0 , s2 = 0;
      for(int i = 0; i < 10; ++i) {
            if(getbit(mask , i) && getbit(mask , i+1) && !getbit(mask , i+2)) {
                  int tmask = mask;
                  tmask = setbit0(tmask , i);
                  tmask = setbit0(tmask , i+1);
                  tmask = setbit(tmask , i+2);
                  ret = max(ret , solve(tmask) + 1);
            }
            else if(!getbit(mask , i) && getbit(mask , i+1) && getbit(mask , i+2)) {
                  int tmask = mask;
                  tmask = setbit(tmask , i);
                  tmask = setbit0(tmask , i+1);
                  tmask = setbit0(tmask , i+2);
                  ret = max(ret , solve(tmask) + 1);
            } 
      }
      return ret;
}
int main() {
      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif

      scanf("%d" , &t);
      while(t--) {
            int msk = 0 , cnt = 0;
            memset(dp , -1 , sizeof dp);
            cin >> s;
            for(int i = 0; i < (int)s.size(); ++i) {
                  if(s[i] == 'o') {
                        msk = setbit(msk , i);
                        ++cnt;
                  }
            }
            printf("%d\n" , cnt - solve(msk));
      }
      return 0;
}
