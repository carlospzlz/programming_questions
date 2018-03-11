#include "baseball_game.h"
#include "benchmark/benchmark.h"
#include <string>
#include <vector>

static void BM_CalPoints1(benchmark::State& state) {
  std::vector<std::string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
  for (auto _ : state) {
    CalPoints1(ops);
  }
}
BENCHMARK(BM_CalPoints1);

BENCHMARK_MAIN();
