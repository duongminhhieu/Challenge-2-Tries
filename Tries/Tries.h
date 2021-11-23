#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include"tries.h"
using namespace std;


// Xây dựng cấu trúc Tries
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
