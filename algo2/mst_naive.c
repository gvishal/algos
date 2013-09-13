/*
Algorithms 2 Week 1 Programming Assignment
Question 3
In this programming problem you'll code up Prim's minimum spanning tree algorithm. Download the text file here. This file describes an undirected graph with integer edge costs. It has the format
[number_of_nodes] [number_of_edges]
[one_node_of_edge_1] [other_node_of_edge_1] [edge_1_cost]
[one_node_of_edge_2] [other_node_of_edge_2] [edge_2_cost]
...
For example, the third line of the file is "2 3 -8874", indicating that there is an edge connecting vertex #2 and vertex #3 that has cost -8874. You should NOT assume that edge costs are positive, nor should you assume that they are distinct.

Your task is to run Prim's minimum spanning tree algorithm on this graph. You should report the overall cost of a minimum spanning tree --- an integer, which may or may not be negative --- in the box below.

IMPLEMENTATION NOTES: This graph is small enough that the straightforward O(mn) time implementation of Prim's algorithm should work fine. OPTIONAL: For those of you seeking an additional challenge, try implementing a heap-based version. The simpler approach, which should already give you a healthy speed-up, is to maintain relevant edges in a heap (with keys = edge costs). The superior approach stores the unprocessed vertices in the heap, as described in lecture. Note this requires a heap that supports deletions, and you'll probably need to maintain some kind of mapping between vertices and their positions in the heap.
*/
#include<stdio.h>
#include<stdlib.h>
struct mst{
	int v1;
	int v2;
	int edge_cost;
	int status;
	};
typedef struct mst mst;
void sort(mst edge[],int e){
	int i,j,v1,v2,ec,pos;
	for(i=0;i<e-1;i++){
		pos=i;
		for(j=i+1;j<e;j++){
			if(edge[j].edge_cost<edge[pos].edge_cost){
				pos=j;
				}
			}
		v1=edge[i].v1;
		v2=edge[i].v2;
		ec=edge[i].edge_cost;
		edge[i].v1=edge[pos].v1;
		edge[i].v2=edge[pos].v2;
		edge[i].edge_cost=edge[pos].edge_cost;
		edge[pos].v1=v1;
		edge[pos].v2=v2;
		edge[pos].edge_cost=ec;
		}
}		
int main(int argc,char **argv[]){
	FILE *fp;
	int i,j,u,v,e,v1,v2,ec;
	fp=fopen(argv[1],"r");
	if(!fp)
	exit(0);
	fscanf(fp,"%d %d",&v,&e);	
	mst edge[e];
	int X[v],x=1,x_t=1,pos,ctr=0;
	long int T=0;
	X[0]=1;
	for(i=0;i<e;i++){
		fscanf(fp,"%d %d %d",&v1,&v2,&ec);
		edge[i].v1=v1;
		edge[i].v2=v2;
		edge[i].edge_cost=ec;
		edge[i].status=1;
		}
	sort(edge,e);
	while(x!=v){
		ec=32766;
		ctr=0;
		for(j=0;j<x_t;j++){
			u=X[j];
			for(i=0;i<e;i++){
				if(edge[i].status==0)
					break;
				else if(u==edge[i].v1){
					if(edge[i].edge_cost<ec){
					pos=i;
					ec=edge[i].edge_cost;
					v=edge[i].v2;
					ctr++;
					}
					break;
					}
				else if(u==edge[i].v2){
					if(edge[i].edge_cost<ec){
					pos=i;
					ec=edge[i].edge_cost;
					v=edge[i].v1;
					ctr++;
					}
					break;
					}
				}	
			}
		if(ctr){
			T+=ec;
			x++;
			X[x-1]=v;
			edge[pos].status=0;
			x_t=x;
		}
	}	
	printf("%ld\n",T);
	return 0;
}

