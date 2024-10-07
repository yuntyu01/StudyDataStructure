#include <stdio.h>
#include<stdlib.h>
#include "SimpleHashTableNode.h"

HashTable* SHT_CreateHashTable(int TableSize) {
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));

	HT->Table = (Node*)malloc(sizeof(Node) * TableSize);
	HT->TableSize = TableSize;

	return HT;
}

void SHT_Set(HashTable* HT, KeyType key, ValueType value) {
	int Adress = SHT_Hash(key, HT->TableSize);

	HT->Table[Adress].Key = key;
	HT->Table[Adress].Value = value;
}

ValueType SHT_Get(HashTable* HT, KeyType key) {
	int Adress = SHT_Hash(key, HT->TableSize);

	return HT->Table[Adress].Value;
}

int SHT_Hash(KeyType Key, int TableSize) {
	return Key % TableSize;
}