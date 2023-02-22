/* Contributer: Lucas Jeong */
/* Clipboard Function Code from: Arian8j2 */

#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include "Clipboard.h"

using namespace std;

void CutZero(string& param)
{
	const int jump = 4;
	int length = param.length();
	int i = 0;
	
	while(true)
	{
		
		if(param[i] == '-')
		{
			i += 5;
			for(int j = i; j+jump <= length; ++j)
				param[j] = param[j+jump];
		}
		else
		{
			i += 4;
			for(int j = i; j+jump <= length; ++j)
				param[j] = param[j+jump];
		}
		length -= jump;
		if(param[i] == '\0') break;
		++i;
	}
	param.resize(length);
}

int main(int argc, char* argv[])
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> two(0, 99);
	uniform_int_distribution<int> three(0, 999);
	uniform_int_distribution<int> color(0, 255);
	uniform_real_distribution<float> minus(-1.0f, 1.0f);
	uniform_real_distribution<float> plus(0.0f, 1.0f);

	bool flag = true;

	cout << "How many copied value?" << endl;
	int copyNum;
	cin >> copyNum;

	while (flag)
	{
		clipboardxx::clipboard clipboard;
		string copyText;

		cout << "1: (00), 2: (000), 3: (0.00)~(1.00), 4: (-1.00)~(1.00)\n"
			"5: (0, 0, 0), 6: (0, 0, 0, 0), 0: Terminate Program" << endl;

		int num;
		cin >> num;

		switch (num)
		{
		case 1:
			copyText = to_string(two(gen));
			for (int i = 0; i < copyNum - 1; ++i)
			{
				copyText += "\n" + to_string(two(gen));
			}
			break;
		case 2:
			copyText = to_string(three(gen));
			for (int i = 0; i < copyNum - 1; ++i)
			{
				copyText += "\n" + to_string(three(gen));
			}
			break;
		case 3:
			copyText = to_string(round(plus(gen) * 100) / 100);
			for (int i = 0; i < copyNum - 1; ++i)
			{
				string tmp = to_string(round(plus(gen) * 100) / 100);
				copyText += "\n" + tmp;
			}
			CutZero(copyText);
			break;
		case 4:
			copyText = to_string(round(minus(gen) * 100) / 100);
			for (int i = 0; i < copyNum - 1; ++i)
			{
				string tmp = to_string(round(minus(gen) * 100) / 100);
				copyText += "\n" + tmp;
			}
			CutZero(copyText);
			break;
		case 5:
			copyText = "(" + to_string(color(gen)) + "," + to_string(color(gen)) +
				"," + to_string(color(gen)) + ")";
			for (int i = 0; i < copyNum - 1; ++i)
			{
				string tmp = "(" + to_string(color(gen)) + "," + to_string(color(gen)) +
					"," + to_string(color(gen)) + ")";
				copyText += "\n" + tmp;
			}
			break;
		case 6:
			copyText = "(" + to_string(color(gen)) + "," + to_string(color(gen)) +
				"," + to_string(color(gen)) + "," + to_string(color(gen)) + ")";
			for (int i = 0; i < copyNum - 1; ++i)
			{
				string tmp = "(" + to_string(color(gen)) + "," + to_string(color(gen)) +
					"," + to_string(color(gen)) + "," + to_string(color(gen)) + ")";
				copyText += "\n" + tmp;
			}
			break;
		default:
			flag = false;
			break;
		}

		cout << copyText << endl << endl;
		clipboard << copyText;
	}

	return 0;
}
