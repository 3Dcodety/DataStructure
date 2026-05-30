#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 10000;
const int inf = 0x3f3f3f3f;
int arc[N][N];//ÁÚ½Ó¾ØÕó
int dist[N];
bool visited[N];//
int vertexNum;
int edgeNum;
void dijkstra(int s)
{
	memset(dist, inf, sizeof(dist));
	memset(visited, false, sizeof(visited));
	dist[s] = 0;
	for (int i = 0; i < vertexNum; i++)
	{
		int u = -1;
		int minDist = inf;
		for (int j = 0; j < vertexNum; j++)
		{
			if (!visited[j] && dist[j] < minDist)
			{
				u = j;
				minDist = dist[j];
			}
		}
		if (u == -1)break;
		visited[u] = true;
		for (int k = 0; k < vertexNum; k++)
		{
			if (!visited[k] && arc[u][k]!=inf)
			{
				dist[k] = min(dist[k],dist[u]+arc[u][k]);
			}
		}
	}
}
int main()
{
	cin >> vertexNum >> edgeNum;
	for (int i = 0; i < vertexNum; i++)
	{
		fill(arc[i], arc[i] + vertexNum, inf);
	}
	for (int i = 0; i < edgeNum; i++)
	{
		int u, v,w;
		cin >> u >> v>>w;
		arc[u][v] = w;
		arc[v][u] = w;
	}
	int start; cin >> start;
	dijkstra(start);
	int a[3][4];
	int (*p)[4] = a + 1;
	cout<<1 << p;
	return 0;
}