#ifndef TEST_INTEROP_CXX_STDLIB_INPUTS_STD_SPAN_H
#define TEST_INTEROP_CXX_STDLIB_INPUTS_STD_SPAN_H

#include <cstddef>
#include <string>
#include <span>

using Span = std::span<const int>;
using NonConstSpan = std::span<int>;
using SpanOfString = std::span<const std::string>;

// TODO remove this code
class CppApi {
public:
  Span getConstSpan();
  std::span<int> getSpan();
  // TODO try with std::span<int>
};

Span CppApi::getConstSpan() {
  Span sp{new int[2], 2};
  return sp;
}

std::span<int> CppApi::getSpan() {
  std::span<int> sp{new int[2], 2};
  return sp;
}

static int iarray[]{1, 2, 3};
static std::string sarray[]{"", "ab", "abc"};
static Span ispan = {iarray};
static SpanOfString sspan = {sarray};

inline Span initSpan() { 
  const int a[]{1, 2, 3};
  return Span(a);
}

#endif // TEST_INTEROP_CXX_STDLIB_INPUTS_STD_SPAN_H
