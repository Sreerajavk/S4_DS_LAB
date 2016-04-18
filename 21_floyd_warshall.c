#include<stdio.h>
#define FOR(i,a) for(i=0;i<a;i++)
#define INF 9999
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int graph[100][100],v,e,i,j,k;
	printf("Enter number of vertices : ");
	scanf("%d",&v);
	//filling
	FOR(i,v)
		FOR(j,v)
			graph[i][j]=INF;

	printf("Enter number of edges : ");
	scanf("%d",&e);

	printf("Enter  %d each edge as from, to, weight ( 0 indexed ) : \n",e );
	FOR(i,e)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		graph[x][y]=w;
	}
	printf("Input graph is \n\n");
	FOR(i,v)
	{
		FOR(j,v)
		{
			if(graph[i][j]==INF)
				printf("  INF  " );
			else
				printf("%5d  ", graph[i][j] );
		}
		printf("\n");
	}

	FOR(i,v)
		FOR(j,v)
			FOR(k,v)
				graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);

	printf("\n\n Shortest distance between each vertices are \n\n\n");
	FOR(i,v)
	{
		FOR(j,v)
		{
			if(graph[i][j]==INF)
				printf(" No path " );
			else
				printf("%7d  ", graph[i][j] );
		}
		printf("\n\n");
	}
}