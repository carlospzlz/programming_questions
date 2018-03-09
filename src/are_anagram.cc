#include "are_anagram.h"
#include <algorithm>
#include <unordered_map>

bool AreAnagram1(const std::string& str1, const std::string& str2) {
  if (str1.size() != str2.size()) {
    return false;
  }

  std::unordered_map<char, size_t> count;
  for (size_t i = 0; i < str1.size(); ++i) {
    ++count[str1[i]];
    --count[str2[i]];
  }
  for (const std::pair<char, size_t>& char_count : count) {
    if (char_count.second != 0) {
      return false;
    }
  }
  return true;
}

bool AreAnagram2(const std::string& str1, const std::string& str2) {
  std::string str1_copy = str1;
  std::string str2_copy = str2;
  std::sort(str1_copy.begin(), str1_copy.end());
  std::sort(str2_copy.begin(), str2_copy.end());
  return str1_copy == str2_copy;
}
