#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string_digits(char* string)
{
  for (int i = 0; i < 13; i++)
  {
    printf("my_string[%d] = %c (=%d)\n", i, string[i], string[i]);
  }
}

int my_string_length(char* string)
{
  int length = 0;
  while(string[length] != 0)
  {
    length++;
  }
  return length;
}

int main()
{
  char my_string[] = "Hello World!";
  print_string_digits(my_string);
  printf("Length: %lu\n", strlen(my_string));

  char favourite_lecture_prefix[] = "My favourite lecture is:";
  char lecture[] = "ESP";

  char my_favourite_lecture[strlen(favourite_lecture_prefix) + strlen(lecture) - 1];
  strcpy(my_favourite_lecture, favourite_lecture_prefix);

  strcat(my_favourite_lecture, lecture);

  printf("%s\n", my_favourite_lecture);

  return 0;
}