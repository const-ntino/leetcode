// 344. Reverse String
// Write a function that reverses a string. The input string is given as an
// array of characters char[].
// Do not allocate extra space for another array, you must do this by modifying
// the input array in-place with O(1) extra memory.
// You may assume all the characters consist of printable ascii characters.

#include <bits/stdc++.h>

using namespace std;

void reverseString(vector<char>& s) {
  if (s.size() <= 1) {
    return;
  }
  int head = 0;
  int tail = s.size() - 1;

  while (head < tail) {
    swap(s[head++], s[tail--]);
  }
}

int main() {
  char str[] = "abcdefg";
  int k = 2;
  

  for (int i = 0; i < strlen(str); i++) {
    cout << str[i];
  }
  cout << endl;

  vector<char> vec(str, str + strlen(str));
  vector<char> rev(str, str + k);
  
  reverseString(rev);

  for (int i = 0; i < vec.size(); i++) {
    if (i < k) {
      auto it = vec.begin();
      vec.erase(it);   
    }
    // cout << vec[i];
  }
  rev.insert(rev.end(), vec.begin(), vec.end());

  for (int i = 0; i < rev.size(); i++) {
    cout << rev[i];
  }
  cout << endl;
}