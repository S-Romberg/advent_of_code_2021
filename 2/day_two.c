#include <stdio.h>
#include <string.h>

int number(char string[11]);

int main() {
  FILE * file = fopen("input.txt", "r");
  char string[11], direction;
  int y = 0, x = 0, aim = 0;

  while(fgets(string, 11, file) != NULL) {
    direction = string[0];
    int count = number(string);
    int product = 0;

    if(direction == 'f') {
      /* It increases your horizontal position by X units. */
      x += count;
      /* It increases your depth by your aim multiplied by X */
      product = count * aim;
      y += product;
    }
    if(direction == 'u') {
      /* up subtracts, since we are counting depth */
      aim -= count;
    }
    if(direction == 'd') {
      /* down adds, since we are counting depth */
      aim += count;
    }
  }
  printf("**************** \n");
  printf("final depth: %d \n", y);
  printf("final horizontal: %d \n", x);
  printf("product: %d", x * y);
  printf("**************** \n");
  fclose(file);
}

int number(char string[11]) {
  for(int i=0;i<=(strlen(string));i++) {
    if(string[i]==' '){
      /* The C Standard guarantees each digit in the range '0'..'9' is one greater than its previous digit, subtracting '0' returns the int */
      return string[i+1] - '0';
    }
  }
  return 0;
}
