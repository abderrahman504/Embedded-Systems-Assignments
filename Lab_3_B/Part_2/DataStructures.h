#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <Arduino.h>


namespace DataStructures
{
    class Stack{
        protected:
            int _size;
            int capacity;
            float* arr;

        public:
            Stack(int capacity);
            ~Stack();
            int size();
            bool push(float val);
            float pop();
            float peak();
    };

    class Queue{
        protected:
            int _size;
            int capacity;
            float* arr;
            int head;
        
        public:
            Queue(int capacity);
            ~Queue();
            int size();
            bool enqueue(float val);
            float dequeue();
            float peak();
    };

    class DynamicArray{
        protected:
            int _size;
            int capacity;
            float* arr;
        
        public:
            DynamicArray(int initialCapacity);
            ~DynamicArray();
            int size();
            void add(float val);
            float remove();
            float operator[](int index);
    };

}

#endif