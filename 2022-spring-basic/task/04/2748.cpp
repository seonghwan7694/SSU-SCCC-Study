#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll f[101], n;

ll fibo(ll n){
  if(f[n] != -1) return f[n];
  return f[n] = fibo(n-1) + fibo(n-2);
}

int main(){
  fill(f, f + 101, -1);
  f[0] = 0, f[1] = 1;
  cin >> n;
  cout << fibo(n) << "\n";
  return 0;
}
