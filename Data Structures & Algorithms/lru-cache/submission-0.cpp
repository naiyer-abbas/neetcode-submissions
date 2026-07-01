class Node
{
    public:
        int key;
        int val;
        Node *next = NULL;
        Node *prev = NULL;
};



class LRUCache {
public:
    int size = 0;
    int max_size = 0;
    Node *head;
    Node *tail;
    unordered_map <int, Node*> um;
    LRUCache(int capacity) {
        max_size = capacity;
        head = new Node;   
        tail = new Node;
        head -> next = tail;
        tail -> prev = head;
    }

    void insertFront(Node *&node)
    {
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }

    void remove_node(Node *&node)
    {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }
    
    int get(int key) {
        if(um.find(key) == um.end())
            return -1;
        Node* node = um[key];
        if(node -> prev != head)
        {
            remove_node(node);
            insertFront(node);
        }
        return node -> val;
    }
    
    void put(int key, int value) {
        if(um.find(key) == um.end())
        {
            Node *node = new Node;
            node -> key = key;
            node -> val = value;
            um[key] = node;
            insertFront(node);
            if(size == max_size)
            {
                Node *lastNode = tail -> prev;
                remove_node(lastNode);
                um.erase(lastNode->key);
                delete(lastNode);
            }
                
            else
                size ++;
        }

        else
        {
            Node *node = um[key];
            node -> val = value;
            remove_node(node);
            insertFront(node);
        }
    }
};
