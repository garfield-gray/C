#include <iostream>
#include <string>

class Person {
private:
    int id;
    std::string name;

public:
    // Default constructor
    Person() : id(0), name("") {
        std::cout << "Default constructor called." << std::endl;
    }

    // Parameterized constructor
    Person(int personId, const std::string& personName) : id(personId), name(personName) {
        std::cout << "Person " << id << " created." << std::endl;
    }

    // Copy constructor
    Person(const Person& other) : id(other.id), name(other.name) {
        std::cout << "Person " << id << " copy constructor called." << std::endl;
    }

    // Move constructor
    Person(Person&& other) noexcept : id(other.id), name(std::move(other.name)) {
        other.id = 0;
        std::cout << "Person " << id << " move constructor called." << std::endl;
    }

    // Destructor
    virtual ~Person() {
        std::cout << "Person " << id << " destroyed." << std::endl;
    }

    // Getter methods
    int getId() const {
        return id;
    }

    const std::string& getName() const {
        return name;
    }

    // Virtual function
    virtual void eat() const {
        std::cout << "Person " << id << " is eating." << std::endl;
    }

    // Overloaded operator ==
    bool operator==(const Person& other) const {
        return (id == other.id && name == other.name);
    }
};

class Student : public Person {
private:
    int grade;

public:
    // Default constructor
    Student() : grade(0) {
        std::cout << "Default constructor of Student called." << std::endl;
    }

    // Parameterized constructor
    Student(int personId, const std::string& personName, int studentGrade) : Person(personId, personName), grade(studentGrade) {
        std::cout << "Student " << getId() << " created." << std::endl;
    }

    // Copy constructor
    Student(const Student& other) : Person(other), grade(other.grade) {
        std::cout << "Student " << getId() << " copy constructor called." << std::endl;
    }

    // Move constructor
    Student(Student&& other) noexcept : Person(std::move(other)), grade(other.grade) {
        std::cout << "Student " << getId() << " move constructor called." << std::endl;
    }

    // Getter method
    int getGrade() const {
        return grade;
    }

    // Override eat() function
    void eat() const override {
        std::cout << "Student " << getId() << " is eating in the self-sevice." << std::endl;
    }
};

class Professor : public Person {
private:
    double salary;

public:
    // Default constructor
    Professor() : salary(0.0) {
        std::cout << "Default constructor of Professor called." << std::endl;
    }

    // Parameterized constructor
    Professor(int personId, const std::string& personName, double professorSalary) : Person(personId, personName), salary(professorSalary) {
        std::cout << "Professor " << getId() << " created." << std::endl;
    }

    // Copy constructor
    Professor(const Professor& other) : Person(other), salary(other.salary) {
        std::cout << "Professor " << getId() << " copy constructor called." << std::endl;
    }

    // Move constructor
    Professor(Professor&& other) noexcept : Person(std::move(other)), salary(other.salary) {
        std::cout << "Professor " << getId() << " move constructor called." << std::endl;
    }

    // Getter method
    double getSalary() const {
        return salary;
    }

    // Override eat() function
    void eat() const override {
        std::cout << "Professor " << getId() << " is having lunch." << std::endl;
    }
};

int main() {





    Student student1(1, "Hassan Gholi", 12);
    Student student2 = student1;  // Copy construction

    Student student3(2, "Saeed rezaie", 10);
    Student student10 = std::move(student3);  // Move construction

    Professor professor1(1, "Ali Fahim", 5000.0);
    Professor professor2 = professor1;  // Copy construction

    Professor professor3(2, "Negin Bagherpour", 6000.0);
    Professor professor10 = std::move(professor3);  // Move construction




    Student student4(1, "Abbas Mo", 12);
    Student student5(1, "Abbas Mo", 12);
    Student student6(3, "Sahar Mo", 10);

    if (student4 == student5)
        std::cout << "student1 and student2 are equal." << std::endl;
    else
        std::cout << "student1 and student2 are not equal." << std::endl;

    if (student5 == student6)
        std::cout << "student1 and student3 are equal." << std::endl;
    else
        std::cout << "student1 and student3 are not equal." << std::endl;

    Professor professor4(1, "Hossein Mah", 5000.0);
    Professor professor5(1, "Hossein Mah", 5000.0);
    Professor professor6(3, "Rezza GHoliz", 6000.0);

    if (professor4 == professor5)
       std::cout << "professor1 and professor2 are equal." << std::endl;
    else
       std::cout << "professor1 and professor2 are not equal." << std::endl;

    if (professor5 == professor6)
        std::cout << "professor1 and professor3 are equal." << std::endl;
    else
       std::cout << "professor1 and professor3 are not equal." << std::endl;

    professor10.eat();
    student10.eat();

    Professor professor20;
    Student student20;









    return 0;
}
