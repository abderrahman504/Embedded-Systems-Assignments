#include "DataStructures.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Is this working?!");
  testing_stack();
  testing_queue();
  testing_dynamic_array();
}

void loop() {
  
  
}

void testing_stack()
{
  Serial.println("Creating stack with capacity 5.");
  DataStructures::Stack* stack = new DataStructures::Stack(5);
  Serial.print("Stack size = ");
  Serial.println(stack->size());
  Serial.println("Pushing 1 to stack.");
  stack->push(1);
  Serial.println("Pushing 5 to stack.");
  stack->push(5);
  Serial.println("Pushing 3 to stack.");
  stack->push(3);
  Serial.print("Stack size = ");
  Serial.println(stack->size());
  Serial.print("Peeking in stack. Found ");
  Serial.println(stack->peak());
  Serial.print("Stack size = ");
  Serial.println(stack->size());
  Serial.print("Popping from stack. Found ");
  Serial.println(stack->pop());
  Serial.print("Stack size = ");
  Serial.println(stack->size());
  Serial.print("Popping from stack. Found ");
  Serial.println(stack->pop());
  Serial.print("Stack size = ");
  Serial.println(stack->size());
  Serial.print("Popping from stack. Found ");
  Serial.println(stack->pop());
  Serial.print("Stack size = ");
  Serial.println(stack->size());
  Serial.println("Finished testing stack\n\n");
}

void testing_queue()
{
  Serial.println("Creating queue with capacity 5.");
  DataStructures::Queue* queue = new DataStructures::Queue(5);
  Serial.print("Queue size = ");
  Serial.println(queue->size());
  Serial.println("Pushing 1 to queue.");
  queue->enqueue(1);
  Serial.println("Pushing 5 to queue.");
  queue->enqueue(5);
  Serial.println("Pushing 3 to queue.");
  queue->enqueue(3);
  Serial.print("Queue size = ");
  Serial.println(queue->size());
  Serial.print("Peeking in queue. Found ");
  Serial.println(queue->peak());
  Serial.print("Queue size = ");
  Serial.println(queue->size());
  Serial.print("Removing from Queue. Found ");
  Serial.println(queue->dequeue());
  Serial.print("Queue size = ");
  Serial.println(queue->size());
  Serial.print("Removing from Queue. Found ");
  Serial.println(queue->dequeue());
  Serial.print("Queue size = ");
  Serial.println(queue->size());
  Serial.print("Removing from Queue. Found ");
  Serial.println(queue->dequeue());
  Serial.print("Queue size = ");
  Serial.println(queue->size());
  Serial.println("Finished testing queue\n\n");
}

void testing_dynamic_array()
{
  Serial.println("Creating dynamic array with initial capacity 3");
  DataStructures::DynamicArray* list = new DataStructures::DynamicArray(3);
  Serial.print("Array size = ");
  Serial.println(list->size());
  Serial.println("Adding 13 to array");
  list->add(13);
  Serial.print("Array size = ");
  Serial.println(list->size());
  Serial.println("Adding 11.67 to array");
  list->add(11.67);
  Serial.print("Array size = ");
  Serial.println(list->size());
  Serial.println("Adding 5 to array");
  list->add(5);
  Serial.print("Array size = ");
  Serial.println(list->size());
  Serial.println("Adding 46 to array");
  list->add(46);
  Serial.print("Array size = ");
  Serial.println(list->size());
  Serial.println("Accessing array elements");
  Serial.print("Index 0: ");
  Serial.println((*list)[0]);
  Serial.print("Index 1: ");
  Serial.println((*list)[1]);
  Serial.print("Index 2: ");
  Serial.println((*list)[2]);
  Serial.print("Index 3: ");
  Serial.println((*list)[3]);
  Serial.println("Removing last element");
  list->remove();
  Serial.print("Array size = ");
  Serial.println(list->size());
}