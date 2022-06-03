// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) { return 1.; }
    if (n == 1) { return value; }
    double x = value;
    for (uint64_t i = 1; i < n; i++) {
        value *= x;
    }
    return value;
}

uint64_t fact(uint16_t n) {
    uint64_t an = 1;
    for (uint64_t i = 2; i <= n; i++) {
        an *= i;
    }
    return an;
}

double calcItem(double x, uint16_t n) {
  if (n == 0 || x == 0) return 0;
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double an = 1.;
    for (uint64_t i = 1; i <= count; i++) {
        an += pown(x, i) / fact(i);
    }
    return an;
}

double sinn(double x, uint16_t count) {
    double an = x;
    for (uint64_t i = 2; i <= count; i++) {
        an += pown(-1, i-1) * (pown(x, i*2-1) / fact(i*2-1));
    }
    return an;
}

double cosn(double x, uint16_t count) {
    double an = 1;
    for (uint64_t i = 2; i <= count; i++) {
        an += pown(-1, i - 1) * (pown(x, i * 2 - 2) / fact(i * 2 - 2));
    }
    return an;
}
