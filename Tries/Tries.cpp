#include<iostream>
#include<string>
#include<fstream>
#include"tries.h"
using namespace std;


trieNode* creatNode()
{
	trieNode* p = new trieNode;
	for (int i = 0; i < 26; i++)
	{
		p->next[i] = NULL;
	}
	p->isWord = 0;
	return p;
}

void insert(trieNode* root, string s)
{
	trieNode* p = root;
	for (int i = 0; i < s.length(); i++)
	{
		int idx = s[i] - 'a';
		if (p->next[idx] == NULL)
		{
			p->next[idx] = creatNode();
		}
		p = p->next[idx];
	}
	p->isWord = 1;
}

trieNode* creatTrieFromFile(string filename)
{
	ifstream ifs(filename);
	if (!ifs.is_open())
	{
		cout << "Khong mo duoc file" << endl;
		return NULL;
	}
	trieNode* root = creatNode();
	while (!ifs.eof())
	{
		string s;
		getline(ifs, s);
		insert(root, s);
	}
	ifs.close();
	return root;
}