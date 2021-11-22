#pragma once
#include<iostream>

using namespace std;
struct trieNode
{
	char value;
	trieNode* next[26];
	bool isWord;
};
trieNode* creatNode();
void insert(trieNode* root, string s);
trieNode* creatTrieFromFile(string filename);
void findWord(trieNode* root, int a[], int count, queue<string>& q, string s);
