#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "ext_sort.h"
#include "util.h"

int main(int argc, char **argv) {
  int page_size = 4000;
  merge_files("ordprog.txt", "r0.txt", "r1.txt", page_size);

  return EXIT_SUCCESS;
}
