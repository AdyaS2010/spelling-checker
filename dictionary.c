// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

/*
N -> size of hash table
LENGTH -> max word length
table -> refers to hash table
*/

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Number of words in dictionary
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash word -> obtain hash value
    int index = hash(word);

    // Access linked list at specific index in hash table
    node *cursor = table[index];

    // Traverse linked list, look for a word
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';

    // (simple) hash function -> sums ASCII values of string's characters
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ tolower(word[i]);
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into the hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            return false;
        }
        // Copy word into node
        strcpy(n->word, word);
        // Hash word to get hash value
        int index = hash(word);
        // Insert node into hash table
        n->next = table[index];
        table[index] = n;

        // Increment word count
        word_count++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Iterate over each element in hash table
    for (int i = 0; i < N; i++)
    {
        // Access linked list at specified index in hash table
        node *cursor = table[i];
        // Go through linked list & free the nodes
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        // Check if memory was freed successfully
        if (table[i] != NULL)
        {
            return false;
        }
    }
    return true;
}
