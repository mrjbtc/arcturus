#ifndef LINKED_LIST_H
#define LINKED_LIST_H


namespace NS_LinkedList {

   struct Node {
       int val;
       Node *next;
       Node() : val(0), next(nullptr) {}
       Node(int x) : val(x), next(nullptr) {}
       Node(int x, Node *next) : val(x), next(next) {}
   };

   class LinkedList {
   private:
      Node* node;
   public:
      LinkedList(Node* node): node(node){}
      void print();
      void remove();
      void reverse();
   };

   void test();
}

#endif