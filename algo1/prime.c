#include<stdio.h>
int main(int argc,char **argv[]){
int n,i,ctr=0;
n=atoi(argv[1]);
for(i=2;i <= (n/2);i++){
	if(n%i==0){
		ctr++;
		break;
		}
	}
if(!ctr)
printf("%d is prime",n);
else
printf("%d is not prime",n);
return 0;
}
