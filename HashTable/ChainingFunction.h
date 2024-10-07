#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Chaining.h"
HashTable* CHT_CreateHashTable(int TableSize) {
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (List*)malloc(sizeof(Node) * TableSize);

	memset(HT->Table, 0, sizeof(List) * TableSize);

	HT->TableSize = TableSize;

	return HT;
}

int CHT_Hash(KeyType Key, int KeyLength, int TableSize) {
	int i = 0;
	int HashValue = 0;
	
	for (i = 0; i < KeyLength; i++) {
		HashValue = (HashValue << 3) + Key[i];
	}

	HashValue = HashValue % TableSize;

	return HashValue;
}


Node* CHT_CreateNode(KeyType Key, ValueType Value) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Key = (char*)malloc(sizeof(char) * (strlen(Key) + 1));
	strcpy(NewNode->Key, Key);

	NewNode->Value = (char*)malloc(sizeof(char) * (strlen(Key) + 1));
	strcpy(NewNode->Value, Value);
	NewNode->Next = NULL;

	return NewNode;
}
ValueType CHT_Get(HashTable* HT, KeyType Key) {
	int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);

	List TheList = HT->Table[Address];
	List Target = NULL;

	if (TheList == NULL)
		return NULL;

	while (1)
	{
		if (strcmp(TheList->Key, Key) == 0) {
			Target = TheList;
			break;
		}

		if (TheList->Next == NULL)
			break;
		else
			TheList = TheList->Next;
	}

	return Target->Value;
}

void CHT_Set(HashTable* HT, KeyType Key, ValueType Value) {
	int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);
	Node* NewNode = CHT_CreateNode(Key, Value);

	if (HT->Table[Address] == NULL) {
		HT->Table[Address] = NewNode;
	}

	else
	{
		List L = HT->Table[Address];
		NewNode->Next = L;
		HT->Table[Address] = NewNode;

		printf("Collision occured: Key(%s), Address(%d)\n\n", Key, Address);

	}

}