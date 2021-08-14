/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Mean, Max, Min and Median statistics
 *
 * This program takes an unsigned char array and calculates 
 * statistics: mean, maximum, minimum and median value.
 * The values are sorted and the result is printed.
 *
 * @author Tanja Klopper
 * @date 08/2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char test[], int size){
  double mean;
  unsigned char max;
  unsigned char median;
  unsigned char min;
  unsigned char *sorted; 
  mean = find_mean(test, SIZE);
  max = find_maximum(test, SIZE);
  sorted = sort_array(test, SIZE, max);
  median = find_median(sorted, SIZE);
  min = find_minimum(test,SIZE);
  printf("The statistics of the array values are: \n");
  printf("Mean value: %2.2f \n", mean);
  printf("Maximum value: %u \n", max);
  printf("Minimum value: %u \n", min);
  printf("Median value: %u \n", median);
}

void print_array(unsigned char test[], int size){
  int cl;
  for(cl=0; cl<size; cl++)
    printf("%u \t", test[cl]);
  printf("\n");
}

unsigned char find_median(unsigned char* sorted, int size){
  unsigned char median;
  int cl;
  for(cl=0;cl<=(size/2);cl++)
    sorted++;
  median = *sorted; /* print the value at size/2*/
  return median;
}

unsigned char * sort_array(unsigned char test[], int size, unsigned char max){
  unsigned int hist[max+1];
  int cl;
  int kl;
  unsigned char sorted[size];
  for(kl=0;kl<(max+1);kl++)
    hist[kl] = 0;
  for(cl=0;cl<size;cl++)
    hist[test[cl]]++;
  int xl = 0;
  int ll = 0;
  /* reverse loop from largest to smallest: */
  for(kl=max;kl>=0;kl--)
    if(hist[kl]!=0){
      /* Add duplicates from the histogram: */
      for(ll=0;ll<hist[kl];ll++){
        sorted[xl]=kl;
        xl++;
      }
    }

  printf("Sorted array: \n");
  print_array(sorted,size);
  
  unsigned char *sorted_ptr = sorted;
  return sorted_ptr;
}

unsigned char find_maximum(unsigned char test[], int size){
  unsigned char max;
  int cl;
  max = test[0];
  for(cl=1; cl<size; cl++)
    if(test[cl]>max)
      max = test[cl];
  return max;
}

unsigned char find_minimum(unsigned char test[], int size){
  unsigned char min;
  int cl;
  min = test[0];
  for(cl=1; cl<size; cl++)
    if(test[cl]<min)
      min = test[cl];
  return min;
}
                              
double find_mean(unsigned char test[], int size){
  double mean = 0;
  int cl;
  for(cl=0; cl<size; cl++)
    mean += test[cl]/size;
  return mean;
}

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  
  printf("Original array: \n");
  print_array(test, SIZE);

  print_statistics(test,SIZE);

  return 0;
}
