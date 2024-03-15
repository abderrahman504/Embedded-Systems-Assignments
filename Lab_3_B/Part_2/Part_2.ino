#include "DataStructures.h"

void setup()
{

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
  Serial.print("Popping from stack. Found");
  Serial.println(stack->pop());
  Serial.print("Stack size = ");
  Serial.println(stack->size());
  Serial.print("Popping from stack. Found");
  Serial.println(stack->pop());
  Serial.print("Stack size = ");
  Serial.println(stack->size());
  Serial.print("Popping from stack. Found");
  Serial.println(stack->pop());
  Serial.print("Stack size = ");
  Serial.println(stack->size());
  Serial.print("Popping from stack. Found");
  Serial.println(stack->pop());
  Serial.print("Stack size = ");
  Serial.println(stack->size());


}

void testing_queue()
{

}

void testing_dynamic_array()
{

}