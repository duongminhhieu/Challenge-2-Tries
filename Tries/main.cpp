
#include "Tries.h"




void main()
{
	string s;
	cout << "Nhap cac ki tu: ";
	getline(cin, s);

	trieNode* root = creatTrieFromFile("Dic.txt");

	int* a = new int[26];
	for (int i = 0; i < 26; i++)
	{
		a[i] = 0;
	}

	for (int i = 0; i < s.length(); i = i + 2)
	{
		a[s[i] - 'a'] += 1;
	}

	queue<string> dsTu;
	string word = "";
	findWord(root, a, 0, dsTu, word);
	cout << dsTu.size()<<endl;
	while (!dsTu.empty())
	{
		cout << dsTu.front()<<endl;
		dsTu.pop();
	}

	cout << endl << endl;
	system("pause");
}