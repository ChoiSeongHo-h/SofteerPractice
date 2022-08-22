#include<iostream>
#include<string>
#include<set>
#include<map>

using namespace std;

int main(int argc, char** argv)
{
	char table[5][5];
	int tablePointer = 0;
	string message;
	string key;
	cin >> message;
	cin >> key;

	//100개의 메시지를 받는데, 그럴때 마다 5*5 테이블을 검사하긴 자원 낭비라 생각. set을 생성하여 중복검사
	set<char> keyOccupySet;
	for (auto i : key)
	{
		if (keyOccupySet.find(i) == keyOccupySet.end())
		{
			keyOccupySet.emplace(i);
			table[tablePointer/5][tablePointer%5] = i;
			tablePointer++;
		}
	}

	for (char i = 'A'; i <= 'Z'; i++)
	{
		if (i == 'J')
			continue;

		if (keyOccupySet.find(i) != keyOccupySet.end())
			continue;

		keyOccupySet.emplace(i);
		table[tablePointer/5][tablePointer%5] = i;
		tablePointer++;
	}

	string outMessage;
	int outMessagePointer = 0;
	for (auto i = message.begin(); i < message.end(); i++)
	{
		if (outMessagePointer == 0)
		{
			outMessage.push_back(*i);
			outMessagePointer++;
			continue;
		}

		//홀짝수 변수 만드는 게 덜 헷갈릴듯 함
		//또한 int로 인덱싱 하는 것 보다 반복자를 두는 게 덜 헷갈릴 듯
		if (outMessagePointer % 2 == 1)
		{
			if (outMessage[outMessagePointer-1] == *i)
			{	
				i = prev(i);

				if (*i == 'X')
				{
					outMessage.push_back('Q');
					outMessagePointer++;
					continue;
				}
				outMessage.push_back('X');
				outMessagePointer++;
				continue;
			}
		}

		outMessage.push_back(*i);
		outMessagePointer++;
		continue;
	}

	if (outMessagePointer % 2 == 1)
		outMessage.push_back('X');

	// 이건 5*5 테이블에서 어떤 좌표를 갖고 있는지 맵으로 표현
	// 메시지 입력이 길기 때문에 5*5에서 일일히 서치하기는 비효율적이라 생각했음
	map<char, pair<int, int>> xyMap;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			pair<int, int> xyPair;
			xyPair.first = i;
			xyPair.second = j;
			xyMap.emplace(table[i][j], xyPair);
		}

	for (auto i = outMessage.begin(); i < prev(outMessage.end()); i = i+2)
	{
		//이전에는 이거없이 아래에 그냥 *i로 바꿨는데 오류가 발생했음
		// 원본 데이터를 지켜줘야 함. 까먹기 쉬울듯
		// 변수명명을 좀 잘해야 할 듯
		char i0Temp = *i;
		char i1Temp = *(i+1);
		if (xyMap[*i].first == xyMap[*(i+1)].first)
		{
			*i = table[xyMap[i0Temp].first][(xyMap[i0Temp].second + 1) % 5];
			*(i+1) = table[xyMap[i1Temp].first][(xyMap[i1Temp].second + 1) % 5];
			continue;
		}

		if (xyMap[*i].second == xyMap[*(i+1)].second)
		{
			*i = table[(xyMap[i0Temp].first + 1) % 5][xyMap[i0Temp].second];
			*(i+1) = table[(xyMap[i1Temp].first + 1) % 5][xyMap[i1Temp].second];
			continue;
		}

		*i = table[xyMap[i0Temp].first][(xyMap[i1Temp].second)];
		*(i+1) = table[xyMap[i1Temp].first][(xyMap[i0Temp].second)];
		continue;
	}

	//endl보다 \n이 빠르다 하는데?
	cout<<outMessage<<endl;
			
	return 0;
}
