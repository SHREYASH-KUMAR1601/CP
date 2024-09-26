#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

class Hashmap {

	node**hashtable;
	int ts;
	int cs;

	void Rehashing() {
		node ** OldHashtable = hashtable;

		hashtable = new node*[2 * ts];
		ts = 2 * ts;
		cs = 0;

		for (int i = 0; i < ts; i++) {
			hashtable[i] = NULL;
		}

		//Copy all data of oldhashtable to new hash table

		for (int i = 0; i < ts / 2; i++) {
			node *head = OldHashtable[i];

			while (head != NULL) {
				Insert(head->key, head->val);
				head = head->next;
			}
		}

		delete[]OldHashtable;
	}

	int HashFunction(string key) {
		int multiplier = 1;
		int index = 0;

		for (int i = 0; i < key.size(); i++) {
			index += (key[i] % ts * multiplier % ts);
			multiplier *= 29;
			multiplier %= ts;
		}

		return index % ts;
	}

public:

	Hashmap(int size = 7) {
		hashtable = new node*[size];
		ts = size;
		cs = 0;

		for (int i = 0; i < ts; i++) {
			hashtable[i] = NULL;
		}
	}

	void Insert(string key, int val) {
		int HashIndex = HashFunction(key);

		node *n = new node(key, val);
		cs++;

		// Insert at head of Linked List

		n->next = hashtable[HashIndex];
		hashtable[HashIndex] = n;

		if (cs / ts * 1.0 >= 0.7) {
			Rehashing();
		}
	}

	void Print() {
		for (int i = 0; i < ts; i++) {
			cout << i << "---->" << " ";

			node*head = hashtable[i];

			while (head != NULL) {
				cout << head->key << " " << head->val << "---->";
				head = head->next;
			}
			cout << endl;
		}
	}

	void Search(string k) {
		int ind = HashFunction(k);
		node * head = hashtable[ind];

		while (head != NULL) {
			if (head->key == k) {
				cout << head->key << " " << head->val << endl;
				return;
			}
			head = head->next;
		}

		cout << "-1" << endl;
		return;
	}

};
