#include "queue.h"
void queue::erase() {
	Node* current = this->front;
	Node* tmp;
	while (current != nullptr) {
		tmp = current;
		current = current->next;
		delete tmp;
	}
}
void queue::copy(queue&& q) {
	front = q.front;
	highPriority = q.highPriority; mediumPriority = q.mediumPriority; lowPriority = q.lowPriority;
	high = q.high; medium = q.medium; low = q.low;
}
void queue::copy(const queue& q) {
	Node* node = q.front; int i;
	if (q.high > 0) {
		for (int i = 0; i < q.high; node = node->next, i++) {
			push(node->value, Priority::High);
		}
	}
	if (q.medium > 0) {
		for (int i = 0; i < q.medium; node = node->next, i++) {
			push(node->value, Priority::Medium);
		}
	}
	if (q.low > 0) {
		for (int i = 0; i < q.low; node = node->next, i++) {
			push(node->value, Priority::Low);
		}
	}
}
queue::queue() {
}
queue::queue(const queue& q) {
	this->copy(q);
}
queue::queue(queue&& q)
{
	copy(std::move(q));
	q.erase();
}
queue::~queue() {
	this->erase();
}
queue& queue::operator=(const queue& q) {
	if (&q == this)
		return *this;
	this->erase();
	this->copy(q);
	return *this;
}
queue& queue::operator=(queue&& q) {
	if (&q == this)
		return *this;
	this->copy(std::move(q));
	q.erase();
	return *this;
}
int queue::size() const
{
	return this->high + this->medium + this->low;
}
int queue::sizeLowPriority() const
{
	return low;
}
int queue::sizeMediumPriority() const
{
	return medium;
}
int queue::sizeHighPriority() const
{
	return high;
}
bool queue::isEmpty() const {
	return (high + medium + low == 0);
}
void queue::push(int value, const Priority priority) {
	Node* node = new Node();
	node->value = value;
	if (priority == Priority::High) {
		if (high > 0) {
			for (Node* t = front; t != nullptr; t = t->next) {
				if (t == highPriority) {
					node->next = highPriority->next;
					highPriority->next = node;
					break;
				}
			}
		}
		else {
			node->next = front;
			front = node;
		}
		high++;
		highPriority = node;
	}
	if (priority == Priority::Medium) {
		if (medium > 0) {
			for (Node* t = front; t != nullptr; t = t->next) {
				if (t == mediumPriority) {
					node->next = mediumPriority->next;
					mediumPriority->next = node;
					break;
				}
			}
		}
		else {
			if (high > 0) {
				for (Node* t = front; t != nullptr; t = t->next) {
					if (t == highPriority) {
						node->next = highPriority->next;
						highPriority->next = node;
						break;
					}
				}
			}
			else {
				node->next = front;
				front = node;
			}
		}
		medium++;
		mediumPriority = node;
	}
	if (priority == Priority::Low) {
		if (low > 0) {
			for (Node* t = front; t != nullptr; t = t->next) {
				if (t == lowPriority) {
					node->next = lowPriority->next;
					lowPriority->next = node;
					break;
				}
			}
		}
		else {
			if (medium > 0) {
				for (Node* t = front; t != nullptr; t = t->next) {
					if (t == mediumPriority) {
						node->next = mediumPriority->next;
						mediumPriority->next = node;
						break;
					}
				}
			}
			else {
				if (high > 0) {
					for (Node* t = front; t != nullptr; t = t->next) {
						if (t == highPriority) {
							node->next = highPriority->next;
							highPriority->next = node;
							break;
						}
					}
				}
				else {
					node->next = front;
					front = node;
				}
			}
		}
		low++;
		lowPriority = node;
	}
}
bool queue::pop() {
	if (!isEmpty()) {
		if (high > 0) {
			high--;
		}
		else {
			if (medium > 0) {
				medium--;
			}
			else
			{
				low--;
			}
		}
		Node* node = front;
		front = node->next;
		delete node;
		return 1;
	}
	return 0;
}
std::pair<int, Priority> queue::top() const {
	if (isEmpty())
		throw std::runtime_error("queue is empty");
	Priority p;
	if (high > 0)
		p = High;
	else if (medium > 0)
		p = Medium;
	else if (low > 0)
		p = Low;
	return std::make_pair(front->value, p);	
}
std::ostream& operator<<(std::ostream& out, const queue& q) {
	Node* node = q.front;
	out << "[ ";
	if (q.high > 0) {
		for (int i = 0; i < q.high; node = node->next, i++) {
			out << node->value << " ";
			if (node == q.highPriority)
				out << "| ";
		}
	}
	else {
		out << "| ";
	}
	if (q.medium > 0) {
		for (int i = 0; i < q.medium; node = node->next, i++) {
			out << node->value << " ";
			if (node == q.mediumPriority)
				out << "| ";
		}
	}
	else {
		out << "| ";
	}if (q.low > 0) {
		for (int i = 0; i < q.low; node = node->next, i++) {
			out << node->value << " ";	
		}
	}
	return out << "]";
}