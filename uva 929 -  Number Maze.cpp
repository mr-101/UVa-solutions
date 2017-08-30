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
 
int dis[1005][1005] , g[1005][1005];
int t , n , m;
int dx[] = {0 , 1 , -1 , 0};
int dy[] = {1 , 0 , 0 , -1};

bool valid(int i , int j) {
      return i < n && i >= 0 && j >= 0 && j < m;
}
void dijkstra(int x , int y , int c) {
      priority_queue<pair<int , ii> > q;
      dis[x][y] = c;
      q.push(mp(0,mp(x , y)));
      while(!q.empty()) {
            int u = q.top().sec.fs , v = q.top().sec.sec , d = -q.top().fs;
            q.pop();
            if(d > dis[u][v])
                  continue;
            for(int i = 0; i < 4; ++i) {
                  int nx = u + dx[i] , ny = v + dy[i];
                  if(!valid(nx , ny) || dis[nx][ny] <= dis[u][v] + g[nx][ny])
                        continue;
                  dis[nx][ny] = dis[u][v] + g[nx][ny];
                  q.push(mp(-dis[nx][ny] , mp(nx , ny)));
            }
      }
}

int main() {
      cin >> t;
      while(t--) {
            cin >> n >> m;
            for(int i = 0; i < n; ++i)
                  for(int j = 0; j < m; ++j)
                        cin >> g[i][j];

            for(int i = 0; i < n; ++i)
                  for(int j = 0; j < m; ++j)
                        dis[i][j] = inf;

            
            dijkstra(0 , 0 , g[0][0]);
            cout << dis[n-1][m-1] << endl;
      }
      return 0;
} 
