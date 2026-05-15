# Online Examination Management System

## 📋 Project Overview

A comprehensive console-based **Online Examination Management System** developed in C++ using Object-Oriented Programming (OOP) principles. This system provides a complete solution for managing examinations, including question management, student registration, exam conducting, and result generation.

## ✨ Features

### Admin Features
- 🔐 Secure admin login
- ➕ Add new questions to the question bank
- ✏️ Edit existing questions
- 🗑️ Delete questions
- 👁️ View all questions with answers
- 👥 View all registered students
- 📊 View all exam results
- 📦 Load sample questions for testing

### Student Features
- 📝 Student registration with unique ID
- 🔑 Secure student login
- 📖 Take interactive examinations
- ✅ Automatic answer validation
- 📈 Instant score calculation
- 🏆 View exam results and history
- 📊 Pass/Fail status based on performance

## 🛠️ Technologies Used

- **Language:** C++
- **Paradigm:** Object-Oriented Programming (OOP)
- **Concepts:**
  - Classes and Objects
  - Encapsulation
  - File Handling
  - Arrays
  - Functions
  - Constructors
  - String Manipulation
  - Control Structures

## 📁 Project Structure

```
Online-Examination-System/
│
├── main.cpp                 # Main source code file
├── README.md                # Project documentation
├── DOCUMENTATION.md         # Detailed project documentation
├── USER_MANUAL.md          # User guide
├── DEVELOPER_GUIDE.md      # Developer documentation
├── TEST_CASES.md           # Testing documentation
├── .gitignore              # Git ignore file
├── LICENSE                 # Project license
│
└── data/                   # Data files (auto-generated)
    ├── questions.txt       # Question bank
    ├── students.txt        # Student records
    └── results.txt         # Exam results
```

## 🚀 Installation & Setup

### Prerequisites
- C++ Compiler (GCC, MinGW, or Visual Studio)
- Windows/Linux/Mac OS
- Basic command line knowledge

### Compilation Instructions

#### Using g++ (Linux/Mac/Windows with MinGW)
```bash
g++ main.cpp -o exam_system
```

#### Using Visual Studio (Windows)
1. Open Visual Studio
2. Create new C++ Console Application
3. Copy main.cpp content
4. Build Solution (Ctrl + Shift + B)
5. Run (Ctrl + F5)

#### Using Code::Blocks
1. Create new Console Application project
2. Add main.cpp to project
3. Build and Run (F9)

### Running the Program

#### On Windows
```bash
exam_system.exe
```

#### On Linux/Mac
```bash
./exam_system
```

## 📖 Usage Guide

### Default Credentials

**Admin Login:**
- Username: `admin`
- Password: `admin123`

### Quick Start

1. **First Time Setup:**
   - Run the program
   - Login as admin
   - Load sample questions (Option 7)
   - Logout

2. **Student Registration:**
   - Select "Student Registration" from main menu
   - Enter required details
   - Remember your Student ID and Password

3. **Taking Exam:**
   - Login with your Student ID
   - Select "Take Exam"
   - Answer all questions
   - View your result immediately

4. **View Results:**
   - Login as student
   - Select "View My Results"
   - See all your exam attempts

## 📊 Sample Input/Output

### Admin Adding Question
```
Enter Question Text: What is OOP?
Enter Option A: Object Oriented Programming
Enter Option B: Object Oriented Process
Enter Option C: Only One Programming
Enter Option D: None of the above
Enter Correct Answer (A/B/C/D): A

Question added successfully!
```

### Student Taking Exam
```
Question 1 of 5
----------------------------------------
What does CPU stand for?
A. Central Processing Unit
B. Computer Personal Unit
C. Central Program Utility
D. Computer Processing Unit
----------------------------------------
Your Answer (A/B/C/D): A
Correct!
```

### Exam Result
```
========================================
        EXAMINATION RESULT
========================================
Student ID: S001
Student Name: John Doe
Total Questions: 5
Correct Answers: 4
Wrong Answers: 1
Percentage: 80%
Status: PASS
========================================
```

## 🎯 Key Features Explained

### File Handling
- Questions stored in `questions.txt`
- Students stored in `students.txt`
- Results stored in `results.txt`
- Persistent data across sessions

### OOP Implementation
- **Question Class:** Manages question data
- **Student Class:** Handles student information
- **ExamResult Class:** Stores and displays results
- **ExamSystem Class:** Core system logic

### Input Validation
- Validates answer options (A/B/C/D only)
- Checks for duplicate student IDs
- Handles invalid menu choices
- Case-insensitive answer input

## 🔮 Future Enhancements

- [ ] Timer for examinations
- [ ] Randomized question order
- [ ] Multiple subjects/categories
- [ ] Difficulty levels
- [ ] Student ranking system
- [ ] Password encryption
- [ ] GUI interface
- [ ] Database integration
- [ ] Export results to PDF
- [ ] Email notifications

## 🐛 Known Limitations

- Maximum 100 questions supported
- Maximum 100 students supported
- No password encryption
- Console-based interface only
- Single admin account
- No question categories in exam

## 🤝 Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Student Project**
- University Final Year Project
- Course: Object-Oriented Programming
- Year: 2024

## 📞 Support

For issues, questions, or suggestions:
- Open an issue on GitHub
- Contact: [your-email@example.com]

## 🙏 Acknowledgments

- Thanks to all contributors
- Inspired by real-world examination systems
- Built for educational purposes

---

**⭐ If you find this project useful, please consider giving it a star!**

## 📸 Screenshots

### Main Menu
```
========================================
  EXAMINATION MANAGEMENT SYSTEM
========================================
1. Admin Login
2. Student Login
3. Student Registration
4. Exit
========================================
```

### Admin Panel
```
========================================
         ADMIN PANEL
========================================
1. Add Question
2. Edit Question
3. Delete Question
4. View All Questions
5. View All Students
6. View All Results
7. Load Sample Questions
8. Logout
========================================
```

### Student Panel
```
========================================
         STUDENT PANEL
========================================
1. Take Exam
2. View My Results
3. Logout
========================================
```

---

**Made with ❤️ using C++**
