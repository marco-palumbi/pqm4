
/**
 * @file api.h
 * @brief NIST SIGN API
 */

#ifndef PROFILED_SCHEME_API_H
#define PROFILED_SCHEME_API_H

#include <stddef.h>

#define CRYPTO_ALGNAME "profiled-scheme"

#define CRYPTO_PUBLICKEYBYTES 10
#define CRYPTO_SECRETKEYBYTES 10
#define CRYPTO_BYTES          10

// As a technicality, the public key is appended to the secret key in order to respect the NIST API.
// Without this constraint, CRYPTO_SECRETKEYBYTES would be defined as SECURITY_BYTES

int crypto_sign_keypair(unsigned char *pk, unsigned char *sk);
int crypto_sign(unsigned char *sm, size_t *smlen, const unsigned char *m, size_t mlen, const unsigned char *sk);
int crypto_sign_open(unsigned char *m, size_t *mlen, const unsigned char *sm, size_t smlen, const unsigned char *pk);

#endif
