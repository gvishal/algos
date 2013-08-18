#include<stdio.h>
#include<stdlib.h>
//Binary Search
int binary_search(long int A[],long int key,int imin,int imax){
int imid;
while(imin <= imax){
	imid=(imin+imax)/2;
	if(key < A[imid]){
		imax=imid-1;
	}
	else if(key > A[imid]){
		imin=imid+1;
	}
	else
		return 1;
	}
return 0;
}
//Quick Sort Procedure
void swap(long int A[],int i,int j);
void Choose_Pivot(long int A[],int p,int r);
void Quicksort(long int A[],int p,int r){
int q;
if(p<r){
	q=Partition(A,p,r);
	Quicksort(A,p,q-1);
	Quicksort(A,q+1,r);
	}
}
int Partition(long int A[],int p,int r){
long int x;
//Choose_Pivot(A,p,r);
x=A[p];
int i,j;
i=p+1;
j=p+1;
for( ;j<=r;j++){
	if(A[j]<x){
		swap(A,i,j);
		i++;
		}
}
swap(A,p,i-1);
return i-1;
}
void swap(long int A[],int i,int j){
long int temp;
if(i!=j){
	temp=A[i];
	A[i]=A[j];
	A[j]=temp;
	}
}
void Choose_Pivot(long int A[],int p,int r){
int i,n;
n=r;
/*if((r-p)==1){
	if(A[p]>A[r])
		n=r;
	else
		n=p;
	}
else{
	if(((r-p+1)%2)==0){
		i=(r-p)/2+p;
		}
	else
		i=(r-p+1)/2+p;
	if(((A[p]>A[i])&&(A[p]<A[r]))||((A[p]<A[i])&&(A[p]>A[r])))
	n=p;
	else if(((A[i]>A[p])&&(A[i]<A[r]))||((A[i]<A[p])&&(A[i]>A[r])))
	n=i;
	else if(((A[r]>A[i])&&(A[r]<A[p]))||((A[r]<A[i])&&(A[r]>A[p])))
	n=r;
	}*/
swap(A,n,p);
}	
int main(){
int i,j,k,R[20001],ctr=0;
long int* A,t,s;
A=(long int*)malloc(1000000*sizeof(long int));
for(i=0;i<=999999;i++)
	scanf("%ld",&A[i]);
Quicksort(A,0,999999);
for(i=-10000;i<=10000;i++)
	R[i+10000]=i;
for(i=0;i<=20001;i++){
	printf("\n %d \n",ctr);
	t=R[i];
	for(j=0;j<=999999;j++){
		s=t-A[j];
		if(s==A[j])
			continue;
		else if((binary_search(A,s,0,999999)==1))
				ctr++;
				}
	}
printf("\n%d\n",ctr);
return 0;
}








