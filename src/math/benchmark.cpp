#include <cmath>
#include <benchmark/benchmark.h>
#include "gcd.h"
#include "binary_exponentiation.h"

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

static void BM_QMI(benchmark::State& state) {
    int b = state.range(0);
    for(auto _ : state) {
        BinPow(2, b);
    }
}

static void BM_STDPOW(benchmark::State& state) {
    int b = state.range(0);
    for(auto _ : state) {
        std::pow(2, b);
    }
}

BENCHMARK(BM_QMI)->Arg(63);
BENCHMARK(BM_STDPOW)->Arg(63);

BENCHMARK_MAIN();
