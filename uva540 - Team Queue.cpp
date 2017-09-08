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
 
int t , n , x , p = 1 , team[1000000] , done[1005];
queue<int> q , draft[1005];
int main() {  
      while(cin >> t , t) {
            printf("Scenario #%d\n" , p++);
            
            while(!q.empty())
                  q.pop();

            memset(done , 0 , sizeof done);

            for(int i = 0; i < t; ++i)
                  while(!draft[i].empty())
                        draft[i].pop();

            for(int i = 0; i < t; ++i) {
                  cin >> n;
                  while(n--) {
                        cin >> x;
                        team[x] = i;
                  }
            }
            string s;
            while(cin >> s) {
                  if(s == "STOP") {
                        cout << endl;
                        break;
                  }
                  else if(s == "ENQUEUE") {
                        cin >> x;
                        if(!done[team[x]]) {
                              done[team[x]] = 1;
                              q.push(team[x]);
                        }
                        draft[team[x]].push(x);
                  }
                  else {
                        cout << draft[q.front()].front() << endl;
                        draft[q.front()].pop();
                        if(draft[q.front()].empty()) {
                              done[q.front()] = 0;
                              q.pop();
                        }
                  }
            }
      }     
      return 0;
} 
