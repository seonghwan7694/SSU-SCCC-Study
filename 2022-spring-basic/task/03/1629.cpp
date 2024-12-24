#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll A, B, C;

int main(){
  ios::sync_with_stdio(false);

  cin >> A >> B >> C;

  // print (A^B) mod C
  // if B & 1 == 1 ((A^(B-1)) mod C * A mod C) mod C

  ll res = 1;
  while(B > 0){
    if(B & 1){
      res = (res * A) % C;
    }
    A = (A * A) % C;
    B /= 2;
  }
  cout << res << "\n";
  return 0;
}