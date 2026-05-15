# Developer Guide - Online Examination Management System

## Table of Contents
1. [Project Architecture](#project-architecture)
2. [Code Structure](#code-structure)
3. [Class Documentation](#class-documentation)
4. [Function Reference](#function-reference)
5. [File Handling](#file-handling)
6. [Extending the System](#extending-the-system)
7. [Coding Standards](#coding-standards)
8. [Build and Deployment](#build-and-deployment)

---

## 1. Project Architecture

### 1.1 Overview
The system follows a **procedural approach with OOP principles**, using classes to encapsulate data and behavior.

### 1.2 Architecture Layers

```
┌──────────────────────────────────────┐
│   User Interface Layer               │
│   (Console I/O, Menus)               │
└──────────────────────────────────────┘
              ↓
┌──────────────────────────────────────┐
│   Business Logic Layer               │
│   (ExamSystem Class)                 │
└──────────────────────────────────────┘
              ↓
┌──────────────────────────────────────┐
│   Data Model Layer                   │
│   (Question, Student, ExamResult)    │
└──────────────────────────────────────┘
              ↓
┌──────────────────────────────────────┐
│   Persistence Layer                  │
│   (File I/O Operations)              │
└──────────────────────────────────────┘
```

### 1.3 Design Patterns Used

**1. Encapsulation Pattern**
- Data members are private
- Access through public getters/setters
- Protects data integrity

**2. Single Responsibility Principle**
- Each class has one clear purpose
- Question class handles question data
- Student class handles student data
- ExamSystem class handles business logic

**3. Separation of Concerns**
- UI logic separate from business logic
- File handling separate from data manipulation
- Clear boundaries between components

---

## 2. Code Structure

### 2.1 File Organization

```
main.cpp
├── Header Comments
├── Include Statements
├── Constants Definition
├── Question Class
│   ├── Private Members
│   ├── Public Methods
│   └── Display Methods
├── Student Class
│   ├── Private Members
│   ├── Public Methods
│   └── Display Methods
├── ExamResult Class
│   ├── Private Members
│   ├── Public Methods
│   └── Display Methods
├── ExamSystem Class
│   ├── Private Members
│   ├── File Handling Methods
│   ├── Admin Methods
│   ├── Student Methods
│   └── Utility Methods
├── Utility Functions
│   ├── clearScreen()
│   ├── pauseScreen()
│   └── Menu Display Functions
└── Main Function
    └── Program Flow Control
```

### 2.2 Dependencies

**Standard Libraries Used:**
- `<iostream>` - Input/output operations
- `<fstream>` - File handling
- `<string>` - String operations
- `<ctime>` - Time operations (if needed)
- `<cstdlib>` - System operations

**No External Dependencies** - Uses only standard C++ libraries

---

## 3. Class Documentation

### 3.1 Question Class

**Purpose:** Represents a single examination question

**Private Members:**
```cpp
int questionId;          // Unique identifier
string questionText;     // Question content
string optionA;          // First option
string optionB;          // Second option
string optionC;          // Third option
string optionD;          // Fourth option
char correctAnswer;      // Correct answer (A/B/C/D)
```

**Public Methods:**

| Method | Purpose | Parameters | Returns |
|--------|---------|------------|---------|
| `Question()` | Default constructor | None | N/A |
| `setQuestionId(int)` | Set question ID | int id | void |
| `setQuestionText(string)` | Set question text | string text | void |
| `setOptionA(string)` | Set option A | string a | void |
| `setOptionB(string)` | Set option B | string b | void |
| `setOptionC(string)` | Set option C | string c | void |
| `setOptionD(string)` | Set option D | string d | void |
| `setCorrectAnswer(char)` | Set correct answer | char ans | void |
| `getQuestionId()` | Get question ID | None | int |
| `getQuestionText()` | Get question text | None | string |
| `getOptionA()` | Get option A | None | string |
| `getOptionB()` | Get option B | None | string |
| `getOptionC()` | Get option C | None | string |
| `getOptionD()` | Get option D | None | string |
| `getCorrectAnswer()` | Get correct answer | None | char |
| `display()` | Display question | None | void |
| `displayWithAnswer()` | Display with answer | None | void |
| `input()` | Input question data | None | void |

**Usage Example:**
```cpp
Question q;
q.setQuestionId(1);
q.setQuestionText("What is OOP?");
q.setOptionA("Object Oriented Programming");
q.setOptionB("Object Oriented Process");
q.setOptionC("Only One Programming");
q.setOptionD("None");
q.setCorrectAnswer('A');
q.display();
```

### 3.2 Student Class

**Purpose:** Represents a registered student

**Private Members:**
```cpp
string studentId;        // Unique student identifier
string name;             // Student full name
string password;         // Login password
string email;            // Email address
```

**Public Methods:**

| Method | Purpose | Parameters | Returns |
|--------|---------|------------|---------|
| `Student()` | Default constructor | None | N/A |
| `setStudentId(string)` | Set student ID | string id | void |
| `setName(string)` | Set student name | string n | void |
| `setPassword(string)` | Set password | string pass | void |
| `setEmail(string)` | Set email | string e | void |
| `getStudentId()` | Get student ID | None | string |
| `getName()` | Get student name | None | string |
| `getPassword()` | Get password | None | string |
| `getEmail()` | Get email | None | string |
| `display()` | Display student info | None | void |
| `input()` | Input student data | None | void |

**Usage Example:**
```cpp
Student s;
s.setStudentId("S001");
s.setName("John Doe");
s.setEmail("john@email.com");
s.setPassword("pass123");
s.display();
```

### 3.3 ExamResult Class

**Purpose:** Stores and displays exam results

**Private Members:**
```cpp
string studentId;        // Student identifier
string studentName;      // Student name
int totalQuestions;      // Total questions in exam
int correctAnswers;      // Number of correct answers
int wrongAnswers;        // Number of wrong answers
float percentage;        // Percentage score
string status;           // PASS or FAIL
```

**Public Methods:**

| Method | Purpose | Parameters | Returns |
|--------|---------|------------|---------|
| `ExamResult()` | Default constructor | None | N/A |
| `setStudentId(string)` | Set student ID | string id | void |
| `setStudentName(string)` | Set student name | string name | void |
| `setTotalQuestions(int)` | Set total questions | int total | void |
| `setCorrectAnswers(int)` | Set correct answers | int correct | void |
| `getStudentId()` | Get student ID | None | string |
| `getStudentName()` | Get student name | None | string |
| `getTotalQuestions()` | Get total questions | None | int |
| `getCorrectAnswers()` | Get correct answers | None | int |
| `getPercentage()` | Get percentage | None | float |
| `getStatus()` | Get status | None | string |
| `display()` | Display result | None | void |

**Auto-Calculation:**
When `setCorrectAnswers()` is called:
- Calculates `wrongAnswers = totalQuestions - correctAnswers`
- Calculates `percentage = (correct / total) * 100`
- Determines `status = (percentage >= 50) ? "PASS" : "FAIL"`

**Usage Example:**
```cpp
ExamResult result;
result.setStudentId("S001");
result.setStudentName("John Doe");
result.setTotalQuestions(5);
result.setCorrectAnswers(4);  // Auto-calculates percentage and status
result.display();
```

### 3.4 ExamSystem Class

**Purpose:** Main system controller handling all operations

**Private Members:**
```cpp
Question questions[MAX_QUESTIONS];    // Array of questions
Student students[MAX_STUDENTS];       // Array of students
ExamResult results[MAX_RESULTS];      // Array of results
int questionCount;                    // Current question count
int studentCount;                     // Current student count
int resultCount;                      // Current result count
string currentStudentId;              // Logged-in student ID
string currentStudentName;            // Logged-in student name
```

**Public Methods:**

**Constructor:**
```cpp
ExamSystem()  // Initializes counts, loads data from files
```

**File Handling:**
- `saveQuestionsToFile()` - Save all questions
- `loadQuestionsFromFile()` - Load all questions
- `saveStudentsToFile()` - Save all students
- `loadStudentsFromFile()` - Load all students
- `saveResultsToFile()` - Append new result
- `loadResultsFromFile()` - Load all results

**Admin Methods:**
- `adminLogin()` - Authenticate admin
- `addQuestion()` - Add new question
- `editQuestion()` - Modify existing question
- `deleteQuestion()` - Remove question
- `viewAllQuestions()` - Display all questions
- `viewAllStudents()` - Display all students
- `viewAllResults()` - Display all results
- `loadSampleQuestions()` - Load predefined questions

**Student Methods:**
- `registerStudent()` - Register new student
- `studentLogin()` - Authenticate student
- `takeExam()` - Conduct examination
- `viewMyResults()` - Display student's results
- `studentLogout()` - Logout student

---

## 4. Function Reference

### 4.1 Utility Functions

#### clearScreen()
```cpp
void clearScreen()
```
**Purpose:** Clears the console screen  
**Platform:** Windows (uses `cls` command)  
**Note:** Change to `clear` for Linux/Mac

#### pauseScreen()
```cpp
void pauseScreen()
```
**Purpose:** Pauses execution until user presses Enter  
**Usage:** After displaying information to give user time to read

#### displayMainMenu()
```cpp
void displayMainMenu()
```
**Purpose:** Displays the main menu options  
**Output:** Formatted menu with 4 options

#### displayAdminMenu()
```cpp
void displayAdminMenu()
```
**Purpose:** Displays admin panel menu  
**Output:** Formatted menu with 8 options

#### displayStudentMenu()
```cpp
void displayStudentMenu()
```
**Purpose:** Displays student panel menu  
**Output:** Formatted menu with 3 options

### 4.2 Main Function Flow

```cpp
int main() {
    ExamSystem system;  // Create system object
    int choice;
    bool running = true;
    
    while(running) {
        displayMainMenu();
        cin >> choice;
        
        switch(choice) {
            case 1: // Admin Login
            case 2: // Student Login
            case 3: // Student Registration
            case 4: // Exit
        }
    }
    
    return 0;
}
```

---

## 5. File Handling

### 5.1 File Format Specifications

#### questions.txt
```
<questionCount>
<questionId>
<questionText>
<optionA>
<optionB>
<optionC>
<optionD>
<correctAnswer>
[repeat for each question]
```

**Example:**
```
2
1
What is OOP?
Object Oriented Programming
Object Oriented Process
Only One Programming
None
A
2
What is CPU?
Central Processing Unit
Computer Personal Unit
Central Program Utility
Computer Processing Unit
A
```

#### students.txt
```
<studentCount>
<studentId>
<name>
<email>
<password>
[repeat for each student]
```

**Example:**
```
2
S001
John Doe
john@email.com
pass123
S002
Jane Smith
jane@email.com
pass456
```

#### results.txt
```
<studentId>
<studentName>
<totalQuestions>
<correctAnswers>
<percentage>
<status>
[repeat for each result]
```

**Example:**
```
S001
John Doe
5
4
80
PASS
S001
John Doe
5
3
60
PASS
```

### 5.2 File Operations

#### Saving Questions
```cpp
void ExamSystem::saveQuestionsToFile() {
    ofstream file("questions.txt");
    if(file.is_open()) {
        file << questionCount << endl;
        for(int i = 0; i < questionCount; i++) {
            file << questions[i].getQuestionId() << endl;
            file << questions[i].getQuestionText() << endl;
            // ... save all fields
        }
        file.close();
    }
}
```

#### Loading Questions
```cpp
void ExamSystem::loadQuestionsFromFile() {
    ifstream file("questions.txt");
    if(file.is_open()) {
        file >> questionCount;
        file.ignore();  // Ignore newline
        for(int i = 0; i < questionCount; i++) {
            // Read all fields
            // Use getline() for strings
            // Use >> for numbers and chars
        }
        file.close();
    }
}
```

---

## 6. Extending the System

### 6.1 Adding New Features

#### Example: Add Question Categories

**Step 1: Modify Question Class**
```cpp
class Question {
private:
    // ... existing members
    string category;  // Add new member
    
public:
    // Add getter and setter
    void setCategory(string cat) { category = cat; }
    string getCategory() { return category; }
};
```

**Step 2: Update File Format**
Modify save/load functions to include category

**Step 3: Update Input Function**
```cpp
void Question::input() {
    // ... existing code
    cout << "Enter Category: ";
    getline(cin, category);
}
```

**Step 4: Update Display**
```cpp
void Question::display() {
    // ... existing code
    cout << "Category: " << category << endl;
}
```

#### Example: Add Timer to Exam

**Step 1: Include Required Header**
```cpp
#include <ctime>
```

**Step 2: Modify takeExam() Function**
```cpp
void ExamSystem::takeExam() {
    time_t startTime = time(0);
    int timeLimit = 300;  // 5 minutes
    
    for(int i = 0; i < questionCount; i++) {
        time_t currentTime = time(0);
        int elapsed = currentTime - startTime;
        
        if(elapsed >= timeLimit) {
            cout << "\nTime's up!\n";
            break;
        }
        
        int remaining = timeLimit - elapsed;
        cout << "Time remaining: " << remaining << " seconds\n";
        
        // ... rest of exam logic
    }
}
```

### 6.2 Adding New Classes

#### Example: Add Admin Class

```cpp
class Admin {
private:
    string adminId;
    string username;
    string password;
    
public:
    Admin() {
        adminId = "A001";
        username = "admin";
        password = "admin123";
    }
    
    bool authenticate(string user, string pass) {
        return (username == user && password == pass);
    }
    
    void changePassword(string newPass) {
        password = newPass;
    }
};
```

### 6.3 Improving Existing Features

#### Example: Better Input Validation

```cpp
char getValidAnswer() {
    char answer;
    while(true) {
        cout << "Your Answer (A/B/C/D): ";
        cin >> answer;
        
        // Convert to uppercase
        if(answer >= 'a' && answer <= 'd')
            answer = answer - 32;
        
        // Validate
        if(answer == 'A' || answer == 'B' || 
           answer == 'C' || answer == 'D') {
            return answer;
        }
        
        cout << "Invalid! Please enter A, B, C, or D.\n";
    }
}
```

---

## 7. Coding Standards

### 7.1 Naming Conventions

**Classes:** PascalCase
```cpp
class ExamSystem { };
class Question { };
```

**Functions:** camelCase
```cpp
void addQuestion();
void viewAllResults();
```

**Variables:** camelCase
```cpp
int questionCount;
string studentName;
```

**Constants:** UPPER_CASE
```cpp
const int MAX_QUESTIONS = 100;
const int PASSING_MARKS = 50;
```

### 7.2 Code Formatting

**Indentation:** 4 spaces
```cpp
class Question {
    private:
        int id;
    
    public:
        void display() {
            if(id > 0) {
                cout << id;
            }
        }
};
```

**Braces:** Opening brace on same line
```cpp
void function() {
    // code
}
```

**Comments:** Use descriptive comments
```cpp
// Calculate percentage score
percentage = (correct / total) * 100;

/**
 * @brief Authenticates admin user
 * @param username Admin username
 * @param password Admin password
 * @return true if authentication successful
 */
bool adminLogin(string username, string password);
```

### 7.3 Best Practices

1. **Always initialize variables**
```cpp
int count = 0;  // Good
int count;      // Bad
```

2. **Use const for constants**
```cpp
const int MAX = 100;  // Good
#define MAX 100       // Avoid
```

3. **Check file operations**
```cpp
ofstream file("data.txt");
if(file.is_open()) {
    // Proceed
} else {
    // Handle error
}
```

4. **Close files after use**
```cpp
file.open("data.txt");
// ... operations
file.close();  // Always close
```

5. **Validate user input**
```cpp
cin >> choice;
if(choice < 1 || choice > 4) {
    cout << "Invalid choice!\n";
}
```

---

## 8. Build and Deployment

### 8.1 Compilation

#### Using g++
```bash
# Basic compilation
g++ main.cpp -o exam_system

# With warnings
g++ -Wall main.cpp -o exam_system

# With optimization
g++ -O2 main.cpp -o exam_system

# With debugging symbols
g++ -g main.cpp -o exam_system
```

#### Using Visual Studio
1. Create new Console Application project
2. Add main.cpp to project
3. Build → Build Solution (Ctrl+Shift+B)
4. Debug → Start Without Debugging (Ctrl+F5)

#### Using Code::Blocks
1. File → New → Project → Console Application
2. Add main.cpp to project
3. Build → Build (Ctrl+F9)
4. Build → Run (Ctrl+F10)

### 8.2 Testing

#### Unit Testing Checklist
- [ ] Test each class constructor
- [ ] Test all getter/setter methods
- [ ] Test file save/load operations
- [ ] Test input validation
- [ ] Test edge cases (empty data, max limits)

#### Integration Testing
- [ ] Test admin login flow
- [ ] Test student registration and login
- [ ] Test complete exam flow
- [ ] Test result viewing
- [ ] Test data persistence

### 8.3 Deployment

#### For Windows
```bash
# Compile
g++ main.cpp -o exam_system.exe

# Create distribution folder
mkdir ExamSystem
copy exam_system.exe ExamSystem\
copy README.md ExamSystem\
copy USER_MANUAL.md ExamSystem\

# Create installer (optional)
# Use NSIS or Inno Setup
```

#### For Linux
```bash
# Compile
g++ main.cpp -o exam_system

# Make executable
chmod +x exam_system

# Create package
tar -czf exam_system.tar.gz exam_system README.md USER_MANUAL.md
```

### 8.4 Version Control

#### Git Workflow
```bash
# Initialize repository
git init

# Add files
git add main.cpp README.md

# Commit
git commit -m "Initial commit"

# Create branch for new feature
git checkout -b feature/timer

# Merge feature
git checkout main
git merge feature/timer
```

---

## Quick Reference

### Common Tasks

**Add new question field:**
1. Add private member to Question class
2. Add getter/setter methods
3. Update input() method
4. Update display() method
5. Update file save/load methods

**Add new menu option:**
1. Update menu display function
2. Add case in switch statement
3. Implement new function
4. Test thoroughly

**Modify file format:**
1. Update save function
2. Update load function
3. Test with existing data
4. Provide migration script if needed

---

**Guide Version:** 1.0  
**Last Updated:** May 2024  
**For System Version:** 1.0.0  

---

*Happy Coding!*
