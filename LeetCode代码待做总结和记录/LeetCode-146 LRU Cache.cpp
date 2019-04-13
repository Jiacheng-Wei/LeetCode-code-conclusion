/*
此题的大意是就是构造一个基于LRU算法的缓存。所谓LRU算法就是，最近最久未使用的意思。注意这个算法和
操作系统中的内存页面置换算法相近。核心意思都是，在给定一个限定大小的空间前提下，设计一个原则如何来
更新和访问元素。
解这道题的思路是：hash表+双向列表。
为什么不使用添加了时间戳的数组了？思路是很简单的，但是需要不停的维护数据项的访问时间戳。另外在插入
数据以及访问数据时，时间复杂度都是O(n)。
为什么不使用hash表和列表了？原因是在删除链表的最后一个结点时，时间复杂度是很高的，需要遍历真个链表 
在测试中很容易超时。 时间复杂度为O(n)。 
综上分析，可以看出要满足时间复杂度为O(1)，只能使用hash表和双向列表。
需要注意的是这里是双向列表而不是循环双向列表。 
*/ 
class Node{
public:
    int key;
    int value;
    Node *pre;
    Node *next;
    Node(int k,int v){
        key=k;
        value=v;
        pre=NULL;
        next=NULL;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {
        count=0;
        size=capacity;
        head=NULL;
        tail=NULL;
    }
    void pushFront(Node* c){
        if(count==1){
            return;
        }
        if(c==head){
            return;
        }
        if(c==tail){
            tail=c->pre;
        }
        c->pre->next=c->next;
        if(c->next!=NULL) c->next->pre=c->pre;
        c->next=head;
        c->pre=NULL;
        head->pre=c;
        head=c;
    }
    
    int get(int key) {
        if(head==NULL){
            return -1;
        }
        map<int,Node*>::iterator it=mp.find(key);
        if(it==mp.end()){
            return -1;
        }
        else{
            Node *p=it->second;
            pushFront(p);
        }
        return head->value;
    }
    
    void put(int key, int value) {
        if(head==NULL){
            head=new Node(key,value);
            mp[key]=head;
            tail=head;
            count++;
        }
        else{//在map中查找
            map<int,Node*>::iterator it=mp.find(key);
            if(it==mp.end()){//链表中没有该节点
                if(count==size){//链表满了的情况
                    if(head==tail&&head!=NULL){//只有一个结点
                        mp.erase(head->key);
                        head->key=key;
                        head->value=value;
                        mp[key]=head;
                    }
                    else{
                        Node* p=tail;
                        tail->pre->next=tail->next;
                        tail=tail->pre;
                        mp.erase(p->key);
                        p->key=key;
                        p->value=value;
                        p->next=head;
                        p->pre=head->pre;
                        head->pre=p;
                        head=p;
                        mp[head->key]=head;
                    }
                }
                else {//没有满的情况
                    Node* p=new Node(key,value);
                    p->next=head;
                    p->pre=NULL;
                    head->pre=p;
                    head=p;
                    mp[head->key]=head;
                    count++;
                    
                }
            }
            else {
                Node *p=it->second;
                p->value=value;
                pushFront(p);
            }
        }
    }
private:
    int count;
    int size;
    map<int,Node*> mp;
    Node* head;
    Node* tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 //其实在STL中的list就是一个双向链表，如果希望代码简短点，可以用list来实现： 
 struct Node
{
    int key;
    int value;
};
 
 
class LRUCache{
private:
    int maxSize ;
    list<Node> cacheList;
    map<int, list<Node>::iterator > mp;
public:
    LRUCache(int capacity) {
      maxSize = capacity;
    }
     
    int get(int key) {
        map<int, list<Node>::iterator >::iterator it = mp.find(key);
        if(it==mp.end())      //没有命中
        {
            return -1;
        }
        else  //在cache中命中了
        {
            list<Node>::iterator listIt = mp[key];
            Node newNode;
            newNode.key = key;
            newNode.value = listIt->value;
            cacheList.erase(listIt);               //先删除命中的节点      
            cacheList.push_front(newNode);   //将命中的节点放到链表头部
            mp[key] = cacheList.begin();
        }
        return cacheList.begin()->value;
    }
     
    void set(int key, int value) {
        map<int, list<Node>::iterator >::iterator it = mp.find(key);
        if(it==mp.end())   //没有命中
        {
            if(cacheList.size()==maxSize)  //cache满了
            {
                mp.erase(cacheList.back().key);    
                cacheList.pop_back();
            }
            Node newNode;
            newNode.key = key;
            newNode.value = value;
            cacheList.push_front(newNode);
            mp[key] = cacheList.begin();
        }
        else  //命中
        {
            list<Node>::iterator listIt = mp[key];
            cacheList.erase(listIt);               //先删除命中的节点          
            Node newNode;
            newNode.key = key;
            newNode.value = value;
            cacheList.push_front(newNode);   //将命中的节点放到链表头部
            mp[key] = cacheList.begin();
        }
    }
};
