#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int vertexNum;//所有点个数
int edgeNum;//所有边个数
const int inf = 0x3f3f3f3f;
const int N = 100;
int dist[N];//起点到i的最短距离
int vis[N] = { 0 };//标记是否访问
int arc[N][N];//arc[i][j]邻接矩阵表示i到j的距离
void dij(int s)
{
	memset(vis, 0,sizeof(vis));
	memset(dist, 0x3f, sizeof(dist));//int为四个字节,该函数将每个字节都填上0x3f   
	dist[s] = 0;
	for (int i = 0; i < vertexNum; i++)//总共进行vertexNum次更新
	{
		int u = -1;
		int mindist = inf;
		for (int j = 0; j < vertexNum; j++)
		{
			if (!vis[j] && dist[j] < mindist)
			{
				u = j;
				mindist = dist[j];
			}
		}//记录此次更新的距离最小且未标记访问过的点
		if (u == -1)break;//表示剩下的未访问点均不可到达故结束提前更新
		vis[u] = 1;//标记代表已确定最短路径
		for (int j = 0; j < vertexNum; j++)
		{
			if (!vis[j] && arc[u][j]!=inf)
			{
				dist[j] =min(arc[u][j]+dist[u],dist[j]);
			}
		}
	}

}
int main()
{
	cin >> vertexNum >> edgeNum;
	memset(arc, 0x3f, sizeof(arc));
	for (int i = 0; i < edgeNum; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		arc[u][v] = w;
	}
	int start; cin >> start;
	int target; cin >> target;
	dij(start);
	if (dist[target] == inf)cout << "无法访问";
	else cout << dist[target];
	return 0;
}
