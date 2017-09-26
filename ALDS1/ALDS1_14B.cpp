#include<iostream>
#include<vector>
using namespace std;
long long int inf = 10000000000;

vector<long long int> rollinghash(string s, int a){
  int n = s.size();
  vector<long long int> rh(n+1, 0);
  for(int i=0; i<n; i++){
    rh[i+1] = rh[i] * a + s[i];
  }
  return rh;
}

int main(){
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  vector<long long int> p(n+1, 0);
  p[0] = 1;
  long long int a = 1000000007;
  for(int i=0; i<n; i++){
    p[i+1] = p[i] * a;
  }

  vector<long long int> rhs = rollinghash(s, a);
  vector<long long int> rht = rollinghash(t, a);

  for(int i=0; i<n; i++){
    int l = i; int r = i + m - 1;
    if( rhs[r+1] - rhs[l] * p[r-l+1] == rht[m] ) cout << i << endl;
  }

  return 0;
}





// EOF
