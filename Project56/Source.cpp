#include <iostream>
using namespace std;
class course {
public:
	string name;
	string code;
	void set(string n, string c) {
		name = n;
		code = c;
	}
};
class stack {
private:
	int maxsize;
	int length;
	course* ptr;
	void expand() {
		maxsize *= 2;
		course* tmp = new course[maxsize];
		for (int i = 0; i < length; i++) {
			tmp[i] = ptr[i];
		}
		delete[] ptr;
		ptr = tmp;
	}
public:
	stack() {
		maxsize = 10;
		length = 0;
		ptr = new course[maxsize];
	}
	int get_length() {
		return length;
	}
	void pop() {
		length--;
	}
	void push(course c) {
		if (length == maxsize) {
			expand();
		}
		ptr[length] = c;
		length++;
	}
	course top() {
		return ptr[length - 1];
	}
	bool isempty() {
		if (length == 0) {
			return true;
		}
		else
			return false;
	}
	void display() {
		for (int i = 0;i < length;i++) {
			cout << ptr[i].name << "--" << ptr[i].code << endl;
		}
	}
};
class Node {
public:
	course value;
	Node* next;
	Node(course v) {
		value = v;
	}
};
class linked_list {
public:
	Node* head;
	Node* tail;
	int size;
	linked_list() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	course At(int index) {
		Node* tmp = head;
		int i = 0;
		while (i < index) {
			tmp = tmp->next;
			i++;
		}
		return tmp->value;
	}
	void append(course c1) {
		Node* new_node = new Node(c1);
		if (head == NULL) {
			head = new_node;
			tail = new_node;
		}
		else {
			tail->next = new_node;
			tail = new_node;
		}
		size++;
	}
	void delete_At(int index) {
		Node* tmp = head;
		Node* deleted_node;
		int i = 0;
		if (index == 0) {
			head = head->next;
			delete tmp;
		}
		else {
			while (i < index - 1) {
				tmp = tmp->next;
				i++;
			}
			deleted_node = tmp->next;
			if (deleted_node->next == NULL) {
				tail = tmp;
			}
			else {
				tmp->next = deleted_node->next;
			}
			delete deleted_node;
		}
		size--;

	}
	int get_index(string c2) {
		Node* tmp = head;
		int i = 0;
		while (i < size) {
			if (tmp->value.code == c2)
				return i;
			tmp = tmp->next;
			i++;
		}
	}
	void insert_At(int index, course val) {
		Node* tmp = head;
		Node* new_node = new Node(val);
		int i = 0;
		if (index == 0) {
			new_node->next = head;
			head = new_node;
		}
		else {
			while (i < index - 1) {
				tmp = tmp->next;
				i++;
			}
			new_node->next = tmp->next;
			tmp->next = new_node;
		}
		size++;
	}
	void display() {
		for (int i = 0; i < size; i++) {
			cout << At(i).name << "\t" << At(i).code << endl;;
		}
	}
};
class list {
protected:
	int maxsize;
	int length;
	course* ptr;
public:
	list() {
		maxsize = 10;
		length = 0;
		ptr = new course[maxsize];
	}
	list(int l) {
		maxsize = 10;
		length = l;
		ptr = new course[maxsize];
	}
	void set_length(int l) {

		length = l;
	}
	void set(string name1, string code1, int i) {
		ptr[i].name = name1;
		ptr[i].code = code1;
	}
	void append(course c1) {
		if (length == maxsize) {
			expand();
		}
		ptr[length] = c1;
		length++;
	}
	int search(string c) {
		for (int i = 0; i < length; i++) {
			if (ptr[i].code == c) {
				return i;
			}
		}
		return -1; // Ensure function always returns a value
	}

	void display() {
		for (int i = 0; i < length; i++) {
			cout << "Details of course " << i + 1 << endl;
			cout << "Name: " << ptr[i].name << endl;
			cout << "Code: " << ptr[i].code << endl;
		}
	}
	void delete_at(int num) {
		if (num > length) {
			cout << "\n Can't delete an unavailable course." << endl;
		}
		for (int i = num; i < length - 1; i++) {
			ptr[i] = ptr[i + 1];
		}
		length--;
	}
	course get_course(int i) {
		return ptr[i];
	}
	course get_course_bycode(string c) {
		for (int i = 0; i < length; i++) {
			if (ptr[i].code == c) {
				return ptr[i];
			}
		}
	}
private:
	void expand() {
		maxsize *= 2;
		course* temp = new course[maxsize];
		for (int i = 0; i < length; i++) {
			temp[i] = ptr[i];
		}
		delete[] ptr;
		ptr = temp;
	}
};
class enrollment {
public:
	list courses;
};

class student {
public:
	student() {
		id = 0;
		name = " ";
	}
	student(string n, int ID) {
		name = n;
		id = ID;
	}
	int id;
	string name;
	linked_list stu_courses;
	stack courses;
	stack changes;
};
int search_for_student(student arr[], int ID, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i].id == ID) {
			return i;
		}
	}
	return -1;
}
int main() {
	student stu[3] = { student("Abdalla Gamal",251984),student("Ibrahim Amr",260080),student("Eyad Tamer",258363) };
	enrollment system;
	string n, c;
	int size;
	int s_choice;
	char UR_choice;
	course c2;
	system.courses.set("Math", "BSCS101", 0);
	system.courses.set("English", "LNGS201", 1);
	system.courses.set("Physics", "PHYS301", 2);
	system.courses.set("Chemsitry", "CHEMS401", 3);
	system.courses.set("Biology", "BIOL501", 4);
	system.courses.set_length(5);
	// cout << "Enter number of courses in the system: ";
	// cin >> size;
	// system.courses.set_length(size);
	// for (int i = 0; i < size; i++) {
	   // cout << "Enter details of course number " << i + 1 << endl;
	   // cout << "Name: "; cin >> n;
	   // cout << "Code: "; cin >> c;
	   // system.courses.set(n, c, i);
	// }
	char choice2;
	do {
		cout << "1: Add a course to enrollment system" << endl;
		cout << "2: Remove a course from the enrollment system " << endl;
		cout << "3: Display available courses in the system " << endl;
		cout << "4: Enroll a student in a course " << endl;
		cout << "5: Drop a course from a student's courses " << endl;
		int choice;
		int stu_number;
		int x, y;
		cout << "Enter choice of operation ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter details of course to add: " << endl;
			cout << "Name: "; cin >> n;
			cout << "Code: "; cin >> c;
			cout << endl;
			c2.name = n;
			c2.code = c;
			system.courses.append(c2);
			break;
		case 2:
			cout << "Enter code of course to drop: ";
			cin >> c;
			x = system.courses.search(c);
			system.courses.delete_at(x);
			break;
		case 3:
			system.courses.display();
			break;
			break;
		case 4:
			cout << "Enter ID of student to enroll: ";
			cin >> stu_number;
			x = search_for_student(stu, stu_number, 3);
			cout << endl;
			cout << "Available courses in the system: " << endl;
			system.courses.display();
			cout << endl;
			cout << "Enter code of course to enroll in: ";
			cin >> c;
			y = system.courses.search(c);
			stu[x].stu_courses.append(system.courses.get_course(y));
			stu[x].courses.push(system.courses.get_course(y));
			cout << "Student courses after enrollment: " << endl;
			stu[x].courses.display();
			cout << endl;
			do {
				cout << "Would You like to undo or redo?(1 for undo, 2 for redo, press 3 for neither)? ";
				cin >> s_choice;
				if (s_choice == 1) {
					stu[x].courses.pop();
					stu[x].changes.push(system.courses.get_course(y));
					cout << "Action successfully undone " << endl;
					cout << "Student courses after undo: " << endl;
					stu[x].courses.display();
					cout << endl;
				}
				else if (s_choice == 2) {
					if (stu[x].changes.isempty())
						cout << "Nothing to redo!" << endl;
					else {
						stu[x].courses.push(stu[x].changes.top());
						stu[x].changes.pop();
						cout << "Action successfully re-done " << endl;
					}
				}
				else {
					cout << "."<<endl;
				}
				cout << "Would you like to perform another undo or redo operation?(Y/N)" << endl;
				cin >> UR_choice;
			} while (UR_choice == 'Y' || UR_choice == 'y');
			while (!stu[x].changes.isempty())
				stu[x].changes.pop();
			break;
		case 5:
			cout << "Enter ID of student to drop from a course: ";
			cin >> stu_number;
			x = search_for_student(stu, stu_number, 3);
			cout << "Student's available courses: "<<endl;
			stu[x].courses.display();
			cout << endl;
			cout << "Enter code of course to drop: ";
			cin >> c;
			y = stu[x].stu_courses.get_index(c);
			stu[x].stu_courses.delete_At(y);
			stu[x].changes.push(system.courses.get_course_bycode(c));
			while (!stu[x].courses.isempty()) {
				stu[x].courses.pop();
			}
			int size = stu[x].stu_courses.size;
			for (int i = 0;i < size;i++) {
				stu[x].courses.push(stu[x].stu_courses.At(i));
			}
			cout << "Student courses after changes: " << endl;
			stu[x].courses.display();
			cout << endl;
			do {
				cout << "Would you like to undo or redo?(1 for undo, 2 for redo, press any button for neither)" << endl;
				cin >> s_choice;
				if (s_choice == 1) {
					stu[x].courses.push(stu[x].changes.top());
					stu[x].changes.pop();
					cout << "Undo successfully done" << endl;
				}
				else if (s_choice == 2) {
					if (!stu[x].changes.isempty()) {
						cout << "Nothing to redo" << endl;
					}
					else {
						stu[x].changes.push(stu[x].courses.top());
						stu[x].courses.pop();
						cout << "Redo Successfully done" << endl;
					}
				}
				cout << "Would you like to perform another undor or redo operation?(Y/N)" << endl;
			} while (UR_choice == 'y' || UR_choice == 'Y');
			break;

		}
		cout << "Would you to perform another operation?(Y/N)";
		cin >> choice2;
	} while (choice2 == 'Y' || choice2 == 'y');
	return 0;
}