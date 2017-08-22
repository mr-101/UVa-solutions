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


int t , x , n , a[25] , sum;

bool solve(int i , int s) {
      if(s == 0)
            return 1;
      if(i == n)
            return s == 0;
      int s1 = solve(i+1 , s);
      int s2 = solve(i+1 , s-a[i]);
      return s1 || s2;
}

int main() {
      cin.tie(0);
      ios::sync_with_stdio(false);

      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif
            
      cin >> t;
      string s;
      cin.ignore();
      while(t--) {
            int i = 0;
            getline(cin , s);
            istringstream iss(s);
            sum = 0;
            while(iss >> x) { 
                  a[i++] = x;
                  sum += x;
            }

            n = i;
            if(sum % 2) {
                  puts("NO");
                  continue;
            }
            sum /= 2;
            puts((solve(0 , sum))? "YES" : "NO");
      }
      return 0;
}
