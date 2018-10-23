
/*
 Lab 2(b): Displaying Queue Behaviours
 Partners: Matan Broner & Timo Bitterli
 Matan rating for Timo: 0
 
 Side note: improper null based return types from Lab 2a Linked List have been fixed.
  --> rather than return null any innapropriate behavior will cause a thrown exception
 */

#include <iostream>
#include "Queue.h"
#include "DerivedCurrencies.h"
using namespace std;
int main(int argc, const char * argv[]) {
    
    cout << "== Welcome to the CIS 22C Queue Program ==" << endl;
    
    Queue<string> stringQueue;
    stringQueue.enqueue("Hello");
    stringQueue.enqueue("CIS22C");
    stringQueue.enqueue("Blorp");
    stringQueue.enqueue("123456789");
    stringQueue.printQueue();
    while(!stringQueue.queueEmpty())
        cout << stringQueue.dequeue() << endl;
    // cout << stringQueue.front() << endl;  // this line causes a thrown exception, empty queue
    
    Queue<int> intQueue;
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    intQueue.enqueue(4);
    intQueue.enqueue(5);
    intQueue.enqueue(6);
    intQueue.enqueue(7);
    intQueue.enqueue(8);
    intQueue.enqueue(9);
    
    while(!intQueue.queueEmpty())
    {
        cout << "intQueue front: " << intQueue.front() << endl;
        intQueue.dequeue();
    }
    
    Queue<Yen> yenQueue;
    yenQueue.enqueue(Yen(12.45));
    yenQueue.enqueue(Yen(45.67));
    yenQueue.enqueue(Yen(100.65));
    yenQueue.enqueue(Yen(1.45));
    cout << "yenQueue rear: " << yenQueue.rear() << endl;
    yenQueue.emptyQueueContents();
    
    // cout << yenQueue.rear() << endl; // this line causes a thrown exception, empty queue
    
   
    return 0;
}

