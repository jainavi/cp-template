#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *nxt[26];
    bool flag = false;

    bool contains(char c)
    {
        return nxt[c - 'a'] != NULL;
    }

    void insert(char c)
    {
        nxt[c - 'a'] = new Node();
    }

    Node *get(char c)
    {
        return nxt[c - 'a'];
    }

    void setEnd()
    {
        this->flag = true;
    }
};

class Trie
{
private:
    Node *root = new Node();

public:
    Trie() {}

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->contains(word[i]))
            {
                node->insert(word[i]);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            node = node->get(word[i]);
            if (node == NULL)
                return false;
        }
        return node->flag;
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            node = node->get(prefix[i]);
            if (node == NULL)
                return false;
        }
        return true;
    }

    bool isComplete(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            node = node->get(word[i]);
            if (!node->flag)
                return false;
        }
        return true;
    }
};