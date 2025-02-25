#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll N, M, K;
vector<ll> A, S;

ll Init(int n, int l, int r){
  if(l == r){
    return S[n] = A[l];
  }
  int m = (l + r) >> 1;
  return S[n] = Init(n * 2, l, m) + Init(n * 2 + 1, m + 1, r);
}

ll Sum(int L, int R, int l, int r, int n){ // L, R -> 값을 구해야하는 구간, l, r -> 내가 탐색하고 있는 구간
  if(r < L or R < l) return 0;
  if(L <= l and r <= R){ // 값을 구해야하는 구간에 내가 탐색하고 있는 구간이 완전히 포함됨
    return S[n];
  }
  ll m = (l + r) >> 1;
  return Sum(L, R, l, m, n * 2) + Sum(L, R, m + 1, r, n * 2 + 1);
}

void Update(int l, int r, int n, int idx, int diff){
  if(idx < l or r < idx) return;
  S[n] += diff;
  int m = (l + r) >> 1;
  if(l != r){
    Update(l, m, n * 2, idx, diff);
    Update(m + 1, r, n * 2 + 1, idx, diff);
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin >> N >> M >> K;
  A.resize(N + 1);
  ll h = (ll) ceil(log2(N));
  ll tree_size = (1 << (h + 1));
  S.resize(tree_size);
  for(int i = 1; i <= N; i++){
    cin >> A[i];
  }
  Init(1, 1, N);
  for(int i = 0, a, b, c; i < M + K; i++){
    cin >> a >> b >> c;
    if(a & 1){
      // update A[b] to c
      Update(1, N, 1, b, c - A[b]);
      A[b] = c;
    }else{
      // sum A[b] .. A[c]
      cout << Sum(b, c, 1, N, 1) << "\n";
    }
  }
  return 0;
}