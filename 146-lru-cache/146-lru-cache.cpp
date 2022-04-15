class LRUCache {
public:
class node
{
    public:
    int key;
    int val;
    node *prev;
    node *next;
    node(int _key,int _val)
    {
        key=_key;
        val=_val;
    }
};

node *head=new node(-1,-1);
node *tail=new node(-1,-1);

int cap=0;
unordered_map<int,node *>map;

LRUCache(int capacity) {
    
    cap=capacity;
    head->next=tail;
    tail->prev=head;
    
}
void deletenode(node *curr)
{
    node *prevnode=curr->prev;
    node *nextnode=curr->next;
    
    prevnode->next=nextnode;
    nextnode->prev=prevnode;
    
}
void addnode(node *curr)
{
    node *temp=head->next;
    curr->next=temp;
    curr->prev=head;
    
    temp->prev=curr;
    head->next=curr;
    
}
int get(int key) {
    
    if(map.find(key)!=map.end())
    {
        node *curr=map[key];
        
        int ans=curr->val;
        
        map.erase(key);
        deletenode(curr);
        addnode(curr);
        map[key]=head->next;
        
        return ans;
    }
    return -1;
}

void put(int key, int value) {
    
    if(map.find(key)!=map.end())
    {
        node *curr=map[key];
        deletenode(curr);
        map.erase(key);
    }
    if(map.size()==cap)
    {
        map.erase(tail->prev->key);
        deletenode(tail->prev);
    }
    addnode(new node(key,value));
    map[key]=head->next;
}
};