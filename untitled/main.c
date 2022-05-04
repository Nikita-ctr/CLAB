#include <stdio.h>

int main() {
  int i=10;
  int *pi=&i;
  int **ppi=&pi;
  int ***pppi=&ppi;

    printf("%d\n",i);
    *pi=20;
    printf("%d\n",i);

    return 0;
}
