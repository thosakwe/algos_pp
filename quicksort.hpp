#ifndef ALGOS_PP_QUICKSORT_HPP
#define ALGOS_PP_QUICKSORT_HPP
#include <vector>

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
void quicksort_old(std::vector<T> &vec, long start = 0, long end = -1) {
  if (end == -1)
    end = vec.size() - 1;

  // If there is one item, return.
  if ((end - start) <= 0)
    return;

  std::cout << vec << std::endl;

  // Find our pivot point - the midpoint.
  auto midPoint = start + (end - start) / 2;
  auto pivot = vec[start + midPoint];

  // Exchange the first element and the midPoint, and then
  // scan the rest.
  auto temp = vec[start];
  vec[start] = pivot;
  vec[midPoint] = temp;

  // Find a value less than the pivot, and swap it with a value greater than
  // pivot.
  //
  // Once the two cursors converge, we are done.
  auto scanUp = start + 1, scanDown = end;
  while (scanUp < scanDown) {
    // Find a value greater than pivot.
    while (vec[scanUp] < pivot)
      scanUp++;
    // Find a lesser value.
    while (vec[scanDown] > pivot)
      scanDown--;
    // If they've converged, quit.
    if (scanDown < scanUp)
      break;
    // Swap
    auto cache = vec[scanDown];
    vec[scanDown] = vec[scanUp];
    vec[scanUp] = cache;
    // Continue
    scanUp--;
    scanDown--;
  }

  // Swap v[0] and scanDown, to replace the pivot.
  vec[start] = vec[scanDown];
  vec[scanDown] = pivot;

  // Scan the next two sublists, if we are not done yet.
  quicksort(vec, start, midPoint - 1);
  quicksort(vec, midPoint + 1, end);
}

#endif