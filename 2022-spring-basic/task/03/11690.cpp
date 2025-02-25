#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1'000'000'000ll

ll N, M, tmp; // 1 <= N <= 1e12
map<ll, ll> nm, mm;

void func(map<ll, ll> &m, ll v){
  for(ll i = 2; i <= sqrt(v); i++){
    if(v % i == 0) m[i]++;
  }

}

int main(){
    ios::sync_with_stdio(false);
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> tmp;
    func(nm, tmp);
  }
  cin >> M;
  for(int i = 0; i < M; i++){
    cin >> tmp;
  }
  return 0;
}
