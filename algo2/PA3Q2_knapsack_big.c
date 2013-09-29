/*
This problem also asks you to solve a knapsack instance, but a much bigger one.
Download the text file here. This file describes a knapsack instance, and it has the following format:
[knapsack_size][number_of_items]
[value_1] [weight_1]
[value_2] [weight_2]
...
For example, the third line of the file is "50074 834558", indicating that the second item has value 50074 and size 834558, respectively. As before, you should assume that item weights and the knapsack capacity are long integers.

This instance is so big that the straightforward iterative implemetation uses an infeasible amount of time and space. So you will have to be creative to compute an optimal solution. One idea is to go back to a recursive implementation, solving subproblems --- and, of course, caching the results to avoid redundant work --- only on an "as needed" basis. Also, be sure to think about appropriate data structures for storing and looking up solutions to subproblems.

In the box below, type in the value of the optimal solution.

ADVICE: If you're not getting the correct answer, try debugging your algorithm using some small test cases. And then post them to the discussion forum!
*/
#include<stdio.h>
#include<stdlib.h>
long int max(long int a,long int b){
	return a>=b?a:b;
	}
void swap(long int A[],long int B[],int W){
	int x;
	for(x=0;x<=W;x++)
		A[x]=B[x];
	}
int main(){
	int W;
	int n;
	scanf("%d %d",&W,&n);
	int w[n],i,x;
	long int v[n];
	for(i=0;i<n;i++)
	scanf("%ld %d",&v[i],&w[i]);
	//long int A[W+1],B[W+1];
	long int *A,*B;
	A=(long int*)calloc(W+1,sizeof(long int));
	if(!A){
		printf("Memory Not Available for A\n");
		exit(0);
		}
	B=(long int*)calloc(W+1,sizeof(long int));
	if(!B){
		printf("Memory Not Available for B\n");
		exit(0);
		}
	for(x=0;x<=W;x++)
		A[x]=0;
	for(i=1;i<=n;i++){
		for(x=0;x<=W;x++){
			if(w[i]>x)B[x]=A[x];
			else B[x]=max(A[x],A[x-w[i]]+v[i]);
			}
		swap(A,B,W);
		}
	printf("\n%ld  %ld\n",A[W],B[W]);
	free(A);free(B);
	return 0;
}
