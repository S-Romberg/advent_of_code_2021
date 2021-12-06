#include <stdio.h>
#include <string.h>
#include <math.h>

/* too high: 76,979,650 */
/* too low: 1,510,850 */
int number();
int binary_converter(char binary[], int length);

int main() {
  FILE * file = fopen("input.txt", "r");
  int counter_ones[12] = { 0,0,0,0,0,0,0,0,0,0,0,0}, counter_zeros[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
  char largest_binary[12], smallest_binary[12];
  int largest_decimal, smallest_decimal;
  char string[12];

  while(fgets(string, 14, file) != NULL) {
    printf("binary: %s \n", string);
    for(int i = 0; i <12; i++) {
      if(string[i] == '0') {
        counter_zeros[i]++;
      }
      if(string[i] == '1') {
        counter_ones[i]++;
      }
    }

  }

  for(int i = 0; i <12; i++) {
    if(counter_ones[i] > counter_zeros[i]) {
      largest_binary[i]='1';
      smallest_binary[i]='0';
    }
    if(counter_ones[i] < counter_zeros[i]) {
      largest_binary[i]='0';
      smallest_binary[i]='1';
    }
  }

  largest_decimal = binary_converter(largest_binary, 12);
  smallest_decimal = binary_converter(smallest_binary, 12);

  printf("mostcommon: %d,  leastcommon: %d \n", largest_decimal, smallest_decimal);
  printf("product: %d:\n", largest_decimal * smallest_decimal);
  printf("\n");
  fclose(file);
}

int binary_converter(char binary[], int length)
{
  int decimal = 0;
  int position = 0;
  int index = length - 1;
  while (index >= 0)
  {
    decimal = decimal + (binary[index] - 48) * pow(2, position);
    index--;
    position++;
  }
  return decimal;
}
