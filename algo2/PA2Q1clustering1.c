/*
In this programming problem and the next you'll code up the clustering algorithm from lecture for computing a max-spacing k-clustering. Download the text file here. This file describes a distance function (equivalently, a complete graph with edge costs). It has the following format:
[number_of_nodes]
[edge 1 node 1] [edge 1 node 2] [edge 1 cost]
[edge 2 node 1] [edge 2 node 2] [edge 2 cost]
...
There is one edge (i,j) for each choice of 1≤i<j≤n, where n is the number of nodes. For example, the third line of the file is "1 3 5250", indicating that the distance between nodes 1 and 3 (equivalently, the cost of the edge (1,3)) is 5250. You can assume that distances are positive, but you should NOT assume that they are distinct.

Your task in this problem is to run the clustering algorithm from lecture on this data set, where the target number k of clusters is set to 4. What is the maximum spacing of a 4-clustering?

ADVICE: If you're not getting the correct answer, try debugging your algorithm using some small test cases. And then post them to the discussion forum!
*/


#include<stdio.h>
#include<stdlib.h>
struct edge{
	int node1;
	int node2;
	int cost;
	int status;
	int cluster;
	};
typedef struct edge edge;
void sort(edge edges[],int e){
	int i,j,v1,v2,ec,pos;
	for(i=0;i<e-1;i++){
		pos=i;
		for(j=i+1;j<e;j++){
			if(edges[j].cost<=edges[pos].cost){
				pos=j;
				}
			}
		v1=edges[i].node1;
		v2=edges[i].node2;
		ec=edges[i].cost;
		edges[i].node1=edges[pos].node1;
		edges[i].node2=edges[pos].node2;
		edges[i].cost=edges[pos].cost;
		edges[pos].node1=v1;
		edges[pos].node2=v2;
		edges[pos].cost=ec;
		}
}
int main(/*int argc,char **argv[]*/){
	int n;
	int n1,n2,c,i=0;
	int k=4,ks,e=124750;
	edge edges[e];
	scanf("%d",&n);
	ks=n;
	for(i=0;i<e;i++){
		scanf("%d %d %d",&n1,&n2,&c);
		edges[i].node1=n1;edges[i].node2=n2;edges[i].cost=c;
		edges[i].status=1;
		edges[i].cluster=i+1;
		}
	/*sort(edges,e);
	//printf("Sorting Completed\n");
	for(i=0;i<e;i++){
		n1=edges[i].node1;n2=edges[i].node2;c=edges[i].cost;
		printf("%d %d %d\n",n1,n2,c);
		}*/
	while(ks!=k){
		i=0;
		for(i=0;i<e;i++){
			if(edges[i].){
				n1=edges[i].node1;n2=edges[i].node2;c=edges[i].cost;
		
		
		
		
		
		
		
		
		
		
	return 0;
}
