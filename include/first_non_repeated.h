#include <cassert>
#include <unordered_map>
#include <vector>

template <class T>
T FirstNonRepeated1(const std::vector<T>& elements) {
  assert(elements.size());
  std::unordered_map<T, size_t> count;
  for (const T& element : elements) {
    ++count[element];
  }
  for (const T& element : elements) {
    const auto& elementIter = count.find(element);
    if (elementIter->second == 1) {
      return element;
    }
  }
  assert(false);
}

template <class T>
T FirstNonRepeated2(const std::vector<T>& elements) {
  assert(elements.size());
  for (size_t i = 0; i < elements.size(); ++i) {
    size_t j;
    for (j = 0; j < elements.size(); ++j) {
      if (i != j && elements[i] == elements[j]) {
        break;
      }
    }
    if (j == elements.size()) {
      return elements[i];
    }
  }
  assert(false);
}
