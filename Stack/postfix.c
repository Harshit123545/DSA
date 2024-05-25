//infix to postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> //isdigit or implicit function
struct stck{
	int top;
	unsigned capacity;
	int* array;
};
//stack operations
struct stck* createStack(unsigned capacity){
	struct stck* stack=(struct stck*)malloc(sizeof(struct stck*));
	if(!stack) return NULL;
	stack->top=-1;
	stack->capacity=capacity;
	stack->array=(int*)malloc(stack->capacity * sizeof(int));
	if(!stack->array) return NULL;
	return stack;
}
//isEmpty
int isEmpty(struct stck* stack) {
	return stack->top==-1;
}
//pop
int pop(struct stck* stack){
	if(!isEmpty(stack)){
		return stack->array[stack->top--];
	}
	return '$';
}
//push
void push(struct stck* stack, int op){
	stack->array[++stack->top]=op;
}
//function that returns value of a given postfix expression
int evaluatePostfix(char* exp){
	//create a stack of capacity equal to expression size
	struct stck* stack=createStack(strlen(exp));
	int i;
	//see if stack was created successfully
	if(!stack) return -1;
	//scan all characters one by one
	for(i=0;exp[i];++i){
		// the scanned character is an operand, push it to the stack.
		if(isdigit(exp[i])) push(stack,exp[i]-'0');  //string is end with null operator'0'
	//if the scanned char is an operator,pop from stack apply the operator
	    else{
	    	int val1=pop(stack);
	    	int val2=pop(stack);
	    	switch(exp[i]){
	    		case '/': push(stack,val2 / val1); break;
	    		case '*': push(stack,val2 * val1); break;
	    		case '+': push(stack,val2 + val1); break;
	    		case '-': push(stack,val2 - val1); break;
			}
		}
	}
	return pop(stack);
}
int main(){
	char exp[]="((9+8)*7+(6*(5+4))*3)+2";
	printf("Postfix evaluation:%d",evaluatePostfix(exp));
	return 0;
}