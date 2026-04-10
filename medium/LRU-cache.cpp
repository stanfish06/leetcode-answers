#include <unordered_map>
#include <iostream>
using namespace std;

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
};

class LinkedList {
public:
    LinkedList(int key, int value) {
        push_back(key, value);
    }

    Node* push_back(int key, int value) {
        Node* new_node = new Node();
        new_node->key = key;
        new_node->value = value;
        new_node->prev = this->tail;
        new_node->next = nullptr;
        if (this->tail != nullptr) this->tail->next = new_node;
        this->tail = new_node;
        if (this->head == nullptr) this->head = new_node;
        return new_node;
    }

    void move_node_to_back(Node* to_move) {
        if (to_move == nullptr) return;
        if (to_move == this->tail) return;
        if (to_move->prev != nullptr) to_move->prev->next = to_move->next;
        if (to_move->next != nullptr) to_move->next->prev = to_move->prev;
        if (this->tail != nullptr && to_move != this->tail) this->tail->next = to_move;
        Node* old_tail = this->tail;
        this->tail = to_move;
        if (old_tail != to_move) {
            to_move->prev = old_tail;
        }
        if (to_move == this->head) {
            if (to_move->next != nullptr) {
                this->head = to_move->next;
            }
        }
        to_move->next = nullptr;
    }

    Node* get_head() {
        return this->head;
    }

    int remove_head() {
        if (head == nullptr) return -1;
        
        Node* new_head = this->head->next;
        if (this->tail == this->head) {
            this->tail = nullptr;
        }
        int head_key = this->head->key;
        delete this->head;
        this->head = new_head;
        if (new_head != nullptr)
            new_head->prev = nullptr;
        return head_key;
    }
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* current = nullptr;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->count = 0;
        this->capacity = capacity;
        this->data = {};
    }
    
    int get(int key) {
        if (this->data.contains(key)) {
            this->lookup->move_node_to_back(this->data[key]);
            return this->data[key]->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (this->lookup == nullptr) {
            if (this->capacity > 0) {
                this->lookup = new LinkedList(key, value);
                Node* first = this->lookup->get_head();
                this->data[key] = first;
                this->count=1;
            }
        } else {
            if (this->data.contains(key)) {
                this->lookup->move_node_to_back(data[key]);
                this->data[key]->value = value;
            } else {
                if (this->count == this->capacity) {  
                    int key_delete = this->lookup->remove_head();
                    if (key_delete != -1) this->data.erase(key_delete);
                    this->count--;
                    
                } 
                Node* new_node = this->lookup->push_back(key, value);
                this->data[key] = new_node;
                this->count++;
            }
        }
    }
private:
    unordered_map<int, Node*> data;
    LinkedList* lookup = nullptr; 
    int count;
    int capacity;
};

int main() {
    LRUCache lru = LRUCache(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;
    lru.put(3, 3);
    cout << lru.get(2) << endl;
    lru.put(4, 4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
