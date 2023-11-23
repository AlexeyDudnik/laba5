#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
class link {
public:
	link();
	link(int data);
	bool add_element(int data);
	void delete_element(int data);
	bool find_element(int data);
	void insert_element(int data, int pos);
	void Print();
private:
	Node* first;
	Node* last;
	Node* p;
};

link::link()
{
	first = nullptr;
	last = nullptr;
	p = nullptr;
}

bool link::add_element(int data) {
	Node* nd = new Node{ data, nullptr };
	if (last == nullptr) {
		first = nd;
		last = nd;
		return true;
	}
	last->next = nd;
	last = nd;
	return true;
}
bool link::find_element(int k) {
	Node* nd = first;
	int i = 0;
	while (nd) {
		if (nd->data == k) {
			++i;
		}
		nd = nd->next;
	}
	return i;
}
void link::delete_element(int data) {
	Node* nd1 = first;
	Node* nd2 = first->next;
	while (nd2 && nd2->data != data) {
		nd2 = nd2->next;
		nd1 = nd1->next;
	}
	nd1->next = nd2->next;
	delete nd2;
}
void link::insert_element(int data, int pos) {
	Node* nd = first;
	if (pos == 0) {
		add_element(data);
	}
	int i = 0;
	while (nd) {
		if (i == pos - 1)
		{
			break;
		}
		nd = nd->next;
		i = i + 1;
	}
	Node* nd1 = new Node{ data, nd->next };
	nd->next = nd1;
}
void link::Print() {
	Node* PP = first;
	while (PP) {
		cout << PP->data << " ";
		PP = PP->next;
	}
}

int main()
{
	link l1;
	l1.add_element(112);
	l1.add_element(113);
	l1.add_element(114);
	l1.add_element(115);
	l1.Print();
	cout << endl;
	cout << l1.find_element(115);
	cout << endl;
	l1.insert_element(116, 2);
	l1.delete_element(114);
	l1.Print();
}