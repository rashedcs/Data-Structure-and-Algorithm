#include <iostream>
#include <string>
using namespace std;
void dfs(char** arr, int x, int y, int** checked);
int n, m, k,s,counter=0;
int main()
{
	s = 0;
	cin >> n >> m >> k;
	char** arr = new char*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new char[m];
	int** checked = new int*[n];
	for (int i = 0; i < n; i++)
		checked[i] = new int[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
			checked[i][j] = false;
			if (arr[i][j] == '.')
				s++;
		}
	}
	int needNumForPath = s - k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '.') {
				dfs(arr, i, j,checked);
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '.' && !checked[i][j]) {
				cout << 'X';
			}
			else
				cout << arr[i][j];
		}
		cout << endl;
	}


}
void dfs(char** arr,int x,int y,int** checked) {
	if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y]=='#' ||checked[x][y]||counter==s-k)
		return;
	counter++;
	checked[x][y] = true;
	dfs(arr,x+1,y,checked);
	dfs(arr, x -1, y, checked);
	dfs(arr, x , y+1, checked);
	dfs(arr, x , y-1, checked);
}
