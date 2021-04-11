#include <iostream>
using namespace std;
template <typename T>
class Stack
{
public:
	Stack(int size);
	Stack(const Stack& other);
	Stack(Stack&& other);
	Stack& operator=(const Stack& other);
	~Stack();
	int GetSize() const;
	void Push(T item);
	T Pop()
	{
		if (front == -1)
		{
			cout << "Deletion is not possible: stack is empty\n";
			return 0;
		}
		else
		{
			cout << "The deleted element is: " << arr[back];
			if (front == back)
			{
				front = back = -1;
			}
			else
				back = back - 1;
			}
	}
	T Peek()
	{
		if (front == -1)
			cout << "Stack is empty\n";
		else
			cout << "Last element is: " << arr[back];
	}
	void show();
private:
	T* arr;
	int front;
	int back;
	int size;
};
template <typename T>
Stack<T>::Stack(const Stack& other)
{
	arr = new T[size];
	front = -1;
	back = -1;
}
template <typename T>
Stack<T>::Stack(Stack&& other)
{
	arr = other.arr;
	size = other.count;
	other.count = nullptr;
}
template <typename T>
Stack<T>::~Stack()
{
	delete[] arr;
}
template <typename T>
void Stack<T>::show()
{
	if (front == -1)
	{
		cout << "Stack is empty\n";
	}
	else
	{
		for (int i = front; i <= back; i++)
		{
			cout << arr[i] << "";
		}
	}
}
int main()
{
	int i, c;
	int size = 5;
	Stack<int> D(size);
	do
	{
		cout << "\n1.Insert" << endl;
		cout << "2.Show" << endl;
		cout << "3.Deletion" << endl;
		cout << "4.Show last element" << endl;
		cout << "5.Enter your choice: " << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Enter the element to be inserted: ";
			cin >> i;
			D.Push(i);
			break;
		case 2:
			D.show();
			break;
		case 3:
			D.Pop();
			break;
		case 4:
			D.Peek();
			break;
		case 0: break;
		default: cout << endl << "Error\n\n";
			break;
		}
	} while (c != 0);
	D.~Stack();
	system("pause");
}