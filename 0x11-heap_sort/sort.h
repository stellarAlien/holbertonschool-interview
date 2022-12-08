#ifndef _SORT_H_
#define _SORT_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



void print_array(const int *array, size_t size);

void heapify(int *array, size_t size, size_t calcsize, int idx);
void heap_sort(int *array, size_t size);

#endif