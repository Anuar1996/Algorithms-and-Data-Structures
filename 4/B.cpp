#include <iostream>
#include <string>

struct listNode {
	listNode *next;
	std::string name;
	std::string number;
	
	listNode(std::string const &_name, std::string const &_number) {
       name = _name;
       number = _number;
       next = NULL;
    }
};

struct list {
	listNode *head;
	
	list() {
		head = NULL;
	}
	
	bool find_key(std::string const &_name) {
		for (listNode *it = head; it != NULL; it = it->next) {
			if (it->name == _name) {
				return true;
			}
		}
		return false;
	}
	
	bool insert_key(std::string _name, std::string _number) {
		if (head == NULL) {
			head = new listNode(_name, _number);
			return true;
		}
		
		if (find_key(_name)) return false;
		
		listNode *it = head;
		for (; it->next != NULL; it = it->next) {
		}
		
		it->next = new listNode(_name, _number);
		return true;
	}
	
	bool delete_key(std::string const &_name) {
		if (!find_key(_name)) return false;
		listNode *it_next = head;
		listNode *it;
		while (it_next != NULL) {
			if (it_next->name == _name) {
				if (it_next == head) {
					head = head->next;
					delete it_next;
					return true;
				}
				else {
					it->next = it_next->next;
					delete it_next;
					it_next = it->next;
					return true;
				}
			}
			else {
				it = it_next;
				it_next = it_next->next;
			}
		}
		return true;
	}
	
	bool edit_key(std::string const &_name, std::string const &_number) {
		if (!find_key(_name)) return false;
		listNode *it = head;
		for (; it->name != _name; it = it->next) {
		}
		
		it->number = _number;
		return true;
	}
	
	bool print_key(std::string const &_name) {
		if (!find_key(_name)) return false;
		for (listNode *i = head; i != NULL; i = i->next) {
			if (i->name == _name) {
				std::cout << i->name << " " << i->number << std::endl;
				return true;
			}
		}
		return false;
	}
	
	void print_list() {
		for (listNode *it = head; it != NULL; it = it->next) {
			std::cout << it->name << ": " << it->number << std::endl; 
		}
	}
	
};

int main() {
	
	int N;
	
	std::cin >> N;
	
	list phone_;
	
	for (int i = 0; i < N; ++i) {
		std::string cmd, name, number;
		std::cin >> cmd;
		std::cin >> name;
		if (cmd == "ADD" || cmd == "EDITPHONE") {
			std::cin >> number;
		}
		
		if (cmd == "ADD"){
			if (!phone_.insert_key(name, number))
				std::cout << "ERROR" << std::endl;
		}
		if (cmd ==  "DELETE") {
			if (!phone_.delete_key(name))
				std::cout << "ERROR" << std::endl;
		}
		if (cmd == "PRINT") {
			if (!phone_.print_key(name))
				std::cout << "ERROR" << std::endl;
		}
		if (cmd == "EDITPHONE"){
			if (!phone_.edit_key(name, number))
				std::cout << "ERROR" << std::endl;
		}
	}
	
	return 0;
}
