#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll A, B, C, ret = 1;
int main(){
  ios::sync_with_stdio(false);

  // a^b mod c
  // if b & 1, a * a^(b-1) mod c
  // if not b & 1, a = a * a mod c, b /= 2;
  cin >> A >> B >> C;

  while(B > 0){
    if(B & 1){
      ret *= A % C;
    }
    A = (A * A) % C;
    B /= 2;
  }
  cout << ret << "\n";
  return 0;
}