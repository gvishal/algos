#include<stdio.h>
#include<stdlib.h>
void inp(int A[]){
char c[1000];
int i=0;
scanf("%s",&c);
for(;i<=1000;i++){
	if(c[i]=='\0')
		break;
	A[i]=c[i]-48;
	}
A[i]=-1;
}
void out(int A[]){
int i=0;
while(A[i]!=-1){
printf("%d\t",A[i]);
i++;
}
}
int main(){
int A[1000],B[1000],i=0;
inp(A);
inp(B);
out(A);
printf("\n");
out(B);
return 0;
}
