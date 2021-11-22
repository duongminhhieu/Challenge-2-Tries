#pragma once
#include<iostream>

using namespace std;

struct trienode
{
	char value;
	trienode* next[26];
	bool isWord;
};