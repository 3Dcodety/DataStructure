#include<iostream>
#include<cstring>
using namespace std;
const int N = 100;
const int inf = 0x3f3f3f3f;
int dist[N][N];
int path[N][N];
int arc[N][N];
//path[i][j]表示第i点到第j点出发经历的第一点
//dist[i][j]表示i到j的最短距离
//arc[i][j]邻接矩阵,记录各点情况
void floyd(int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dist[i][k] != inf && dist[k][j] != inf)
				{
					if (dist[i][k] + dist[k][j] < dist[i][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						path[i][j] = path[i][k];
					}
				}
			}
		}
	}
}
void print(int start, int target)
{
	cout << start << "到" << target << "的最短路径为" << dist[start][target];
	cout << endl;
	while (start != target)
	{
		cout << start << "->";
		start = path[start][target];
	}
	cout << target;
}
int main()
{
	int n, m;
	cin >> n >> m;
	memset(dist, 0x3f, sizeof(dist));
	for (int i = 0; i < n; i++)
	{
		dist[i][i] = 0;
		for (int j = 0; j < n; j++)
		{
			path[i][j] = j;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		arc[u][v] = w;
		dist[u][v] = w;
	}
	floyd(n);
	print(0, 3);
	return 0;
}