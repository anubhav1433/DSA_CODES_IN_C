#include <stdio.h>
#include <stdlib.h>
#define maxnodes 20
typedef struct node
{
	int data;
	struct node* link;
}graph;

void insert_rear(graph** nodep, int i, int j)
{
	graph* temp = (graph*)malloc(sizeof(graph));
	temp->data = j;
	temp->link = NULL;
	graph* cur = nodep[i];
	if (cur == NULL) {
		nodep[i] = temp;
	}
	else {
		while (cur->link != NULL) {
			cur = cur->link;
		}
		cur->link = temp;
	}
}
void init_adjlist(graph** nodep, int n)
{
	for (int i = 1; i <= n; i++) {
		nodep[i] = NULL;
	}
}
void init_visited(int* visited, int n)
{
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}
void create_graph(graph** nodep, int n)
{
	while (1) {
		int i, j;
		printf("Enter node and its adjacent nodes information, otherwise type 0: ");
		scanf("%d %d", &i, &j);
		if (i == 0 && j == 0) {
			break;
		}
		insert_rear(nodep, i, j);
	}
}

void display(graph** nodep, int n)
{
	for (int i = 1; i <= n; i++) {
		printf("Nodes adjacent to %d: ", i);
		graph* cur = nodep[i];
		while (cur != NULL) {
			printf("%d->", cur->data);
			cur = cur->link;
		}
		printf("\n");
	}
}
void dfs_display(graph** nodep, int *visited, int s, int n)
{
	visited[s] = 1;
	printf("%d ", s);
	int adj;
	for (graph* p = nodep[s]; p != NULL; p = p->link) {
		adj = p->data;
		if (visited[adj] == 0) {
			dfs_display(nodep, visited, adj, n);
		}
	}
}

void bfs(graph **nodep,int *visited,int s,int n)
{
    int q[20],f=0,r=-1;
    visited[s]=1;
    printf("\n%d",s);
    q[++r]=s;
    while(f<=r)
    {
        s=q[f++];
        for(graph *p=nodep[s];p!=NULL;p=p->link)
        {
            if(visited[p->data]==0)
            {
                visited[p->data]=1;
                q[++r]=p->data;
                printf("\n%d",p->data);
            }
        }
    }
}



void main()
{
	int ch, n, s, visited[maxnodes];
	graph *listnodes[maxnodes];
	do {
		printf("1-create_graph, 2-display, 3-dfs_display, 4-check if graph is connected/not connected, 5-bfs_display, any other number to exit: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter number of nodes in graph: ");
			scanf("%d", &n);
			init_adjlist(listnodes, n);
			create_graph(listnodes, n);
			break;
		case 2:
			display(listnodes, n);
			break;
		case 3:
			printf("Enter source node: ");
			scanf("%d", &s);
			init_visited(visited, n);
			dfs_display(listnodes, visited, s, n);
			/*for (int i = 1; i <= n; i++) {
				if (visited[i] == 0) {
					dfs_display(listnodes, visited, s, n);
				}
			}*/
			printf("\n");
			break;
		//case 4:
		//	init_visited(visited, n);
		//	int flag = 0;
		//	for (int i = 1; i <= n; i++) {
		//		if (visited[i] == 0) {
		//			flag = 1;
		//			break;
		//		}
		//	}
		//	if (flag == 0) {
		//		printf("Graph is connected\n");
		//	}
		//	else {
		//		printf("Graph is not connected\n");
		//	}
		//	break;
		case 5:
			printf("Enter the source node: ");
			scanf("%d", &s);
			init_visited(visited, n);
			bfs(listnodes, visited, s, n);
			printf("\n");
			break;
		}
	} while (ch >= 1 && ch <= 3);
}