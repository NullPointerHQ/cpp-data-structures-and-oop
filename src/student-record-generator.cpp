/*Project Description:
This program will compute the average score of a student based on their academic records, their records will be composed of no more than 10 quizzes that will
have a score of no more than 20, both the scores and the amount of quizzes will be randomly generated however the student names must still be input by the user.*/

//Preprocessor Directives
#include <iostream>//Standard I/O Library
#include <string> //Standard String Library
#include <sstream>//Used for String Stream, please see UDF gpa_calculator for more details
#include <fstream>//Required for File Read/Write
#include <cstdlib>//Required for Other Functions
#include <ctime>//For srand time functionality

using namespace std;//Standard Namespace

//F(x) Prototype Declaration Block

//F(X) Proto gathers user input where needed, calls other functions.
void information_gatherer(ofstream& out_stream, int& quizzesCount);

//F(x) Proto generates a random number not greater than 10 that is the amount of quizzes taken, value will be passed to the scores F(x)
int quiz_number();

//F(x) Proto generates a series of quiz scores and write those scores to the file, amount changes depending on # of scores needed.
void quiz_scores_generator(ofstream& out_stream, int limiter);

//F(x) Proto Reads the input file and copies it over to the output file.
void copier(ofstream& out_stream, ifstream& in_stream);

//F(x) Proto takes the student's total score and calculates the average based on that and the number of quizzes total
void gpa_calculator(ofstream& out_stream, ifstream& in_stream, string section);

//F(x) Proto displays to the user the results and the averages etc.
void printer(ifstream& in_stream);

int main() {
	//Preparing the Input file for writing. 
	ofstream out_stream;//Declares Output Variable
	out_stream.open("Assignment3Input.txt");//Opens the file for output, Make sure its in the right folder

	if (out_stream.fail()) {			//Handles out_stream failure
		cout << "Failed to open file for input." << endl << "Terminating Program..." << endl << "I need an adult!";
		exit(1);
	}
	
	cout << "Hello user. Welcome to [Insert School Name Here]'s GPA calculator." << endl;//Flavor Text.

	int quizzesCount = 0;//Holds the total number of scores for a specific student
	
	information_gatherer(out_stream, quizzesCount);//Calls Information Gathering function.
	

	//Closes Write mode on Input file and opens it in Reading mode
	out_stream.close();//Closes file for input.
	
	ifstream in_stream;//Declares Input Variable
	in_stream.open("Assignment3Input.txt");//Opens the file for input, Make sure its in the right folder

	if (in_stream.fail()) {			//Handles in_stream failure
		cout << "Failed to open file for output." << endl << "Terminating Program..." << endl << "I need an adult!";
		exit(1);
	}

	//Opens the Output file in Write mode 
	out_stream.open("Assignment3Output.txt");//Opens the file for output

	if (out_stream.fail()) {			//Handles out_stream failure
		cout << "Failed to open file for input." << endl << "Terminating Program..." << endl << "I need an adult!";
		exit(1);
	}

	out_stream << "This file holds the names, scores and calculated averages of the students." << endl;
	out_stream << "Student Name | Scores | Average" << endl;
	
	copier(out_stream, in_stream);//Calls Output file creation function

	in_stream.close();//Closes the input file
	in_stream.open("Assignment3Output.txt");//Opens the Output file in Read mode.
	if (in_stream.fail()) {	//Handles in_stream failure
		cout << "Failed to open file for output." << endl << "Terminating Program..." << endl << "I need an adult!";
		exit(1);
	}

	out_stream.close();//Writing to file no longer necessary, closing.
	printer(in_stream);//Calls Printer function to display results
	return 0;
}

//F(x) Definition Block

//F(X) gathers user input where needed, calls other functions.
void information_gatherer(ofstream& out_stream, int& quizzesCount) {

	string student;//Will hold the student's name and will eventually be written to a file. 

	for (int i = 1; i <= 10; i++) {
		cout << "Please enter the name of a student:" << endl;//Prompts user for input
		cin >> student;//Gathers Student name 
		out_stream << student << " | ";//Writes Name to file
		quizzesCount = quiz_number();//Calls the number of Quizzes function to det. the #of quizzes taken by the student
		quiz_scores_generator(out_stream, quizzesCount);
		out_stream << endl;
	}
}

int quiz_number() {
	srand(time(0));//Seeds RNG with current time

	int numberOfQuizzes = (rand() % 10 - 1 + 1);//Generates a random between 1 and 10	
	return numberOfQuizzes;
}

//F(x) Proto generates a series of quiz scores and write those scores to the file, amount changes depending on # of scores needed.
void quiz_scores_generator(ofstream& out_stream, int limiter) {
	
	int scoreGenerated = 0;//Holds the score for the student, value is randomly generated

	//Continues to randomly generate scores and write the information to the file until enough scores have been written
	for (int i = 1; i <= limiter; i++) {
		scoreGenerated = (rand() % 21 - 1 + 1);//Generates a random int between 1 and 20 
		out_stream << " " << scoreGenerated << " ";//Writes the score to the file and provides proper spacing between scores.
	}
}

//F(x) Reads the input file and copies it over to the output file.
void copier(ofstream& out_stream, ifstream& in_stream){
	string lineJumper;
	while (getline(in_stream, lineJumper)) {
		out_stream << lineJumper; // Writes the string held in 'lineJumper' to output file
		gpa_calculator(out_stream, in_stream, lineJumper);//Calls the average calculator to calculate the avg and append that to the line.
	}
}

//F(x) takes the student's total score and calculates the average based on that and the number of quizzes total
void gpa_calculator(ofstream& out_stream, ifstream& in_stream, string section) {

	int average, totalScore = 0, score;
	string name, formatting;
	//string section;//Holds the specific section of the file that is up for review.

	//Loop repeats until EOF
	istringstream iss(section);//Sets up the stream to gather the scores
		
	iss >> name;//Eats the name at the start
	iss >> formatting;//Eats up any ' | ' spots before the characters

		while (iss >> ws >> score) {//Keeps getting numbers from the string as long as there are numbers to get
			totalScore += score;//Adds the score found in the line to the running total
		}
		
		average = totalScore / 10;//Calculates the average for that student at that point
		
		if (average != 0 && totalScore != 0) {
			out_stream << " | " << average << endl;//Writes down the average in the file
		}

		if (totalScore != 0) {
			totalScore = 0;//Resets Total Score after writing the average down
		}
		else {
			out_stream << " | " << endl;//Writes the vertical bar formatting.
		}
		
	}

//F(x) Proto displays to the user the results and the averages etc.
void printer(ifstream& in_stream) {
	string eyes;//Holds the line the program is currently reading. 

	cout << "Names gathered..." << endl << "Scores generated....." << endl << "Averages calculated where possible." << endl;
	cout << "Displaying Result:" << endl << endl;

	while (getline(in_stream, eyes)) {//Will read as long as there is something to read
		if (eyes == "This file holds the names, scores and calculated averages of the students.") {//Catches the file header and discards it in a sense
			getline(in_stream, eyes);
		}
		cout << eyes << endl;//Prints out the contents of the eyes variable
	}
}