#include<stdio.h>
#define MAX 2^32
//top point at the index in the stack top
typedef struct{
    int data[MAX];
    int top;
}Stack;

void initStack(Stack *s){
    s->top=-1;
}

bool isEmpty(Stack *s){
    return s->top==-1;
}
int size(Stack*s){
    return s->top+1;
}

bool push(Stack*s,int x){
    if(s->top==MAX-1){
        return false;
    }
    s->data[++s->top]=x;//extend stack and store value
    return true;
}

bool pop(Stack*s,int *val){
    if(isEmpty(s))return false;
    *val=s->data[s->top--];//pop stack and return the stack point
    return true;
}

bool peek(Stack*s,int *val){
    if(isEmpty(s))return false;
    *val=s->data[s->top];//only read not move
    return true;
}

//application
//compiler find {[()]} is it match?
bool isValidBrackets(const char *str){
    Stack s;
    initStack(&s);
    for(int i=0;str[i]!='/0';i++){
        char ch=str[i];
        //
        if(ch=='('||ch=='['||ch=='{'){
            push(&s,ch);
        }
        else if(ch=='}'||ch==']'||ch==')'){
            int topval;
            if(isEmpyt(&s))return false;
            pop(&s,&topval);
            if(!isMatchingPair((char)topval,ch)){
                return false;//type not mismatch
            }
        }
    }
    return isEmpty(&s);//end stack is empty
}