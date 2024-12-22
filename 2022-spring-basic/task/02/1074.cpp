#include <bits/stdc++.h>
using namespace std;

int N, R, C;
bool vis;

int func(int r_st, int r_en, int c_st, int c_en){ // visit rectangle {x -> [r_st, r_en], y -> [c_st, c_en]}
	if(vis) return 0;
  // 범위에 완전히 벗어남 -> 사각형의 크기만큼 방문처리를 해주면 됨.
  if(!(r_st <= R and R <= r_en) or !(c_st <= C and C <= c_en)) return (r_en - r_st + 1) * (c_en - c_st + 1);

  // 그 지점에 도달함
  if(r_st == r_en and c_st == c_en){
    vis = true;
    return 0;
  }

  // 범위 내에 방문하고자 하는 곳이 있음.
	int r_mid = (r_st + r_en) >> 1, c_mid = (c_st + c_en) >> 1;
 	return func(r_st, r_mid,  c_st, c_mid) + // 1st -> vist rectangle {x -> [r_st, r_mid], y -> [c_st, c_mid]}
         func(r_st, r_mid, c_mid + 1, c_en) + // 2st -> vist rectangle {x -> [r_st, r_mid], y -> [c_mid + 1, c_en]}
         func(r_mid + 1, r_en, c_st, c_mid) + // 3st -> vist rectangle {x -> [r_mid + 1, r_en], y -> [c_st, c_mid]}
         func(r_mid + 1, r_en, c_mid + 1, c_en); // 4st -> vist rectangle {x -> [r_mid + 1, r_en], y -> [c_mid + 1, c_en]}
}

int main(){
  ios::sync_with_stdio(false);
   cin >> N >> R >> C;
   cout << func(0, (1 << N) - 1, 0, (1 << N) - 1) << "\n";
  return 0;
}