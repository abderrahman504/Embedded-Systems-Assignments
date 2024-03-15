#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

namespace DataStructures
{
    template<class T> class Stack{
        protected:
            int size;
            int capacity;
            T* arr;

        public:
            Stack(int capacity);
            ~Stack();
            int size();
            bool push(T val);
            T pop();
            T peak();
    };

    template<class T> class Queue{
        protected:
            int size;
            int capacity;
            T arr[];
            int head;
        
        public:
            Queue(int capacity);
            ~Queue();
            int size();
            bool enqueue(T val);
            T dequeue();
            T peak();
    };

    template<class T> class DynamicArray{
        protected:
            int size;
            int capacity;
            T arr[];
        
        public:
            DynamicArray(int initialCapacity);
            ~DynamicArray();
            int size();
            void add(T val);
            T remove();
            T operator[](int index);
    };

}

#endif