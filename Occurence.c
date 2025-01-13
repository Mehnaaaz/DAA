#include <stdio.h>
#include <string.h>

int findFirstOccurrence(const char *str, const char *substr) {
    char *pos = strstr(str, substr);
    if (pos != NULL) {
        return pos - str;  // Calculate the index
    }
    return -1;  // Not found
}

int main() {
    char str[] = "Hello, world!";
    char substr[] = "world";
    
    int index = findFirstOccurrence(str, substr);
    if (index != -1) {
        printf("First occurrence of \"%s\" in \"%s\" is at index %d\n", substr, str, index);
    } else {
        printf("Substring not found.\n");
    }
    
    return 0;
}
