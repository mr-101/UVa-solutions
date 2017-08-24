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

int n , m , x;
vector<vi> v , dp1;
vi c , dp2;

int solveRows(int i , int j) {
      if(j >= m)
            return 0;

      if(dp1[i][j] != -1)
            return dp1[i][j];
      int s1 = solveRows(i , j+2) + v[i][j];
      int s2 = solveRows(i , j+1);
      return dp1[i][j] = max(s1 , s2);
}
int solveCol(int i) {
      if(i >= n)
            return 0;

      if(dp2[i] != -1)
            return dp2[i];

      int s1 = solveCol(i+2) + c[i];
      int s2 = solveCol(i+1);

      return dp2[i] = max(s1 , s2);
}

int main() {
      cin.tie(0);
      ios::sync_with_stdio(false);
      
      while(cin >> n >> m , (n && m)) {
            v.assign(n+5 , vi(m+5 , 0));
            c.clear();
            dp1.assign(n+5 , vi(m+5 , -1));
            dp2.assign(n+5 , -1);

            for(int i = 0; i < n; ++i) 
                  for(int j = 0; j < m; ++j) 
                        cin >> v[i][j];

            for(int i = 0; i < n; ++i) 
                  c.pb(solveRows(i , 0));

            cout << solveCol(0) << endl;
      }

      return 0;
}
