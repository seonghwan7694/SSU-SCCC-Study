#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int N, res = (1 << 31) - 1;
vector<int> cost(11, 0);
vector<int> order;

vector<vector<pii>> sale(11);

int func(){
  vector<int> cpy_cost(cost.begin(), cost.end());
  int tmp_res = 0;

  for(int i = 1; i <= N; i++){
    // buy
    int t = order[i-1];
    tmp_res += cpy_cost[t];
    // discount
    for(auto &x : sale[t]){
      cpy_cost[x.first] = (cpy_cost[x.first] - x.second <= 0 ? 1 : cpy_cost[x.first] - x.second);
    }
  }
  return tmp_res;
}

int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> cost[i]; // i번째에 해당하는 물건의 가격
    order.push_back(i); // 물건을 사는 순서를 배정하는 배열
 }
  for(int i = 1, p, a, j; i <= N; i++){
    cin >> p;
    while(p--){
      cin >> a >> j;
      sale[i].push_back({a, j}); // i번째 물건을 구매하면 할인되는 상품들의 목록과 할인 값
    }
  }

  do{
    res = min(res, func());
  }while(next_permutation(order.begin(), order.end()));
  cout << res << "\n";
  return 0;
}