#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, K, P = 1e9 + 7;

// caculate a^b mod p
ll modular_exponentiation(ll a, ll b, ll p){
  ll res = 1;
  a = a % p;
  while(b > 0){
    if(b % 2 == 1){
      res = (res * a) % p;
    }
    a = (a * a) % p;
    b /= 2;
  }
  return res;
}

ll modular_inverse(ll a, ll p){
  return modular_exponentiation(a, p - 2, p);
}

// caculate N! % p
ll factorial_mod(ll n, ll p){
  if(n >= p) return 0;
  ll res = 1;
  for(ll i = 1; i <= N; i++){
    res = (res * i) % p;
  }
  return res;
}

// 이항 계수 (N K)를 P로 나눈 나머지를 구하는 프로그램을 작성하시오
// N! * (K! * (N - K)!)^(-1) mod P
int main(){
  ios::sync_with_stdio(false);
  cin >> N >> K;
  ll res = 1;
  for(int i = K + 1; i <= N; i++){ // caculate N! * (K!)^(-1) mod P
    res = (res * i) % P;
  }

  // how to calculate ((N - K)!)^(-1) mod P
  // using 페르마 소정리
  // ((N - K)!)^(-1) 와 ((N - K)!)^(P - 2) 는 모듈러 P 에서 합동이다.
  ll tmp = 1;
  for(int i = 1; i <= N - K; i++){
    tmp = (tmp * i) % P;
  }
  tmp = modular_exponentiation(tmp, P - 2, P);
  cout << (res * tmp) % P << "\n";
  return 0;
}