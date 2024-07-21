#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define LOAD_FACTOR 0.7

// Linked List node
struct node {
    char* key;
    char* value;
    struct node* next;
};

// HashMap structure
struct hashMap {
    int numOfElements;
    int capacity;
    struct node** arr;
};

// Create a new node
struct node* createNode(char* key, char* value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = strdup(key);  // Copy key
    newNode->value = strdup(value); // Copy value
    newNode->next = NULL;
    return newNode;
}

// Initialize the hash map
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = INITIAL_CAPACITY;
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;
    }
}

// Hash function
int hashFunction(struct hashMap* mp, char* key) {
    int hash = 0;
    while (*key) {
        hash = (hash * 31 + *key++) % mp->capacity;
    }
    return hash;
}

// Insert a key-value pair
void insert(struct hashMap* mp, char* key, char* value) {
    if ((float)mp->numOfElements / mp->capacity > LOAD_FACTOR) {
        // Rehash if needed
        rehash(mp);
    }

    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = createNode(key, value);

    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

// Delete a key-value pair
void delete(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* currNode = mp->arr[bucketIndex];
    struct node* prevNode = NULL;

    while (currNode != NULL) {
        if (strcmp(currNode->key, key) == 0) {
            if (prevNode == NULL) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            mp->numOfElements--;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Search for a key-value pair
char* search(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* currNode = mp->arr[bucketIndex];
    while (currNode != NULL) {
        if (strcmp(currNode->key, key) == 0) {
            return currNode->value;
        }
        currNode = currNode->next;
    }
    return "Oops! No data found.";
}

// Rehash the hash map
void rehash(struct hashMap* mp) {
    int oldCapacity = mp->capacity;
    struct node** oldArr = mp->arr;

    mp->capacity *= 2;
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;
    }
    mp->numOfElements = 0;

    for (int i = 0; i < oldCapacity; i++) {
        struct node* currNode = oldArr[i];
        while (currNode != NULL) {
            struct node* nextNode = currNode->next;
            insert(mp, currNode->key, currNode->value);
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            currNode = nextNode;
        }
    }
    free(oldArr);
}

// Cleanup memory for hash map
void cleanupHashMap(struct hashMap* mp) {
    for (int i = 0; i < mp->capacity; i++) {
        struct node* currNode = mp->arr[i];
        while (currNode != NULL) {
            struct node* nextNode = currNode->next;
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            currNode = nextNode;
        }
    }
    free(mp->arr);
    free(mp);
}

// Driver code
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));

    printf("%s\n", search(mp, "randomKey"));

    printf("\nAfter deletion : \n");
    delete(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));

    // Cleanup memory
    cleanupHashMap(mp);

    return 0;
}
