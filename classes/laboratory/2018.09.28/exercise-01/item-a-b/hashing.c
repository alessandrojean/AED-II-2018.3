#include "hashing.h"

int div_hash(int key, int m) {
  return key % m;
}