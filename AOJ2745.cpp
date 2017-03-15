// 今，W0 [L] の水に R0 [g] のルウを混ぜた作りかけのカレーがある． 今回使うルウは 1 種類で，1 個あたり R [g] である．ルウは十分な量の備蓄がある． あなたはこのルウを使う場合，濃度が C [g/L] のカレーが最も美味しいと考えているので，このカレーにいくつかのルウと水を適切に加え，濃度を C [g/L] にしたいと考えている． ここで，ルウ R0 [g] が水 W0 [L] に溶けているカレーの濃度は R0 / W0 [g/L] であり，このカレーに R [g] のルウを X 個と水 Y [L] を追加すると，その濃度は (R0 + X R) / (W0 + Y) [g/L] になる． ルウは大量にあるものの，使い過ぎるのは良くないと考えたあなたは，追加するルウの個数を出来る限り少なくして濃度 C [g/L] のカレーを作ることにした．
//
// 濃度 R0/W0 [g/L] のカレーに，ルウか水のいずれか，またはその両方を適切に加えることによって濃度 C [g/L] のカレーを作るとき，追加すべきルウの個数 X の最小値を求めて欲しい．
//
// ただし，今回のカレー作りについては，以下の事柄に注意すること．
//
// 追加するルウの個数 X の値は 0 以上の整数でなければならない．つまり，ルウを 1/3 個分だけ追加する，といったことは出来ない．
// 追加する水の体積 Y の値は 0 以上の実数として良く，整数である必要はない．
// ルウか水のいずれか，またはその両方を追加しなくても濃度 C のカレーを作ることが出来る場合もある．
// ルウや水は十分な量を確保しているので，ルウや水が足りず濃度 C のカレーを作ることが出来ない，という事態は起こらないとして良い．
// Input
// 入力は複数のデータセットからなる． 各データセットは 1 行からなり，次の形式で表される．
//
// R0 W0 C R
// ここで，R0，W0，C，R はそれぞれ作りかけのカレーに既に溶け込んだルウの質量 [g]，カレーに含まれる水の体積 [L]，あなたが作りたいカレーの濃度 [g/L]，ルウ 1 個あたりの質量 [g] を表す． これらの値は，全て 1 以上 100 以下の整数である． 入力の終わりは，空白で区切られた 4 つのゼロからなる行によって示される．
//
// Output
// 各データセットについて，W0 [L] の水に R0 [g] のルウを混ぜた作りかけのカレーから，濃度 C のカレーを作るために追加する必要のあるルウの個数の最小値を 1 行で出力すること．追加する水の量を出力してはならない．
//
// 入力制約から，各データセットの答えとなるルウの個数の最小値は，32ビット符号付き整数で表現される範囲におさまることが保証されることに注意せよ．
#include<iostream>
using namespace std;

int main(){

  int r0, w0, c, r;
  while( cin >> r0 >> w0 >> c >> r ){
    if( r0 == 0 && w0 == 0 && c == 0 && r == 0 ) break;
    int cnt = 0;

    while( true ){
      if( r0 < w0 * c ){
        r0 += r;
        cnt++;
      }else break;
    }
    cout << cnt << endl;
  }

  return 0;
}