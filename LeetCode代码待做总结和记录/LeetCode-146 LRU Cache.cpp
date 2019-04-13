/*
����Ĵ����Ǿ��ǹ���һ������LRU�㷨�Ļ��档��νLRU�㷨���ǣ�������δʹ�õ���˼��ע������㷨��
����ϵͳ�е��ڴ�ҳ���û��㷨�����������˼���ǣ��ڸ���һ���޶���С�Ŀռ�ǰ���£����һ��ԭ�������
���ºͷ���Ԫ�ء�
��������˼·�ǣ�hash��+˫���б�
Ϊʲô��ʹ�������ʱ����������ˣ�˼·�Ǻܼ򵥵ģ�������Ҫ��ͣ��ά��������ķ���ʱ����������ڲ���
�����Լ���������ʱ��ʱ�临�Ӷȶ���O(n)��
Ϊʲô��ʹ��hash����б��ˣ�ԭ������ɾ����������һ�����ʱ��ʱ�临�Ӷ��Ǻܸߵģ���Ҫ����������� 
�ڲ����к����׳�ʱ�� ʱ�临�Ӷ�ΪO(n)�� 
���Ϸ��������Կ���Ҫ����ʱ�临�Ӷ�ΪO(1)��ֻ��ʹ��hash���˫���б�
��Ҫע�����������˫���б������ѭ��˫���б� 
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
        else{//��map�в���
            map<int,Node*>::iterator it=mp.find(key);
            if(it==mp.end()){//������û�иýڵ�
                if(count==size){//�������˵����
                    if(head==tail&&head!=NULL){//ֻ��һ�����
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
                else {//û���������
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
 //��ʵ��STL�е�list����һ��˫���������ϣ�������̵㣬������list��ʵ�֣� 
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
        if(it==mp.end())      //û������
        {
            return -1;
        }
        else  //��cache��������
        {
            list<Node>::iterator listIt = mp[key];
            Node newNode;
            newNode.key = key;
            newNode.value = listIt->value;
            cacheList.erase(listIt);               //��ɾ�����еĽڵ�      
            cacheList.push_front(newNode);   //�����еĽڵ�ŵ�����ͷ��
            mp[key] = cacheList.begin();
        }
        return cacheList.begin()->value;
    }
     
    void set(int key, int value) {
        map<int, list<Node>::iterator >::iterator it = mp.find(key);
        if(it==mp.end())   //û������
        {
            if(cacheList.size()==maxSize)  //cache����
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
        else  //����
        {
            list<Node>::iterator listIt = mp[key];
            cacheList.erase(listIt);               //��ɾ�����еĽڵ�          
            Node newNode;
            newNode.key = key;
            newNode.value = value;
            cacheList.push_front(newNode);   //�����еĽڵ�ŵ�����ͷ��
            mp[key] = cacheList.begin();
        }
    }
};
