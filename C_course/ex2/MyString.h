#pragma once

//Checks if str2 is a sub string of str1.
//return :  the location of first time str2 is a sub string of str1.
int extendedSubStr(int isCyclic, int step, const char* str1,
                                                const char* str2);

//Sorts the words in str separated by the chars in delim.
void sortDelim(char str[], const char* delim);