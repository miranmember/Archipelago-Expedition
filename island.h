#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

class Node{
    private:
        int island;
        Node * next;

    public:
        //Constructor
        Node(int val){ 
            island = val;
            next = NULL;
        }

        Node(int val, Node* nxt){   
            island = val;
            next = nxt;
        }

  
        int getIsland(){
            return island;
        }

    
        Node * getNext(){
            return next;
        }

        void setIsland(int val){
            island = val;
        }

        void setNext(Node* nxt){
            next = nxt;
        }

};

class MyList{
    private:
        Node* head;
				Node* tail;
    public:

        MyList(){
            head = NULL;
        }

				Node *getHead() {
					return head;
				}

				void setHead(Node *tmp) {
					head = tmp;
				}

				Node *getTail() {
					return tail;
				}

				void setTail(Node *tmp) {
					tail = tmp;
				}

        virtual void insert(int val){
           
            Node* temp = new Node(val, NULL);
            Node* curr = head;
            Node* prev = NULL; 

            while(curr!= NULL){
                if(curr->getIsland() == val){
                    printf("Ferry ride already added!\n");
                    return;
                }
                prev = curr; 
                curr = curr->getNext();
            }
            if(prev == NULL){
                head = temp; 
            }
            else{
                prev->setNext(temp) ; 
            }
         
        }

        virtual void remove(int v1){
  
            Node * curr = head;
            Node * prev = NULL;
            while(curr != NULL && curr->getIsland() != v1){
                prev = curr;
                curr = curr->getNext();
            }
            if(curr == NULL){
                printf("Ferry ride does not exist\n");
                return;
            }
            //if node to delete is at head of list
            if(prev == NULL){
                prev = curr->getNext();
                delete curr;
                head = prev;
            }
       
            else{
                prev->setNext(curr->getNext());
                delete curr;
            }
        }

        int getListLength(){
            int total = 0;
            Node* tmp = head;

            while(tmp != NULL){
                total++;
                tmp = tmp->getNext();
            }

            return total;
        }

        int getNthElem(int n){
            int curr = 0;
            Node * temp = head;
            while(temp != NULL && curr != n){
                curr++;
                temp = temp->getNext();
            }

            if(temp == NULL)
                return -999;

            else{
                return temp->getIsland();
            }
        }

        void printList(){
            Node* temp = head;
            while(temp != NULL){
                printf("%d  ", temp->getIsland());
                temp = temp->getNext();
            }
        }


};


class Island{
    private:
        MyList *adjacent;
        bool visited;
				int previousLocation;
    public:
        Island(){
            adjacent = new MyList;
            visited = false;
        }

        MyList* getAdjacent(){
            return adjacent;
        }

        bool getVisited(){
            return visited;
        }

				int getpreviousLocation () {
					return previousLocation;
				}

				void setpreviousLocation(int x) {
					previousLocation = x;
				}
        void setVisited(bool status){
            visited = status;
        }
        
};

class IslandQueue : public MyList {
	public:
		IslandQueue () {
			setHead(nullptr);
			setTail(nullptr);
		}

		void pop() {
			if (getHead() != nullptr) {
				Node *tmp = getHead();
				if (tmp->getNext() == nullptr) {
					setHead(nullptr);
					setTail(nullptr);
					return;
				}
				setHead(tmp->getNext());
				delete tmp;
			}
		}

		int front() {
			return getHead()->getIsland();
		}

		void push(int x) {
			Node *tmp = new Node(x);
			if (getHead() == nullptr) {
				setHead(tmp);
				setTail(tmp);
				return;
			}

			getTail()->setNext(tmp);
			setTail(tmp);
		}

		bool empty() {
			if (getHead() == nullptr) {
				return true;
			}
			return false;
		}

		void clear() {
			Node *current = getHead();
			Node *next = nullptr;
			while(current != nullptr) {
				next = current->getNext();
				delete current;
				current = next;
			}
		}
};

class Stack : public MyList {
	public:
		Stack() {
			setHead(nullptr);
			setTail(nullptr);
		}

		void pop() {
			if (getHead() != nullptr) {
				Node *tmp = getHead();
				setHead(tmp->getNext());
				delete tmp;
			}
		}

		void push(int x) {
			Node *tmp = new Node(x);
			if (getHead() == nullptr) {
				setHead(tmp);
				tmp->setNext(nullptr);
				return;
			}

			tmp->setNext(getHead());
			setHead(tmp);
		}

		int top() {
			return getHead()->getIsland();
		}

		int size() {
			return getListLength();
		}

		bool empty() {
			if (getHead() == nullptr) {
				return true;
			}
			return false;
		}

		void clear() {
			Node *current = getHead();
			Node *next = nullptr;
			while(current != nullptr) {
				next = current->getNext();
				delete current;
				current = next;
			}
		}
};

class File {
	private:
		string T;
		File *Next;
	public:
		void setNext(File *x) {
			Next = x;
		}

		File(string x) {
			T = x;
			Next = nullptr;
		}

		File* getNext() {
			return Next;
		}

		string getName() {
			return T;
		}
};

class FileList {
	private:
		File *head;
		File *Tail;
	public:
		FileList() {
			head = nullptr;
			Tail = nullptr;
		}

		void push(string x) {
			File *tmp = new File(x);
			tmp->setNext(head);
			head = tmp;
		}

		void remove(string v1){
            File * curr = head;
            File * prev = NULL;
            while(curr != NULL && curr->getName() != v1){
                prev = curr;
                curr = curr->getNext();
            }
            if(curr == NULL){
                printf("File does not exist\n");
                return;
            }
            if(prev == NULL){
                prev = curr->getNext();
                delete curr;
                head = prev;
            }
       
            else{
                prev->setNext(curr->getNext());
                delete curr;
            }
        }

		void clear() {
			File *current = head;
			File *next = nullptr;
			while(current != nullptr) {
				next = current->getNext();
				delete current;
				current = next;
			}
		}

		bool inUse(string x) {
			File * cur = head;
			while (cur != nullptr) {
				if (cur->getName() == x) {
					return true;
				}
				cur = cur->getNext();
			}
			return false;
		}
};