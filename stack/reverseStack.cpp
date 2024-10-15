#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int topElement = s.top();
    s.pop();
    reverseStack(s);
    //back track
    s.push(topElement);

}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);
    while (!s.empty())
    {
        cout<< s.top() << " ";
        s.pop();
    }
    
    return 0;
}