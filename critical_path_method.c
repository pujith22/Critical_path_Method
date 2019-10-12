#include<stdio.h>
#include<stdlib.h>
typedef struct Activity{
	int duration;
	int earlyStart;
	int earlyFinish;
	int latestStart;
	int latestFinish;
	int floatValue;
}activity;

typedef struct GraphNode
{
	int activityNum;
	GraphNode* next;
}graphNode;


typedef struct ActivityGraph
{
	int n;
	graphNode* arr;
}activityGraph;

void initGraph(activityGraph *Graph,int n)
{
	Graph->n = n;
	Graph->arr = (graphNode*)malloc(sizeof(n*sizeof(void*)));
	int i;
	for(i=0;i<n;i++)
	{
		Graph->arr[i] = NULL;
	}
}

void graphInsert(activityGraph *Graph,int parent,int child)
{
	graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
	newNode->activityNum = child;
	newNode->next = NULL;
	if(Graph->arr[parent]==NULL)
		Graph->arr[parent]=newNode;
	else
	{
		newNode->next = Graph->arr[parent];
		Graph->arr[parent] = newNode;
	}
}

typedef struct ActivityHashtable
{
	activity* arr;
	int n;
}activityHashTable;

void initHashTable(activityHashTable* table,int n)
{
	table->arr = (activity*)malloc(n*sizeof(void*));
	table->n = n;
	int i;
	for(i=0;i<n;i++)
	{
		table->arr[i] = NULL;
	}
}

void main()
{
	activityGraph G1,G2;
	activityHashTable h;
	int no_of_activities;
	printf("Enter no.of total activities in your project: ");
	scanf("%d",&no_of_activities);
	initGraph(&G1,no_of_activities+2);
	initGraph(&G2,no_of_activities+2);
	initHashTable(&h,no_of_activitiesd+2);
	init
	int i,j,input;
	for(i=1;i<=no_of_activities;i++)
	{
		printf("\nEnter duration for Activity %d in months: ",i);
		scanf("%d",&input);
		activity* newActivity = (activity*)malloc(sizeof(activity));
		newActivity->duration = input;
		h->arr[i] = newActivity;
	}

	for(i=1;i<=no_of_activities;i++)
	{
		printf("\nEnter precedence of activity %d (-1 for end): ");
		scanf("%d",&input);
		if(input==-1)
		{
			graphInsert(&G1,0,input);
			graphInsert(&G2,input,0);
		}
		while(input!=-1)
		{
			graphInsert(&G1,i,input);
			graphInsert(&G2,input,i);
			scanf("%d",&input);
		}
	}
}