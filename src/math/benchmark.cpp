#include <benchmark/benchmark.h>
#include "gcd.h"

static void BM_GcdGeneral(benchmark::State& state) {
    int a = state.range(0), b = state.range(1);
    for(auto _ : state) {
        gcd_general(a, b);
    }
}

static void BM_GcdDivision(benchmark::State& state) {
    int a = state.range(0), b = state.range(1);
    for(auto _ : state) {
        gcd_division(a, b);
    }
}

BENCHMARK(BM_GcdGeneral)->Args({123023, 2312});
BENCHMARK(BM_GcdDivision)->Args({123023, 2312});
BENCHMARK_MAIN();