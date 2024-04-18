#include<stdio.h>
#define max 30

void dijkstra(int adj_mat[max][max], int n)
{
    int i,j,count,mindist,next,tot_cost = 0;
    int visited[max],dist[max],cost[max][max],prev[max];

    for(i = 0;i<n;i++)
    {
        for(j = 0;j<n;j++)
        {
            if(adj_mat[i][j] == 0)
                cost[i][j] = 999999;
            else
                cost[i][j] = adj_mat[i][j];
        }
    }

    for(i = 0;i < n;i++)
    {
        dist[i] = cost[0][i];
        prev[i] = 0;
        visited[i] = 0;
    }

    visited[0] = 1;
    dist[0] = 0;
    count = 1;
    
    while(count < n - 1 )
    {
        mindist = 999;

        for(i = 0;i < n;i++)
        {
            if(dist[i] < mindist && !visited[i])
            {
                mindist = dist[i];
                next = i;
            }
        }
        visited[next] = 1;

        for(i= 0;i<n;i++)
        {
            if(!visited[i])
            {
                if(mindist + cost[next][i] < dist[i])
                {
                    dist[i] = mindist + cost[next][i];
                    prev[i] = next;
                }
            }
        }
        count++;
    }
    int start = 0;
    printf("The minimum distance to each vertex is: \n");
    for(i = 0;i < n;i++)
    {
        printf("%d -> %d : %d",start,i,dist[i]);
        tot_cost += dist[i];
    }


}

void main()
{
    int v,i,j;
    printf("Enter the number of vertices: \n");
    scanf("%d",&v);
    int adj_matrix[max][max];
    printf("Enter the weighted undirected graph: \n");
    for(i = 0;i<v;i++)
    {
        for(j = 0;j<v;j++)
        {
            printf("Edge %d,%d ",i,j);
            scanf("%d",&adj_matrix[i][j]);
        }
    }
    dijkstra(adj_matrix,v);
}