#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll M, N, K, P = 1e9 + 7;

ll modular_pow(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b % 2 == 1){
      res = (res * a) % P;
    }
    a = (a * a) % P;
    b /= 2;
  }
  return res;
}

void C(){
    // N! * (K! * ((N - K)!) ^ (-1)) mod P
    // 페르마 소정리 활용에 의해 (K! * ((N - K)!) ^ (-1)) 와 (K! * ((N - K)!) ^ (P - 2) 는 모듈러 P에서 합동이다.

    // N! * (K!)^(P-2) * ((N-K)!)^(P-2) mod P 가 된다.
    ll res = 1;
    for(ll i = 1; i <= N; i++){
      res = (res * i) % P;
    }
    ll a = 1, b = 1;
    for(int i = 1; i <= K; i++){ a = (a * i) % P; }
    for(int i = 1; i <= N - K; i++){ b = (b * i) % P; }
}
int main(){
  ios::sync_with_stdio(false);
  cin >> M;
  while(M--){
    cin >> N >> K;
    C();
  }


  return 0;
}