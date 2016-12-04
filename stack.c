#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define STACK_MAX 100
#include "stack.h"


/*
	The structure Stack will be my way of implementing the stack data type for this project. 
	Because C does not have classes, using a struct to simulate all of the behaviors of the data
	structure will be used instead.
*/
struct Stack {
	int data[STACK_MAX]; //an array of elements of the size STACK_MAX
	int size; 
};

/*
	Here the struct Stack is typedefed so it can be refered to as simply "Stack"
*/
typedef struct Stack Stack; 

/*
	Here the functions of the stack are prototyped as helper functions 
*/
int Stack_Top(Stack *S);
void Stack_Init(Stack *S);
void Stack_Push(Stack *S, int numberToPush);
char Stack_Pop(Stack *S);


/*
	The implementation of the helper functions
*/


/*
	This is effectively how I will initialize my stack. It will set the size of the stack initially to 0.
*/
void Stack_Init(Stack *S) {
	S->size = 0;
}


int Stack_Top(Stack *S) {
	if (S->size == 0) {
		// fprinf(stderr, "Error: stack empty\n");
		return -1;
	}
	return S->data[S->size-1];
}

void Stack_Push(Stack *S, int numberToPush) {
	if (S->size < STACK_MAX) {
		S->data[S->size++] = numberToPush;
	}
	else {
		fprintf(stderr, "Error: stack full\n");
	}
}

char Stack_Pop(Stack *S) {
	if (S->size == 0) {
		fprintf(stderr, "Error: stack empty\n");
	}
	else {
		S->size--;
	}
	return S->size;
}

// MAIN METHOD
int main() {

	int SIZE = 10;

	printf("hello world\n");
	Stack postfixStack; //create a stack
	Stack_Init(&postfixStack); //initialize a stack
	Stack_Push(&postfixStack, 10);

	int printThis = Stack_Top(&postfixStack);
	printf("%d\n", printThis);

	Stack_Pop(&postfixStack);
	printThis = Stack_Top(&postfixStack);
	printf("%d\n", printThis);

	char input[SIZE]; //the input string by the user

	// char** array = new char*[SIZE];


	int inputNumber;
	printf("Enter a postfix expression: ");
	scanf("%[^\n]", input); //READ IN DATA

	// inputNumber = atoi(input);
	// printf("%d\n", inputNumber);
	printf("%s\n", input);

	size_t length = strlen(input);
	printf("The length of the array is %zu: \n", length);

	// char inputChar = input[0];
	// printf("%s\n", &inputChar);

	// inputChar = input[1];
	// printf("%s\n", &inputChar);

	// inputChar = input[2];
	// printf("%s\n", &inputChar);


	//create another array to store the values into?
	char noSpacesCharArrayOfIntegers[length/2];
	int counterForNewArray = 0;


	for (int i = 0; i < length; i++) {
		if (input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' ||
			input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' ||
			input[i] == '9' || input[i] == '0')
		{
			printf("The character at index %d is %c\n", i, input[i]);
			noSpacesCharArrayOfIntegers[counterForNewArray] = input[i];
			counterForNewArray++;

		}
		else if (input[i] == ' ') {
			printf("\n");
		}
		else if (input[i] == '+') {
			printf("The character at index %d is %c\n", i, input[i]);
			noSpacesCharArrayOfIntegers[counterForNewArray] = input[i];
			counterForNewArray++;
		}
		else if (input[i] == '-') {
			printf("The character at index %d is %c\n", i, input[i]);
			noSpacesCharArrayOfIntegers[counterForNewArray] = input[i];
			counterForNewArray++;
		}
		else if (input[i] == '*') {
			printf("The character at index %d is %c\n", i, input[i]);
			noSpacesCharArrayOfIntegers[counterForNewArray] = input[i];
			counterForNewArray++;
		}
		else if (input[i] == '/') {
			printf("The character at index %d is %c\n", i, input[i]);
			noSpacesCharArrayOfIntegers[counterForNewArray] = input[i];
			counterForNewArray++;
		}
		else {
			printf("Invalid syntax, please enter a valid expression\n");
		}
	}

	printf("\n");
	printf("%c\n", noSpacesCharArrayOfIntegers[0]); //so now this contains everything minus spaces

	size_t nospaceCharArrayOfIntegersLength = strlen(noSpacesCharArrayOfIntegers);
	printf("The length of this new array is: %zu\n", nospaceCharArrayOfIntegersLength);


	//if I see a number in the input, then push it onto the stack
	//if I see an operator in the input, pop the stack twice
	//compute the result and push the result on the stack
	//when the input is empty, pop the stack and that's your answer

	// for (int j = 0; j < nospaceCharArrayOfIntegersLength; j++) {

	// 	if (noSpacesCharArrayOfIntegers[j] == '1' || noSpacesCharArrayOfIntegers[j] == '2' ||
	// 		noSpacesCharArrayOfIntegers[j] == '3' || noSpacesCharArrayOfIntegers[j] == '4' ||
	// 		noSpacesCharArrayOfIntegers[j] == '5' || noSpacesCharArrayOfIntegers[j] == '6' ||
	// 		noSpacesCharArrayOfIntegers[j] == '7' || noSpacesCharArrayOfIntegers[j] == '8' ||
	// 		noSpacesCharArrayOfIntegers[j] == '9' || noSpacesCharArrayOfIntegers[j] == '0')
	// 	{
	// 		Stack_Push(&postfixStack, noSpacesCharArrayOfIntegers[j]);
	// 	}
	// 	else if (noSpacesCharArrayOfIntegers[j] == '+' && nospaceCharArrayOfIntegersLength < 3) {
	// 		char first = Stack_Pop(&postfixStack);
	// 		char second = Stack_Pop(&postfixStack);

	// 		int intFirst = atoi(&first);
	// 		int intSecond = atoi(&second);

	// 		int result = intFirst + intSecond;
	// 	}
	// 	else if (noSpacesCharArrayOfIntegers[j] == '-' && nospaceCharArrayOfIntegersLength < 3) {
	// 		char first = Stack_Pop(&postfixStack);
	// 		char second = Stack_Pop(&postfixStack);

	// 		int intFirst = atoi(&first);
	// 		int intSecond = atoi(&second);

	// 		int result = intSecond - intFirst;
	// 	}
	// 	else if (noSpacesCharArrayOfIntegers[j] == '*' && nospaceCharArrayOfIntegersLength < 3) {
	// 		char first = Stack_Pop(&postfixStack);
	// 		char second = Stack_Pop(&postfixStack);

	// 		int intFirst = atoi(&first);
	// 		int intSecond = atoi(&second);

	// 		int result = intFirst * intSecond;
	// 	}
	// 	else if (noSpacesCharArrayOfIntegers[j] == '/' && nospaceCharArrayOfIntegersLength < 3) {
	// 		char first = Stack_Pop(&postfixStack);
	// 		char second = Stack_Pop(&postfixStack);

	// 		int intFirst = atoi(&first);
	// 		int intSecond = atoi(&second);

	// 		int result = intSecond + intFirst;
	// 	}
	// 	else if (nospaceCharArrayOfIntegersLength == 0) { //if the stack is empty
	// 		char answer = Stack_Pop(&postfixStack);
	// 	}
	// } 


}



