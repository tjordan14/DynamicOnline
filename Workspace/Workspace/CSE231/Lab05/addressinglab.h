/*                       *
 * DO NOT EDIT THIS FILE *
 *                       */

/*
 * AddressingLab (c) 2021 Christopher A. Bohn
 */

/******************************************************************************
 * This header provides function declarations and a structure for addressinglab.
 ******************************************************************************/

#ifndef ADDRESSINGLAB_H
#define ADDRESSINGLAB_H

#include <stdbool.h>

#define MAXIMUM_INPUT_LENGTH 256

struct cipher_package {
    char *plaintext;
    char *ciphertext;
    int sentence_length;
    int key;
};

/**
 * Performs a classical Caesar Cipher on messages in uppercase. Numbers,
 * punctuation, and lowercase letters are unaffected. The caller is responsible
 * for allocating enough space in the destination to receive the modified text.
 * @param destination The receiving string
 * @param text The source string
 * @param key The alphabetic distance to shift letters
 * @return The destination pointer
 */
char *caesar_cipher(char *destination, const char *text, int key);

/**
 * Makes a copy of a sentence, replacing all lowercase letters with uppercase
 * letters. Numbers, punctuation, and uppercase letters are unaffected. The
 * caller is responsible for allocating enough space in the destination to
 * receive the modified text.
 * @param destination The receiving string
 * @param sentence The source string
 * @return The destination pointer
 */
char *sentence_to_uppercase(char *destination, const char *sentence);

/**
 * Validates whether the plaintext and ciphertext are a valid pair by
 * confirming that they are both the length specified by the package's
 * sentence_length field and that the inverse of the package's key field will
 * decipher the ciphertext back to the plaintext.
 * @param package The structure containing the cipher elements to be validated
 * @return 1 if the plaintext and ciphertext are a Caesar Cipher pair and both
 *      have a length that corresponds to the specified length; 0 otherwise
 */
bool validate_cipher(struct cipher_package *package);

#endif //ADDRESSINGLAB_H
