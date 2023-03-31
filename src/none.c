#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "none.h"
#include "utils.h"

int none_encrypt_all(buffer_t *plaintext, cipher_t *cipher, size_t capacity)
{
#ifdef SS_DEBUG
    dump("PLAIN", plaintext->data, plaintext->len);
#endif
    return 0;
}

int none_decrypt_all(buffer_t *ciphertext, cipher_t *cipher, size_t capacity)
{
#ifdef SS_DEBUG
    dump("CIPHER", ciphertext->data, ciphertext->len);
#endif
    return 0;
}

int none_encrypt(buffer_t *plaintext, cipher_ctx_t *cipher_ctx, size_t capacity)
{
#ifdef SS_DEBUG
    dump("PLAIN", plaintext->data, plaintext->len);
#endif
    return 0;
}

int none_decrypt(buffer_t *ciphertext, cipher_ctx_t *cipher_ctx, size_t capacity)
{
#ifdef SS_DEBUG
    dump("CIPHER", ciphertext->data, ciphertext->len);
#endif
    return 0;
}

void none_ctx_init(cipher_t *cipher, cipher_ctx_t *cipher_ctx, int enc)
{
    return ;
}

void none_ctx_release(cipher_ctx_t *cipher_ctx)
{
    return ;
}

cipher_t *none_init(const char *pass, const char *key, const char *method)
{
    cipher_t *cipher = (cipher_t *)ss_malloc(sizeof(cipher_t));
    memset(cipher, 0, sizeof(cipher_t));
    return cipher;
}
