/*
In this programming problem and the next you'll code up the knapsack algorithm from lecture. Let's start with a warm-up. Download the text file here. This file describes a knapsack instance, and it has the following format:
[knapsack_size][number_of_items]
[value_1] [weight_1]
[value_2] [weight_2]
...
For example, the third line of the file is "50074 659", indicating that the second item has value 50074 and size 659, respectively.
You can assume that all numbers are positive. You should assume that item weights and the knapsack capacity are integers.

In the box below, type in the value of the optimal solution.

ADVICE: If you're not getting the correct answer, try debugging your algorithm using some small test cases. And then post them to the discussion forum!
*/
#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
	return a>=b?a:b;
	}
int main(){
	int n,W;
	scanf("%d %d",&W,&n);
	int v[n],w[n],i,x;
	for(i=0;i<n;i++)
	scanf("%d %d",&v[i],&w[i]);
	int A[n+1][W+1];
	for(x=0;x<=W;x++)
		A[0][x]=0;
	for(i=1;i<=n;i++){
		for(x=0;x<=W;x++){
			if(w[i]>x)A[i][x]=A[i-1][x];
			else A[i][x]=max(A[i-1][x],A[i-1][x-w[i]]+v[i]);
			}
		}
	printf("\n%d\n",A[n][W]);
	return 0;
}
