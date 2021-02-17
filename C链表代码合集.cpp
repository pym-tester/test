#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>



typedef struct ListNode {
	int val;
	ListNode* next;
}Node_t, *pNode_t;

pNode_t split_list[2];

void insert(Node_t *p) {
	pNode_t pMerge = (pNode_t)calloc(1, sizeof(Node_t));
}

void print_list(ListNode *head) {
	ListNode *p = head;
	printf("结果是：");
	while (p != nullptr) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

void print_list_for_Big_int_add(ListNode *head) {
	ListNode *p = head;
	printf("结果是：");
	while (p->next != nullptr) {			//因为会输入回车'\n'进去，所以最后一位不打印
		printf("%d", p->val);
		p = p->next;
	}
	printf("\n");
}

void headInsert(pNode_t *p_p_head, pNode_t *p_p_tail, int val) {
	pNode_t pNew = (pNode_t)calloc(1, sizeof(Node_t));
	pNew->val = val;
	if (*p_p_head == NULL) {
		*p_p_head = pNew;
		*p_p_tail = pNew;
	}
	else {
		pNew->next = *p_p_head;
		*p_p_head = pNew;
	}
}

void tailInsert(pNode_t *p_p_head, pNode_t *p_p_tail, int val) {
	pNode_t pNew = (pNode_t)calloc(1, sizeof(Node_t));
	pNew->val = val;
	if (*p_p_head == NULL) {
		*p_p_head = pNew;
		*p_p_tail = pNew;
	}
	else {
		(*p_p_tail)->next = pNew;
		*p_p_tail = pNew;
	}
}

pNode_t reverseList(pNode_t head, pNode_t tail) {
	pNode_t p = head;
	pNode_t pNewHead = NULL;
	pNode_t pNewTail = NULL;
	while (p != NULL) {
		headInsert(&pNewHead, &pNewTail, p->val);
		p = p->next;
	}
	return pNewHead;
}

pNode_t mergeList(pNode_t head_1, pNode_t head_2) {
	pNode_t pMerge_head = NULL;
	pNode_t pMerge_tail = NULL;
	pNode_t p1 = head_1;
	pNode_t p2 = head_2;

	while (p1 != NULL && p2 != NULL) {
		if (p1->val <= p2->val) {
			tailInsert(&pMerge_head, &pMerge_tail, p1->val);
			p1 = p1->next;
		}
		else {
			tailInsert(&pMerge_head, &pMerge_tail, p2->val);
			p2 = p2->next;
		}
	}
	if (p1 == NULL) {
		pMerge_tail->next = p2;
	}
	else if (p2 == NULL) {
		pMerge_tail->next = p1;
	}
	return pMerge_head;
}

pNode_t findFourthNodeFromButtom(pNode_t head) {
	pNode_t pFourthNode = head;
	pNode_t pEnd = head;
	for (int i = 1; i <= 4; i++) {
		pEnd = pEnd->next;
	}
	while (pEnd != NULL) {
		pEnd = pEnd->next;
		pFourthNode = pFourthNode->next;
	}
	return pFourthNode;
}

pNode_t findMiddleNode(pNode_t head) {
	pNode_t pOneStep = head;
	pNode_t pTwoStep = head;
	while (!(pTwoStep == NULL || pTwoStep->next == NULL)) {
		pOneStep = pOneStep->next;
		pTwoStep = pTwoStep->next->next;
	}
	return pOneStep;
}

void if_List_is_a_ring(pNode_t head) {
	pNode_t pOneStep = head;
	pNode_t pTwoStep = head;
	while (!(pTwoStep == NULL || pTwoStep->next == NULL)) {
		pOneStep = pOneStep->next;
		pTwoStep = pTwoStep->next->next;
		if (pOneStep == pTwoStep) {
			printf("This is a ring.\n");
			return;
		}
	}
	printf("This is not a ring.\n");
}

pNode_t if_intersect(pNode_t head_1,pNode_t head_2) {
	int length_list_1 = 0, length_list_2 = 0;
	pNode_t p_1 = head_1;
	while (p_1 != NULL) {
		length_list_1++;
		p_1 = p_1->next;
	}
	pNode_t p_2 = head_2;
	while (p_2 != NULL) {
		length_list_2++;
		p_2 = p_2->next;
	}
	p_1 = head_1;
	p_2 = head_2;
	while (p_1 != NULL || p_2 != NULL) {
		if (p_1 == p_2) {
			return p_1;
		}
		if (length_list_1 > length_list_2) {
			p_1 = p_1->next;
			length_list_1--;
		}
		else if (length_list_1 < length_list_2) {
			p_2 = p_2->next;
			length_list_2--;
		}
		else if (length_list_1 == length_list_2) {
			p_1 = p_1->next;
			length_list_1--;
			p_2 = p_2->next;
			length_list_2--;
		}
	}
	return NULL;
}

void delete_duplicate_val(pNode_t head) {
	pNode_t p = head;
	while (p != NULL && p->next != NULL) {
		if (p->val == p->next->val) {
			p->next = p->next->next;
		}
		else {
			p = p->next;
		}
	}
}

void split_list_to_two_lists(pNode_t head) {
	pNode_t pNewHead_1 = NULL;
	pNode_t pNewTail_1 = NULL;
	pNode_t pNewHead_2 = NULL;
	pNode_t pNewTail_2 = NULL;
	pNode_t p = head;
	int count = 0;
	while (p != NULL) {
		if (count % 2 == 0) {
			tailInsert(&pNewHead_1, &pNewTail_1, p->val);
		}
		else {
			tailInsert(&pNewHead_2, &pNewTail_2, p->val);
		}
		count++;
		p = p->next;
	}
	split_list[0] = pNewHead_1;
	split_list[1] = pNewHead_2;
}

pNode_t Big_int_add(pNode_t head_1,pNode_t tail_1,pNode_t head_2,pNode_t tail_2) {
	int Length_1 = 0, Length_2 = 0, LengthDifference = 0;				
	//计算数字1和2的长度，比较短的需要在前面补0对齐
	pNode_t p;
	p = head_1;
	while (p != NULL) {
		Length_1++;
		p = p->next;
	}
	p = head_2;
	while (p != NULL) {
		Length_2++;
		p = p->next;
	}
	//补0对齐
	if (Length_1 > Length_2) {											
		LengthDifference = Length_1 - Length_2;
		while (LengthDifference > 0) {
			tailInsert(&head_2, &tail_2, 0);
			LengthDifference--;
		}
	}
	else if (Length_1 < Length_2) {
		LengthDifference = Length_2 - Length_1;
		while (LengthDifference > 0) {
			tailInsert(&head_1, &tail_1, 0);
			LengthDifference--;
		}
	}
	//从末位逐位相加，carry为进位标志，sum为每位的和，超过10则sum-=10并carry=1；pReturnHead存储结果
	pNode_t p_2;
	pNode_t pReturnHead = NULL;
	pNode_t pReturnTail = NULL;
	int carry = 0;
	int sum = 0;
	p = head_1;
	p_2 = head_2;
	while (p != NULL && p_2 != NULL) {
		sum = p->val + p_2->val + carry;
		if (sum >= 10) {
			sum -= 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		headInsert(&pReturnHead, &pReturnTail, sum);
		p = p->next;
		p_2 = p_2->next;
	}
	if (carry == 1) {										//首位需要进位则在前面补1
		headInsert(&pReturnHead, &pReturnTail, 1);
	}
	return pReturnHead;
}

int main() {
	pNode_t head_1 = NULL;
	pNode_t tail_1 = NULL;
	pNode_t head_2 = NULL;
	pNode_t tail_2 = NULL;
	int num = 0;
	printf("输入要插入的数1：");
	while (scanf("%c", &num) != EOF) {
		headInsert(&head_1, &tail_1, num - 48);
	}
	printf("输入要插入的数2：");
	while (scanf("%c", &num) != EOF) {
		headInsert(&head_2, &tail_2, num - 48);
	}

	print_list_for_Big_int_add(Big_int_add(head_1, tail_1, head_2, tail_2));
	
	//tail_1->next = head_1;
	//printf("The tail has linked to head.\n");
	//if_List_is_a_ring(head_1);

	//pNode_t head_2 = NULL;
	//pNode_t tail_2 = NULL;
	//printf("输入要插入的数：");
	//while (scanf("%d", &num) != EOF) {
	//	tailInsert(&head_2, &tail_2, num);
	//}
	/*print_list(mergeList(head_1, head_2));*/

	/*printf("中间节点：%d", findMiddleNode(head_1)->val);*/

	//printf("输入要插入的数：");
	//while (scanf("%d", &num) != EOF) {
	//	tailInsert(&head_2, &tail_2, num);
	//}
	//pNode_t pTest = (pNode_t)calloc(1, sizeof(Node_t));
	//tail_1->next = pTest;
	//pTest->next = tail_2;
	//pNode_t nodeIntersect = if_intersect(head_1, head_2);
	//if (nodeIntersect == NULL) {
	//	printf("不相交\n");
	//}
	//else {
	//	printf("相交,交点的值为%d\n",nodeIntersect->val);
	//}

	//delete_duplicate_val(head_1);
	//print_list(head_1);

	//split_list_to_two_lists(head_1);
	//print_list(split_list[0]);
	//print_list(split_list[1]);

	return 0;
}

