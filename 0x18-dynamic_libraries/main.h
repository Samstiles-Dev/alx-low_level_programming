#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>

int _putchar(char c);
void _puts(char *str);
void *_calloc(unsigned int elem_num, unsigned int mem_size);
int *array_range(int _min, int _max);
void *_realloc(void *pointer, unsigned int fmr_size, unsigned int latest_size);
int _atoi(const char *s);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void print_int(unsigned long int n);

#endif
