#include <iostream>

using namespace std;

class Course {
public:
	Course() {
		courseName = "";
		capacity = 0;
	}
	Course(string courseName, int cap) {
		this->courseName = courseName;
		capacity = cap;
	}
	void setCourseName(string n) {
		this->courseName = n;
	}
	void setCapacity(int x) {
		capacity = x;
	}
	string const getCourseName() {
		return courseName;
	}
protected:
	string courseName;
	int capacity;
};
class Student : public Course {
public:
	Student(string courseName, int cap) {
		this->courseName = courseName;
		capacity = cap;
		students = new string[capacity];
	}
	void addStudent(string name) {
		if ((numberOfStudents + 1) > capacity) { //if it has reached capacity
			string* bigger = new string[capacity + 1]; //makes a new pointer with a new string array thats bigger by 1

			for (int i = 0; i < capacity; i++) {
				bigger[i] = students[i];
			}
			bigger[capacity] = name;
			students = bigger;
			capacity++;
		}
		else { 
			students[numberOfStudents] = name;
		}
		numberOfStudents++;
	}
	void dropStudent(string name) {
		int j = 0;
		string* copy = new string[capacity];
		for (int i = 0; i < capacity; i++) { //runs through the array
			if (students[i] != name) { //if it isnt the name that we want to remove copy it over to the new array
				copy[j] = students[i];
				j++;
			}
			else { //if it is the name we want to remove decrease the num of students and dont copy it over
				numberOfStudents--;
			}
		}
		students = copy;
	}
	string* const getStudents() {
		return students;
	}
	int const getNumberOfStudents() {
		return numberOfStudents;
	}
private:
	string* students;
	int numberOfStudents = 0;
};

void printStudents(Student math,string* students) {
	for (int i = 0; i < math.getNumberOfStudents(); i++) {
		cout << students[i] << endl;
	}
}
int main()
{
	Student math("Math-120",1);
	math.addStudent("Apple");
	math.addStudent("Gg");

	string* students = math.getStudents();

	cout << math.getCourseName() << " " << math.getNumberOfStudents() << endl;

	printStudents(math, students); //print out the students
	math.dropStudent("Apple"); //drop the student "Apple"
	students = math.getStudents(); //reget the student array
	printStudents(math, students); //print out the students
}
