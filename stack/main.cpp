#include <iostream>
using namespace std;
 class Stack{
        public:

        int *arr;
        int top;
        int size;

        Stack(int size){
            arr = new int[size];
            this->top = -1;
            this->size = size;
            
        }  

        void push(int num){
            if(size - top > 1){
                //space available 
                top++;
                arr[top] = num;
            } else{
                cout << "stack overflow";
            }
        }
        void pop(){
            if(top == -1){
                cout << "stack underflow";
            }else{
                top --;
            }
        }
        int getTop(){
            if(top == -1) {
                return -1;
            }else{
                return arr[top];
            }
        }

        int getSize(){
            if(top == -1){
                return -1;
            }else{
                return top +  1;
            }
        }
        bool isEmpty(){
            if(top == -1){
                return true;
            }else{
                return false;
            }

        }
    };
int main(){
   Stack s(10);
   s.push(10);
   s.push(20);
   s.push(30);
   while (!s.isEmpty())
   {
        cout << s.getTop()<<" ";
        s.pop();
   }
   
    return 0;
}