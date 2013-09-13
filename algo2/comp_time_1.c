/*
Algorithms 2 Week1 Programming Assignment
Question 1
In this programming problem and the next you'll code up the greedy algorithms from lecture for minimizing the weighted sum of completion times.. Download the text file here. This file describes a set of jobs with positive and integral weights and lengths. It has the format
[number_of_jobs]
[job_1_weight] [job_1_length]
[job_2_weight] [job_2_length]
...
For example, the third line of the file is "74 59", indicating that the second job has weight 74 and length 59. You should NOT assume that edge weights or lengths are distinct.

Your task in this problem is to run the greedy algorithm that schedules jobs in decreasing order of the difference (weight - length). Recall from lecture that this algorithm is not always optimal. IMPORTANT: if two jobs have equal difference (weight - length), you should schedule the job with higher weight first. Beware: if you break ties in a different way, you are likely to get the wrong answer. You should report the sum of weighted completion times of the resulting schedule --- a positive integer --- in the box below.

ADVICE: If you get the wrong answer, try out some small test cases to debug your algorithm (and post your test cases to the discussion forum)!

*/
#include<stdio.h>
#include<stdlib.h>
struct task{
	int w;
	int l;
	int w_l;
	int C;
	};
typedef struct task task;
//This function sorts based on width-lenght and then computes weighted sum of completion times
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
	job[i].w_l=jw-jl;
	job[i].C=0;
	}
	total=sort_compute(job,jobs);
	printf("%ld\n",total);
	return 0;
}
