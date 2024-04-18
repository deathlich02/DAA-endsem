#include<stdio.h>
#define max 50
void prims(int adj_mat[50][50], int v)
{
    int e = 0;          //current edges in min cost tree
    int passed[max];      //vertices that are currently contained in min cost tree
    int i,j,x,y;
    for(i = 0;i<v;i++)  
        passed[i] = 0;
    
    passed[0] = 1;      //dont forget this otherwise there will not be any vertices in tree

    while(e < v-1)  //spanning can have a max of v-1 edges
    {
        int min = 999;
        for(i = 0;i < v;i++)  
        {
            if(passed[i])       //checking if the vertex currently belongs to min cost tree
            {
                for(j = 0;j<v;j++)              //within this loop we find the min cost edge from a particular vertex
                {
                    if(!passed[j] && adj_mat[i][j])
                    {
                        if(adj_mat[i][j] < min)
                        {
                            min = adj_mat[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }       
        }
        passed[y] = 1;
        printf("%d -> %d : %d\n",x,y,min);
        e++;
    }
} 

void main()
{
    int v,i,j;
    printf("Enter the number of vertices: \n");
    scanf("%d",&v);
    int adj_matrix[50][50];
    printf("Enter the weighted undirected graph: \n");
    for(i = 0;i<v;i++)
    {
        for(j = 0;j<v;j++)
        {
            printf("Edge %d,%d ",i,j);
            scanf("%d",&adj_matrix[i][j]);
        }
    }
    prims(adj_matrix,v);
}