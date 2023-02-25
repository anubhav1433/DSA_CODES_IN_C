#include<stdio.h>

int n;

void topo_sort(int graph[100][100]){
    int top=-1;
    int stk[20];
    int indegree[100];
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum=sum+graph[j][i];            
        }
        indegree[i]=sum;
        printf("%d\n",indegree[i]);
    }
    
}

int main()
{
    scanf("%d",&n);
    int graph[100][100]; 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    topo_sort(graph);
    return 0;
}