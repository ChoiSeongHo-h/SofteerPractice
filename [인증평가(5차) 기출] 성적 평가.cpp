#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int N = 0;
	scanf("%d", &N);
	vector<vector<int>> sigma(N, vector<int>(2, 0));
	for(int j = 0; j<3; ++j)
	{

		vector<vector<int>> partial(N, vector<int>(2));
		for(int i = 0; i<N; ++i)
		{
			int score;
			scanf("%d ", &score);
			partial[i][0] = score;
			partial[i][1] = i;
			sigma[i][0] += score;
			sigma[i][1] = i;
		}
		sort(partial.begin(), partial.end(), greater<vector<int>>());

		int before = partial[0][0]-1;
		int cnt = 0;
		vector<int> order(N);
		for(int i = 0; i<N; ++i)
		{
			order[partial[i][1]] = i+1;

			if(before == partial[i][0])
			{
				++cnt;
				order[partial[i][1]] -= cnt;
			}
			else
				cnt = 0;

			before = partial[i][0];
		}

		for(auto i : order)
			printf("%d ", i);
		printf("\n");
	}
	
	sort(sigma.begin(), sigma.end(), greater<vector<int>>());
	int before = sigma[0][0]-1;
	int cnt = 0;
	vector<int> order(N);
	for(int i = 0; i<N; ++i)
	{
		order[sigma[i][1]] = i+1;

		if(before == sigma[i][0])
		{
			++cnt;
			order[sigma[i][1]] -= cnt;
		}
		else
			cnt = 0;

		before = sigma[i][0];
	}

	for(auto i :order)
		printf("%d ", i);

	return 0;
}
