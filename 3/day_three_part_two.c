#include <math.h>
#include <stdio.h>
#include <string.h>

int binary_converter(char binary[], int length);
void remove_element(int *array, int index, int array_length);

#define LENGTH 14

int main() {
  FILE *file = fopen("input.txt", "r");
  int index = 0;
  char binary[1000][LENGTH];
  int indexes_with_zeros[1000];
  int with_zeros_length = 0;
  int indexes_with_ones[1000];
  int with_ones_length = 0;

  while (fgets(binary[index], LENGTH, file) != NULL) {
    if (binary[index][0] == '0') {
      indexes_with_zeros[with_zeros_length] = index;
      with_zeros_length++;
    }
    if (binary[index][0] == '1') {
      indexes_with_ones[with_ones_length] = index;
      with_ones_length++;
    }
    index++;
  }

  int string_index = 1;
  index = 0;
  while (with_zeros_length > 1 && string_index < LENGTH) {
    for (int i = 0; i < with_zeros_length; i++) {
      int current_index = indexes_with_zeros[i];
      if (binary[current_index][string_index] != '0') {
        printf("removing: %s \n", binary[indexes_with_zeros[i]]);
        remove_element(indexes_with_zeros, i, with_zeros_length);
        with_zeros_length--;
      }
    }
    string_index++;
  }
  char *zero_binary = binary[indexes_with_zeros[0]];
  printf("zero_binary: %s \n", zero_binary);
  printf("maybe zero_binary?: %s \n",
         binary[indexes_with_zeros[with_zeros_length]]);

  string_index = 1;
  index = 0;
  while (with_ones_length > 1 && string_index < LENGTH) {
    for (int i = 0; i < with_ones_length; i++) {
      int current_index = indexes_with_ones[i];
      if (binary[current_index][string_index] != '1') {
        printf("removing: %s \n", binary[indexes_with_ones[i]]);
        remove_element(indexes_with_ones, i, with_ones_length);
        with_ones_length--;
      }
    }
    string_index++;
  }

  char *ones_binary = binary[indexes_with_ones[0]];
  printf("ones_binary: %s \n", ones_binary);
  printf("maybe ones_binary?: %s \n",
         binary[indexes_with_ones[with_ones_length]]);

  fclose(file);
}

void remove_element(int *array, int index, int array_length) {
  int i;
  for (i = index; i < array_length - 1; i++)
    array[i] = array[i + 1];
}

int binary_converter(char binary[], int length) {
  int decimal = 0;
  int position = 0;
  int index = length - 1;
  while (index >= 0) {
    decimal = decimal + (binary[index] - 48) * pow(2, position);
    index--;
    position++;
  }
  return decimal;
}
