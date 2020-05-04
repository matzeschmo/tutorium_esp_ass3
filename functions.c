#include <stdio.h>
#include <stdlib.h>

#define UPPER_BOUND 30

int sum(int* values, int length)
{
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += values[i];
  }
  return sum;
}

float mean(int* values, int length)
{
  float mean = 0;
  for (int i = 0; i < length; i++)
  {
    mean += values[i];
  }
  mean = mean / length;
  return mean;
}

void calc_histogram(int* values, int length, int* histogram)
{
  for (int i = 0; i < length; i++)
  {
    histogram[values[i]]++;
  }
}

void print_histogram(int* histogram)
{
  for (int i = 0; i < UPPER_BOUND; i++)
  {
    printf("%d\t", i);
    for (int n = 0; n < histogram[i]; n++)
    {
      printf("|");
    }
    printf("\n");
  }
}

void calc_all_measures(int* values, int length, int* sum_value, float* mean_value, int* histogram)
{
  *sum_value = sum(values, length);
  *mean_value = mean(values, length);
  calc_histogram(values, length, histogram);
}


int main()
{
  const int num_values = 100;

  int values[num_values];
  for (int i = 0; i < num_values; i++)
  {
    values[i] = rand() % UPPER_BOUND;
  }

  int histogram[UPPER_BOUND];
  int sum;
  float mean;

  calc_all_measures(values, num_values, &sum, &mean, histogram);
  print_histogram(histogram);
  printf("Sum: %d", sum);
  printf("Mean: %f", mean);
  return 0;
}