#include <ctype.h>
#include "dictionary.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;

typedef struct node
	{
    bool is_word;
    struct node *children[27];
	}
	node;

int charNumber(char c);
void freeNode(node *currentNode);
node root = {false,{NULL}};  

bool check(const char *word)
{
    node *ptr = &root;
    for (int i=0; i < strlen(word); i++)
    {
        if (ptr->children[charNumber(word[i])] == NULL)
            return false;
        ptr = ptr->children[charNumber(word[i])];
    }
    if (ptr->is_word)
        return true;
    else
        return false;
}

bool load(const char *dictionary)
{
    FILE *fp = fopen(dictionary,"r");
    if (fp == NULL)
        return false;
    while (!feof(fp))
    {
        char word[LENGTH+1] = {};     
        fscanf(fp,"%s\n",word);
        count++;
        node *ptr = &root;
        for (int i=0; i<strlen(word); i++)
        {
            if (ptr->children[charNumber(word[i])] == NULL)
            {
                node *new = malloc(sizeof(node));
                *new = (node) {false,{NULL}};
                ptr->children[charNumber(word[i])] = new;
                ptr = new;
            }
            else
            {
                ptr = ptr->children[charNumber(word[i])];
            }
         }
         ptr->is_word = true;
    }
fclose(fp);
return true;
}

int charNumber(char c)
{
    int num;
    if (c == '\'')
        return 26;
    else if(c >= 'A' && c <= 'Z')
        c += 32;
    num = c - 'a';
    return num;
}

unsigned int size(void)
{
    if (count)
        return count;
    else
        return 0;
}

bool unload(void)
{
    for (int i=0; i<27; i++)
    {
        if (root.children[i] != NULL)
            freeNode(root.children[i]);
    }
    return true;
}
void freeNode(node *currentNode)
{
    for (int i=0; i<27; i++)
    {
        if (currentNode->children[i] != NULL)
            freeNode(currentNode->children[i]);
    }
    free(currentNode);
 }