# C - Hash Tables

A implementation of Hash Tables in C, demonstrating hash functions, collision handling via chaining (doubly/singly linked lists), and sorted hash tables.

## Learning Objectives
* What is a hash function
* What makes a good hash function
* What is a collision and the main ways to deal with them
* What are the advantages and drawbacks of using hash tables
* What are the most common use cases of hash tables

## Data Structures

```c
/**
 * struct hash_node_s - Node of a hash table
 * @key: The key, string (unique in the HashTable)
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;

/**
 * struct shash_node_s - Node of a sorted hash table
 * @key: The key, string (unique in the HashTable)
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted linked list
 * @snext: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
     char *key;
     char *value;
     struct shash_node_s *next;
     struct shash_node_s *sprev;
     struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
     unsigned long int size;
     shash_node_t **array;
     shash_node_t *shead;
     shash_node_t *stail;
} shash_table_t;
```

## Compilation & Execution
To compile the implementation files, run:
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 <main-file.c> <implementation-files.c> -o <binary-name>
```

## Files Description

| File | Description |
| --- | --- |
| [hash_tables.h](hash_tables.h) | Header file containing all standard structures and function declarations. |
| [0-hash_table_create.c](0-hash_table_create.c) | Creates a new hash table and allocates memory for the array buckets. |
| [1-djb2.c](1-djb2.c) | Implements the **djb2** hash algorithm. |
| [2-key_index.c](2-key_index.c) | Retrieves the correct index in the hash table array for a given key. |
| [3-hash_table_set.c](3-hash_table_set.c) | Adds or updates a key/value pair in the hash table. Handles collisions using chaining (prepending). |
| [4-hash_table_get.c](4-hash_table_get.c) | Retrieves the value associated with a key from the hash table. |
| [5-hash_table_print.c](5-hash_table_print.c) | Prints the entire hash table. |
| [6-hash_table_delete.c](6-hash_table_delete.c) | Frees all dynamically allocated memory for the hash table. |
| [100-sorted_hash_table.c](100-sorted_hash_table.c) | PHP-like sorted hash table implementation using a doubly linked list sorted by key (ASCII values). |
