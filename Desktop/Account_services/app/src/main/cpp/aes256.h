#pragma once
#ifndef uint8_t
#define uint8_t  unsigned char
#endif

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct {
		uint8_t key[32];
		uint8_t enckey[32];
		uint8_t deckey[32];
	} aes256_context;


	void aes256_init(aes256_context *, uint8_t * /* key */);
	void aes256_done(aes256_context *);
	void aes256_encrypt(aes256_context *, uint8_t * /* plaintext */);
	void aes256_decrypt(aes256_context *, uint8_t *, uint8_t */* cipertext */);
	void aes256_encrypt_cbc(aes256_context *, uint8_t *, uint8_t *, uint8_t *);
	void aes256_decrypt_cbc(aes256_context *, uint8_t *, uint8_t *, uint8_t *);
	double GetTime();

#ifdef __cplusplus
}
#endif

#define DUMP(s, i, buf, sz)  {printf(s);                   \
                              for (i = 0; i < (sz);i++)    \
                                  printf("%02x ", buf[i]); \
                              printf("\n");}

