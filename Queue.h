template<class T>
class Queue {
	T* data;
	int front;    
	int back;
	int maxSize;
	int size;

public:
	Queue(int size) {
		maxSize = size;
		data = new T[maxSize];
		front = -1;
		back = 0;
		this->size = 0;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void push(T elem) {
		if (size == maxSize) {
			cout << "Queue is full " << endl;
			return;
		}

		if (front == -1) {
			front = 0;
		}

		data[back] = elem;
		back++;
		size++;
	}

	T pop() {
		T c;
		if (front == -1) {
			cout << "Queue is empty " << endl;
			return c;
		}
		T temp = data[front];
		
		front++;
		back--;
		size--;
		if (size == 0) {
			front = -1;
			back = 0;
		}
		return temp;
	}
};
