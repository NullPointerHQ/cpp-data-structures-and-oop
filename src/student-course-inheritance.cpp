/*@brief: This program holds two classes, CS101 and Spring24 which is derived from CS101. The program will create a set of 
'test bench' objects of both classes starting with CS101. The first object will be a default object with default (or 'dummy')
values and the second object created is based off User input. After the creation of each object the contents of the object are
immediately available to the user. 

After this the program will prompt the user if they wish to continue object creation, at this point they may choose to create
a new object of either class or to exit the program altogether.
*/

#include <iostream>//Standard I/O Library
#include <string>//Standard String Library
#include <iomanip>//For Formatting

using namespace std;//Sets the namespace to standard

//Class for Student details.
class CS101 {
public:
    CS101();//Default Constructor || All values will be set to 100.

    //Constructor || Values given by user
    CS101(string fname, string lname, int id, double assign1, double assign2, double assign3, double assign4, double mid, double fin);

    void info_sniffer(CS101& student); //F(x) proto, Gathers information from the user
    void printer();//F(x) proto, Displays the results to the user.
    void grading_policy();//F(x) proto applies the Midterm and Final grading policy if applicable

    //Setters
    void set_name(string fname, string lname);//Sets the values of the student's first and last name
    void set_student_id(int std_id);//Sets the value of the student's ID
    void set_assignment_grades(double assign1, double assign2, double assign3, double assign4);//Will set all the grades of the student assignments
    void set_test_grades(double mid, double fin);//Will set all of the grades for the exams
    void set_final_grade();//Calculate the final grade of the student
    void set_letter_grade();//F(x) proto will det. letter grade

    //Getters
    string get_student_first_name();//Retrives the first name of the student
    string get_student_last_name();//Retrives the last name of the student
    int get_student_id();//Retrieves the student's ID number

    double get_assignment1();//Retrieves the student's grade for assignment 1
    double get_assignment2();//Retrieves the student's grade for assignment 2
    double get_assignment3();//Retrieves the student's grade for assignment 3
    double get_assignment4();//Retrieves the student's grade for assignment 4

    double get_midterm();//Retrieves the student's grade for the midterm
    double get_final();//Retrieves the student's grade for the final

    double get_final_grade();//Retrieves the student's final grade
    string get_letter_grade();//Retrieves the student's letter grade

    double final_grade;//Final grade in the course NOT the grade of the final

private:
    //Variable Declaration Block
    string first_name, last_name;//Holds the first and last name of the student.
    int id;//Holds their ID number 
    double assignment1, assignment2, assignment3, assignment4, midterm, final;//Holds Assignment and Test grades
    string letter_grade;
};

//Derived Class with Labs added
class Spring24 :public CS101{//Values are carried over so class recreation not necessary
public:
    Spring24();//Default Constructor
    Spring24(string fname, string lname, int id, double assign1, double assign2, double assign3, double assign4, double midterm, double final, double value);//Constructor

    //Setters
    void derived_info_sniffer(Spring24& student);//New Input function for Spring24
    void set_labs_grade(double labsg);//Labs Grade 
    void set_final_grade_2();//Recalculates the final grade with labs included 
    void derived_printer();//Displays the information held in the class

    //Getters
    double get_labs_grade();//Returns the Lab's grade

private:
    double labs;//Holds the labs grade
};

int main() {
    //Creating Test Bench Cases for CS101
    cout << "Hi, first let me demonstrate some default class object creation starting with CS101" << endl;
    
    //Default
    cout << "CS101 Default Class" << endl;
    CS101 D_student;//Calls the Default Constructor to establish the object,. D_student means Default_Student
    D_student.printer();//Calls the output function of that object
    
    //User Driven
    cout << "CS101 User Defined Class" << endl;
    CS101 U_student;//Calls the Default Constructor to establish the object
    U_student.info_sniffer(U_student);//Calls the Class's input function
    U_student.printer();//Calls the output function of that object
    
    //Creating Test Bench Cases for Spring24
    cout << "and now for Spring24" << endl;
    //Default
    cout << "Spring24 Default Class" << endl;
    Spring24 SD_student;//Calls the Default Constructor to establish the object,. SD_student means SpringDefault_Student
    SD_student.derived_printer();//Calls the output function of that object
    
    //User Driven
    cout << "Spring24 User Defined Class" << endl;
    Spring24 SU_student;//Calls the Default Constructor to establish the object
    SU_student.derived_info_sniffer(SU_student);//Calls the Class's input function
    SU_student.derived_printer();//Calls the output function of that object

    //Test Bench Classes Created, allow user to create more classes if desired
    char Choice = 'Y';//Choice Variable
    
    while (Choice != 'n' || Choice != 'N') {
        //Prompts the user for permission to continue
        cout << "Would you like to create more objects? (Y/N)" << endl;
        cin >> Choice;

        //Error Handling 
        if (Choice != 'Y' && Choice != 'y' && Choice != 'N' && Choice != 'n') {
            cout << "That is not a valid option, valid options include Y, y, N, n. Please try again." << endl;
            cin >> Choice;
        }

        char classType;//Holds User's class type choice

        //Ends the program as requested by the user.
        if (Choice == 'N' || Choice == 'n') {
        cout << "I hope you've enjoyed the program.\nGoodbye!";
        return 0;
        }
        
        //Continues the program infinitely until the user sees fit to intervene
        else if (Choice == 'Y' || Choice == 'y') {
            cout << "Fantastic, do you want to account for a lab? (Y/N)" << endl;//Asking the user to decide which object to create
            cin >> classType;

             //Error Handling
             if (classType != 'Y' && classType != 'y' && classType != 'N' && classType != 'n') {
                cout << "That is not a valid option, valid options include Y, y, N, n. Please try again." << endl;
                cin >> classType;
            }

             //Creates an object of base class CS101 by user choice
            if (classType == 'N' || classType == 'n') {
                CS101 student;//Student Class Initialzation, will call def. constructor
                student.info_sniffer(student);//Calls the input function using the preestablished class
                student.printer();//Calls the output function
            }

            //Creates an object of child class Spring24 by user choice
            if (classType == 'Y' || classType == 'y') {
            
             Spring24 student2;//Student Class Initialzation, will call def. constructor

             student2.derived_info_sniffer(student2);//Calls the input function using the preestablished class
             student2.derived_printer();//Calls the output function
            }
        }
    }
    return 0;
}

//FOR MAIN CS101 CLASS

//Default Constructor || Will Set Default Values for the Variables
CS101::CS101() {
    set_name("John", "Doe");
    set_student_id(99999999);
    set_assignment_grades(100, 100, 100, 100);
    set_test_grades(100, 100);
    set_final_grade();
}

//Constructor, Calls the Setters and gives them values that were provided by the user
CS101::CS101(string fname, string lname, int id, double assign1, double assign2, double assign3, double assign4, double midterm, double final) {
    set_name(fname, lname);
    set_student_id(id);
    set_assignment_grades(assign1, assign2, assign3, assign4);
    set_test_grades(midterm, final);
    set_final_grade();//Tabulates the final grade
}

//F(x) Gathers information from the user
void CS101::info_sniffer(CS101& student) {
    //Variables used to temporarily store values to pass to a constructor 
    string fname, lname;
    double id, assign1, assign2, assign3, assign4, midterm, fin;

    //Gathering Values to send to the Constructor
    cout << "Please enter the student's name seperated by a space: \t";
    cin >> fname >> lname;

    cout << endl << "Please enter the student's ID: \t";
    cin >> id;

    cout << endl << "Please enter the following information." << endl << "Assignment 1 Grade:\t";
    cin >> assign1;
    cout << endl << "Assignment 2 Grade:\t";
    cin >> assign2;
    cout << endl << "Assignment 3 Grade:\t";
    cin >> assign3;
    cout << endl << "Assignment 4 Grade:\t";
    cin >> assign4;
    cout << endl << "Midterm Grade:\t";
    cin >> midterm;
    cout << endl << "Final Grade:\t";
    cin >> fin;
    cout << endl;

    student = CS101(fname, lname, id, assign1, assign2, assign3, assign4, midterm, fin);//Calls the constructor to set the values of the class || Lecture Code 12
}

//F(x) Displays the results to the user.
void CS101::printer() {

    cout << get_student_first_name() << " " << get_student_last_name() << " - ID:" << get_student_id() << endl;

    cout << "\tAssignment 1: " << get_assignment1() << endl;
    cout << "\tAssignment 2: " << get_assignment2() << endl;
    cout << "\tAssignment 3: " << get_assignment3() << endl;
    cout << "\tAssignment 4: " << get_assignment4() << endl;

    cout << "\tMidterm: " << get_midterm() << endl;
    cout << "\tFinal: " << get_final() << endl;
    cout << "\tFinal Grade:\t" << get_final_grade() << endl;
    cout << "\tLetter Grade:\t" << get_letter_grade() << endl;

}

//F(x) applies the Midterm and Final grading policy if applicable
void CS101::grading_policy(){
    //Missed Final
    if (get_final() == 0.00) {
        final_grade = 0.00;//Sets the Grade to be an F per grading policy on missed Final
        set_letter_grade();//Calls the Letter grade function
    }
    //Missed Midterm, will not apply if current grade is WORSE than the theoretical max
    else if (get_midterm() == 0 && final_grade >= 70) {
        final_grade = 70.0;//Sets the grade to be a C per grading policy on missed Midterm
        set_letter_grade();//Calls the Letter grade function
    }

    //No assessments missed.
    else{
        set_letter_grade();//Calls the Letter grade function
    }
}
//Setter Function Definitions Chunk

//Sets the values of the student's first and last name
void CS101::set_name(string fname, string lname) {
    first_name = fname;//Assigns the value of the string fname to be the value of the first_name member 
    last_name = lname;//Assigns the value of the string lname to be the value of the last_name member 
}

//Sets the value of the student's ID
void CS101::set_student_id(int std_id) {
    id = std_id;//Assigns the value of the int std_id to the member id.
}

//Will set all the grades of the student assignments
void CS101::set_assignment_grades(double assign1, double assign2, double assign3, double assign4) {
    assignment1 = assign1;//Assigns the value of the int assign1 to the member assignment1
    assignment2 = assign2;//Assigns the value of the int assign2 to the member assignment2
    assignment3 = assign3;//Assigns the value of the int assign3 to the member assignment3
    assignment4 = assign4;//Assigns the value of the int assign4 to the member assignment4
}

//Will set all of the grades for the exams
void CS101::set_test_grades(double mid, double fin) {
    midterm = mid;//Assigns the value of mid to the member midterm
    final = fin;//Assigns the value of fin to the member final
}

//F(x) proto will calculate the final grade of the student
void CS101::set_final_grade() {
    //Cumulative Assignment grade
    double assignment_grade = get_assignment1() + get_assignment2() + get_assignment3() + get_assignment4();
    
    //Used only to calculate the grade
    double mid = get_midterm();
    double fin = get_final();

    final_grade = ((assignment_grade / 4.0) * 0.25) + (mid * 0.3) + (fin * 0.45);//Provided formula
    grading_policy();//Calls grade policy function to apply the grading policy
}

//F(x) proto will det. letter grade based on what range the value received from get_final_grade falls into.
void CS101::set_letter_grade() {
    double fin_g = get_final_grade();

    if (fin_g <= 50.0) {//50 or Below
        letter_grade = "F";
    }
    else if (fin_g >= 51.0 && fin_g < 67.0) {//D Category
        if (fin_g < 60) {
            letter_grade = "D-";
        }
        else if (fin_g >= 51.0 && fin_g < 63.0) {
            letter_grade = "D";
        }
        else {
            letter_grade = "D+";
        }
    }
    else if (fin_g >= 67.0 && fin_g < 77.0) {//C Category
        if (fin_g < 70) {
            letter_grade = "C-";
        }
        else if (fin_g >= 70.0 && fin_g < 73.0) {
            letter_grade = "C";
        }
        else {
            letter_grade = "C+";
        }
    }
    else if (fin_g >= 77.0 && fin_g < 87.0) {//B Category
        if (fin_g < 80) {
            letter_grade = "B-";
        }
        else if (fin_g >= 80.0 && fin_g < 83.0) {
            letter_grade = "B";
        }
        else {
            letter_grade = "B+";
        }
    }
    else if (fin_g >= 87.0) {//A Category
        if (fin_g >= 90) {
            letter_grade = "A";
        }
        else {
            letter_grade = "A-";
        }
    }
}

//Getters Function Definitions Chunk

//Retrieves the first name of the student
string CS101::get_student_first_name() {
    return first_name;
}
//Retrieves the last name of the student
string CS101::get_student_last_name() {
    return last_name;
}
//Retrieves the student's ID number
int CS101::get_student_id() {
    return id;
}

//Retrieves the student's grade for assignment 1
double CS101::get_assignment1() {
    return assignment1;
}

//Retrieves the student's grade for assignment 2
double CS101::get_assignment2() {
    return assignment2;
}

//Retrieves the student's grade for assignment 3
double CS101::get_assignment3() {
    return assignment3;
}

//Retrieves the student's grade for assignment 4
double CS101::get_assignment4() {
    return assignment4;
}

//Retrieves the student's grade for the midterm
double CS101::get_midterm() {
    return midterm;
}

//Retrieves the student's grade for the final  
double CS101::get_final() {
    return final;
}

//Retrieves the student's final grade
double CS101::get_final_grade() {
    return final_grade;
}
//Retrieves the student's letter grade
string CS101::get_letter_grade() {
    return letter_grade;
}

//FOR DERIVED Spring24 CLASS
//Default Constructor will set dummy values to all the fields
Spring24::Spring24() {
    set_name("John", "Doe");
    set_student_id(99999999);
    set_assignment_grades(100, 100, 100, 100);
    set_test_grades(100, 100);
    set_labs_grade(100);
    set_final_grade_2();
}
//Constructor calls the correct setters and passes the values to them
Spring24::Spring24(string fname, string lname, int id, double assign1, double assign2, double assign3, double assign4, double midterm, double final, double labsg) {
    set_name(fname, lname);
    set_student_id(id);
    set_assignment_grades(assign1, assign2, assign3, assign4);
    set_test_grades(midterm, final);
    set_labs_grade(labsg);//Calls Lab Grade Setter function and passes the labgs grade value to it
    set_final_grade_2();//Recalculates the final grade with labs included
}

//New Input function for Spring24
void Spring24::derived_info_sniffer(Spring24& student) {
    //Variables used to temporarily store values to pass to a constructor 
    string fname, lname;
    double id, assign1, assign2, assign3, assign4, midterm, fin, labsg;

   //Gathering Values to send to the Constructor
    cout << "Please enter the student's name seperated by a space: \t";
    cin >> fname >> lname;

    cout << endl << "Please enter the student's ID: \t";
    cin >> id;

    cout << endl << "Please enter the following information." << endl << "Assignment 1 Grade:\t";
    cin >> assign1;
    cout << endl << "Assignment 2 Grade:\t";
    cin >> assign2;
    cout << endl << "Assignment 3 Grade:\t";
    cin >> assign3;
    cout << endl << "Assignment 4 Grade:\t";
    cin >> assign4;

    cout << endl << "Midterm Grade:\t";
    cin >> midterm;
    cout << endl << "Final Grade:\t";
    cin >> fin;
    cout << endl;

    cout << "Labs Grade\t";
    cin >> labsg;
    cout << endl;


    student = Spring24(fname, lname, id, assign1, assign2, assign3, assign4, midterm, fin, labsg);//Calls the constructor to set the values of the class 
}
//Setters
 //Sets the Labs Grade 
void Spring24::set_labs_grade(double labsg) {
    labs = labsg;
}

//Recalculates the final grade with labs included
void Spring24::set_final_grade_2() {
    double assignment_grade = get_assignment1() + get_assignment2() + get_assignment3() + get_assignment4();
    double mid = get_midterm();
    double fin = get_final();
    double labg = get_labs_grade();

    final_grade = ((assignment_grade / 4) * 0.25) + (mid * 0.25) + (fin * 0.4) + (labg * 0.10);//Provided formula
    grading_policy();//Calls grade policy function to apply the grading policy, uses the same function from CS101
}

//Displays the information held in the class
void Spring24::derived_printer() {
    CS101::printer();//Calls Base Printer Function
    cout << "\tLabs Grade:\t" << get_labs_grade() << endl;//Displays lab grade
}

//Getters
//Returns the Lab's grade
double Spring24::get_labs_grade() {
    return labs;
}