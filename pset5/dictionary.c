// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <cs50.h>
#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH * 'z' + 1);

// keep track of the number of words
int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash the word
    int Hash_Value = hash(word);
    
    // acess linked list at the index in the hash table
    node *cursor = table[Hash_Value];
    
    
    // traverse linked list looking for the word
    while (cursor != NULL)
    {
        int result = strcasecmp(cursor->word, word); 
        
        if (result == 0)
        {
            return true;
        }
        
        cursor = cursor -> next;
    }
    return false;
    
}



// Hashes word to a number
//  source : https://research.cs.vt.edu/AVresearch/hashing/strings.php
unsigned int hash(const char *word)
{
    int sum = 0;
    
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
        
    }
    
    return (sum % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictrionary file
    FILE *dic_pointer = fopen(dictionary, "r");
    
    // check if value is null = return false
    if (dic_pointer == NULL)
    {
        return false;
    }
    
    // read strings from file one at a time
    char word[LENGTH + 1];
    
    while (fscanf(dic_pointer, "%s", word) != EOF)
    {
        // create a new node for each word
        node *New_n = malloc(sizeof(node));
        
        // check if returns null
        if (New_n == NULL)
        {
            return false;
            
        }
        
        // copy word into node
        strcpy(New_n->word, word);
        New_n->next = NULL;
        
        //hash word to obtain a hash value
        int index = hash(word);
        
        // insert node into hash table at that location
        if (table[index] == NULL)
        {
            table[index] = New_n;
            
        }
        else
        {
            New_n->next = table[index];
            table[index] = New_n;
            
        }
        
        // keep track of nodes to add to size function
        count++;
        
    }
    fclose(dic_pointer);
    return true;
}
  

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // iterate over hashtable
    for (int i = 0; i < N; i++)
    
    {
        node *cursor = table[i];
        node *tmp = table[i]; 
        
        // stop at end of list
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
            
        }
            
    }
    
    return true;
}
