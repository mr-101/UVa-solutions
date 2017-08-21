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

int t , n , m , st , en , dist[105];
vi adj[105];

void printPath(map<int , int> &prev , int v) {
      int u = prev[v];
            if (u != v)
      printPath(prev, u);
      cout << (char)(v+'A');
}

int main() {
      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif
            
      scanf("%d" , &t);
      bool f = 0;
      while(t--) {
            if(f) puts("");
            f = 1;
            scanf("%d %d" , &n , &m);
            string s1 , s2;
            for(int i = 0; i < 104; ++i)
                  adj[i].clear();

            for(int i = 0; i < n; ++i) {
                  cin >> s1 >> s2;
                  adj[s1[0] - 'A'].pb(s2[0] - 'A');
                  adj[s2[0] - 'A'].pb(s1[0] - 'A');
            }

            for(int i = 0; i < m; ++i) {
                  memset(dist , -1 , sizeof dist);
                  cin >> s1 >> s2;
                  st = s1[0] - 'A';
                  en = s2[0] - 'A';
                  queue<int> q;
                  map<int , int> prev;
                  q.push(st);
                  prev[st] = st;
                  dist[st] = 0;
                  while(!q.empty()) {
                        int a = q.front();
                        q.pop();
                        for(auto i : adj[a]) {
                              if(dist[i] == -1) {
                                    prev[i] = a;
                                    q.push(i);
                                    dist[i] = dist[a] + 1;
                              }

                        }
                  }
                  printPath(prev, en);
                  puts("");
            }

      }
      return 0;
}
