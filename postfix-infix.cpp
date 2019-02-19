#include<iostream>
#include<stack>

using namespace std;

bool isOperator(char x) { 
  switch (x) { 
  case '+': 
  case '-': 
  case '/': 
  case '*': 
    return true; 
  } 
  return false; 
} 

string getInfix(string line){
    stack<string> s;
    int size = line.size();
    for (int i=0; i < size;i++){
        if (isOperator(line[i])){
            string op1 = s.top();   s.pop(); 
            string op2 = s.top();   s.pop(); 
            string temp = "(" + op2 + line[i] + op1 + ")"; 
            s.push(temp); 
         } else { 
            s.push(string(1, line[i])); //string s(int n, char x); Creates a string of size n and fill the string with character x.
          } 
    }
    return s.top();
};

int main() 
{ 
	string exp = "ab*c+"; 
	cout << getInfix(exp); 
	return 0; 
} 