#include <bits/stdc++.h>
using namespace std;

int A[7] = {5, 4, 3, 2, 1, 0, -1};

void Merge(int l, int m, int r){
  static int tmp[10];
  int i = l, j = m + 1, idx = l;
  while(i <= m and j <= r){
    if(A[i] < A[j]) tmp[idx++] = A[i++];
    else tmp[idx++] = A[j++];
  }
  while(i <= m) tmp[idx++] = A[i++];
  while(j <= r) tmp[idx++] = A[j++];
  for(int k = l; k <= r; k++) A[k] = tmp[k];
  return;
}

void mergeSort(int l, int r){
  if(l == r) return;
  int m = (l + r) >> 1;
  mergeSort(l, m), mergeSort(m + 1, r);
  Merge(l, m, r);
  return;
}


int main(){
  ios::sync_with_stdio(false);
  mergeSort(0, 6);
  for(int i = 0; i < 7; i++){
    cout << A[i] << " ";
  }
  return 0;
}