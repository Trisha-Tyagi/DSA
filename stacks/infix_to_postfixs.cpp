#include <iostream>
#include <string>
#include <cmath>
#define SIZE 100
using namespace std;

char stack[SIZE];
int stack2[SIZE];
int top = -1;
int top2 = -1;

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

    for (int i = 0; i < x.length(); i++) {
        bool flag = true;

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
                            push(x[i]);
                            flag = false;
                        } else {
                            output += stack[top];
                            pop();
                        }
                    } else if (prec(prev_operator) < prec(current_operator)) {
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

    return output;
}

int evaluate(string result){
    for(int i=0;i<result.length();i++){
        if(result[i]=='*' || result[i]=='/' || result[i]=='+' ||result[i]=='-' ||result[i]=='^'){
            int opr1=stack2[top2];
            pop2();
            int opr2=stack2[top2];
            pop2();
            int solution=0;
            switch(result[i]){
                case '*':
                    solution=opr2*opr1;
                    break;
                case '/':
                    solution=opr2/opr1;
                    break;
                case '+':
                    solution =opr2+opr1;
                    break;
                case '-':
                    solution =opr2-opr1;
                    break;
                case '^':
                    solution =pow(opr2,opr1);
                    break;


            }
            push2(solution);

        }
        else{
            push2(result[i]-'0');//convert to int
        }
        
    }
    return stack2[top2];

}

int main() {
    string expression = "a+b*c-d/e^f";
    string result = infix_to_postfix(expression);
    cout << "Postfix Expression: " << result << endl;
    for (int i = 0; i < result.length(); i++) {
        if (isalpha(result[i])) {
            cout << "Enter the value for " << result[i] << ": ";
            int value;
            cin >> value;
            result[i] = value + '0'; //convert to char
        }
    }
    cout << "Prefix Expression after replacement: " << result<< endl;

    
    

    int result2=evaluate(result);
    cout<<"Evaluated result"<<result2<<endl;

    return 0;
}
