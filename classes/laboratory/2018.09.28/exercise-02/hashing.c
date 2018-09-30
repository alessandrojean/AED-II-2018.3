#include <math.h>
#include "hashing.h"

int mul_hash (int key, int m, float a) {
  return floor(m * fmod(key * a, 1.0));
}