#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char a[] = "abcdefgh";
    char token[5]; // Allocate memory for token
    strncpy(token, a + 2, 4);
    token[4] = '\0'; // Null-terminate the token string
    cout << token;
    return 0; // Return 0 to indicate successful execution
}