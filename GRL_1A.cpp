#include<iostream>
#include<vector>
using namespace std;
int inf = 1000000000;

struct Node{
  int to, from, cost;
};

int main(){
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> dist(n, inf);
  vector<Node> node(m);
  for(int i=0; i<m; i++){
    int s, t, d;
    cin >> s >> t >> d;
    node[i].to = t; node[i].from = s; node[i].cost = d;
  }

  dist[r] = 0;
  while( true ){
    bool f = false;
    for(int i=0; i<node.size(); i++){
      Node d = node[i];
      if( dist[d.from] != inf && dist[d.to] > dist[d.from] + d.cost ){
        dist[d.to] = dist[d.from] + d.cost;
        f = true;
      }
    }
    if( !f ) break;
  }

  for(int i=0; i<n; i++){
    if( dist[i] == inf ) cout << "INF" << endl;
    else cout << dist[i] << endl;
  }

  return 0;
}





// EOF
