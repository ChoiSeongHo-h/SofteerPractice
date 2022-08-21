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

	cout<<outMessage<<endl;
			
	return 0;
}
