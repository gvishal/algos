#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//#define NGMOD(a,b) (((a)%(b))+(b))%(b))
const int m=1200009;
const int m1=1200008;
//Modulus function to handle negatives
//inline int mod(long int a,int b){
//return ((a%b) + b)%b;
//} 
//Double Hashing
/*
int h(long int k,int i){
return ((NGMOD(k,m)) + i*(1 + (NGMOD(k,m1))) )%m;
}*/
inline int h(long int k,int i){
register int n=labs(k)%m;
return ( n + i*n )%m;
}
//Hash Insert
void hash_insert(long int A[],long int k){
int i=0,j;
while(i<m){
	j=h(k,i);
	if(A[j]==0){
		A[j]=k;
		//printf("Collision %d for %ld\n",i,k);
		return;
		}
	else{
		i++;
		//printf("Collision %d for %ld\n",i,k);
		}
	}
}
//Hash Search
inline int hash_search(long int A[],long int k){
register int i=0,j;
while((i<m)){
	j=h(k,i);
	if(A[j]==0)
		return 0;
	else if(A[j]==k)
		return 1;
	else 
		i++;
	}
return 0;
}
int main(){
int i,j,k,R[20001],ctr=0;
long int* A;
long int t,h_key;
register long int s;
A=(long int*)malloc(m*sizeof(long int));
for(i=0;i<m;i++){
	A[i]=0;
	}
for(i=0;i<=999999;i++){
	scanf("%ld",&h_key);
	//printf("%d is %ld \n",h(h_key,0),h_key);
	hash_insert(A,h_key);
	}
/*for(i=0;i<m;i++){
	printf("%ld\n",A[i]);
	}*/
for(i=-10000;i<=10000;i++)
	R[i+10000]=i;
for(i=0;i<=20001;i++){
	t=R[i];
	printf("\n %d \t %d \n",t,ctr);
	for(j=0;j<=m;j++){
		if(A[j]==0)
			continue;
		s=t-A[j];
		if(s==A[j])
			continue;
		else if((hash_search(A,s)==1)){
				ctr++;
				break;
				}
			}
	}
printf("\n%d\n",ctr);
free(A);
return 0;
}
