#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define N 100005
#define M 1000005
#define mod 1000000007

using namespace std;

typedef pair<int,int> ii;
typedef pair<ll,ll> lii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double pi = acos(-1);
const int inf = 1e9;

int p , q , r , s , t , u;

bool ok(double x) {
      double res = p*exp(-x) + q*sin(x) +
                    r*cos(x) + s*tan(x) + t*x*x
                   + u;
      return res <= (double)0;
}

double check(double x) {
      double res = p*exp(-x) + q*sin(x) +
                    r*cos(x) + s*tan(x) + t*x*x
                   + u;
      return res;
}

int main() {

      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif

      while(scanf("%d%d%d%d%d%d" , &p , &q , &r , &s , &t , &u) != EOF) {
            double lo = 0.0 , hi = 1.0 , mid , ans = 0;
            
            for(int i = 0; i < 30; ++i) {
                  mid = (lo + hi)/2.0;
                  
                  if(ok(mid)) 
                        hi = mid;

                  else
                        lo = mid;
            }

            if(check(0) * check(1) > 0)
                  puts("No solution");

            else
                  printf("%.4f\n" , hi);
      }

    
      return 0;
}
