//#include "SimpleHashFunction.h"
#include "ChainingFunction.h"
int main() {

	HashTable* HT = CHT_CreateHashTable(12289);

	CHT_Set(HT, "MSFT", "Microsoft");
	CHT_Set(HT, "MSFT", "Microsoft");
	CHT_Set(HT, "SDSD", "DSDSDSDSDS");
	CHT_Set(HT, "WWWW", "WWWWWWWWW");
	CHT_Set(HT, "ZZZZ", "ZZZZZZZZZ");
	CHT_Set(HT, "XCXC", "ZXZXZXZX");
	CHT_Set(HT, "DFSD", "SOSSOSOS");
	CHT_Set(HT, "GDFG", "DSODDOSS");

	printf("Key:%s, Value:%s\n", "MSFT", CHT_Get(HT, "MSFT"));
	printf("Key:%s, Value:%s\n", "MSFT", CHT_Get(HT, "MSFT"));
	printf("Key:%s, Value:%s\n", "SDSD", CHT_Get(HT, "SDSD"));
	printf("Key:%s, Value:%s\n", "WWWW", CHT_Get(HT, "WWWW"));
	printf("Key:%s, Value:%s\n", "XCXC", CHT_Get(HT, "XCXC"));


	//SIMPLE_HASHTABLE
	//HashTable* HT = SHT_CreateHashTable(193);

	//SHT_Set(HT, 11, 1);
	//SHT_Set(HT, 404, 2);
	//SHT_Set(HT, 705, 4);
	//SHT_Set(HT, 1031, 15);

	//printf("Key:%d, Value:%d\n", 11, SHT_Get(HT, 11));
	//printf("Key:%d, Value:%d\n", 404, SHT_Get(HT, 404));
	//printf("Key:%d, Value:%d\n", 705, SHT_Get(HT, 705));
	//printf("Key:%d, Value:%d\n", 1031, SHT_Get(HT, 1031));
}