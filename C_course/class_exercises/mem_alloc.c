#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct _MyString
{
    char* s;
} MyString;

MyString* string_alloc(const char* st);
void string_free(MyString* myStr);
size_t string_size(MyString* myStr);
char string_at(MyString* myStr, size_t index);
MyString* string_append(MyString* myStr1, const MyString* myStr2);

int main () {
    
    char* s = "elad";
    char* s2 = "shlomi";
    MyString* newStr = string_alloc(s);
    MyString* newStr2 = string_alloc(s2);
    
    printf("new string: %s \n",newStr->s);
    printf("first char in MyString.s: %c \n",  *(newStr->s));
    printf("newStr length is: %zu \n" , string_size(newStr));
    printf("string at index 2: %c \n", string_at(newStr, 2));
    printf("string appended: %s \n" , string_append(newStr, newStr2)->s);
    string_free(newStr);
}




MyString* string_alloc(const char* st) {
    MyString* newStr = (MyString*) malloc(sizeof(MyString));
    newStr->s = (char*) malloc(sizeof(char)*(strlen(st)+1));
    char* p = newStr->s;
    
    while (*st != '\0') {
        *p = *st;
        st++;
        p++;
    }
    return newStr;
}


void string_free(MyString* myStr) {
    free(myStr->s);
    free(myStr);
}

size_t string_size(MyString* myStr) {
    
    return strlen(myStr->s);

}

char string_at(MyString* myStr, size_t index){
    return (myStr->s)[index];
}
MyString* string_append(MyString* myStr1, const MyString* myStr2){
    
    MyString* newStr = (MyString*) malloc(sizeof(MyString));
    newStr->s = (char*) malloc(sizeof(char)* (strlen(myStr1->s) + strlen(myStr2->s) + 1));
    
    char* p = newStr->s;
    char* s1 = myStr1->s;
    char* s2 = myStr2->s;
    
    while (*s1 != '\0') {
        *p = *s1;
        s1++;
        p++;
    }
    
    while (*s2 != '\0') {
        *p = *s2;
        s2++;
        p++;
    }
    
    return newStr;
}






