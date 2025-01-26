#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
	char student_id[100];
	char first_name[100];
	char last_name[100];
	char faculty[100];
	char university[100];
	int birth_year;
} Student;

Student *students;
int studentCount;

void printMenu();
void getAllStudents();
void addStudent();
void getStudentById();
void updateStudentById();
void deleteStudentById();


int main(){
	students = malloc(sizeof(Student)*100);

	while (1){
		printMenu();
		printf("\n\n");	
	}

	free(students);
	return 0;
}


void deleteStudentById(){
	printf("* ---------------- Delete ---------------- *\n");
	printf("	[Student id] $ ->  ");
	char *student_id = malloc(sizeof(char)*101);
	scanf("%s", student_id);
	printf("* ________________________________________ *\n");

	bool is_deleted = false;
	int index_to_remove = -1;
	for (size_t i=0; i<studentCount; i++){
		if (strcmp(students[i].student_id, student_id) == 0){
			index_to_remove = i;
			is_deleted = true;
			break;
		}
	}

	for (int j=index_to_remove; j<studentCount; j++){
		students[j] = students[j+1];
	}
	--studentCount;
	free(student_id);

	if (is_deleted)
		printf("* [ Student deleted succesfully! ] *\n");
	else 
		printf("* [ Student not found! ] *\n");
}


void updateStudentById(){
	Student *updating_student = malloc(sizeof(Student));
	
	printf("* ---------------- Update ---------------- *\n");
	printf(" 	[Student-id] $ ->  ");
	scanf("%s", updating_student->student_id);
	printf("* __________________________________________ *\n");

	printf(" 	[Updating Firstname]  % ->  ");
	scanf("%s", updating_student->first_name);

	printf(" 	[Updating Lastname]   % ->  ");
	scanf("%s", updating_student->last_name);

	printf(" 	[Updating Faculty]    % ->  ");
	scanf("%s", updating_student->faculty);

	printf(" 	[Updating University] % ->  ");
	scanf("%s", updating_student->university);

	printf(" 	[Updating Birth year] % ->  ");
	scanf("%d", &updating_student->birth_year);
	
	bool is_updated = false;
	for (size_t i=0; i<studentCount; i++){
		if (strcmp(students[i].student_id, updating_student->student_id) == 0){
			students[i] = *updating_student;
			is_updated = true;
			printf("* [ Student info updated successfully ] *\n");
		}
	}

	if (is_updated == 0)
		printf("* [ Student-id is not valid ] *\n");
	
	free(updating_student);
}


void getStudentById(){
	printf("* ---------------- Get a student by id ------------------ *\n");
	printf("	[Student-id] $ ->  ");
	char *student_id = malloc(sizeof(char)*100);
	if (student_id == NULL) {
		fprintf(stderr, "Memory allocation failed!\n");
		return;
	}

	scanf("%s", student_id);
	bool is_found = false;
	Student student;

	for (int i=0; i<studentCount; i++){
		if (strcmp(students[i].student_id,student_id) == 0){
			is_found = true;
			student = students[i];	
		}
	}
	
	if (!is_found)
		printf("* [ This student-id is not valid!!! ] *\n");
	else {
		printf("* ---------------------------------------------- *\n");
		printf("* [Student-id] ------------ %s ---------- *\n", student.student_id);
		printf("* [Firstname]  ------------ %s ---------- *\n", student.first_name);
		printf("* [Lastname]   ------------ %s ---------- *\n", student.last_name);
		printf("* [Faculty]    ------------ %s ---------- *\n", student.faculty);
		printf("* [University] ------------ %s ---------- *\n", student.university);
		printf("* [Birth year] ------------ %d ---------- *\n", student.birth_year);
		printf("* ______________________________________________ *\n");
	}

	free(student_id);
}


void addStudent(){
	Student new_student;
	

	printf("* ------------------- Add a new student ------------------ *\n");
	printf("  	[Student-id]	$ ->  ");
	scanf("%s", new_student.student_id);

	printf("  	[Firstname]	$ ->  ");
	scanf("%s", new_student.first_name);
	
	printf("	[Lastname] 	$ ->  ");
	scanf("%s", new_student.last_name);

	printf("	[Faculty]   	$ ->  ");
	scanf("%s", new_student.faculty);

	printf("	[University]	$ ->  ");
	scanf("%s", new_student.university);

	printf("	[Birth year]	$ ->  ");
	scanf("%d", &new_student.birth_year);
	printf("* ________________________________________________________ *\n");
	
	if (studentCount == sizeof(students)/sizeof(students[0])){
		students = realloc(students, sizeof(Student)*101);	
	}

	students[studentCount] = new_student;
	++studentCount;
	printf("* [ A new student added successfully! ] *\n");
}
	


void getAllStudents(){
	if (studentCount == 0){
		printf("* [ we don't have students yet ] *\n");
		return;
	}

	printf("* --------------- Students --------------- *\n");
	for (size_t i=0; i<studentCount; i++){
		printf("* ----------------------------------------------------------- *\n");
		printf("* [Student-id] -------------- %s ------------- *\n", students[i].student_id);
		printf("* [Firstname] --------------- %s ------- *\n", students[i].first_name);
		printf("* [Lastname] ---------------- %s ------- *\n", students[i].last_name);
		printf("* [Date of birth(year)] ----- %d ------- *\n", students[i].birth_year);
		printf("* [Faculty] ----------------- %s ------- *\n", students[i].faculty);
		printf("* [University] -------------- %s ------- *\n", students[i].university);
		printf("* __________________________________________________________ *\n");
	}
}




void printMenu(){
	printf("* --------------- Student Management System -------------- *\n");
	printf("* [1] ------ Get all students ------ *\n");
	printf("* [2] ------ Get a student by its student-id ------ *\n");
	printf("* [3] ------ Add a new student ------ *\n");
	printf("* [4] ------ Update a student by its student-id ------ *\n");
	printf("* [5] ------ Delete a student by its student-id ------ *\n");
	printf("* --------------- ************************* -------------- *\n");

	int input;
	printf(" [------] $ -> "); 
	scanf("%d", &input);
	
	if (input < 1 || input > 5){
		printf("* ------ Input must be greater than \"0\" and less than \"6\"! ------ *\n");
		return;
	}

	switch (input){
		case 1:
			getAllStudents();
			break;
		case 2:
			getStudentById();
			break;
		case 3:
			addStudent();
			break;
		case 4:
			updateStudentById();
			break;
		case 5:
			deleteStudentById();
			break;
	}
}

