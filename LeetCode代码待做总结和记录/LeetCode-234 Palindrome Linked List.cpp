//�õ��������׳���Ĳ���������[0.0]��[]���������������ʱһ��Ҫ���� 
//�ⷨһ��ע������ⷨ�ͽⷨ����������Ȼ����һ����������ϸ�ڴ��������ϲ��ܴ��ر��ǵ�һ���ӵ�ʮ�п�ʼ�� 
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
//ע�⻰��λ��ͼ������������ͬ�㷨��ϸ�ڴ����ϵĲ�ͬ�� 
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
/*��������������������followҪ��Could you do it in O(n) time and O(1) space���Ͳ���ʹ��stack�ˣ����Կ��Բ���һ�ַ��������ڱ�����ǰһ��Ķ��к�
�����ζ��з�ת��Ȼ��ǰ���������н��бȽ�*/
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
        while (last->next!=NULL)//�ر�ע�������ת�㷨 
        {
            ListNode *temp=last->next;
            last->next=temp->next;
            temp->next=slow->next;
            slow->next=temp;
        }
        ListNode *pre=head;
        while (slow->next)//�������ѭ�����ж����� 
        {
            slow=slow->next;
            if(slow->val!=pre->val) return false;
            pre=pre->next;
        }
        return true;
    }
};
 
