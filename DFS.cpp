#include <iostream>
#include <vector>
using namespace std;
#define size 5
int s = size;
int num = size*size;
int map[5][5]=
{
	{1,1,1,1,1},
	{0,1,0,0,1},
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,1,1,1,1}
};

void dfs(int row, int col, int n){
	//check the speps of the shortest path
	if (row == s - 1 && col == s - 1){
		if (num > n){
			num = n;
			cout << "Find!\n";
		}
		return;
	}
	cout << "(" << row << "," << col << ")" << endl;
	map[row][col] = 0;
	if (row > 0 && map[row - 1][col] != 0)
		dfs(row - 1, col, n + 1);
	if (row < s + 1 && map[row + 1][col] != 0)
		dfs(row + 1, col, n + 1);
	if (col > 0 && map[row][col - 1] != 0)
		dfs(row, col - 1, n + 1);
	if (col < s - 1 && map[row][col + 1] != 0)
		dfs(row, col + 1, n + 1);
	map[row][col] = 1;

}

int main(){
	dfs(0, 0, 1);
	cout << "shortest paht : " << num << endl;
	return 0;
}