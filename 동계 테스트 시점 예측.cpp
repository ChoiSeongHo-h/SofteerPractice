#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_set>

using namespace std;

vector<vector<int>> table;
int N, M;
int outIdx = 3;

void BFS(int i_, int j_)
{
	bool isIn = true;
	
	queue<pair<int, int>> q;
	queue<pair<int, int>> visited;
	q.emplace(pair<int, int>(i_, j_));
	visited.emplace(pair<int, int>(i_, j_));
	while(!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		table[i][j] = 2;
		if(j+1 == M || j-1 == -1 || i+1 == N || i-1 == -1)
		{
			isIn = false;
		}

		if(j+1 != M && table[i][j+1] == 0)
		{
			q.emplace(pair<int, int>(i, j+1));
			visited.emplace(pair<int, int>(i, j+1));
		}
		if(j-1 != -1 && table[i][j-1] == 0)
		{
			q.emplace(pair<int, int>(i, j-1));
			visited.emplace(pair<int, int>(i, j-1));
		}
		if(i+1 != N && table[i+1][j] == 0)
		{
			q.emplace(pair<int, int>(i+1, j));
			visited.emplace(pair<int, int>(i+1, j));
		}
		if(i-1 != -1 && table[i-1][j] == 0)
		{
			q.emplace(pair<int, int>(i-1, j));
			visited.emplace(pair<int, int>(i-1, j));
		}
	}

	if(isIn)
	{
		while(!visited.empty())
		{
			int i = visited.front().first;
			int j = visited.front().second;
			visited.pop();
			table[i][j] = outIdx;
		}
		outIdx++;
	}

}

int main(int argc, char** argv)
{
	cin >> N >> M;
	table = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i<N; i++)
	{
		for(int j = 0; j<M; j++)
		{
			int block;
			cin >> block;
			table[i][j] = block;
		}
	}

	set<pair<int, int>> ices;
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<M; j++)
		{
			if(table[i][j] == 0)
			{
				BFS(i, j);
			}
			else if(table[i][j] == 1)
			{
				ices.emplace(pair<int, int>(i, j));
			}
		}
	}

	unordered_set<int> targetAirs;
	targetAirs.emplace(2);
	int t = 0;

	while (1)
	{
		bool isNoIce = true;
		queue<pair<int, int>> eraseIces;
		for (auto ice = ices.begin(); ice!=ices.end(); ice++)
		{
			int i = ice->first;
			int j = ice->second;
			if(table[i][j] != 1)
				continue;

			int surroundCnt = 0;
			if(j+1 != M && targetAirs.find(table[i][j+1]) != targetAirs.end())
			{
				surroundCnt++;
			}
			if(j-1 != -1 && targetAirs.find(table[i][j-1]) != targetAirs.end())
			{
				surroundCnt++;
			}
			if(i+1 != N && targetAirs.find(table[i+1][j]) != targetAirs.end())
			{
				surroundCnt++;
			}
			if(i-1 != -1 && targetAirs.find(table[i-1][j]) != targetAirs.end())
			{
				surroundCnt++;
			}
			if(surroundCnt >= 2)
			{
				//printf("%d %d\n", i, j);
				isNoIce = false;
				eraseIces.emplace(pair<int, int>(i, j));
			}
		}

		if(isNoIce)
		{
			cout<<t;
			return 0;
		}
		t++;

		while(!eraseIces.empty())
		{
			int i = eraseIces.front().first;
			int j = eraseIces.front().second;
			eraseIces.pop();
			table[i][j] = 2;

			if(j+1 != M && table[i][j+1] >= 3)
			{
				targetAirs.emplace(table[i][j+1]);
			}
			if(j-1 != -1 && table[i][j-1] >= 3)
			{
				targetAirs.emplace(table[i][j-1]);
			}
			if(i+1 != N && table[i+1][j] >= 3)
			{
				targetAirs.emplace(table[i+1][j]);
			}
			if(i-1 != -1 && table[i-1][j] >= 3)
			{
				targetAirs.emplace(table[i-1][j]);
			}
		}

	}

	return 0;
}
