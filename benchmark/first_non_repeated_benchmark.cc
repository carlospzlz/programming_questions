#include <vector>
#include "first_non_repeated.h"
#include "benchmark/benchmark.h"

std::vector<int> createElements(size_t size)
{
  std::vector<int> elements;
  for (size_t i = 0; i < size/2; ++i)
  {
    elements.push_back(i);
    elements.push_back(i);
  }
  elements.push_back(size/2);
  //std::random_shuffle(elements.begin(), elements.end());
  return elements;
}

static void BM_FirstNonRepeated1(benchmark::State& state)
{
  std::vector<int> elements = createElements(state.range(0));
  for (auto _ : state)
  {
    FirstNonRepeated1(elements);
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_FirstNonRepeated1)->RangeMultiplier(2)->Range(8, 8<<10)->Complexity();

static void BM_FirstNonRepeated2(benchmark::State& state)
{
  std::vector<int> elements = createElements(state.range(0));
  for (auto _ : state)
  {
    FirstNonRepeated2(elements);
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_FirstNonRepeated2)->RangeMultiplier(2)->Range(8, 8<<10)->Complexity();

BENCHMARK_MAIN();
