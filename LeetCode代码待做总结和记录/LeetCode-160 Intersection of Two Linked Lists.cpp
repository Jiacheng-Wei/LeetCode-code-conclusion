/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //��hashʵ�� 

/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        	return NULL;
        int lenA = 1;
        ListNode* hA = headA;
        while(hA->next != NULL) {
        	lenA ++;
        	hA = hA->next;
        }

        int lenB = 1;
        ListNode* hB = headB;
        while( hB->next != NULL ) {
        	lenB ++;
        	hB = hB->next;
        }

        if(hA != hB) 
        	return NULL;

        hA = headA;
        hB = headB;
        if( lenA > lenB ) {
        	for(int i = 0; i < lenA - lenB; ++i) {
        		hA = hA->next;
        	}
        } else {
        	for(int i = 0; i < lenB - lenA; ++i) {
        		hB = hB->next;
        	}
        }

        while(hA != hB) {
        	hA = hA->next;
        	hB = hB->next;
        }
        return hA;


    }
};
*/ 
//���������������two pointer 
/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        unordered_set<ListNode*> pt_set;
        while(headA || headB) {
            if(pt_set.count(headA)) return headA;
            if(headA) pt_set.insert(headA);
            if(pt_set.count(headB)) return headB;
            if(headB) pt_set.insert(headB);
            headA = headA != NULL ? headA -> next : headA;
            headB = headB != NULL ? headB -> next : headB;
        }
        return NULL;
    }
};
*/ 
//��setģ��ʵ�ֵ�hash���� 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        set<ListNode*> setA;
        while(headA != NULL) {
        	setA.insert(headA);
        	headA = headA->next;
        }
        while(headB != NULL) {
        	if(setA.find(headB)!=setA.end()) return headB;
        	headB = headB->next;
        }
        return NULL;
    }
};
//����hash��Ľ����������ɹ��ˣ�������һ���ǣ���ǰ��֪��find()�����ڲ��Ҳ��ɹ�ʱ���ص���end()��ֵ����һ��֪���ˡ���Ҫһ����������
//��mapģ��ʵ�ֵ�hash���� 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        map<ListNode*,int>  mp;
        while(headA!= NULL) {
        	mp[headA]=1;
        	headA = headA->next;
        }
        while(headB != NULL) {
        	if(mp[headB]==1) return headB;
        	headB = headB->next;
        }
        return NULL;
    }
};
