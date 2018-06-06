#include <iostream>
#include <cstdio>
#include <hash_map>
using namespace std;

int main(){

	hash_map<int, float> hashmap1, hashmap2;
	
	hashmap1.insert(hash_map<int, float>::value_type(3, 45.6f));
	hashmap1.insert(hashmap1.begin(), hash_map<int, float>::value_type(1, 50.6f));
	hashmap1.insert(hash_map<int, float>::value_type(0, 30.2f));
	hashmap1.insert(hash_map<int, float>::value_type(2, 25.1f));
	hashmap2.insert(hashmap1.begin(), hashmap1.end());

	for (int i = 0; i < hashmap1.size(); i++)
		cout << hashmap1[i] << " ";
	cout << endl;

	hash_map<int, float>::iterator itr;
	for (itr = hashmap1.begin(); itr != hashmap1.end(); itr++)
		printf("(%d, %.1f)\n", itr->first, itr->second);

	cout << endl << "1: " << hashmap1[1] << endl;
	cout << endl << "lower_bound(1)" << endl;
	itr = hashmap1.lower_bound(1);
	while (itr != hashmap1.end()){
		cout << itr->second << " ";
		itr++;
	}
	
	cout << endl << "upper_bound(1)" << endl;
	itr = hashmap1.upper_bound(1);
	while (itr != hashmap1.end()){
		cout << itr->second << " ";
		itr++;
	}

	return 0;
}