//Enter file name as parameter name
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int t_edge=0;
typedef struct Graph{
	int vertex;
	struct Graph *next;
	}Graph;
struct info{
	Graph *address;
	Graph *lastaddress;
	int degree;
	bool status;
	}InfoArray[201];//Create one more than that required
int r_edge(){
	return rand()%t_edge;
	}
void ConstructNode(int A[]){
	int i=1;
	static int vertex=1;
	Graph *node,*prev;
	node=NULL;
	prev=NULL;
	while(A[i]!=0){
		node=(Graph *)malloc(sizeof(Graph));
		if(i==1){
			InfoArray[vertex].address=node;
			}
		else{
			prev->next=node;
			}
		node->vertex=A[i];
		i++;
		node->next=NULL;
		prev=node;
		}
	InfoArray[vertex].degree=i-1;
	t_edge+=i-1;
	InfoArray[vertex].status=true;
	InfoArray[vertex].lastaddress=node;
	vertex++;
	}
void display(){
	int i=1;
	Graph *node;
	node=NULL;
	printf("Total Edges: %d  %d\n",t_edge,r_edge());
	for(i=1;i<=200;i++){ //Change the number of verticies accordingly
		node=InfoArray[i].address;
		printf("\nVertex: %d Degree: %d Status: %d Edges: \n",i,InfoArray[i].degree,InfoArray[i].status);
		while(node->next!=NULL){
			printf("%d\t",node->vertex);
			node=node->next;
			}
		printf("%d\n",node->vertex);
		}
	}		

void main(int argc,char **argv[]){
	char c,ch[3];
	int i=0,pos=0,A[200],j=0;
	FILE *fp;
	fp=fopen(argv[1],"r");
	if(!fp)
	exit(0);
	while(true){
		c=fgetc(fp);
		if(c=='\t'||c==' '){
			ch[pos]='\0';
			A[i]=atoi(ch);
			i++;
			pos=0;
			}
		else if(c=='\n'){
			ch[pos]='\0';
			A[i]=atoi(ch);
			i++;
			pos=0;
			A[i]=0;
			i=0;
			ConstructNode(A);
			}
		else{
			ch[pos]=c;
			pos++;
			}
		if(c==EOF)
			break;
		}
	display();
	}
