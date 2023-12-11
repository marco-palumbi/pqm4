
/**
 * @file sign.c
 * @brief Implementation of the NIST api functions
 */

#include <stdlib.h>
#include "api.h"

/**
 * @brief Generate a keypair.
 *
 * @param [out] pk pointer to public key bytes
 * @param [out] sk pointer to public key bytes
 * @returns 0 if key generation is successful and -1 otherwise
 */
int crypto_sign_keypair(unsigned char *pk, unsigned char *sk) {
    (void) pk;
    (void) sk;

    return 0;
}

/**
 * @brief Generate a signature of a message.
 *
 * @param [out] sm pointer to output signed message
 *                 (allocated array with CRYPTO_BYTES + mlen bytes), can be equal to m
 * @param [out] smlen pointer to output length of signed message
 * @param [in] m pointer to message to be signed
 * @param [in] mlen length of the message
 * @param [in] sk pointer to the secret key bytes
 * @returns 0 if signing is successful and -1 otherwise
 */
int crypto_sign(unsigned char *sm, size_t *smlen, const unsigned char *m, size_t mlen, const unsigned char *sk) {
    (void) sm;
    (void) smlen;
    (void) m;
    (void) mlen;
    (void) sk;

    return 0;
}

/**
 * @brief Verify a signed message
 *
 * @param [out] m pointer to output message
 *                (allocated array with smlen bytes), can be equal to sm
 * @param [out] mlen pointer to output length of message
 * @param [in] sm pointer to signed message
 * @param [in] smlen length of signed message
 * @param [in] pk pointer to the public key bytes
 * @returns 0 if signed message could be verified correctly and -1 otherwise
 */
int crypto_sign_open(unsigned char *m, size_t *mlen, const unsigned char *sm, size_t smlen, const unsigned char *pk) {
    (void) sm;
    (void) smlen;
    (void) m;
    (void) mlen;
    (void) pk;

    return 0;

// badsig:
    /* Signature verification failed */
    *mlen = -1;
    return -1;
}