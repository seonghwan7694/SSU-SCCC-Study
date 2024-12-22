#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N;
vector<string> v;


bool can_resizing(const int &r_st, const int &r_en, const int &c_st, const int &c_en){
  char ch = v[r_st][c_st];
  for(int r = r_st; r < r_en; r++){
    for(int c = c_st; c < c_en; c++){
      if(v[r][c] != ch) return false;
    }
  }
  return true;
}

void func(int r_st, int r_en, int c_st, int c_en){
  // can resizing
  if(can_resizing(r_st, r_en, c_st, c_en)){ // check x -> [r_st, r_en), y -> [c_st, c_en)
    cout << v[r_st][c_st];
    return;
  }

  // can't resizing
  cout << "(";
  int r_mid = (r_st + r_en) >> 1, c_mid = (c_st + c_en) >> 1;
  func(r_st, r_mid, c_st, c_mid);
  func(r_st, r_mid, c_mid, c_en);
  func(r_mid, r_en, c_st, c_mid);
  func(r_mid, r_en, c_mid, c_en);
  cout << ")";
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  for(int i = 0; i < N; i++){
    string str;
    cin >> str;
    v.push_back(str);
  }
  func(0, N, 0, N); // resizing {x -> [0, N), y -> [0, N)}
  return 0;
}