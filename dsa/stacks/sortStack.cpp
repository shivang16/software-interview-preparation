#include <bits/stdc++.h>
void insert(stack <int> &stack, int el){
	if(stack.empty()){
		stack.push(el);
		return;
	}
	int tp = stack.top();
	if(el>=tp){
		stack.push(el);
		return;
	}
	stack.pop();
	insert(stack,el);
	stack.push(tp);
} 
void sortStack(stack<int> &stack)
{
	if(stack.empty())
		return;
	int el = stack.top();
	stack.pop();
	sortStack(stack);
	insert(stack,el);
	// Write your code here
}