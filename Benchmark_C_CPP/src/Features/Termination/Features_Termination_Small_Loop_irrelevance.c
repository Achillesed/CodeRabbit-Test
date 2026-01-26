#include "benchmark.h"
int Features_Termination_Small_Loop_irrelevance_good(int x) {
  int result = 0;
  int *p = &x;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      p == 0; 
      result = *p; //FP: Null Pointer Dereference
    }
  }
  return result;
}

int Features_Termination_Small_Loop_irrelevance_bad(int x) {
  int result = 0;
  int *p = NULL;  //Source: 空指针null
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      p == 0; 
      result = *p; //Null Pointer Dereference
    }
  }
  return result;
}