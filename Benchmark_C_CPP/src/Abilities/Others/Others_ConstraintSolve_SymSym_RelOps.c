#include "benchmark.h"

void Others_ConstraintSolve_SymSym_RelOps_good0(int x, int y, int z)
{
  int *r = (int *)0;
  if (x == y)
  {
    if (z > x)
    {
      if (z < y) // condition: x == y && z > x && z < y
      {
        *r = 42; // Null Pointer Dereference not reachable
      }
    }
  }
}

void Others_ConstraintSolve_SymSym_RelOps_good1(int x, int y, int z) {
  int *r = (int *)0;
  if (x != y) return; // x == y
  if (z <= x) return; // z > x
  if (z >= y) return; // z < y
  // condition: x == y && z > x && z < y
  // if use eager garbage-collect, the condition will be empty
  *r = 42; // Null Pointer Dereference not reachable
  // (void)(x + y + z); // keep the constraints alive.
}

void Others_ConstraintSolve_SymSym_RelOps_good2(int x, int y, int z) {
  int *r = (int *)0;
  if (x >= y) return; // x < y
  if (y >= z) return; // y < z
  y = 10; // symbol $y dies
  if (x <= z) return; // x > z
  // condition: x < y && y < z && x > z
  // if use garbage-collect, the condition may be x > z
  *r = 42; // Null Pointer Dereference not reachable
}

void Others_ConstraintSolve_SymSym_RelOps_good3(int x, int y, int z, int w) {
  int *r = (int *)0;
  if (w < x) return; // w >= x
  if (x < y) return; // x >= y
  if (y < z) return; // y >= z
  // condition: w >= x && x >= y && y >= z
  x = 10;
  y = 10; 
  // both $x and $y die
  // if simplifying this system of constraints to w >= z && y >= z, lose  w >= z 
  if (w >= z) return; // w < z
  // condition: w >= x && x >= y && y >= z && w < z
  *r = 42; // Null Pointer Dereference not reachable
}