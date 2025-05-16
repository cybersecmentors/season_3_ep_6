#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[12]; // Tiny buffer — very easy to overflow
    strcpy(buffer, input); // No bounds check
    printf("Echo: %s\n", buffer);
}

int main() {
    char input[1024];
    if (fgets(input, sizeof(input), stdin)) {
        vulnerable_function(input);
    }
    return 0;
}
