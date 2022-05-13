#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<fstream>

using namespace std;
void topsort(int x, int &k, vector<int> &mark, vector<int> &answer, vector<vector<int>> arr) {
	mark[x] = 1;
	int y;
	for (int i = 0; i < arr[x].size(); ++i) {
		y = arr[x][i];
		if (mark[y] == 0) {
			topsort(y, k,  mark, answer, arr);
		}
	}
	answer.push_back(x);

}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int V, E, v_i, v_j, y, k = 0;
	vector<int> answer;
	fin >> V >> E;
	vector<vector<int>> count;
	vector<int> mark(V + 1, 0);
	vector<int> level(V + 1, -1);
	vector<vector<int>> arr(V + 1, vector<int>(0));
	for (int i = 0; i < E; ++i) {
		fin >> v_i >> v_j;
		arr[v_i].push_back(v_j);
	}

	/*for (int i = 0; i <= V; ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			for (int a = 0; a <= V; ++a) {
				if (i == arr[a][j]) {
					k++;
					level[arr[a][j]] = k;
				}
			}
		}
		
	}*/
	
	for (int i = V; i > 0; --i) {
		if (mark[i] == 0) {
			topsort(i, k, mark, answer, arr);
		}
	}
	fin.close();
	fout.close();
	return 0;
}