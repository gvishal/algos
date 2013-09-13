#include<stdio.h>
int count;
void swap(int A[],int i,int j);
void Choose_Pivot(int A[],int p,int r);
void Quicksort(int A[],int p,int r){
int q;
if(p<r){
	q=Partition(A,p,r);
	Quicksort(A,p,q-1);
	Quicksort(A,q+1,r);
	}
}
int Partition(int A[],int p,int r){
int x;
Choose_Pivot(A,p,r);
x=A[p];
int i,j;
i=p+1;
j=p+1;
count+=r-p;
for( ;j<=r;j++){
	if(A[j]<x){
		swap(A,i,j);
		i++;
		}
}
swap(A,p,i-1);
return i-1;
}
void swap(int A[],int i,int j){
int temp;
if(i!=j){
	temp=A[i];
	A[i]=A[j];
	A[j]=temp;
	}
}
void Choose_Pivot(int A[],int p,int r){
int i,a,b,small,n,temp,pos;
//n=r;
if((r-p)==1){
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
	}
/*else{
	i=(r-p+1)/2;
	int B[]={A[p],A[i],A[r]};
	for(a=0;a<2;a++){
	small=a;
	for(b=a+1;b<=2;b++){
	if(B[b]<B[small])
	small=b;
		}
	temp=B[a];
	B[a]=B[small];
	B[small]=temp;
	}
	if(B[1]==A[p])
	n=p;
	else if(B[1]==A[i])
	n=i;
	else
	n=r;
	}*/
//n=Select(A,p,r,i);
swap(A,n,p);
}
void SChoose_Pivot(int A[],int p,int r){
int i,m,n;
n=p;
//i=(r-p+1)/2;
//n=Select(A,p,r,i);
swap(A,n,p);
}
int SPartition(int A[],int p,int r){
int x;
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
int Select(int A[],int p,int r,int i){
if(p==r)
	return p;
int q;
q=SPartition(A,p,r);
int k;
k=q-p+1;
if(i==k)
	return q;
else if(i<k)
	return Select(A,p,q-1,i);
else
	return Select(A,q+1,r,i-k);
}
void main(){
int A[10000];
count=0;
int p=0,r=9999;
int i;
for(i=0;i<=r;i++){
	scanf("%d",&A[i]);
	}
Quicksort(A,p,r);
printf("\nCount is %d\n",count);
}	
