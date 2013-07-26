#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
long int merge(int A[],int p,int q,int r){
int n1,n2;
long int count=0;
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
L[n1+1]=INT_MAX;
R[n2+1]=INT_MAX;
i=1;
j=1;
for(k=p;k<=r;k++){
	if(L[i]<=R[j]){
		A[k]=L[i];
		i++;
		}
	else{
		count+=n1-i+1;
		A[k]=R[j];
		j++;
		}
	}
return count;
}
long int mergesort(int A[],int p,int r){
int q;
long int c1,c2,c3;
if(p==r)
return 0;
if(p<r){
	q=(p+r)/2;
	c1=mergesort(A,p,q);
	c2=mergesort(A,q+1,r);
	c3=merge(A,p,q,r);
return c1+c2+c3;
	}
}
void main(){
int A[100000];
int p=0,r=99999,i=0;
for(i=0;i<=r;i++){
scanf("%d",&A[i]);
}
long int count=0;
count=mergesort(A,p,r);
printf("The no of inversions is:%ld \n",count);
}
