#include <stdlib.h>
#include <stdio.h>

typedef struct _student {
    char* name;
    int midterm_grade;
    int exam_grade;
    int final_grade;
} Student;

void calcFinalGrade(Student* students);


int main () {
    
    
    Student students [2];
    
    students[0].name = "elad";
    students[0].midterm_grade = 67;
    students[0].exam_grade = 89;
    
    calcFinalGrade(students);
    
    
    
}

void calcFinalGrade(Student* students) {
    Student* p = students;
//    for (int i=0; i<1; i++) {
//        printf("Final grade for %s is: %d",students[i].name,(int)(0.3*students[i].midterm_grade + 0.7*students[i].exam_grade));
//    }
    

        printf("Final grade for %s is: %d",p->name,(int)(0.3*p->midterm_grade + 0.7*p->exam_grade));
    
    
    
    
    printf("\n");
}
