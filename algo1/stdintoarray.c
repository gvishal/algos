#include<stdio.h>
void main(){
char input[3][50];
fgets(&input[0], 50, stdin);
printf("Inputted string: %s\n", input[0]);
}
