#include <stdio.h>
#include <string.h>

int number(char string[11]);

int main() {
  FILE * file = fopen("input.txt", "r");
  char string[11], direction;
  int y = 0, x = 0;

  while(fgets(string, 11, file) != NULL) {
    direction = string[0];
    int count = number(string);

    if(direction == 'f') {
      x += count;
    }
    if(direction == 'u') {
      y += count;
    }
    if(direction == 'd') {
      y -= count;
    }
  }
  printf("**************** \n");
  printf("%d \n", y);
  printf("%d \n", x);
  printf("%d", x * y);
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
