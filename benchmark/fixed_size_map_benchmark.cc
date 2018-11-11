#include "fixed_size_map.h"
#include "benchmark/benchmark.h"
#include <iostream>

template <class MAP>
void fillMap(MAP& map, const int capacity)
{
    for (int i = 0; i < capacity; ++i)
    {
        map.insert(std::to_string(i), "");
    }
}

// Using list + iterator.
static void BM_FixedSizeMap1_find(benchmark::State& state)
{
    int capacity = state.range(0);
    FixedSizeMap1 map(capacity);
    fillMap(map, capacity);
    const auto key = std::to_string(state.range(0) / 2);
    for (auto _ : state)
    {
        // This breaks ?
        //map.find(key);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_FixedSizeMap1_find)
    ->RangeMultiplier(2)
    ->Range(8, 8 << 10)
    ->Complexity();

static void BM_FixedSizeMap1_erase(benchmark::State& state)
{
    int capacity = state.range(0);
    FixedSizeMap1 map(capacity);
    fillMap(map, capacity);
    const auto key = std::to_string(state.range(0) / 2);
    for (auto _ : state)
    {
        map.erase(key);
        // Erases and it stays erased!
        map.insert(key, "");
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_FixedSizeMap1_erase)
    ->RangeMultiplier(2)
    ->Range(8, 8 << 10)
    ->Complexity();

static void BM_FixedSizeMap1_insert(benchmark::State& state)
{
    int capacity = state.range(0);
    FixedSizeMap1 map(capacity);
    fillMap(map, capacity);
    const auto key = std::to_string(state.range(0) / 2);
    for (auto _ : state)
    {
        map.insert(key, "");
        map.erase(key);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_FixedSizeMap1_insert)
    ->RangeMultiplier(2)
    ->Range(8, 8 << 10)
    ->Complexity();

// Using vector.
static void BM_FixedSizeMap2_find(benchmark::State& state)
{
    const int capacity = state.range(0);
    FixedSizeMap2 map(capacity);
    fillMap(map, capacity);
    const auto key = std::to_string(state.range(0) / 2);
    for (auto _ : state)
    {
        map.find(key);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_FixedSizeMap2_find)
    ->RangeMultiplier(2)
    ->Range(8, 8 << 10)
    ->Complexity();

static void BM_FixedSizeMap2_erase(benchmark::State& state)
{
    const int capacity = state.range(0);
    FixedSizeMap2 map(capacity);
    fillMap(map, capacity);
    const auto key = std::to_string(state.range(0) / 2);
    for (auto _ : state)
    {
        map.erase(key);
        map.insert(key, "");
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_FixedSizeMap2_erase)
    ->RangeMultiplier(2)
    ->Range(8, 8 << 10)
    ->Complexity();

static void BM_FixedSizeMap2_insert(benchmark::State& state)
{
    const int capacity = state.range(0);
    FixedSizeMap2 map(capacity);
    fillMap(map, capacity);
    const auto key = std::to_string(state.range(0) / 2);
    for (auto _ : state)
    {
        map.insert(key, "");
        map.erase(key);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_FixedSizeMap2_insert)
    ->RangeMultiplier(2)
    ->Range(8, 8 << 10)
    ->Complexity();

BENCHMARK_MAIN();
