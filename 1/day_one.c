#include <stdio.h>

int main() {
  FILE * file = fopen("input.txt", "r");
  int number;
  int index = 0;
  int total_increases = 0;
  int numbers[2000];
  int one, two, three, current = 0, previous = 0;
  while(fscanf(file, "%d", &number)==1){
    numbers[index] = number;
    if(index >= 2) {
      three = numbers[index];
      two = numbers[index-1];
      one = numbers[index-2];
      current = three + two + one;
    }
    if(index > 3 && current > previous) {
      total_increases += 1;
    }
    previous = current;
    index += 1;
  }
  fclose(file);
  printf("%d", total_increases);
}

