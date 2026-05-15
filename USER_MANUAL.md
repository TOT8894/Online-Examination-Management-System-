# User Manual - Online Examination Management System

## Table of Contents
1. [Getting Started](#getting-started)
2. [System Overview](#system-overview)
3. [Admin Guide](#admin-guide)
4. [Student Guide](#student-guide)
5. [Troubleshooting](#troubleshooting)
6. [FAQs](#faqs)

---

## 1. Getting Started

### 1.1 System Requirements
- Computer with Windows/Linux/Mac OS
- C++ compiler installed
- Basic keyboard skills
- 50 MB free disk space

### 1.2 Installation
1. Download the source code
2. Compile using: `g++ main.cpp -o exam_system`
3. Run the executable: `./exam_system` (Linux/Mac) or `exam_system.exe` (Windows)

### 1.3 First Time Setup
When you run the program for the first time:
1. Login as admin (username: `admin`, password: `admin123`)
2. Load sample questions (Option 7 in Admin Menu)
3. Logout and proceed with student registration

---

## 2. System Overview

### 2.1 Main Menu
When you start the program, you'll see:
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

### 2.2 User Roles

#### Administrator
- Manages questions (add, edit, delete)
- Views all students
- Views all exam results
- Loads sample data

#### Student
- Registers in the system
- Takes examinations
- Views personal results

---

## 3. Admin Guide

### 3.1 Admin Login

**Steps:**
1. Select option `1` from main menu
2. Enter username: `admin`
3. Enter password: `admin123`
4. Press Enter

**Success:** You'll see "Login Successful!" and the Admin Panel menu

**Failure:** "Invalid Credentials!" - check your username and password

### 3.2 Admin Panel Menu
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

### 3.3 Adding a Question

**Steps:**
1. Select option `1` from Admin Panel
2. Enter question text (e.g., "What is OOP?")
3. Enter option A (e.g., "Object Oriented Programming")
4. Enter option B (e.g., "Object Oriented Process")
5. Enter option C (e.g., "Only One Programming")
6. Enter option D (e.g., "None of the above")
7. Enter correct answer: A, B, C, or D
8. Press Enter

**Example:**
```
Enter Question Text: What does CPU stand for?
Enter Option A: Central Processing Unit
Enter Option B: Computer Personal Unit
Enter Option C: Central Program Utility
Enter Option D: Computer Processing Unit
Enter Correct Answer (A/B/C/D): A

Question added successfully!
```

**Tips:**
- Keep questions clear and concise
- Ensure options are distinct
- Double-check the correct answer
- Questions are automatically assigned IDs

### 3.4 Editing a Question

**Steps:**
1. Select option `2` from Admin Panel
2. View the list of all questions with their IDs
3. Enter the Question ID you want to edit
4. Enter new question text (or press Enter to keep current)
5. Enter new options (or press Enter to keep current)
6. Enter new correct answer (or press Enter to keep current)
7. Confirm changes

**Example:**
```
Enter Question ID to edit: 3

Current Question:
----------------------------------------
Question ID: 3
What is the output of 2*3?
A. 5
B. 6
C. 8
D. 9
Correct Answer: B
----------------------------------------

Enter new details (press Enter to keep current):
New Question Text: [Press Enter]
New Option A: [Press Enter]
...
```

**Tips:**
- View all questions first to find the correct ID
- Press Enter to keep existing values
- Changes are saved immediately

### 3.5 Deleting a Question

**Steps:**
1. Select option `3` from Admin Panel
2. View the list of all questions
3. Enter the Question ID to delete
4. Confirm deletion

**Warning:** Deleted questions cannot be recovered!

**Example:**
```
Enter Question ID to delete: 5

Question deleted successfully!
```

### 3.6 Viewing All Questions

**Steps:**
1. Select option `4` from Admin Panel
2. All questions will be displayed with:
   - Question ID
   - Question text
   - All four options
   - Correct answer

**Use this to:**
- Review question bank
- Find question IDs for editing/deleting
- Check for duplicate questions
- Verify correct answers

### 3.7 Viewing All Students

**Steps:**
1. Select option `5` from Admin Panel
2. All registered students will be displayed with:
   - Student ID
   - Full name
   - Email address

**Use this to:**
- Check registered students
- Verify student information
- Monitor system usage

### 3.8 Viewing All Results

**Steps:**
1. Select option `6` from Admin Panel
2. All exam results will be displayed with:
   - Student ID and name
   - Total questions
   - Correct/wrong answers
   - Percentage
   - Pass/Fail status

**Use this to:**
- Monitor student performance
- Identify struggling students
- Generate reports
- Analyze exam difficulty

### 3.9 Loading Sample Questions

**Steps:**
1. Select option `7` from Admin Panel
2. System will load 5 sample questions automatically
3. Confirmation message will appear

**Note:** This option is useful for:
- Testing the system
- Quick setup
- Demonstration purposes

**Sample questions include topics like:**
- Computer Science basics
- Programming concepts
- Data structures

### 3.10 Admin Logout

**Steps:**
1. Select option `8` from Admin Panel
2. You'll return to the main menu

**Always logout when finished** to maintain security.

---

## 4. Student Guide

### 4.1 Student Registration

**Steps:**
1. Select option `3` from main menu
2. Enter your Student ID (must be unique)
3. Enter your full name
4. Enter your email address
5. Enter a password (remember this!)
6. Confirm registration

**Example:**
```
========================================
      STUDENT REGISTRATION
========================================
Enter Student ID: S001
Enter Full Name: John Doe
Enter Email: john.doe@email.com
Enter Password: mypassword123

Registration successful! You can now login.
```

**Important:**
- Student ID must be unique
- Remember your password (no recovery option)
- Use a valid email format
- All fields are required

**Tips:**
- Choose a memorable Student ID
- Use a strong password
- Write down your credentials

### 4.2 Student Login

**Steps:**
1. Select option `2` from main menu
2. Enter your Student ID
3. Enter your password
4. Press Enter

**Example:**
```
========================================
         STUDENT LOGIN
========================================
Student ID: S001
Password: mypassword123

Login Successful! Welcome, John Doe!
```

**Troubleshooting:**
- "Invalid Credentials!" - Check your ID and password
- Make sure you're registered first
- Student ID is case-sensitive

### 4.3 Student Panel Menu
```
========================================
         STUDENT PANEL
========================================
1. Take Exam
2. View My Results
3. Logout
========================================
```

### 4.4 Taking an Exam

**Steps:**
1. Select option `1` from Student Panel
2. Read the exam instructions
3. Press Enter to start
4. For each question:
   - Read the question carefully
   - Review all four options
   - Enter your answer (A, B, C, or D)
   - See immediate feedback (Correct/Wrong)
5. View your final result

**Example:**
```
========================================
         START EXAM
========================================
Total Questions: 5
Passing Marks: 50%

Press Enter to start...

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

[Continue for all questions...]

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

Result saved successfully!
```

**Exam Rules:**
- Answer all questions (cannot skip)
- Each correct answer = 1 mark
- No negative marking
- Immediate feedback after each answer
- 50% required to pass
- Results saved automatically

**Tips:**
- Read questions carefully
- Don't rush
- Review all options before answering
- Learn from wrong answers
- You can take the exam multiple times

### 4.5 Viewing Your Results

**Steps:**
1. Select option `2` from Student Panel
2. All your exam attempts will be displayed
3. Review your performance history

**Information Shown:**
- Student ID and name
- Total questions in each attempt
- Correct and wrong answers
- Percentage scored
- Pass/Fail status
- Date of exam (if implemented)

**Use this to:**
- Track your progress
- Identify weak areas
- Celebrate improvements
- Plan further study

**Example:**
```
========================================
      YOUR EXAM RESULTS
========================================

Attempt 1:
========================================
        EXAMINATION RESULT
========================================
Student ID: S001
Student Name: John Doe
Total Questions: 5
Correct Answers: 3
Wrong Answers: 2
Percentage: 60%
Status: PASS
========================================

Attempt 2:
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

### 4.6 Student Logout

**Steps:**
1. Select option `3` from Student Panel
2. You'll return to the main menu

**Always logout** when you're done to protect your privacy.

---

## 5. Troubleshooting

### 5.1 Common Issues and Solutions

#### Issue: Program won't compile
**Solutions:**
- Check if C++ compiler is installed
- Verify file name is correct (main.cpp)
- Try: `g++ --version` to check compiler
- Ensure no syntax errors in code

#### Issue: "File not found" error
**Solutions:**
- Program creates files automatically
- Ensure you have write permissions
- Check if running from correct directory
- Files are created in same folder as executable

#### Issue: Cannot login as admin
**Solutions:**
- Username: `admin` (lowercase)
- Password: `admin123` (exact match)
- Check for extra spaces
- Credentials are case-sensitive

#### Issue: Student ID already exists
**Solutions:**
- Choose a different Student ID
- Check if you're already registered
- Try logging in instead of registering

#### Issue: No questions available for exam
**Solutions:**
- Login as admin first
- Load sample questions (Admin option 7)
- Or add questions manually
- Logout and login as student again

#### Issue: Invalid answer input during exam
**Solutions:**
- Enter only A, B, C, or D
- Both uppercase and lowercase work
- Don't enter full words
- Press Enter after your choice

#### Issue: Results not saving
**Solutions:**
- Check disk space
- Ensure write permissions
- Don't close program abruptly
- Complete the exam fully

#### Issue: Screen not clearing properly
**Solutions:**
- This is normal on some systems
- Doesn't affect functionality
- Scroll up to see previous content
- Consider using terminal with clear screen support

### 5.2 Data File Issues

#### Lost data files
**Problem:** Accidentally deleted questions.txt, students.txt, or results.txt

**Solution:**
- Files will be recreated automatically
- But previous data is lost
- Always keep backups
- Load sample questions to restart

#### Corrupted data files
**Problem:** Files contain invalid data

**Solution:**
- Delete the corrupted file
- Program will create new one
- Re-enter data manually
- Or restore from backup

### 5.3 Performance Issues

#### Program running slow
**Solutions:**
- Close other applications
- Check available RAM
- Reduce number of questions/students
- Restart the program

#### File operations taking time
**Solutions:**
- Normal for large data files
- Be patient during save/load
- Don't interrupt file operations
- Consider data cleanup

---

## 6. FAQs

### General Questions

**Q: Is this system free to use?**  
A: Yes, it's an open-source educational project.

**Q: Can I modify the source code?**  
A: Yes, you can customize it for your needs.

**Q: Does it work on Mac/Linux?**  
A: Yes, it's cross-platform compatible.

**Q: Do I need internet connection?**  
A: No, it works completely offline.

### Admin Questions

**Q: Can I change admin password?**  
A: Currently no, but you can modify the code to change it.

**Q: How many questions can I add?**  
A: Maximum 100 questions in current version.

**Q: Can I import questions from Excel?**  
A: Not in current version, but can be added as enhancement.

**Q: Can I delete all questions at once?**  
A: No, delete one by one or delete the questions.txt file.

**Q: Can I have multiple admins?**  
A: Not in current version, only one admin account.

### Student Questions

**Q: Can I change my password?**  
A: Not in current version, register with new ID if needed.

**Q: How many times can I take the exam?**  
A: Unlimited attempts allowed.

**Q: Can I review questions before submitting?**  
A: No, current version shows one question at a time.

**Q: Is there a time limit?**  
A: No time limit in current version.

**Q: Can I skip questions?**  
A: No, must answer all questions in sequence.

**Q: What's the passing percentage?**  
A: 50% or above is considered passing.

**Q: Can I see correct answers after exam?**  
A: Yes, shown immediately after each answer.

**Q: Are questions randomized?**  
A: Not in current version, same order for all.

### Technical Questions

**Q: Where is data stored?**  
A: In text files in the same directory as program.

**Q: Is my password encrypted?**  
A: No, stored in plain text (not recommended for production).

**Q: Can multiple users use simultaneously?**  
A: No, single-user system only.

**Q: How do I backup my data?**  
A: Copy questions.txt, students.txt, and results.txt files.

**Q: Can I run this on a server?**  
A: It's a console application, not designed for server deployment.

**Q: What C++ standard is required?**  
A: C++98 or higher, uses basic features only.

### Troubleshooting Questions

**Q: Program crashes during exam, what happens?**  
A: Results not saved, need to retake exam.

**Q: Forgot my student password, what to do?**  
A: No recovery option, register with new ID or ask admin to check students.txt file.

**Q: Can I recover deleted questions?**  
A: No, deletion is permanent unless you have backup.

**Q: System shows wrong result, why?**  
A: Check if correct answers are set properly in questions.

---

## Quick Reference Card

### Admin Credentials
- Username: `admin`
- Password: `admin123`

### File Locations
- Questions: `questions.txt`
- Students: `students.txt`
- Results: `results.txt`

### Passing Criteria
- Minimum: 50%
- Status: PASS/FAIL

### System Limits
- Max Questions: 100
- Max Students: 100
- Max Results: 100

### Valid Answer Options
- A, B, C, D (case-insensitive)

### Important Tips
1. Always logout after use
2. Backup data files regularly
3. Load sample questions for testing
4. Remember your credentials
5. Complete exams fully

---

## Getting Help

### Support Resources
- Read this manual thoroughly
- Check troubleshooting section
- Review code comments
- Consult developer guide

### Reporting Issues
- Document the problem clearly
- Note error messages
- Describe steps to reproduce
- Check if issue is already known

### Feedback
Your feedback helps improve the system:
- Suggest new features
- Report bugs
- Share user experience
- Contribute improvements

---

**Manual Version:** 1.0  
**Last Updated:** May 2024  
**For System Version:** 1.0.0  

---

*Thank you for using the Online Examination Management System!*
