#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pb push_back
#define M 1000005
#define N 100005
#define EPS 1e-9
#define inf 1e9+1
#define MOD 1e9

using namespace std;

typedef pair<int,int> ii;
typedef pair<ll,ll> lii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double pi = acos(-1);

int n , t , a , TC , p = 1 , adjmat[105][105] , vis[105];

void DFS(int node , int absent) {
  if(node == absent)
    return;
  vis[node] = 1;
  for(int i = 0; i < n; ++i) {
    if(adjmat[node][i] && !vis[i])
      DFS(i , absent);
  }
}


int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  #endif

  scanf("%d" , &TC);
  while(TC--) {
    scanf("%d" , &n);
    memset(adjmat , 0 , sizeof adjmat);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        scanf("%d" , &a);
        adjmat[i][j] = a;
      }
    }
    int iniVis[105] , output[105][105];
    memset(vis , 0 , sizeof vis);
    DFS(0 , -1);

    for(int i = 0; i < 102; ++i)
        iniVis[i] = vis[i];

    for(int i = 0; i < n; ++i) {
      memset(vis , 0 , sizeof vis);
      DFS(0 , i);
      for(int j = 0; j < n; ++j) {
        if(iniVis[j] && !vis[j])
          output[i][j] = 1;
        else
          output[i][j] = 0;
      }
      output[i][i] = iniVis[i];
    }
    printf("Case %d:" , p++);
    printf("\n+");

    for(int i = 0; i < 2*n-1; i++)
      printf("-");

    printf("+\n");

    for(int i = 0; i < n; i++) {
      printf("|");
      for(int j = 0; j < n; ++j) {
        if(output[i][j])
            printf("Y");
        else
            printf("N");

        printf("|");
      }
    printf("\n+");

    for (int j = 0; j < 2*n-1; j++) {
        printf("-");
      }
      printf("+\n");
    }
  }
   	return 0;
}
