

class LRUCache {
private:
    struct node
    {
        int key;
        int val;
        node* prev;
        node* next;

        node(int k , int v) : key(k), val(v) , prev(nullptr), next(nullptr){}

    };
    int currentsize;
    int maxsize;
    node* dummyHead;
    node* dummyTail;
    unordered_map<int,node*>keyToNode;

    void removeNode(node* node)
    {
        node->prev->next=node->next;
        node->next->prev= node->prev;
    }
    void addToHead(node* node)
    {
        node->next=dummyHead->next;
        node->prev=dummyHead;
        dummyHead->next->prev= node;
        dummyHead->next=node;
    }
public:
    LRUCache(int capacity) : currentsize(0),maxsize(capacity){
        dummyHead = new node(0,0);
        dummyTail = new node(0,0);
        dummyHead->next=dummyTail;
        dummyTail->prev= dummyHead;

        
    }
    
    int get(int key) {

        if(keyToNode.find(key)==keyToNode.end())
        {
            return -1;
        }
        node * node = keyToNode[key];
        removeNode(node);
        addToHead(node);

        return node->val;
        
    }
    
    void put(int key, int value) {
        if(keyToNode.find(key)!=keyToNode.end())
        {
            node* node = keyToNode[key];
            removeNode(node);
            node->val=value;
            addToHead(node);
        }
        else
        {
            node* newnode = new node(key,value);
            keyToNode[key]=newnode;
            addToHead(newnode);
            currentsize++;

            if(currentsize> maxsize)
            {
                node* lruNode = dummyTail->prev;
                keyToNode.erase(lruNode->key);
                removeNode(lruNode);
                delete lruNode;
                currentsize--;
            }
        }

        
    }
};
