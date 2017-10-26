/**
 * @file fib.cpp
 * Contains Fibonacci-number generating functions both utilizing and not
 * utilizing memoization.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "fib.h"

#include <map>

using std::map;

/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long fib(unsigned long n)
{
  if(n <= 0)
    return 0;
  if(n == 1)
    return 1;
  return fib(n - 1) + fib(n - 2);
    /* Your code goes here! */
}

/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0. This version utilizes memoization.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long memoized_fib(unsigned long n)
{
    /* Your code goes here! */
  static map<unsigned long, unsigned long> fibStore = {{0, 0}, {1, 1}};
  auto it = fibStore.find(n);
  if(it != fibStore.end())
    return it->second;
  else{
    unsigned long result = memoized_fib(n - 1) + memoized_fib(n - 2);
    fibStore.insert(std::pair<unsigned long, unsigned long>(n, result));
    return result;
  }

}
