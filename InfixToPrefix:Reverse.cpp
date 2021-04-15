//
//  
//  61hw-1
//
//  Created by Patrick Brennan on 4/11/18.
//  Copyright © 2018 Patrick Brennan. All rights reserved.
//
//Assignment: Program which takes in an expression in either Infix or Prefix notation and converts it to other

#include <iostream>
#include <stack>
#include <string>

bool isOperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/'){
        return true;
    }else{
        return false;
    }
}

std::string reverseString(std::string str){
    std::string reverse;
    for(int i=str.length(); i>=0; i--){
        reverse += str[i];
    }
    return reverse;
}

void prefixToInfix(std::string str){
    std::stack<char> infix;
    infix.push(str[0]);
    char op;
    for (int i = 1; i<str.length(); i++){
        if (str[i-1] == '(' && str[i+1] == '('){
            op = str[i];
        }
        if (str[i] == ')' || str[i] == '('){
            if (str[i] == '(' && str[i-1] == ')'){
                infix.push(op);
            }
            infix.push(str[i]);
        }else if (str[i] >= '0' && str[i] <= '9'){
            if (isOperator(str[i-1])){
                    infix.push(str[i]);
                    infix.push(str[i-1]);
            }else if (str[i-1] >= '0' && str[i-1] <= '9'){
                    infix.push(str[i]);
            }
        }
    }
    
    std::string output;
    while(!infix.empty()){
        output += infix.top();
        infix.pop();
    }
    output = reverseString(output);
    std::cout<<output<<std::endl;
}

void infixToPrefix(std::string str){
    std::stack<char> prefix;
    prefix.push(str[0]);
    for (int i=0; i<str.length(); i++){
        if (isOperator(str[i]) && str[i-1] == ')' && str[i+1] == '('){
            prefix.push(str[i]);
        }
    }
    for (int i = 1; i<str.length(); i++){
        if (str[i] == '(' || str[i] == ')'){
            prefix.push(str[i]);
        }else if (str[i] >= '0' && str[i] <='9'){
            if (str[i+1] == ')'){
                if (str[i-1] >= '0' && str[i-1] <= '9'){
                    prefix.push(str[i-1]);
                }
                prefix.push(str[i]);
            }else if (isOperator(str[i+1])==true){
                prefix.push(str[i+1]);
                if (str[i-1] >= '0' && str[i-1] <= '9'){
                    prefix.push(str[i-1]);
                }
                prefix.push(str[i]);
            }
        }
    }
    std::string output;
    while(!prefix.empty()){
        output += prefix.top();
        prefix.pop();
    }
    output = reverseString(output);
    std::cout<<output<<std::endl;
}


int main(int argc, const char * argv[]) {
    std::string input;
    std::cout<<"Please enter the infix line to convert to prefix (NOTE: please input with proper parenthesis for order of operations)"<<std::endl;
    std::cin>>input;
    infixToPrefix(input);
    std::cout<<"Please enter the Prefix line to convert to infix (NOTE: please input with proper parenthesis for order of operations)"<<std::endl;
    std::cin>>input;

    prefixToInfix(input);
    
    return 0;
}
