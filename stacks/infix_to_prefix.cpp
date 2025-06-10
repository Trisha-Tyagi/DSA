#include<iostream>
#include <cmath>
#define SIZE 100
#include <string>
#include <algorithm>

using namespace std;

char stack[SIZE];
int stack2[SIZE];
int top = -1;
int top2=-1;


// Function to return precedence of operators
int prec(char x) {
    if (x == '^') {
        return 3;
    } else if (x == '*' || x == '/') {
        return 2;
    } else if (x == '+' || x == '-') {
        return 1;
    } else {
        return -1;
    }
}

// Push element onto the stack
void push(char data) {
    if (top < SIZE - 1) {
        stack[++top] = data;
    } else {
        cout << "Stack overflow!" << endl;
    }
}

void push2(char data) {
    if (top2 < SIZE - 1) {
        stack2[++top2] = data;
    } else {
        cout << "Stack overflow!" << endl;
    }
}

// Pop element from the stack
void pop() {
    if (top > -1) {
        top--;
    } else {
        cout << "Stack underflow!" << endl;
    }
}

void pop2() {
    if (top2 > -1) {
        top2--;
    } else {
        cout << "Stack underflow!" << endl;
    }
}


// Convert infix to postfix based on your logic
string infix_to_postfix(string x) {
    string output = "";

    for (int i = x.length()-1; i >=0; i--) {
        bool flag = true;
        
        if (x[i] == '(') {
            x[i] = ')';
        } else if (x[i] == ')') {
            x[i] = '(';
        }
    

        while (flag) {
            // If the character is an operator
            if (x[i] == '^' || x[i] == '*' || x[i] == '+' || x[i] == '-' || x[i] == '/') {
                if (top == -1 || stack[top]=='(') {
                    push(x[i]);
                    flag = false;
                } else {
                    // Get the previous operator
                    char prev_operator = stack[top];
                    char current_operator = x[i];

                    if (prec(prev_operator) == prec(current_operator)) {
                        if (current_operator == '^') {
                            output += stack[top];
                            pop();
                            
                        } else {
                            push(x[i]);
                            flag = false;
                            
                        }
                    } else if (prec(prev_operator) <prec(current_operator)) {
                        push(x[i]);
                        flag = false;
                    } else if (prec(prev_operator) > prec(current_operator)) {
                        output += stack[top];
                        pop();
                    }
                }
            }
            // If the character is a parenthesis
            else if (x[i] == '(' || x[i] == ')') {
                if (x[i] == '(') {
                    push(x[i]);
                    flag = false;
                } else {
                    while (stack[top] != '(') {
                        output += stack[top];
                        pop();
                    }
                    pop(); // Remove '(' from stack
                    flag = false;
                }
            }
            // If the character is an operand
            else {
                output += x[i];
                flag = false;
            }
        }
    }

    // Pop all remaining elements from the stack
    while (top != -1) {
        output += stack[top];
        top--;
    }
    reverse(output.begin(),output.end());
    return output;

   
    // for(int j=output.length()-1;j>=0;j--){
    //     cout<<output[j];
    // }

}

int evaluate(string result){
    for (int i=result.length()-1;i>=0;i--){
        if(result[i]=='*'|| result[i]=='/'|| result[i]=='+'|| result[i]=='-'|| result[i]=='^'){
            int opr1=stack2[top2];
            pop2();
            int opr2=stack2[top2];
            pop2();
            int solution =0;
            switch(result[i]){
                case '*':
                    solution =opr1*opr2;
                    break;
                case '/':
                    solution =opr1/opr2;
                    break;
                case '+':
                    solution =opr1+opr2;
                    break;
                case '-':
                    solution =opr1-opr2;
                    break;
                case '^':
                    solution =pow(opr1,opr2);
                    break;
            }
            push2(solution);

        }
        else{
            push2(result[i]-'0');
        }

    }
    return stack2[top2];
}

int main() {
    string expression = "a+b*c-d/e^f";
    cout<<"Prefix Expression ";
    string result=infix_to_postfix(expression);
    cout<<result<<endl;
    for(int i=0;i<result.length();i++){
        if(isalpha(result[i])){
            cout<<"Enter the value for "<<result[i]<<": ";
            int replace;
            cin>>replace;
            result[i]=replace+'0';
        }
    }
    cout << "Prefix Expression after replacement: " << result<< endl;


    int value1=evaluate(result);
    cout<<"Evaluated value"<<value1;
    return 0;
}