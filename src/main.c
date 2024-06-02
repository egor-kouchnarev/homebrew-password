#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Define function to generate password
char* generate_password(int length) {
    char* characters[] = {"abcdefghijklmnopqrstuvwxyz",
                          "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                          "0123456789",
                          "!@#$%^&*"};
    char characters_[100] = "";
    for (int i = 0; i < 4; i++) {
        strcat(characters_, characters[i]);
    }

    // Open /dev/urandom for reading binary data
    FILE* urandom = fopen("/dev/urandom", "rb");
    if (urandom == NULL) {
        perror("Error opening /dev/urandom");
        return NULL;
    }

    // Read 4 bytes of random data from /dev/urandom
    unsigned int seed;
    fread(&seed, sizeof(seed), 1, urandom);

    // Close /dev/urandom
    fclose(urandom);

    // Seed the random number generator
    srand(seed);

    char* password = (char*)malloc((length + 1) * sizeof(char));
    int characters_length = strlen(characters_);
    while (1) {
        char* input = (char*)malloc((length + 1) * sizeof(char));
        for (int i = 0; i < length; i++) {
            input[i] = characters_[rand() % characters_length];
        }
        input[length] = '\0';
        int has_lowercase = 0, has_uppercase = 0, has_digit = 0, has_special = 0;
        for (int i = 0; i < length; i++) {
            if (islower(input[i])) has_lowercase = 1;
            if (isupper(input[i])) has_uppercase = 1;
            if (isdigit(input[i])) has_digit = 1;
            if (!isalnum(input[i])) has_special = 1;
        }
        if (has_lowercase && has_uppercase && has_digit && has_special) {
            strcpy(password, input);
            free(input);
            break;
        }
        free(input);
    }
    return password;
}

int main(int argc, char* argv[]) {
    int length = 16; // Default password length

    // Check if password length is provided as command-line argument
    if (argc == 2) {
        int arg_length = atoi(argv[1]);
        if (arg_length >= 4 && arg_length <= 64) {
            length = arg_length;
        }
    }

    // Generate password
    char* password = generate_password(length);
    if (password == NULL) {
        return 1; // Error occurred
    }

    // Print password
    printf("%s\n", password);

    // Free dynamically allocated memory
    free(password);

    return 0;
}
