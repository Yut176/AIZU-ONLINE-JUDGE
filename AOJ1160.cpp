// Problem B: 島はいくつある？
// この問題では，同じ大きさの正方形に区切られたメッシュ状の地図が与えられる． この地図は，ある海域を表しており，各正方形の領域が陸または海に対応する． 図B-1は地図の一例である．
//
// 図B-1：ある海域の地図
// 陸に対応する二つの正方形領域が，地図上で縦，横または斜め方向に隣接しているなら，一方から他方へ歩いて行くことができる． 陸に対応する二つの領域が同じ島に属するのは，一方から他方へ（一般には別の陸地を経由して）歩いて行ける時であり，またその時のみである． なお，この地図の海域は海で囲まれており，その外側へ歩いて出ることはできない．
//
// 与えられた地図を読み取り，この海域に島がいくつあるか数えるプログラムを作成して欲しい． たとえば，図B-1の地図には，全部で三つの島がある．
//
// Input
// 入力はデータセットの列であり，各データセットは次のような形式で与えられる．
//
// w h
// c1,1 c1,2 ... c1,w
// c2,1 c2,2 ... c2,w
// ...
// ch,1 ch,2 ... ch,w
// w と h は地図の幅と高さを表す50以下の正の整数であり，地図は w×h 個の同じ大きさの正方形から構成される． w と h の間は空白文字1個で区切られる．
//
// ci, j は，0 または 1 であり，空白文字1個で区切られる． ci, j = 0 なら，地図上で左から i 番目，上か ら j 番目の正方形は海であり，ci, j = 1 なら陸である．
//
// 入力の終わりは，空白文字1個で区切られた2個のゼロのみからなる行で表される．
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector< vector<int> > bfs(int h, int w, int y, int x, vector< vector<int> > t, int g){
  vector< vector<bool> > b(h, vector<bool> (w, false));
  b[y][x] = true;
  queue< pair<int, int> > q;
  q.push( make_pair(x, y) );
  int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
  int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
  while(true){
    if( q.empty() ) break;

    pair<int, int> p = q.front();
    q.pop();
    int px = p.first;
    int py = p.second;

    for(int dir=0; dir<8; dir++){
      int tx = px + dx[dir];
      int ty = py + dy[dir];

      if( tx < 0 || tx >= w || ty < 0 || ty >= h ) continue;
      if( b[ty][tx] ) continue;
      if( t[ty][tx] == 0 ) continue;

      b[ty][tx] = true;
      t[ty][tx] = g;
      q.push( make_pair(tx, ty) );
    }
  }

  return t;
}

int main(){

  int w, h;
  while(cin >> w >> h){
    if( w == 0 && h == 0 ) break;
    vector< vector<int> > t(h, vector<int> (w));
    int g = 2;
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        cin >> t[i][j];
      }
    }

    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        if( t[i][j] == 1 ){
          t = bfs(h, w, i, j, t, g);
          g++;
        }
      }
    }
    cout << g-2 << endl;
  }

  return 0;
}
