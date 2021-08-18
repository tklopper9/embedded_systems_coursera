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

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
int main();

/**
 * @brief The statistics are printed to the screen.
 *
 * Call all the functions to calculate max, mean, min, median.
 * For the median, max is first calculated and then sort_array() 
 * is called.
 *
 * @param test: input array
 * @param SIZE: size of input array
 *
 * @return None
 */
void print_statistics(unsigned char test[], int SIZE);

/**
 * @brief The array values are printed to the screen
 *
 * Loop through the array and print the values with tabs in between
 *
 * @param test: input array
 * @param SIZE: size of input array
 *
 * @return None
 */
void print_array(unsigned char test[], int SIZE);

/**
 * @brief Finds the mean of array
 *
 * <Add Extended Description Here>
 *
 * @param test: input array
 * @param SIZE: size of input array
 *
 * @return double: Mean value
 */
double find_mean(unsigned char test[], int SIZE);

/**
 * @brief Finds the median of array
 *
 * Loop through the sorted array until size/2. 
 * This is the median value.
 *
 * @param sorted: pointer to the sorted array
 * @param SIZE: size of input array
 *
 * @return unsigned char median value
 */
unsigned char find_median(unsigned char* sorted, int size);

/**
 * @brief Sorts the array.
 *
 * First step: generate a histogram.
 * Than loop through the histogram from largest to smallest and
 * store the numbers (bins) in a new array (sorted[]).
 *
 * @param sorted: pointer to the sorted array
 * @param SIZE: size of input array
 *
 * @return unsigned char *sorted: pointer to sorted[]
 */
unsigned char * sort_array(unsigned char test[], int size, unsigned char max);

/**
 * @brief Finds the maximum of array
 * 
 * Loop to the array, in every iteration compare to the current max.
 * Store the new max.
 *
 * @param test: input array
 * @param SIZE: size of input array
 *
 * @return unsigned char max
 */
unsigned char find_maximum(unsigned char test[], int size);

/**
 * @brief Finds the minimum of array
 * 
 * Loop to the array, in every iteration compare to the current min.
 * Store the new min.
 *
 * @param test: input array
 * @param SIZE: size of input array
 *
 * @return unsigned char min
 */
unsigned char find_minimum(unsigned char test[], int size);


#endif /* __STATS_H__ */
