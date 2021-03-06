#include <iostream>
#include <iterator>
#include <list>
using namespace std;
template <typename T>
class Deque {
    // construct an empty deque
    struct Node {
        T data;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
public:
    Deque() {
        _head = _tail;
        _tail = nullptr;
        _head = nullptr;
    }

    // is the deque empty?
    bool isEmpty() const {
        return (_head == nullptr);
    }

    // return the number of items on the deque
    int size() const{
        if (isEmpty()) {
            return 0;
        }
        int count = 1;
        Node* runner = _head;
        while (runner != _tail) {
            count++;
            runner = runner->next;
        };
        return count;
    }
    T getFront() const {
        if (isEmpty()) {
            return -1;
        }
        return _head->data;
    }
    T getRear() const {
        if (isEmpty()) {
            return -1;
        }
        return _tail->data;
    }
    // add the item to the front
    void addFirst(T n) {
        Node* newFirst = new Node();
        newFirst->data = n;
        if (isEmpty()) {
            _head = newFirst;
            _tail = newFirst;
        }
        _head->prev = newFirst;
        newFirst->next = _head;
        _head = _head->prev;
        
    }

    // add the item to the back
    void addLast(T n) {
        Node* newLast = new Node();
        newLast->data = n;
        if (isEmpty()) {
            _head = newLast;
            _tail = newLast;
        }
        _tail->next = newLast;
        newLast->prev = _tail;
        _tail = _tail->next;
    }

    // remove and return the item from the front
    void  removeFirst() {
        auto temp = _head;
        _head = _head->next;
        _head->prev = nullptr;
        free(temp);
    }

    // remove and return the item from the back
    void  removeLast() {
        auto temp = _tail;
        _tail = _tail->prev;
        _tail->next = nullptr;
        free(temp);
    }

    // return an iterator over items in order from front to back
    /*Iterator<T> iterator() {

    }*/
private:
    Node* _head;
    Node* _tail;
};
void test1() {
    Deque<int>* test = new Deque<int>;
    test->addLast(5);
    test->addLast(10);
    cout << test->getRear() << endl;
    test->removeLast();
    cout << test->getRear() << endl;
    test->addFirst(15);
    cout << test->getFront() << endl;
    cout << test->size() << endl;
    test->removeFirst();
    cout << test->getFront() << endl;
    cout << test->size() << endl;
}
void test2() {
    Deque<char>* test = new Deque<char>;
    test->addLast('a');
    test->addLast('b');
    cout << test->getRear() << endl;
    test->removeLast();
    cout << test->getRear() << endl;
    test->addFirst('c');
    cout << test->getFront() << endl;
    cout << test->size() << endl;
    test->removeFirst();
    cout << test->getFront() << endl;
    cout << test->size() << endl;
}
void main()
{
    test2();
}

