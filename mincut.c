#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Graph{
	int vertex;
	struct Graph *next;
	}Graph;
struct info{
	Graph *address;
	Graph *lastaddress;
	int degree;
	bool status;
	}InfoArray[3];
void ConstructNode(int A[]){
	int i=1;
	static int vertex=1;
	Graph *node,*prev;
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
	InfoArray[vertex].status=true;
	InfoArray[vertex].lastaddress=node;
	}
void display(){
	int i=1;
	Graph *node;
	for(i=1;i<=2;i++){ //Change the number of verticies accordingly
		node=InfoArray[i].address;
		printf("The vertex is: %d and its edges are \n",i);
		while(node->next!=NULL){
			printf("%d",node->vertex);
			node=node->next;
			}
		printf("%d",node->vertex);
		}
	}
			

void main(){
	char c,ch[3];
	int i=0,pos=0,A[50];
	FILE *fp;
	fp=fopen("kargerMinCut.txt","r");
	while(c!=EOF){
		c=fgetc(fp);
		printf("%c",c);
		if(c==" "){
			ch[pos]="\0";
			A[i]=atoi(ch);
			i++;
			pos=0;
			}
		else if(c=="\n"){
			pos=0;
			A[i]=0;
			//ConstructNode(A);
			}
		else{
			ch[pos]=c;
			pos++;
			}
		if(c==EOF)
			break;
		}
	//display();
	}
