#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define fs first
#define sec second
#define N 100005
#define M 1000005
 
using namespace std;
 
typedef pair<int,int> ii;
typedef pair<ll,ll> lii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double pi = acos(-1);

const int MAXMODE = 105;

struct DSU {
      int parent[MAXMODE];
      int sz[MAXMODE];
      DSU() {
            for(int i = 0; i < MAXMODE; ++i)
                  parent[i] = i;

            fill(sz , sz+MAXMODE , 1);
      }

      int findParent(int i) {
            if(parent[i] == i)
            return i;
            return parent[i] = findParent(parent[i]);
      }

      bool areTeam(int x , int y) {
            int leader1 = findParent(x);
            int leader2 = findParent(y);
            return leader1 == leader2;
      }

      void mergeTeams(int x , int y) {
            int leader1 = findParent(x);
            int leader2 = findParent(y);

            if(leader1 == leader2)
            return;

            if(sz[leader1] > sz[leader2]) {
                  parent[leader2] = leader1;
                  sz[leader1] += sz[leader2];
                  sz[leader2] = 0;
            }
            else {
                  parent[leader1] = leader2;
                  sz[leader2] += sz[leader1];
                  sz[leader1] = 0;
            }
      }
};

int main() {
      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif
      int t;
      cin >> t;
      while(t--) {
            int n , m , inicost = 0;  
            cin >> n >> m;
            vector< pair<int , ii> > adj(m);
            DSU D;
            int u , v , w;
            for(int i = 0; i < m; ++i) {
                  cin >> u >> v >> w;
                  inicost += w;
                  adj[i] = (mp(w , mp(u , v)));
            }

            sort(adj.begin() , adj.end());
            
            int cost = 0;
            for(int i = 0; i < m; ++i) {
                  auto a = adj[i];
                  if(!D.areTeam(a.sec.fs , a.sec.sec)) {
                        cost += a.fs;
                        D.mergeTeams(a.sec.fs , a.sec.sec);
                  }
            }
            cout << inicost - cost << endl;
      }
      return 0;
}
