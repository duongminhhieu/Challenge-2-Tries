#include<iostream>
#include<string>
#include<fstream>
#include<queue>
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
	p->isWord = 1; // danh dau la ket thuc cua mot tu
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

void findWord(trieNode* root, int a[],int count,queue<string> &q,string s)
{
	if (count >= 3 && root->isWord == 1)
	{
		q.push(s);
	}
	for (int i = 0; i < soKiTu; i++)
	{
		if (a[i] > 0&& root->next[i] != NULL)
		{
			a[i] -= 1;
			findWord(root->next[i], a,count+1,q,s+char('a'+i));
			a[i] += 1;
		}
	}
}