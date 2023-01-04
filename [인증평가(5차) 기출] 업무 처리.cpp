#include<iostream>
#include<vector>
#include<array>
#include<queue>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int H, K, R;
	scanf("%d %d %d", &H, &K, &R);
	int num_leaf = pow(2, H);
	int n = num_leaf*2;
	
	vector<array<queue<int>, 2>> tb(n);
	for(int i = num_leaf; i<n; ++i)
	{
		for(int j = 0; j<K; ++j)
		{
			int task;
			scanf("%d", &task);
			tb[i][j%2].emplace(task);
		}
	}

	int ans = 0;
	for(int day = 1; day<=R; ++day)
	{
		for(int i = 1; i<n; ++i)
		{
			int dir = 1-(day%2);
			if(tb[i][dir].empty())
				continue;
			
			if(i == 1)
			{
				ans += tb[i][dir].front();
				tb[i][dir].pop();
				continue;
			}

			int next = i/2;
			int lr = i%next;
			if(next == 1)
				lr = i%(next+1);
			tb[next][lr].emplace(tb[i][dir].front());
			tb[i][dir].pop();
		}
	}
	printf("%d", ans);
	return 0;
}
