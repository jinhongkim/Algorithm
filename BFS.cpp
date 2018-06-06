#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int graph[1001][1001];
//N:num. of Vertex
//M:num. of edgd
//V:start vertex num.
int N, M, V;

void BFS(){

	queue<int> q;
	bool check[1001];
	int arr[1000];
	int idx = 0;
	fill(&check[0], &check[N + 1], false);
	q.push(V);
	while (!q.empty()){
		int now = q.front();
		q.pop();
		if (check[now] == false){
			check[now] = true;
			arr[idx++] = now;

			for (int i = 0; i <= N; i++){
				if (graph[now][i] == 1 && check[i] == false){
					//if connection and Not passed 
					q.push(i);
				}
			}
		}
	}
	for (int i = 0; i < idx; i++){
		cout << arr[i] << " ";
	}cout << endl;
}

int main(){

	cin >> N >> M >> V;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			graph[i][j] = 0;
			graph[j][i] = 0;
		}
	}
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	BFS();
	return 0;
}