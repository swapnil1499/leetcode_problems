//
// Created by spatel on 2022-03-07.
//

#include <stdio.h>
#include <chrono>
#include <vector>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{

		ListNode *answer = NULL;

		int carry = 0;
		while(l1 != NULL || l2 != NULL)
		{
			int n1 = (l1 != NULL) ? l1->val : 0;
			int n2 = (l2 != NULL) ? l2->val : 0;

			int sum = n1 + n2 + carry;

			carry = sum / 10;
			append(&answer, sum % 10);

			if (l1 != NULL)
				l1 = l1->next;
			if (l2 != NULL)
				l2 = l2->next;

		}
		if (carry > 0)
			append(&answer, carry);

		return answer;

	}
private:
	// Inserts n value at the end of the linked list
	void append(ListNode **node, int n){
		ListNode *newNode = new ListNode(n);
		//newNode = (ListNode *)malloc(sizeof(ListNode));
		//newNode->val = n;
		//newNode->next = NULL;

		if (*node == NULL) {
			*node = newNode;
			return;
		}

		ListNode *last = *node;
		while(last->next != NULL)
			last = last->next;

		last->next = newNode;
	}

};

// Inserts n value at the end of the linked list
void append(ListNode **node, int n){
	ListNode *newNode = new ListNode(n);
	//newNode = (ListNode *)malloc(sizeof(ListNode));
	//newNode->val = n;
	//newNode->next = NULL;

	if (*node == NULL) {
		*node = newNode;
		return;
	}

	ListNode *last = *node;
	while(last->next != NULL)
		last = last->next;

	last->next = newNode;
}

void printLinkedList(ListNode *linkedList)
{
	while(linkedList != NULL)
	{
		printf("%i ", linkedList->val);
		linkedList = linkedList->next;
	}
	printf("\n\r");
}
int main()
{
	ListNode *l1 = NULL;
	ListNode  *l2 = NULL;

	std::vector<int> list1 = {9, 9, 9, 9, 9, 9, 9};
	std::vector<int> list2 = {9, 9, 9, 9};

	for (size_t i = 0; i < list1.size(); i++) {
		append(&l1, list1[i]);
	}

	for (size_t i = 0; i < list2.size(); i++) {
		append(&l2, list2[i]);
	}

	printf("Linked List #1\n\t");
	printLinkedList(l1);
	printf("Linked List #2\n\t");
	printLinkedList(l2);

	// Start measuring time
	auto begin = std::chrono::high_resolution_clock::now();
	Solution solve;

	ListNode *answer = solve.addTwoNumbers(l1, l2);
	printf("answer\n\t");
	printLinkedList(answer);

	// Stop measuring time and calculate the elapsed time
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	printf("Time measured: %.3f milliseconds.\n", elapsed.count() * 1e-6);
	return 0;
}