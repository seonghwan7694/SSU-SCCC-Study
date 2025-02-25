#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int M[129][129], ret[3], N;

// rect -> {(x -> [x, x + n), y -> [y, y + n)}에서의 색상 코드를 반환하는 함수
// 0 반환 -> White 로 이루어짐
// 1 반환 -> Blue 로 이루어짐
// 2 반환 -> 섞여있음
void Divide(int x, int y, int n){
  int c = M[x][y];
  for(int i = x; i < x + n; i++){
    for(int j = y; j < y + n; j++){
      if(c != M[i][j]){
        int nn = n >> 1;
        Divide(x, y, nn);
        Divide(x + nn, y, nn);
        Divide(x, y + nn, nn);
        Divide(x + nn, y + nn, nn);
        return;
      }
    }
  }
  ret[c]++;
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin >> N;

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> M[i][j];
    }
  }
  Divide(1, 1, N);
  cout << ret[0] << "\n";
  cout << ret[1] << "\n";
  return 0;
}