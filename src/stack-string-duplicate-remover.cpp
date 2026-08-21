//Preprocessor Directives
#include <iostream>//Standard Input/Output Library
#include <stack>//Req. for Stack programming
#include <string> //Req for String Manip.
using namespace std;

//F(x) proto converts the user's string to characters and pushes that to a stack
void duplicate_eliminator(string& userString, stack<char>& stack, int length);

//F(x) proto Inverts the inverted Stack so that the Printer can spit out the characters in the right order.
void stack_flipper(stack<char>& mainStack, stack<char>& transferStack);

//F(x) proto rattles off the characters remaining in the stack after duplicate removal.
void printer(stack<char> &mainStack);

int main() {
	string userInputstr;//Variable to hold input string.

	cout << "Greetings user, please enter a string" << endl;
	cin >> userInputstr;//Storing the string prov. by the user
	
	int len = userInputstr.size();//Length of the string.
	
	stack<char> userStack;//Stack for the userInputstr
	stack<char> transferStack;//Used to hold characters temporarily if they arent duplicates

	cout << endl << "User Provided String: " << userInputstr << endl << "Remaining characters after Duplicate removal: ";

	//Converting the String to individual characters and pushing that onto the stack.
	duplicate_eliminator(userInputstr, transferStack, len);

	//Inverting the transfer stack.
	stack_flipper(userStack, transferStack);

	//Displaying Result.
	printer(userStack);
}

//Converts the user's string to individual characters and checks if they are duplicates before pushing them to a stack.
//Should they be duplicates the stack will not receive the new character and the top element will be popped.
void duplicate_eliminator(string &userString, stack<char> &stack, int length){
	char a;//Character storage variable.
	
	//Loops through the entire string checking each character for duplicity.
	for (int i = 0; i < length; i++) {

		a = userString[i];
		//cout << "Current Character: " << a << endl; Ignore, used to debug.

		//If the stack is NOT empty and 'a' is a duplicate of what is on top of the stack we can pop the element on top
		//and remove it from circulation, thus eliminating the duplicate.
		if (!stack.empty() && a == stack.top()) {
			stack.pop();
		}
		//Should the above condition NOT be met then the character gets pushed onto the stack 
		else{
			stack.push(a);
		}
	}
}

//Inverts the inverted Stack so that the Printer can spit out the characters in the right order.
void stack_flipper(stack<char>& mainStack, stack<char>& transferStack){
	
	while (!transferStack.empty()) {
		char c = transferStack.top();//Init. a char variable c and sets it's element to the element at the top of the transfer stack
		transferStack.pop();//Removes top element of transfer stack
		mainStack.push(c);//Adds c to the main stack.
}

}

//Rattles off the characters remaining in the stack after duplicate removal.
void printer(stack<char> &mainStack) {
	char character = ' ';
	if (!mainStack.empty()) {//Runs if stack was not empty
		while (!mainStack.empty()) {
			character = mainStack.top();//Character will take the value of the top element.
			cout << character;
			mainStack.pop();//Removes top element of stack
		}
	}

	else if (mainStack.empty()) {//Runs if stack is empty
		cout << "Empty String";
	}
}
