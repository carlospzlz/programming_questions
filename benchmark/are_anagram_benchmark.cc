#include "are_anagram.h"
#include "benchmark/benchmark.h"

static const char charset[] = "abcdefghijklmnopqrstvwxyz";

std::pair<std::string, std::string> createStrings(size_t size) {
  std::string str1;
  for (size_t i = 0; i < size; ++i) {
    str1.push_back(rand() % sizeof(charset));
  }
  std::string str2 = str1;
  std::random_shuffle(str2.begin(), str2.end());
  return std::pair<std::string, std::string>(str1, str2);
}

static void BM_AreAnagram1(benchmark::State& state) {
  std::pair<std::string, std::string> strs = createStrings(state.range(0));
  for (auto _ : state) {
    AreAnagram1(strs.first, strs.second);
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_AreAnagram1)->RangeMultiplier(2)->Range(8, 8 << 10)->Complexity();

static void BM_AreAnagram2(benchmark::State& state) {
  std::pair<std::string, std::string> strs = createStrings(state.range(0));
  for (auto _ : state) {
    AreAnagram2(strs.first, strs.second);
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_AreAnagram2)->RangeMultiplier(2)->Range(8, 8 << 10)->Complexity();

BENCHMARK_MAIN();
