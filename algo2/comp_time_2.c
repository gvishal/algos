#include<stdio.h>
#include<stdlib.h>
struct task{
	int w;
	int l;
	float w_l;
	int C;
	};
typedef struct task task;
long int sort_compute(task job[],int jobs){
	int i,j,pos,C=0;
	long int total=0;
	task temp;
	for(i=0;i<jobs-1;i++){
		pos=i;
		for(j=i+1;j<jobs;j++){
			if(job[j].w_l>job[pos].w_l)
				pos=j;
			else if((job[j].w_l==job[pos].w_l)&&(job[j].w>job[pos].w))
				pos=j;
				}
		temp.w=job[i].w;
		temp.l=job[i].l;
		temp.w_l=job[i].w_l;
		job[i].w=job[pos].w;
		job[i].l=job[pos].l;
		job[i].w_l=job[pos].w_l;
		job[pos].w=temp.w;
		job[pos].l=temp.l;
		job[pos].w_l=temp.w_l;
		}
	for(i=0;i<jobs;i++){
		C+=job[i].l;
		job[i].C=C;
		total+=job[i].w*job[i].C;
		}
	return total;
}
int main(int argc,char **argv[]){
	FILE *fp;
	fp=fopen(argv[1],"r");
	int jobs,i,jw,jl;
	long int total=0;
	fscanf(fp,"%d",&jobs);
	task job[jobs];
	for(i=0;i<jobs;i++){
	fscanf(fp,"%d %d",&jw,&jl);
	job[i].w=jw;
	job[i].l=jl;
	job[i].w_l=(float)jw/jl;
	job[i].C=0;
	}
	total=sort_compute(job,jobs);
	printf("%ld\n",total);
	return 0;
}
