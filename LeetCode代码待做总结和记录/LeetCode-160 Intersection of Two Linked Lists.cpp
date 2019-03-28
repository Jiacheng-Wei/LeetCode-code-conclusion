/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //用hash实现 

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
//下面这个方法很像two pointer 
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
//用set模板实现的hash查找 
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
//类似hash表的解决方案总算成功了，卡到的一点是，以前不知道find()函数在查找不成功时返回的是end()的值，这一下知道了。主要一点就是这个。
//用map模板实现的hash查找 
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
