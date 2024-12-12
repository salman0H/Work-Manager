### Project Name: **Workforce Management System**  
An OOP-based Employee Classification and Salary Management System  

---

## 📚 About the Project  
The **Workforce Management System** is a robust application designed to manage and calculate salaries for different types of workers, including salaried employees, hourly workers, commission-based workers, and bosses. It demonstrates the power of object-oriented programming (OOP) concepts, such as inheritance, polymorphism, and operator overloading, in C++.  

This project provides:  
- A **user-friendly interface** to input worker details.  
- **Custom salary calculations** based on worker type.  
- Demonstrations of **virtual functions**, **friend functions**, and **operator overloading**.

---

## 🚀 Features  
### Worker Types Supported:  
1. **Salaried Workers**  
   - Fixed monthly salary.  
2. **Hourly Workers**  
   - Wage calculated based on hours worked and hourly rate.  
3. **Commission Workers**  
   - Salary based on rate and quantity of sales.  
4. **Boss**  
   - Salaried worker with additional bonuses.  

### Core Functionality  
- **Custom Input/Output Overloading**: Simplifies data entry and display.
- **Flexible Salary Calculations**: Implements unique logic for each worker type.  
- **Extensible Design**: New worker types can be added with minimal changes.  

---

## 🛠️ Installation and Usage  
1. Clone the repository:  
   ```bash
   git clone <repository_url>
   ```
2. Compile the program using any C++ compiler (e.g., g++):  
   ```bash
   g++ -o workforce_management main.cpp
   ```
3. Run the compiled program:  
   ```bash
   ./workforce_management
   ```

---

## 🌐 Program Workflow  
1. Choose the type of worker to manage:  
   - Salaried Worker  
   - Hourly Worker  
   - Commission Worker  
   - Boss  
2. Enter relevant details (name, family, salary details, etc.).  
3. View calculated salary and worker information.  

---

## 🎨 Code Highlights  
### Key OOP Features:  
- **Inheritance**: Derived classes for each worker type extend the base `worker` class.  
- **Polymorphism**: Virtual functions for flexible implementation.  
- **Encapsulation**: Private data members with getter and setter methods.  
- **Operator Overloading**: Custom behaviors for `>>` and `<<` operators.

### Sample Code:  
```cpp
class worker {
    friend istream &operator>>(istream &in, worker &obj);
    friend ostream &operator<<(ostream &out, worker &obj);
private:
    string name;
    string family;
public:
    worker(string _name = "N", string _family = "F") : name(_name), family(_family) {}
    virtual void print() {
        cout << name << '\t' << family << endl;
    }
    virtual double getsalary() = 0; // Pure virtual function
};
```

---

## 🎉 Contributions  
Feel free to fork the repository and submit pull requests to enhance the program.  

---

## 🔧 License  
This project is licensed under the MIT License - see the `LICENSE` file for details.
