#include<stdio.h>
#define max 10

typedef struct edge
{
    int u,v,w;
}edge;

typedef struct edge_list
{
    edge edges[max];
    int n;
}edge_list;

edge_list list;
int adj_mat[max][max],n;
edge_list spanning;

void kruskal()
{
    int c1,c2,belongs[max],i,j;
    list.n = 0;
    for(i = 1;i < n;i++)
    {
        for(j = 0; j < i;j++)
        {
            list.edges[list.n].u = i;
            list.edges[list.n].v = j;
            list.edges[list.n].w = adj_mat[i][j];
            list.n++;
        }
    }

    sort(list);
}

void union_comp(int belongs[],int c1,int c2)      //joining 2 components and making them 1
{
 int i;
 for(i = 0;i<n;i++)
 {
    if(belongs[i] == c2)
        belongs[i] == c1;
 }
}

int find(int belongs[],int v)
{
    return(belongs[v]);
}

void sort(edge_list edge_list)
{
    int i,j;
    edge temp;
    for(i = 1;i < edge_list.n ;i++)
    {
        for(j = 0; j < edge_list.n -1,j++)
        {
            if(edge_list.edges[j].w > edge_list.edges[j+1].w)
            {
                temp = edge_list.edges[j+1];
                edge_list.edges[j+1] = edge_list.edges[j];
                edge_list.edges[j] = temp;
            }
        }
    }
}