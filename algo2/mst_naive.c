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
	int X[v],x=1,x_t=1,T=0,pos;
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
					}
					break;
					}
				else if(u==edge[i].v2){
					if(edge[i].edge_cost<ec){
					pos=i;
					ec=edge[i].edge_cost;
					v=edge[i].v1;
					}
					break;
					}
				}	
			}
		T+=ec;
		x++;
		X[x-1]=v;
		edge[pos].status=0;
		x_t=x;
	}	
	printf("%d\n",T);
	return 0;
}

