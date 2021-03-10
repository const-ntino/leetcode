// 541. Reverse String II
// Given a s s and an integer k, reverse the first k characters for every
// 2k characters counting from the start of the s.
// If there are fewer than k characters left, reverse all of them. If there are
// less than 2k but greater than or equal to k characters, then reverse the
// first k characters and left the other as original.

#include <bits/stdc++.h>

using namespace std;

string reverseString(string s, int k) {
  vector<char> vec(s, s + s.length());
  vector<char> rev(s, s.length() + k);
  
  if (rev.size() <= 1) {
    return;
  }
  int head = 0;
  int tail = rev.size() - 1;

  while (head < tail) {
    swap(rev[head++], rev[tail--]);
  }

  for (int i = 0; i < vec.size(); i++) {
    if (i < k) {
      auto it = vec.begin();
      vec.erase(it);   
    }
  }
  rev.insert(rev.end(), vec.begin(), vec.end());

  for (int i = 0; i < rev.size(); i++) {
    cout << rev[i];
  }
  cout << endl;

  return rev;
}

int main() {
  string str = "abcdefg";

  reverseString(str, 4);
}