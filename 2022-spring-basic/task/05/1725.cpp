#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100'000
#define lld long long
lld N, H[MAX_N], ret;

// [i, j] -> (j - i + 1) * min(H[i], .., H[j])
// O(N^3)에 해결 가능하지만, N = 100'000이니 시간초과. 적어도 O(N^2) 이하의 시간복잡도를 가진 알고리즘 필요

void Divide(int l, int r){
  if(l == r){
    ret = max(ret, H[l]);
    return;
  }

  int m = (l + r) >> 1;
  Divide(l, m);
  Divide(m + 1, r);

  // m을 포함하는 구간 [l, r]에서 가장 큰 직사각형의 넓이를 구하기
  // (j - i + 1) * min(H[i], .., H[j])
  lld ll = m, rr = m, mh = H[m];
  while(l <= ll and rr <= r){
    ret = max(ret, (rr - ll + 1) * mh);
    if(H[ll - 1] < H[rr + 1]){
      mh = min(mh, H[++rr]);
    }else{
      mh = min(mh, H[--ll]);
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> H[i];
  }
  Divide(0, N - 1); // get MAX rectangle from [0, N - 1]
  cout << ret << "\n";
  return 0;
}