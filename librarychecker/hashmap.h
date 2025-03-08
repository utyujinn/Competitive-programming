#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct Entry Entry;
struct Entry {
  char *key;
  char *value;
  Entry *next;  // for chaining
};

typedef struct HashMap HashMap;
struct HashMap {
  Entry **entries;
  int size;  // size of entries
};

HashMap *newHashMap(int size);
void insertToHashMap(const HashMap *hashmap, const char *key,
                     const char *value);
char *getValueFromHashMap(const HashMap *hashmap, const char *key);
void freeHashMap(HashMap *hashmap);
int removeFromHashMap(const HashMap *hashmap, const char *key);

#endif  // HASHMAP_H
