#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int N, Si, Fi;
	scanf("%d", &N);
	vector<int> S(N);
	vector<int> F(N);
	for(int i = 0; i<N; i++)
	{
		scanf("%d %d", &Si, &Fi);
		S[i] = Si;
		F[i] = Fi-1;
	}

  set<pair<int, int>> fs;
	for(int i = 0; i<N; i++)
	{
		fs.emplace(make_pair(F[i], S[i]));
	}

  int cnt = 0;
	int occ = -1;
	for(auto& i : fs)
	{
		int s = i.second;
		int f = i.first;
		if(s <= occ)
			continue;
		
		++cnt;
		occ = f;
	}
	printf("%d", cnt);

	return 0;
}
