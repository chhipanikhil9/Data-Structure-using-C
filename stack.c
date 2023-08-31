#include<stdio.h>
#include<conio.h>

struct stack
{
	int arr[100];
	int capacity = 100;
	int top = -1;

	void push(int x) {
		if (isFull()) {
			printf("Stack is Full!\n");
		}
		else {
			arr[++top] = x;
		}
	}

	int pop() {
		int ele = 0;
		if (top == -1) {
			printf("Stack is empty!\n");
		}
		else {
			ele = arr[top];
			top--;
		}
		return ele;
	}

	bool isEmpty() {
		if (top == -1) {
			return 1;
		}
		return 0;
	}

	bool peek() {
		if (isEmpty()) {
			return 0;
		}
		return arr[top];
	}

	bool isFull() {
		if (top == capacity - 1) {
			return 1;
		}
		return 0;
	}

	void traverse() {
		for (int i = top; i >= 0; i--) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

	int size() {
		return top + 1;
	}

};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	stack st;
	int arr[10] = {1, 2, 4, 3, 4, 5, 3, 2, 5, 3};
	for (int i = 0; i < 10; i++) {
		st.push(arr[i]);
	}
	st.traverse();
	printf("Size of the Stack: %d\n", st.size());

	return 0;
}


