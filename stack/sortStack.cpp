#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }

    if(s.top() >= target){
        s.push(target);
        return;
    }
    int topEle = s.top();
    s.pop();

    insertSorted(s,target);

    //backtrack
    s.push(topEle);
}

void sortedStack(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }
    int topEle = s.top();
    s.pop();

    //Recursion call
    sortedStack(s);

    insertSorted(s,topEle);
}
int main(){
    stack<int> s;
    s.push(20);
    s.push(10);
    s.push(30);
    s.push(60);
    s.push(50);

    sortedStack(s);

    while(!s.empty()){
        cout<< s.top() <<" ";
        s.pop();
    }
    return 0;
}