#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
    int data;
    Node *next;
};
typedef struct Node NODE;

struct List {
    NODE *first;
    NODE *last;
};
typedef struct List LIST;

void Init(LIST &list);
void input(LIST &list);
void release(LIST &list);
LIST reverse(LIST list);
bool palindromeOrNot(LIST first);
void output(LIST list);
NODE lastNode(LIST list);
void union_(LIST list, LIST);
void difference(LIST, LIST);
void intersect(LIST, LIST);
void Exercise3(LIST&, LIST);
void Exercise4(LIST&);
void delete_(LIST &list, NODE *q);

int main() {
    LIST listFirst;


    Init(listFirst);


    input(listFirst);


//    cout << lastNode(list).data;
//    cout << palindromeOrNot(list);



    output(listFirst);

    release(listFirst);
    release(listFirst);
    return 0;
}





// Exercise 3:

void Exercise3(LIST &listFirst, LIST listSecond) {
    NODE *i;
    for (i = listFirst.first; i != NULL; i = i->next){
        if (i->next == NULL) {
            i->next = listSecond.first;
            return;
        }
    }
}


// determine the last node of the linked list
NODE lastNode(LIST list) {
   for (NODE *i = list.first; i != NULL; i = i->next) {
       if (i->next == NULL) {
           return *i;
       }
   }
}

// check a linked list is palindrome or not
bool palindromeOrNot(LIST first) {

    LIST firstLocal = first;
    LIST reverseList = reverse(first);

    while (firstLocal.first != NULL && reverseList.first != NULL) {
        if (firstLocal.first->data == reverseList.first->data) {
            firstLocal.first = firstLocal.first->next;
            reverseList.first = reverseList.first->next;
        } else
            return false;
    }
    return !(firstLocal.first == NULL && reverseList.first == NULL);

}


// 2. initial linked list
void Init(LIST &l) {
    l.first = l.last = NULL;
}

// create node in linked list
NODE* getNode(int x) { // x la du lieu dua vao data
    NODE* p = new NODE;

    if (p == NULL) {
        return NULL;
    }

    p->data = x; // store x to data
    p->next = NULL; //init the pointer
    return p;
}

// Add the node p to the top of the list
void firstAdd(LIST &list, NODE *p) {
    if (list.first == NULL) {
        list.first = list.last = p;
    } else {
        p->next = list.first; //
        list.first = p;
    }
}


// Add the node p to the end of the list
void lastAdd(LIST &l, NODE *p) {
    if (l.first == NULL) {
        l.first = l.last = p;
    } else {
        l.last->next = p;
        l.last = p;
    }
}

// find max value in linked list
int maxValue(LIST &list) {
    int max = list.first->data;
    for (NODE *i = list.first->next; i != NULL; i = i->next) {
        if (max  < i->data) {
            max = i->data;
        }
    }
    return max;
}


// reverse of the linked list
LIST reverse(LIST listOfParameter) {

    LIST list = listOfParameter;
    NODE *parent = list.first;
    NODE *current = list.first->next;
    list.first = current->next;
    parent->next = NULL;
    current->next = parent;
    while (list.first->next) {
        parent = current;
        current = list.first;
        list.first = list.first->next;
        current->next = parent;
    }
    list.first->next = current;

    return list;
}

// swap 2 integer number
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// swap linked list bubble sort
void sort(LIST &list) {

    for (NODE *i = list.first; i != list.last; i = i->next)
        for (NODE *j = list.first; j != list.last; j = j->next) {
            if (j->data > j->next->data) {
                swap(j->data,j->next->data);
            }
        }

}

// average of the linked list
float average(LIST list) {
    int sum = 0;
    int count = 0;
    for (NODE *i = list.first; i != NULL; i = i->next) {
        sum = sum + i->data;
        count ++;
    }
    return sum/(float)count;
}


// enter data for linked list
void input(LIST &list) {
    int n;
    cout << "enter n: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        // each a loop. create a new node
        int x;
        cout << "enter data: "; cin >> x;
        NODE *p = getNode(x);
        //firstAdd(l,p);
        lastAdd(list,p); // add node p
    }
}

//display list to screen
void output(LIST list) {
    for( NODE *p = list.first; p != NULL;p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
}

// insert q after p
void insert(LIST &list,NODE *q, NODE *p) {
    for (NODE *i = list.first; i != NULL; i = i->next) {
        if (i->data == q->data) {
            p->next = i->next;
            i->next = p;
            return; // end of program
        }
    }
}

// delete first node
void firstDelete(LIST &list) {
    list.first = list.first->next;
}


// delete last node
void lastDelete(LIST &list) {
    int k = 0;
    for (NODE *i = list.first;i != list.last; i = i->next  ) {
        if (i->next == list.last) {
            i->next = NULL;
            i = list.last;
            k = 1;
        }
        if (k == 1) {
            return;
        }
    }
}


// todo: delete node p , after node q
void delete_(LIST &list, NODE *q) {
    for (NODE *i = list.first; i != NULL; i = i->next) {
        if (i->data == q->data) {
            i->next = i->next->next;
            return;
        }
    }
}

// release pointer in linked list
void release(LIST &list) {
    NODE *p;
    while (list.first) {
        p = list.first;
        list.first = list.first->next;
        delete p;
    }
}

// todo : find data in linked list
bool find(LIST l, int data) {
    for (NODE *i = l.first; i != NULL; i = i->next) {
        if (i->data == data) {
            return true;
        }
    }
    return false;
}


// count node in linked list
int countNode(LIST list) {
    int count = 0;
    for (NODE *i = list.first; i != NULL; i = i->next) {
        count ++;
    }
    return count;
}

// display the intersection of 2 linked list
void intersect(LIST list1, LIST list2) {
    for (NODE *i = list1.first; i != NULL; i = i->next) {
        if (find(list2,i->data)) cout << setw(3) <<i->data;
    }
}

// display the union of 2 linked list
void union_(LIST listFirst, LIST listSecond) {
    for (NODE *i = listFirst.first; i != NULL; i = i->next) {
        cout << setw(2) << i->data;
    }
    for (NODE *i =listSecond.first; i != NULL;  i = i->next) {
        cout << setw(2) << i->data;
    }
}

// display the Difference of 2 linked list
void difference(LIST listFirst, LIST listSecond) {
    for (NODE *i = listFirst.first; i != NULL; i = i->next) {
        if (find(listSecond,i->data))
            continue;
        else {
            cout << setw(2) << i->data;
        }
    }
}


// compare two linked list
bool compare(LIST list1, LIST list2) {

    while (list1.first && list2.first) {
        if (list1.first->data == list2.first->data) {
            list1.first = list1.first->next;
            list2.first = list2.first->next;
        } else
            return false;
    }
    return list1.first == NULL && list2.first == NULL;
}

