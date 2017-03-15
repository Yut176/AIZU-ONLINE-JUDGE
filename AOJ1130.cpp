// Red and Black
// 正方形のタイルが敷き詰められた長方形の部屋がある．タイルの色は赤か黒 である．最初に一人の人が部屋の黒いタイルの上に立っている． あるタイルからは隣接する四つのタイルに移動することができる． ただし，赤いタイルの上に移動することはできない．移動できるのは黒いタイルの上 だけである．
//
// 上記の移動を繰り返すことによって到達できるタイルの数を答えるプログラムを書きなさい．
//
// Input
// 入力は複数のデータセットからなる．データセットは，WとHと いう二つの正の整数からなる行で始まる．WとHは部屋のx方向， y方向にタイルがいくつ並ぶかを表す．WとHは20以下である．
//
// その後ろにH行続く．それぞれの行にはW個の文字が含まれてい る．それぞれの文字は次に示すようにタイルの状態を表す．
//
// '.' - 黒いタイル
// '#' - 赤いタイル
// '@' - 黒いタイルの上の人(一つのデータセットに1度だけ出現)
// 入力の終わりは0を二つ含む行で表される．
//
// Output
// 入力のデータセットごとに， 最初の位置から到達可能なタイルの数を1行で出力しなさい(最初のタイルも含む)．

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){

  int w, h;
  while(cin >> w >> h){
    if( w == 0 && h == 0 ) break;

    vector<string> t(h);
    for(int i=0; i<h; i++) cin >> t[i];
    int x, y;
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        if( t[i][j] == '@' ){
          x = j;
          y = i;
        }
      }
    }

    vector< vector<bool> > b(h, vector<bool> (w, false));
    b[y][x] = true;
    queue< pair<int, int> > q;
    q.push( make_pair(x, y) );
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    while(true){
      if( q.empty() ) break;

      pair<int, int> p = q.front();
      q.pop();
      int px = p.first;
      int py = p.second;

      for(int dir=0; dir<4; dir++){
        int tx = px + dx[dir];
        int ty = py + dy[dir];

        if( tx < 0 || tx >= w || ty < 0 || ty >= h ) continue;
        if( b[ty][tx] ) continue;
        if( t[ty][tx] == '#' ) continue;

        b[ty][tx] = true;
        q.push( make_pair(tx, ty) );
      }
    }
    int cnt = 0;
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        if( b[i][j] ) cnt++;
      }
    }
    cout << cnt << endl;
  }

  return 0;
}
