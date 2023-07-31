#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define N  100
int n;
int Mgraph[N][N]; //邻接矩阵
void turn_graph(vector<vector<int> > &i_graph) {
	vector<int>temp;
	int i, j;
	for (i = 0; i < n; ++i) {
		temp.clear();
		for (j = 0; j < n; ++j)
			temp.push_back(Mgraph[i][j]);
		i_graph.push_back(temp);
	}
}
void search(vector<vector<int> >i_graph, int x) {
	int i;
	int size = i_graph.size();
	vector<int> compare;   //存储点x通向的点
	vector<int> visit;
	vector<int> stack;
	int top = -1;
	compare.clear();
	for (int k1 = 0; k1 < size; ++k1)
		compare.push_back(0);
	for ( i = 0; i < size; ++i) 
		if (i_graph[x][i] == 1) //将点x通向的点，存储到compare中
			compare[i] = 1;
	for ( i = 0; i < size; ++i) { //对点x的每个点进行遍历
		//初始化
		visit.clear();
		stack.clear();
		for (int k1 = 0; k1 < size; ++k1) {
			visit.push_back(0);
			stack.push_back(0);
		}
		top = -1;
//		stack.push_back(x);
		stack[++top] = x;
		visit[x] = 1;

		if (i_graph[x][i] == 1) { //若有连接
			stack[++top] = i;
			visit[i] = 1;
			while (top != 0) { //根节点x不应该出栈
				int k1;
				i = stack[top];
				for ( k1 = 0; k1 < size; ++k1) {
					if (i_graph[i][k1] == 1 && !visit[k1]) {
						stack[++top] = k1;
						visit[k1] = 1;
						break;
					}
				}
				if (k1 == size) {         //若没有与其它节点相连的，就输出stack中所有的元素
					if (top > 1) {
						for (int k2 = 0; k2 <= top; ++k2) 
							cout << stack[k2]+1;
						if (compare[stack[top]]+1 == 1)
							cout << "  环" << endl;
						else
							cout << endl;
					}
					--top;
				}
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == '1' && i!=j)
				Mgraph[i][j] = 1;
			else
				Mgraph[i][j] = 0;
	}
	vector<vector<int>>i_graph;
	int i = 1;
	turn_graph(i_graph); 
	for (int i = 0; i < N; ++i) {
		search(i_graph, i);
	}
}