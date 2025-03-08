#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

HashMap *newHashMap(int size) {
  HashMap *hashmap = (HashMap*)malloc(sizeof(HashMap));
  hashmap->size = size;

  // initialize entries
  hashmap->entries = (Entry**)malloc(sizeof(Entry) * size);
  for (int i = 0; i < size; i++) {
    hashmap->entries[i] = NULL;
  }

  return hashmap;
}

static unsigned int hash(const char *key, const int size) {
  unsigned int hash = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    hash = 31 * hash + key[i];
  }
  return hash % size;
}

void insertToHashMap(const HashMap *hashmap, const char *key,
                     const char *value) {
  unsigned int index = hash(key, hashmap->size);

  // check if key already exists
  Entry *entry = hashmap->entries[index];
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      free(entry->value);
      entry->value = strdup(value);
      return;
    }
    entry = entry->next;
  }

  // create new entry
  entry = (Entry*)malloc(sizeof(Entry));
  entry->key = strdup(key);
  entry->value = strdup(value);
  entry->next = hashmap->entries[index];  // for chaining
  hashmap->entries[index] = entry;
}

char *getValueFromHashMap(const HashMap *hashmap, const char *key) {
  unsigned int index = hash(key, hashmap->size);

  Entry *entry = hashmap->entries[index];
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      return entry->value;
    }
    entry = entry->next;
  }

  return NULL;
}

static void freeEntry(Entry *entry) {
  while (entry != NULL) {
    Entry *next = entry->next;
    free(entry->key);
    free(entry->value);
    free(entry);
    entry = next;
  }
}

void freeHashMap(HashMap *hashmap) {
  for (int i = 0; i < hashmap->size; i++) {
    freeEntry(hashmap->entries[i]);
  }
  free(hashmap->entries);
  free(hashmap);
}

int removeFromHashMap(const HashMap *hashmap, const char *key) {
  unsigned int index = hash(key, hashmap->size);
  Entry *entry = hashmap->entries[index];

  // find the entry and its predecessor
  Entry *pred = NULL;
  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      break;
    }
    pred = entry;
    entry = entry->next;
  }

  if (entry == NULL) return -1;
  if (pred == NULL) {  // entry is the first in the list
    hashmap->entries[index] = entry->next;
  } else {  // entry is not the first in the list
    pred->next = entry->next;
  }

  free(entry->key);
  free(entry->value);
  free(entry);

  return 0;
}

int main(void) {
  int size = 100;
  HashMap *hashmap = newHashMap(size);

  insertToHashMap(hashmap, "key1", "value1");
  insertToHashMap(hashmap, "key1", "value2");
  insertToHashMap(hashmap, "key2", "value1");
  char *value = getValueFromHashMap(hashmap, "key1");
  printf("key1: %s\n", value);  // should be value2

  removeFromHashMap(hashmap, "key1");
  value = getValueFromHashMap(hashmap, "key1");
  printf("key1: %s\n", value);  // should be NULL

  freeHashMap(hashmap);
  return 0;
}
