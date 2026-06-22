#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(int d): data(d) ,next(nullptr) {}
    void pop(){
        node* temp = this;
        if(next) next->pop();
        delete temp;
    }

};

class queue{
    private:
        node* fron;
        node* rea;
        int siz;
    public:
        queue(): fron(nullptr),rea(nullptr),siz(0) {}
        ~queue() { fron->pop(); }
        void push(int d){
            node* newNode = new node(d);
            if(rea) rea->next = newNode;
            rea = newNode;
            if(!fron) fron = rea;
            siz++;
        }
        void pop(){
            node* temp = fron;
            if(fron) fron = fron->next;
            else rea = nullptr;
            delete temp;
            siz--;
        }
        int front(){
            if(fron) return fron->data;
            return -1;
        }
        int rear(){
            if(rea) return rea->data;
            return -1;
        }
        int size() const { return siz; }
        int empty(){
            fron->pop();
            fron = rea = nullptr;
            return siz==0;
        }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Front: " << q.front() << endl; // Front: 1
    cout << "Rear: " << q.rear() << endl;   // Rear: 3
    cout << "Size: " << q.size() << endl;   // Size: 3
    q.pop();
    cout << "Front after pop: " << q.front() << endl; // Front after pop: 2
    cout << "Size after pop: " << q.size() << endl;   // Size after pop: 2
    return 0;
}