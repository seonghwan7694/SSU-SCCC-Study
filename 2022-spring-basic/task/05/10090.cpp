#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1'000'000
unsigned long long ret;
int n, A[MAX_N], tmp[MAX_N];

void Merge(int l, int r){ // merge [l, r]
  int m = (l + r) >> 1;
  int i = l, j = m + 1, idx = l;

  while(i <= m and j <= r){
    if(A[i] < A[j]){ // Not exist Inversions
      tmp[idx++] = A[i++];
    }else{ // Exist Inversions
      ret += m - i + 1;
      tmp[idx++] = A[j++];
    }
  }
  while(i <= m){ // Exist Inversions{
    tmp[idx++] = A[i++];
  }
  while(j <= r) tmp[idx++] = A[j++]; // Not exist Inversions
  for(int k = l; k <= r; k++) A[k] = tmp[k];
  return;
}

void Sort(int l, int r){ // sort [l, r]
  if(l == r) return;
  int m = (l + r) >> 1;
  Sort(l, m);
  Sort(m + 1, r);
  Merge(l, r);
}

int main(){
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  Sort(0, n - 1);
  cout << ret << "\n";
  return 0;
}