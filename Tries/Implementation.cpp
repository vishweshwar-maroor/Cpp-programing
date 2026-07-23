#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
class TrieNode
{
private:
public:
    char data;
    TrieNode *children[26];
    bool isTerminating;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminating = false;
    }
};
class Trie
{
private:
    TrieNode *root = new TrieNode('\0');
    void InsertWord(TrieNode *root, string word)
    {
        TrieNode *curr = root;

        for (char c : word)
        {
            int idx = tolower(c) - 'a';
            if (idx < 0 || idx >= 26)
                continue; // skip non-alphabet characters

            if (curr->children[idx] != NULL)
            {
                curr = curr->children[idx];
            }
            else
            {
                curr->children[idx] = new TrieNode(static_cast<char>(tolower(c)));
                curr = curr->children[idx];
            }
        }
        curr->isTerminating = true;
    }
    bool SearchUtil(TrieNode *root, string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            int idx = tolower(c) - 'a';
            if (idx < 0 || idx >= 26)
                return false;

            if (curr->children[idx] == NULL)
            {
                return false;
            }
            else
            {
                curr = curr->children[idx];
            }
        }
        return curr->isTerminating;
    }
    void DeleteWord(TrieNode *root, string word)
    {

        TrieNode *curr = root;
        for (char c : word)
        {
            int idx = tolower(c) - 'a';
            if (idx < 0 || idx >= 26)
                return;

            if (curr->children[idx] == NULL)
            {
                return;
            }
            else
            {
                curr = curr->children[idx];
            }
        }
        curr->isTerminating = false;
    }

public:
    void addWord(string word)
    {
        InsertWord(root, word);
    }
    bool searchWord(string word)
    {
        return SearchUtil(root, word);
    }
    void removeWord(string, word)
    {
        DeleteWord(root, word);
    }
};
int main()
{
    Trie *t = new Trie;

    cout << t->searchWord("bhola");
}
// Implementation using hashmap
class Trienode
{
public:
    unordered_map<char, Trienode *> children;
    bool terminal;
    Trienode()
    {

        terminal = false;
    }
};
class Trie
{
    Trienode *root;

public:
    Trie() { root = new Trienode(); }

    void insert(string word)
    {
        Trienode *curr = root;
        for (char c : word)
        {

            if (!(curr->children.contains(c)))
            {
                curr->children[c] = new Trienode();
                curr = curr->children[c];
            }
            else
            {
                curr = curr->children[c];
            }
        }
        curr->terminal = true;
    }

    bool search(string word)
    {
        Trienode *curr = root;
        for (char c : word)
        {

            if (curr->children.contains(c))
            {
                curr = curr->children[c];
            }
            else
            {
                return false;
            }
        }
        return curr->terminal;
    }

    bool startsWith(string prefix)
    {
        Trienode *curr = root;
        for (char c : prefix)
        {

            if (!(curr->children.contains(c)))
            {

                return false;
            }
            else
            {
                curr = curr->children[c];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */