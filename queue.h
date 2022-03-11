#pragma once
#include<iostream>
struct Node
{
	int value = 0;
	Node* next = nullptr;
};
enum Priority {
	High,
	Medium,
	Low
};
class queue
{
private:
	Node* front = nullptr;
	Node* highPriority = nullptr;
	Node* mediumPriority = nullptr;
	Node* lowPriority = nullptr;
	int high, medium, low = 0;
	void erase();
	void copy(const queue&);
	void copy(queue&&);
public:
	queue();
	queue(const queue&);
	queue(queue&&);
	~queue();
	queue& operator= (const queue&);
	queue& operator= (queue&&);
	int size() const;
	int sizeLowPriority() const;
	int sizeMediumPriority() const;
	int sizeHighPriority() const;
	bool isEmpty() const;
	void push(int, const Priority);
	bool pop();
	std::pair<int, Priority> top() const;
	friend std::ostream& operator<<(std::ostream&, const queue&);
};