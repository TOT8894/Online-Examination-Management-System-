/**
 * ============================================================================
 * ONLINE EXAMINATION MANAGEMENT SYSTEM
 * ============================================================================
 * A simple console-based examination system using basic C++ and OOP
 * Author: Student Project
 * Version: 1.0.0
 * ============================================================================
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// ============================================================================
// CONSTANTS
// ============================================================================
const int MAX_QUESTIONS = 100;
const int MAX_STUDENTS = 100;
const int MAX_RESULTS = 100;
const int PASSING_MARKS = 50;

// ============================================================================
// QUESTION CLASS
// ============================================================================
class Question {
private:
    int questionId;
    string questionText;
    string optionA;
    string optionB;
    string optionC;
    string optionD;
    char correctAnswer;

public:
    // Constructor
    Question() {
        questionId = 0;
        questionText = "";
        optionA = "";
        optionB = "";
        optionC = "";
        optionD = "";
        correctAnswer = 'A';
    }

    // Setters
    void setQuestionId(int id) { questionId = id; }
    void setQuestionText(string text) { questionText = text; }
    void setOptionA(string a) { optionA = a; }
    void setOptionB(string b) { optionB = b; }
    void setOptionC(string c) { optionC = c; }
    void setOptionD(string d) { optionD = d; }
    void setCorrectAnswer(char ans) { 
        if(ans >= 'a' && ans <= 'd') ans = ans - 32; // Convert to uppercase
        correctAnswer = ans; 
    }

    // Getters
    int getQuestionId() { return questionId; }
    string getQuestionText() { return questionText; }
    string getOptionA() { return optionA; }
    string getOptionB() { return optionB; }
    string getOptionC() { return optionC; }
    string getOptionD() { return optionD; }
    char getCorrectAnswer() { return correctAnswer; }

    // Display question
    void display() {
        cout << "\n----------------------------------------\n";
        cout << "Question ID: " << questionId << endl;
        cout << questionText << endl;
        cout << "A. " << optionA << endl;
        cout << "B. " << optionB << endl;
        cout << "C. " << optionC << endl;
        cout << "D. " << optionD << endl;
        cout << "----------------------------------------\n";
    }

    // Display with answer (for admin)
    void displayWithAnswer() {
        display();
        cout << "Correct Answer: " << correctAnswer << endl;
    }

    // Input question details
    void input() {
        cout << "\nEnter Question Text: ";
        cin.ignore();
        getline(cin, questionText);
        
        cout << "Enter Option A: ";
        getline(cin, optionA);
        
        cout << "Enter Option B: ";
        getline(cin, optionB);
        
        cout << "Enter Option C: ";
        getline(cin, optionC);
        
        cout << "Enter Option D: ";
        getline(cin, optionD);
        
        cout << "Enter Correct Answer (A/B/C/D): ";
        cin >> correctAnswer;
        if(correctAnswer >= 'a' && correctAnswer <= 'd') 
            correctAnswer = correctAnswer - 32;
    }
};

// ============================================================================
// STUDENT CLASS
// ============================================================================
class Student {
private:
    string studentId;
    string name;
    string password;
    string email;

public:
    // Constructor
    Student() {
        studentId = "";
        name = "";
        password = "";
        email = "";
    }

    // Setters
    void setStudentId(string id) { studentId = id; }
    void setName(string n) { name = n; }
    void setPassword(string pass) { password = pass; }
    void setEmail(string e) { email = e; }

    // Getters
    string getStudentId() { return studentId; }
    string getName() { return name; }
    string getPassword() { return password; }
    string getEmail() { return email; }

    // Display student info
    void display() {
        cout << "\n========================================\n";
        cout << "Student ID: " << studentId << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "========================================\n";
    }

    // Input student details
    void input() {
        cout << "\nEnter Student ID: ";
        cin >> studentId;
        cin.ignore();
        
        cout << "Enter Full Name: ";
        getline(cin, name);
        
        cout << "Enter Email: ";
        cin >> email;
        
        cout << "Enter Password: ";
        cin >> password;
    }
};

// ============================================================================
// EXAM RESULT CLASS
// ============================================================================
class ExamResult {
private:
    string studentId;
    string studentName;
    int totalQuestions;
    int correctAnswers;
    int wrongAnswers;
    float percentage;
    string status;

public:
    // Constructor
    ExamResult() {
        studentId = "";
        studentName = "";
        totalQuestions = 0;
        correctAnswers = 0;
        wrongAnswers = 0;
        percentage = 0.0;
        status = "Fail";
    }

    // Setters
    void setStudentId(string id) { studentId = id; }
    void setStudentName(string name) { studentName = name; }
    void setTotalQuestions(int total) { totalQuestions = total; }
    void setCorrectAnswers(int correct) { 
        correctAnswers = correct; 
        wrongAnswers = totalQuestions - correct;
        percentage = ((float)correct / totalQuestions) * 100;
        status = (percentage >= PASSING_MARKS) ? "PASS" : "FAIL";
    }

    // Getters
    string getStudentId() { return studentId; }
    string getStudentName() { return studentName; }
    int getTotalQuestions() { return totalQuestions; }
    int getCorrectAnswers() { return correctAnswers; }
    float getPercentage() { return percentage; }
    string getStatus() { return status; }

    // Display result
    void display() {
        cout << "\n========================================\n";
        cout << "        EXAMINATION RESULT\n";
        cout << "========================================\n";
        cout << "Student ID: " << studentId << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Total Questions: " << totalQuestions << endl;
        cout << "Correct Answers: " << correctAnswers << endl;
        cout << "Wrong Answers: " << wrongAnswers << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Status: " << status << endl;
        cout << "========================================\n";
    }
};

// ============================================================================
// EXAM SYSTEM CLASS
// ============================================================================
class ExamSystem {
private:
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];
    ExamResult results[MAX_RESULTS];
    int questionCount;
    int studentCount;
    int resultCount;
    string currentStudentId;
    string currentStudentName;

public:
    // Constructor
    ExamSystem() {
        questionCount = 0;
        studentCount = 0;
        resultCount = 0;
        currentStudentId = "";
        currentStudentName = "";
        loadQuestionsFromFile();
        loadStudentsFromFile();
        loadResultsFromFile();
    }

    // ==================== FILE HANDLING FUNCTIONS ====================
    
    void saveQuestionsToFile() {
        ofstream file("questions.txt");
        if(file.is_open()) {
            file << questionCount << endl;
            for(int i = 0; i < questionCount; i++) {
                file << questions[i].getQuestionId() << endl;
                file << questions[i].getQuestionText() << endl;
                file << questions[i].getOptionA() << endl;
                file << questions[i].getOptionB() << endl;
                file << questions[i].getOptionC() << endl;
                file << questions[i].getOptionD() << endl;
                file << questions[i].getCorrectAnswer() << endl;
            }
            file.close();
        }
    }

    void loadQuestionsFromFile() {
        ifstream file("questions.txt");
        if(file.is_open()) {
            file >> questionCount;
            file.ignore();
            for(int i = 0; i < questionCount; i++) {
                int id;
                string text, a, b, c, d;
                char ans;
                
                file >> id;
                file.ignore();
                getline(file, text);
                getline(file, a);
                getline(file, b);
                getline(file, c);
                getline(file, d);
                file >> ans;
                file.ignore();
                
                questions[i].setQuestionId(id);
                questions[i].setQuestionText(text);
                questions[i].setOptionA(a);
                questions[i].setOptionB(b);
                questions[i].setOptionC(c);
                questions[i].setOptionD(d);
                questions[i].setCorrectAnswer(ans);
            }
            file.close();
        }
    }

    void saveStudentsToFile() {
        ofstream file("students.txt");
        if(file.is_open()) {
            file << studentCount << endl;
            for(int i = 0; i < studentCount; i++) {
                file << students[i].getStudentId() << endl;
                file << students[i].getName() << endl;
                file << students[i].getEmail() << endl;
                file << students[i].getPassword() << endl;
            }
            file.close();
        }
    }

    void loadStudentsFromFile() {
        ifstream file("students.txt");
        if(file.is_open()) {
            file >> studentCount;
            file.ignore();
            for(int i = 0; i < studentCount; i++) {
                string id, name, email, pass;
                getline(file, id);
                getline(file, name);
                getline(file, email);
                getline(file, pass);
                
                students[i].setStudentId(id);
                students[i].setName(name);
                students[i].setEmail(email);
                students[i].setPassword(pass);
            }
            file.close();
        }
    }

    void saveResultsToFile() {
        ofstream file("results.txt", ios::app);
        if(file.is_open()) {
            file << results[resultCount-1].getStudentId() << endl;
            file << results[resultCount-1].getStudentName() << endl;
            file << results[resultCount-1].getTotalQuestions() << endl;
            file << results[resultCount-1].getCorrectAnswers() << endl;
            file << results[resultCount-1].getPercentage() << endl;
            file << results[resultCount-1].getStatus() << endl;
            file.close();
        }
    }

    void loadResultsFromFile() {
        ifstream file("results.txt");
        if(file.is_open()) {
            resultCount = 0;
            while(!file.eof() && resultCount < MAX_RESULTS) {
                string id, name, status;
                int total, correct;
                float percentage;
                
                getline(file, id);
                if(id.empty()) break;
                getline(file, name);
                file >> total >> correct >> percentage;
                file.ignore();
                getline(file, status);
                
                results[resultCount].setStudentId(id);
                results[resultCount].setStudentName(name);
                results[resultCount].setTotalQuestions(total);
                results[resultCount].setCorrectAnswers(correct);
                resultCount++;
            }
            file.close();
        }
    }

    // ==================== ADMIN FUNCTIONS ====================

    bool adminLogin() {
        string username, password;
        cout << "\n========================================\n";
        cout << "         ADMIN LOGIN\n";
        cout << "========================================\n";
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        
        // Default admin credentials
        if(username == "admin" && password == "admin123") {
            cout << "\nLogin Successful!\n";
            return true;
        }
        cout << "\nInvalid Credentials!\n";
        return false;
    }

    void addQuestion() {
        if(questionCount >= MAX_QUESTIONS) {
            cout << "\nQuestion limit reached!\n";
            return;
        }
        
        cout << "\n========================================\n";
        cout << "         ADD NEW QUESTION\n";
        cout << "========================================\n";
        
        questions[questionCount].setQuestionId(questionCount + 1);
        questions[questionCount].input();
        questionCount++;
        
        saveQuestionsToFile();
        cout << "\nQuestion added successfully!\n";
    }

    void editQuestion() {
        if(questionCount == 0) {
            cout << "\nNo questions available!\n";
            return;
        }
        
        viewAllQuestions();
        
        int id;
        cout << "\nEnter Question ID to edit: ";
        cin >> id;
        
        bool found = false;
        for(int i = 0; i < questionCount; i++) {
            if(questions[i].getQuestionId() == id) {
                found = true;
                cout << "\nCurrent Question:\n";
                questions[i].displayWithAnswer();
                cout << "\nEnter new details:\n";
                questions[i].input();
                saveQuestionsToFile();
                cout << "\nQuestion updated successfully!\n";
                break;
            }
        }
        
        if(!found) {
            cout << "\nQuestion not found!\n";
        }
    }

    void deleteQuestion() {
        if(questionCount == 0) {
            cout << "\nNo questions available!\n";
            return;
        }
        
        viewAllQuestions();
        
        int id;
        cout << "\nEnter Question ID to delete: ";
        cin >> id;
        
        bool found = false;
        for(int i = 0; i < questionCount; i++) {
            if(questions[i].getQuestionId() == id) {
                found = true;
                // Shift all questions after this one
                for(int j = i; j < questionCount - 1; j++) {
                    questions[j] = questions[j + 1];
                }
                questionCount--;
                saveQuestionsToFile();
                cout << "\nQuestion deleted successfully!\n";
                break;
            }
        }
        
        if(!found) {
            cout << "\nQuestion not found!\n";
        }
    }

    void viewAllQuestions() {
        if(questionCount == 0) {
            cout << "\nNo questions available!\n";
            return;
        }
        
        cout << "\n========================================\n";
        cout << "    ALL QUESTIONS (" << questionCount << ")\n";
        cout << "========================================\n";
        
        for(int i = 0; i < questionCount; i++) {
            questions[i].displayWithAnswer();
        }
    }

    void viewAllStudents() {
        if(studentCount == 0) {
            cout << "\nNo students registered!\n";
            return;
        }
        
        cout << "\n========================================\n";
        cout << "    REGISTERED STUDENTS (" << studentCount << ")\n";
        cout << "========================================\n";
        
        for(int i = 0; i < studentCount; i++) {
            students[i].display();
        }
    }

    void viewAllResults() {
        if(resultCount == 0) {
            cout << "\nNo results available!\n";
            return;
        }
        
        cout << "\n========================================\n";
        cout << "    ALL EXAM RESULTS (" << resultCount << ")\n";
        cout << "========================================\n";
        
        for(int i = 0; i < resultCount; i++) {
            results[i].display();
        }
    }

    // ==================== STUDENT FUNCTIONS ====================

    void registerStudent() {
        if(studentCount >= MAX_STUDENTS) {
            cout << "\nStudent limit reached!\n";
            return;
        }
        
        cout << "\n========================================\n";
        cout << "      STUDENT REGISTRATION\n";
        cout << "========================================\n";
        
        students[studentCount].input();
        
        // Check if ID already exists
        string newId = students[studentCount].getStudentId();
        for(int i = 0; i < studentCount; i++) {
            if(students[i].getStudentId() == newId) {
                cout << "\nStudent ID already exists!\n";
                return;
            }
        }
        
        studentCount++;
        saveStudentsToFile();
        cout << "\nRegistration successful! You can now login.\n";
    }

    bool studentLogin() {
        string id, pass;
        cout << "\n========================================\n";
        cout << "         STUDENT LOGIN\n";
        cout << "========================================\n";
        cout << "Student ID: ";
        cin >> id;
        cout << "Password: ";
        cin >> pass;
        
        for(int i = 0; i < studentCount; i++) {
            if(students[i].getStudentId() == id && students[i].getPassword() == pass) {
                currentStudentId = id;
                currentStudentName = students[i].getName();
                cout << "\nLogin Successful! Welcome, " << currentStudentName << "!\n";
                return true;
            }
        }
        
        cout << "\nInvalid Credentials!\n";
        return false;
    }

    void takeExam() {
        if(currentStudentId.empty()) {
            cout << "\nPlease login first!\n";
            return;
        }
        
        if(questionCount == 0) {
            cout << "\nNo questions available!\n";
            return;
        }
        
        cout << "\n========================================\n";
        cout << "         START EXAM\n";
        cout << "========================================\n";
        cout << "Total Questions: " << questionCount << endl;
        cout << "Passing Marks: " << PASSING_MARKS << "%" << endl;
        cout << "\nPress Enter to start...";
        cin.ignore();
        cin.get();
        
        int correctAnswers = 0;
        char answer;
        
        for(int i = 0; i < questionCount; i++) {
            cout << "\n\nQuestion " << (i+1) << " of " << questionCount << endl;
            questions[i].display();
            
            do {
                cout << "Your Answer (A/B/C/D): ";
                cin >> answer;
                if(answer >= 'a' && answer <= 'd') 
                    answer = answer - 32;
                
                if(answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D') {
                    cout << "Invalid option! Please enter A, B, C, or D.\n";
                }
            } while(answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D');
            
            if(answer == questions[i].getCorrectAnswer()) {
                correctAnswers++;
                cout << "Correct!\n";
            } else {
                cout << "Wrong! Correct answer is: " << questions[i].getCorrectAnswer() << endl;
            }
        }
        
        // Save result
        results[resultCount].setStudentId(currentStudentId);
        results[resultCount].setStudentName(currentStudentName);
        results[resultCount].setTotalQuestions(questionCount);
        results[resultCount].setCorrectAnswers(correctAnswers);
        resultCount++;
        
        results[resultCount-1].display();
        saveResultsToFile();
        
        cout << "\nResult saved successfully!\n";
    }

    void viewMyResults() {
        if(currentStudentId.empty()) {
            cout << "\nPlease login first!\n";
            return;
        }
        
        bool found = false;
        cout << "\n========================================\n";
        cout << "      YOUR EXAM RESULTS\n";
        cout << "========================================\n";
        
        for(int i = 0; i < resultCount; i++) {
            if(results[i].getStudentId() == currentStudentId) {
                results[i].display();
                found = true;
            }
        }
        
        if(!found) {
            cout << "\nNo results found!\n";
        }
    }

    void studentLogout() {
        currentStudentId = "";
        currentStudentName = "";
        cout << "\nLogged out successfully!\n";
    }

    // ==================== SAMPLE DATA ====================

    void loadSampleQuestions() {
        if(questionCount > 0) return; // Don't load if questions exist
        
        // Question 1
        questions[0].setQuestionId(1);
        questions[0].setQuestionText("What does CPU stand for?");
        questions[0].setOptionA("Central Processing Unit");
        questions[0].setOptionB("Computer Personal Unit");
        questions[0].setOptionC("Central Program Utility");
        questions[0].setOptionD("Computer Processing Unit");
        questions[0].setCorrectAnswer('A');
        
        // Question 2
        questions[1].setQuestionId(2);
        questions[1].setQuestionText("Which data structure uses LIFO principle?");
        questions[1].setOptionA("Queue");
        questions[1].setOptionB("Stack");
        questions[1].setOptionC("Array");
        questions[1].setOptionD("Tree");
        questions[1].setCorrectAnswer('B');
        
        // Question 3
        questions[2].setQuestionId(3);
        questions[2].setQuestionText("What is the output of 2*3 in most languages?");
        questions[2].setOptionA("5");
        questions[2].setOptionB("6");
        questions[2].setOptionC("8");
        questions[2].setOptionD("9");
        questions[2].setCorrectAnswer('B');
        
        // Question 4
        questions[3].setQuestionId(4);
        questions[3].setQuestionText("Which is not a programming language?");
        questions[3].setOptionA("Python");
        questions[3].setOptionB("Java");
        questions[3].setOptionC("HTML");
        questions[3].setOptionD("C++");
        questions[3].setCorrectAnswer('C');
        
        // Question 5
        questions[4].setQuestionId(5);
        questions[4].setQuestionText("What is the smallest unit of data?");
        questions[4].setOptionA("Bit");
        questions[4].setOptionB("Byte");
        questions[4].setOptionC("Nibble");
        questions[4].setOptionD("Word");
        questions[4].setCorrectAnswer('A');
        
        questionCount = 5;
        saveQuestionsToFile();
        cout << "\nSample questions loaded successfully!\n";
    }
};

// ============================================================================
// UTILITY FUNCTIONS
// ============================================================================

void clearScreen() {
    system("cls");  // For Windows
    // system("clear");  // For Linux/Mac
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void displayMainMenu() {
    cout << "\n========================================\n";
    cout << "  EXAMINATION MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Admin Login\n";
    cout << "2. Student Login\n";
    cout << "3. Student Registration\n";
    cout << "4. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

void displayAdminMenu() {
    cout << "\n========================================\n";
    cout << "         ADMIN PANEL\n";
    cout << "========================================\n";
    cout << "1. Add Question\n";
    cout << "2. Edit Question\n";
    cout << "3. Delete Question\n";
    cout << "4. View All Questions\n";
    cout << "5. View All Students\n";
    cout << "6. View All Results\n";
    cout << "7. Load Sample Questions\n";
    cout << "8. Logout\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

void displayStudentMenu() {
    cout << "\n========================================\n";
    cout << "         STUDENT PANEL\n";
    cout << "========================================\n";
    cout << "1. Take Exam\n";
    cout << "2. View My Results\n";
    cout << "3. Logout\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main() {
    ExamSystem system;
    int choice;
    bool running = true;
    
    cout << "\n";
    cout << "========================================\n";
    cout << "  WELCOME TO EXAMINATION SYSTEM\n";
    cout << "========================================\n";
    
    while(running) {
        displayMainMenu();
        cin >> choice;
        
        switch(choice) {
            case 1: {
                // Admin Login
                if(system.adminLogin()) {
                    bool adminLoggedIn = true;
                    while(adminLoggedIn) {
                        displayAdminMenu();
                        int adminChoice;
                        cin >> adminChoice;
                        
                        switch(adminChoice) {
                            case 1:
                                system.addQuestion();
                                pauseScreen();
                                break;
                            case 2:
                                system.editQuestion();
                                pauseScreen();
                                break;
                            case 3:
                                system.deleteQuestion();
                                pauseScreen();
                                break;
                            case 4:
                                system.viewAllQuestions();
                                pauseScreen();
                                break;
                            case 5:
                                system.viewAllStudents();
                                pauseScreen();
                                break;
                            case 6:
                                system.viewAllResults();
                                pauseScreen();
                                break;
                            case 7:
                                system.loadSampleQuestions();
                                pauseScreen();
                                break;
                            case 8:
                                adminLoggedIn = false;
                                cout << "\nLogged out successfully!\n";
                                break;
                            default:
                                cout << "\nInvalid choice!\n";
                        }
                    }
                }
                pauseScreen();
                break;
            }
            
            case 2: {
                // Student Login
                if(system.studentLogin()) {
                    bool studentLoggedIn = true;
                    while(studentLoggedIn) {
                        displayStudentMenu();
                        int studentChoice;
                        cin >> studentChoice;
                        
                        switch(studentChoice) {
                            case 1:
                                system.takeExam();
                                pauseScreen();
                                break;
                            case 2:
                                system.viewMyResults();
                                pauseScreen();
                                break;
                            case 3:
                                system.studentLogout();
                                studentLoggedIn = false;
                                break;
                            default:
                                cout << "\nInvalid choice!\n";
                        }
                    }
                }
                pauseScreen();
                break;
            }
            
            case 3:
                // Student Registration
                system.registerStudent();
                pauseScreen();
                break;
            
            case 4:
                // Exit
                running = false;
                cout << "\nThank you for using Examination System!\n";
                cout << "Goodbye!\n";
                break;
            
            default:
                cout << "\nInvalid choice! Please try again.\n";
                pauseScreen();
        }
    }
    
    return 0;
}
