struct SinglyLinkedList {
    int val;
    SinglyLinkedList *next;
    SinglyLinkedList(int x): val(x), next(NULL){}  
};

class MyLinkedList {
private:
    SinglyLinkedList *head = NULL;

public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        
        // cout << "Get from index " << index << endl;
        // print();
        int idx = 0;
        SinglyLinkedList *curr = head;
        while (curr != NULL) {
            
            if (index == idx) {
                break;
            }
            idx++;
            curr = curr->next;
        }
        
       
        if (curr != NULL) {
            return curr->val;     
        }
        return -1;
    }
    
    void addAtHead(int val) {
        SinglyLinkedList *node = new SinglyLinkedList(val);
        node->next = head;
        head = node;
        // cout << "Add " << val << " to head" << endl;
        // print();
    }
    
    void addAtTail(int val) {
        SinglyLinkedList *node = new SinglyLinkedList(val);
        SinglyLinkedList *curr = head;
        SinglyLinkedList *prev = NULL;
        while (curr != NULL) {
            prev = curr;
            curr = curr->next;
        }
        if (prev != NULL) {
            prev->next = node;
        } else {
            head = node;
        }
        // cout << "Add " << val << " to tail" << endl;
        // print();
    }
    
    void addAtIndex(int index, int val) {
        // cout << "before add [" << index << "] " << val << endl;
        // print();
        int len = 0;
        
        SinglyLinkedList *curr = head;
        while (curr != NULL) {
            len++;
            curr = curr->next;
        }
        if (index > len) {
            return;
        }
        curr = head;
        int idx = 0;
        SinglyLinkedList *prev = NULL;
        while (curr != NULL) {
            if (index == idx) {
                break;
            }
            prev = curr;
            idx++;
            curr = curr->next;
        }
        
        //cout << prev->val << endl;
        SinglyLinkedList *node = new SinglyLinkedList(val);
        if (prev != NULL) {
            node->next = prev->next;
            prev->next = node;
        } else {
            node->next = head;
            head = node;
        }
        // cout << "after add" << endl;
        // print();
    }
    
    void print()
    {
        SinglyLinkedList *curr = head;
        while(curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    void deleteAtIndex(int index) {
        // cout << "before delete" << endl;
        // print();
        int idx = 0;
        SinglyLinkedList *curr = head;
        SinglyLinkedList *prev = NULL;
        while (curr != NULL) {
            if (index == idx) {
                break;
            }
            idx++;
            prev = curr;
            curr = curr->next;
        }
        
        
        if (prev != NULL) {
            if (prev->next != NULL) {
                prev->next = prev->next->next; 
            }
        } else {
            head = head->next;
        }
        // cout << "after delete" << endl;
        // print();
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */