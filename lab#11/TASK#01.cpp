#include<iostream>
using namespace std;

/*
Task 1
Write recursive code for the following functions, You may use more helper functions but all the functions
must be recursive and use a suitable main to test all these functions:
Can’t change the prototype of the functions, unless required and explained in comments
1. void countWords(const char * sentence); // Count and display number of words in the sentence
2. void countCharaters(const char * sentence); //Count and display number of characters
3. void reverse(char * & sentence); // reverses the sentence character- wise
4. void reverseWords(char * & sentence); // reverses the sentence words-wise
5. void convert(char * sentence); // converts lower to uppercase and uppercase to lowercase
*/
#include <iostream>
using namespace std;


int strLength(const char* str)
{
    if (*str == '\0')
    {
        return 0;
    }

    return 1 + strLength(str + 1);
}

int countWordsHelper(const char* str, bool inWord)
{
    if (*str == '\0')
    {
        return 0;
    }

    if (*str == ' ')
    {
        return countWordsHelper(str + 1, false);
    }

    if (!inWord)
    {
        return 1 + countWordsHelper(str + 1, true);
    }

    return countWordsHelper(str + 1, true);
}
void countWords(const char* sentence)
{
    cout << "Number of words: " << countWordsHelper(sentence, false) << endl;
}

int countCharactersHelper(const char* str)
{
    if (*str == '\0')
    {
        return 0;
    }

    return 1 + countCharactersHelper(str + 1);
}

void countCharaters(const char* sentence)
{
    cout << "Number of characters: " << countCharactersHelper(sentence) << endl;
}

void reverseHelper(char* str, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseHelper(str, start + 1, end - 1);
}

void reverse(char*& sentence)
{
    int len = strLength(sentence);

    reverseHelper(sentence, 0, len - 1);
}

void reverseWord(char* str, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseWord(str, start + 1, end - 1);
}

void reverseWordsHelper(char* str, int index, int start)
{
    if (str[index] == '\0')
    {
        reverseWord(str, start, index - 1);
        return;
    }

    if (str[index] == ' ')
    {
        reverseWord(str, start, index - 1);
        reverseWordsHelper(str, index + 1, index + 1);
    }
    else
    {
        reverseWordsHelper(str, index + 1, start);
    }
}

void reverseWords(char*& sentence)
{
    int len = strLength(sentence);

    reverseHelper(sentence, 0, len - 1);

    reverseWordsHelper(sentence, 0, 0);
}

void convertHelper(char* str)
{
    if (*str == '\0')
    {
        return;
    }

    if (*str >= 'a' && *str <= 'z')
    {
        *str = *str - 32;
    }

    else if (*str >= 'A' && *str <= 'Z')
    {
        *str = *str + 32;
    }

    convertHelper(str + 1);
}

void convert(char* sentence)
{
    convertHelper(sentence);
}

//int main()
//{
//    char sentence1[] = "Hello World From UCp LAHORE Cs Department";
//    char sentence2[] = "doing are you what";
//    char sentence3[] = "WRWFhgnyj";
//
//    char* ptr1 = sentence1;
//    char* ptr2 = sentence2;
//    char* ptr3 = sentence3;
//
//    cout << "Original Sentence: " << ptr1 << endl;
//
//
//    countWords(ptr1);
//
//
//    countCharaters(ptr1);
//
//
//    reverse(ptr1);
//    cout << "Character-wise Reverse: " << ptr1 << endl;
//
//    cout << endl;
//
//
//    cout << "Original Sentence: " << ptr2 << endl;
//    reverseWords(ptr2);
//    cout << "Words-wise Reverse: " << ptr2 << endl;
//
//    cout << endl;
//
//
//    cout << "Original String: " << ptr3 << endl;
//    convert(ptr3);
//    cout << "Converted String: " << ptr3 << endl;
//
//    return 0;
//}
