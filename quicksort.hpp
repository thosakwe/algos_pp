#ifndef ALGOS_PP_QUICKSORT_HPP
#define ALGOS_PP_QUICKSORT_HPP
#include <vector>

// Returns the index that should split the two tables.
//
// The pivot, the value at the midpoint, will be at the middle of
// the actual vector, in its proper position.
template <typename T>
long partition(std::vector<T> &vec, long start = 0, long end = -1) {
  auto pivot = vec[start + (end - start) / 2];
  while (true) {
    while (vec[start] < pivot)
      start++;

    while (vec[end] > pivot)
      end--;

    if (start >= end)
      return end;

    auto temp = vec[start];
    vec[start] = vec[end];
    vec[end] = temp;
    start++;
    end--;
  }
}

// Recursive version.
template <typename T>
void quicksort(std::vector<T> &vec, long start = 0, long end = -1) {
  if (end == -1)
    end = vec.size() - 1;

  if (start < end) {
    auto p = partition(vec, start, end);
    quicksort(vec, start, p);
    quicksort(vec, p + 1, end);
  }
}

template <typename T>
void quicksort_end(std::vector<T> &vec, long start = 0, long end = -1) {
  // Default to end being the actual end of the vector.
  if (end == -1)
    end = vec.size() - 1;

  // This is clearly a loop, so just keep going until the list is definitely
  // sorted.
  //
  // Once the list is sorted, they will converge.
  while (start < end) {
    // For each iteration
  }
}

#endif