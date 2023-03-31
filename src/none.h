#ifndef _NONEX_H
#define _NONEX_H

#ifndef __MINGW32__
#include <sys/socket.h>
#endif
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#ifdef HAVE_STDINT_H
#include <stdint.h>
#elif HAVE_INTTYPES_H
#include <inttypes.h>
#endif

#include <sodium.h>
#define STREAM_CIPHER_NUM          21

#include "crypto.h"

int none_encrypt_all(buffer_t *, cipher_t *, size_t);
int none_decrypt_all(buffer_t *, cipher_t *, size_t);
int none_encrypt(buffer_t *, cipher_ctx_t *, size_t);
int none_decrypt(buffer_t *, cipher_ctx_t *, size_t);

void none_ctx_init(cipher_t *, cipher_ctx_t *, int);
void none_ctx_release(cipher_ctx_t *);

cipher_t *none_init(const char *pass, const char *key, const char *method);

#endif //_NONEX_H