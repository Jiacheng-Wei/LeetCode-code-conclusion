//该道题最容易出错的测试用例是[0.0]和[]的情况，做题遇到时一定要考虑 
//解法一：注意这个解法和解法二的区别，虽然方法一样，但是在细节处理问题上差别很大。特别是第一个从第十行开始。 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        stack<int> s;
        s.push(head->val);
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            s.push(slow->val);
        }
        if (!fast->next) s.pop();
        while (slow->next) {
            slow = slow->next;
            int tmp = s.top(); s.pop();
            if (tmp != slow->val) return false;
        }
        return true;
    }
};
//注意话四位导图来区分两个相同算法在细节处理上的不同。 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        stack<int> s;
        while (fast->next!=NULL&&fast->next->next!=NULL)
        {
            s.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if (fast->next!=NULL) s.push(slow->val);
        slow=slow->next;
        while (slow!=NULL)
        {
            int temp=s.top();
            if (temp!=slow->val) return false;
            slow=slow->next;
            s.pop();
        }
        return true;
    }
};
/*方法二：由于在题中有follow要求：Could you do it in O(n) time and O(1) space。就不能使用stack了，所以可以采用一种方法，即在遍历完前一半的队列后，
将后半段队列翻转，然后将前后两个队列进行比较*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        stack<int> s;
        while (fast->next!=NULL&&fast->next->next!=NULL)
        {
            s.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *last=slow->next; 
        while (last->next!=NULL)//特别注意这个翻转算法 
        {
            ListNode *temp=last->next;
            last->next=temp->next;
            temp->next=slow->next;
            slow->next=temp;
        }
        ListNode *pre=head;
        while (slow->next)//还有这个循环的判断条件 
        {
            slow=slow->next;
            if(slow->val!=pre->val) return false;
            pre=pre->next;
        }
        return true;
    }
};
 
