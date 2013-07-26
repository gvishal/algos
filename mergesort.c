#include<stdio.h>
#include<stdlib.h>
void merge(int A[],int p,int q,int r){
int n1,n2;
n1=q-p+1;
n2=r-q;
int L[n1+1],R[n2+1];
int i,j,k;
for(i=1;i<=n1;i++){
	L[i]=A[p+i-1];
	}
for(j=1;j<=n2;j++){
	R[j]=A[q+j];
	}
L[n1+1]=32767;
R[n2+1]=32767;
i=1;
j=1;
for(k=p;k<=r;k++){
	if(L[i]<=R[j]){
		A[k]=L[i];
		i++;
		}
	else{
		A[k]=R[j];
		j++;
		}
	}
}
void mergesort(int A[],int p,int r){
int q;
if(p<r){
	q=(p+r)/2;
	mergesort(A,p,q);
	mergesort(A,q+1,r);
	merge(A,p,q,r);
	}
}
void main(){
int A[100];
int p=0,r=99,i=0;
for(i=0;i<=r;i++){
	A[i]=rand();
	if(A[i]>32767)
		A[i]=A[i]%32767;
	}
mergesort(A,p,r);
printf("The sorted array is:\n");
for(i=0;i<=r;i++){
	printf("%d\n",A[i]);
	}
}
