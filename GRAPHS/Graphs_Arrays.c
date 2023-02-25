#include <stdio.h>
#define max 20
int path[max];
int ind=0;
void init_adjmat(int adjmat[][max], int n)
{
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adjmat[i][j] = 0;
}

void create_graph(int adjmat[][max], int n)
{
    int i, j;
    while (1)
    {
        printf("enter the node and its adjacent nodes info else 0");
        scanf("%d %d", &i, &j);
        if (i == 0 && j == 0)
            break;
        adjmat[i][j] = 1;
    }
}

void display(int adjmat[][max], int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%5d", adjmat[i][j]);
        }
        printf("\n");
    }
}

void init_visited(int *v, int n)
{
    for (int i = 0; i <= n; i++)
        v[i] = 0;
}

void dfs(int adjmat[][max], int *visited, int s, int n)
{
    visited[s] = 1;
    printf("%d\n", s);
    for (int i = 1; i <= n; i++)
    {
        if (adjmat[s][i] == 1 && visited[i] == 0)
            dfs(adjmat, visited, i, n);
    }
}


int find_path(int adjmat[][max], int *visited, int s, int d,int n)
{
    visited[s] = 1;
    path[ind++]=s;
    if(s==d)
        return 1;
    printf("%d\n", s);
    for (int i = 1; i <= n; i++)
    {
        if (adjmat[s][i] == 1 && visited[i] == 0)
            if(find_path(adjmat,visited,i,d,n)==1)
                return 1;
    }
    ind--;
}


void bfs(int adjmat[][max], int *visited, int s, int n)
{
    int q[20], f = 0, r = -1;
    visited[s] = 1;
    printf("\n%d", s);
    q[++r] = s;
    while (f <= r)
    {
        s = q[f++];
        for (int i = 1; i <= n; i++)
        {
            if (adjmat[s][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[++r] = i;
                printf("\n%d", i);
            }
        }
    }
}

int strong_conn(int adjmat[][max], int *visited, int n)
{
    for (int i = 1; i <= n; i++)
    {
        init_visited(visited, n);
        dfs(adjmat, visited, i, n);
        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == 0)
                return 0;
        }
    }
    return 1;
}

int weakly_conn(int adjmat[][max], int *visited, int n)
{
    int b[max][max];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjmat[i][j] == 1)
            {
                b[i][j] = 1;
                b[j][i] = 1;
            }
        }
    }
    init_visited(visited, n);
    dfs(b, visited, 1, n);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int ch, adjmat[max][max], visited[max], s, n,x,d;
    do
    {
        printf("1. create graph ,2. display , 3. traverse 4. exit 5.bfs  6.strong_connection 7.path");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter no. of nodes");
            scanf("%d", &n);
            init_adjmat(adjmat, n);
            create_graph(adjmat, n);
            break;
        case 2:
            display(adjmat, n);
            break;
        case 4:
            ch = 0;
            break;
        case 3:
            printf("enter the src node");
            init_visited(visited, n);
            for (int i = 1; i <= n; i++)
            {
                if (visited[i] == 0)
                {
                    dfs(adjmat, visited, s, n);
                }
            }
            break;

        case 5:
            printf("enter src node");
            scanf("%d", &s);
            init_visited(visited, s);
            bfs(adjmat, visited, s, n);
            break;

        case 6:
            int strong_con = strong_conn(adjmat, visited, n);
            if (strong_con == 1)
                printf("graph strongly connected\n");
            else
            {
                if (weakly_conn(adjmat, visited, n) == 1)
                    printf("not strongly connected\n");
                else
                {
                    printf("graph neither weakly nor strongly\n");
                }
            }
            break;

        case 7:
            printf("enter src and dest");
            scanf("%d %d",&s,&d);
            x=find_path(adjmat,visited,s,d,n);
            if(x==1)
                printf("path exists\n");
            else
                printf("path doesn't exists\n");
            break;
        }
    } while (ch != 0);
}