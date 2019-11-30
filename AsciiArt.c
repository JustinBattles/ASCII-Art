#include <stdio.h>
#include <stdlib.h>

// Converts a pgm file into ASCII art
int main (int argc, char *argv[]) {

  FILE *fd;
  char junk[10] = "";
  int width = 0, height = 0;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <pgm file>\n", argv[0]);
    exit(1);
  }

  if ((fd = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Usage: %s <pgm file>\n", argv[1]);
    exit(1);
  }

  fscanf(fd, "%s", &junk);
  fscanf(fd, "%d", &height);
  fscanf(fd, "%d", &width);
  fscanf(fd, "%d", &junk);
  fscanf(fd, "%c", &junk);
  
  unsigned char c;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
    fscanf(fd, "%c", &c);
   if (c <= 26)
          printf("@");
	else if (c <= 51)
	  printf("%c", '%');
	else if (c <= 77)
          printf("#");
	else if (c <= 102)
          printf("*");
	else if (c <= 128)
	  printf("+");
	else if (c <= 154)
	  printf("=");
	else if (c <= 179)
	  printf("-");
	else if (c <= 205)
	  printf(":");
	else if (c <= 230)
	  printf(".");
	else if (c <= 256)
	  printf(" ");
	
   }
    printf("\n");
  
  }

  printf("\n");

  return 0;

}
