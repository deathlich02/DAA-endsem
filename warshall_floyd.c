#include<stdio.h>

void walsh_floyd(int v,int graph[v][v])
{
    int i,j,k;
    for(k = 0;k<v;k++)
    {
        for(i = 0;i<v;i++)
        {
            for(j = 0;j<v;j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    printf("Final matrix: \n");
    for(i = 0;i<v;i++)
    {
        for(j = 0;j<v;j++)
        {
            printf("%d  ",graph[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int v,i,j;
    printf("Enter the number of vertices: \n");
    scanf("%d",&v);
    int inp_graph[v][v];
    printf("Enter the weighted graph: \n");
    for(i = 0;i<v;i++)
    {
        for(j = 0;j<v;j++)
        {
            printf("Edge %d,%d",i,j);
            scanf("%d",&inp_graph[i][j]);
        }
    }
    walsh_floyd(v,inp_graph);
}