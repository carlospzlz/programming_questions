#include "benchmark/benchmark.h"
#include "is_palindrome.h"

static void BM_IsPalindrome1(benchmark::State& state) {
  std::string palindrome = "asantadoglivedasadevilgodatnasa";
  for (auto _ : state) {
    IsPalindrome1(palindrome);
  }
}
BENCHMARK(BM_IsPalindrome1);

static void BM_IsPalindrome2(benchmark::State& state) {
  std::string palindrome = "asantadoglivedasadevilgodatnasa";
  for (auto _ : state) {
    IsPalindrome2(palindrome);
  }
}
BENCHMARK(BM_IsPalindrome2);

BENCHMARK_MAIN();
