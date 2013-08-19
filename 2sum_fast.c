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
int main(){
int i,R[20001],ctr=0;
register int left,right;
register long int sum;
long int* A,t;
A=(long int*)malloc(1000000*sizeof(long int));
for(i=0;i<=999999;i++)
	scanf("%ld",&A[i]);
Quicksort(A,0,999999);
for(i=-10000;i<=10000;i++)
	R[i+10000]=i;
for(i=0;i<=20001;i++){
	t=R[i];
	left=0;right=999999;
	printf("\n %d \t %d \n",t,ctr);
	while(left<right){
		sum=A[left]+A[right];
		if(sum==t){
			ctr++;
			break;
			}
		else if(sum>t)
			right--;
		else
			left++;
		}
	}
printf("\n%d\n",ctr);
return 0;
}
