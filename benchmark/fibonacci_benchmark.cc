#include "fibonacci.h"
#include "benchmark/benchmark.h"

static void BM_Fibonacci1(benchmark::State& state) {
  for (auto _ : state) {
    Fibonacci1(state.range(0));
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_Fibonacci1)->RangeMultiplier(2)->Range(1, 1<<8)->Complexity();

static void BM_Fibonacci2(benchmark::State& state) {
  for (auto _ : state) {
    Fibonacci2(state.range(0));
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_Fibonacci2)->RangeMultiplier(2)->Range(1, 1<<8)->Complexity();

static void BM_Fibonacci3(benchmark::State& state) {
  for (auto _ : state) {
    Fibonacci3(state.range(0));
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_Fibonacci3)
  ->Arg(1)
  ->Arg(2)
  ->Arg(4)
  ->Arg(6)
  ->Arg(8)
  ->Arg(10)
  ->Arg(12)
  ->Arg(14)
  ->Arg(16)
  ->Arg(18)
  ->Arg(20)
  ->Arg(22)
  ->Arg(24)
  ->Arg(26)
  ->Arg(28)
  ->Arg(30)
  ->Complexity();

BENCHMARK_MAIN();
