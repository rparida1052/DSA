#include<iostream>
using namespace std;
#include<stack>


void solve(stack<int> &s,int target){
    //bc
    if(s.empty()){
        s.push(target);
        return;
    }

    int top = s.top();
    s.pop();

    //RE 
    solve(s,target);

    //backtracking
    s.push(top);
}

void insertAtBottom(stack<int> &s){
    if(s.empty()){
        cout << "stack is empty";
        return;
    }

    int target = s.top();
    s.pop();
    solve(s, target);
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    insertAtBottom(s);

    while (!s.empty())  
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}