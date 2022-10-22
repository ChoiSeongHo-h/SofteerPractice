#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	long long K, P, N;
	scanf("%lld %lld %lld", &K, &P, &N);
	long long target = 10*N;
	
	long long ans = 1;
	while(target > 0)
	{
		long long ans_temp = P;
		long long cnt = 1;
		while(2*cnt <= target)
		{
			cnt *= 2;
			ans_temp *= ans_temp;
			ans_temp %= 1000000007;
		}
		target -= cnt;
		ans *= ans_temp;
		ans %= 1000000007;
	}

	ans *= K;
	ans %= 1000000007;
	printf("%lld", ans);

	return 0;
}
