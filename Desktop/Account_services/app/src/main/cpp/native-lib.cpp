#include <jni.h>
#include <string>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//#include "openssl/crypto.h"
#include "openssl/aes.h"






extern "C"
JNIEXPORT jstring
JNICALL
Java_com_example_xingyan_accountservices_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    const char *cstr = hello.c_str();

    unsigned char key[32] = { 0x6e, 0x92, 0xcc, 0x91, 0x3e, 0x5d, 0x27, 0xa2,
                              0x97, 0xd1, 0x13, 0xd7, 0x90, 0x99, 0xee, 0x67,
                              0xcd, 0xdc, 0x6c, 0x16, 0x08, 0x33, 0x28, 0x63,
                              0x87, 0xa3, 0xd0, 0x06, 0x16, 0x55, 0x63, 0x5d };
    //初始化向量
    uint8_t iv[16] = { 0x53, 0xc6, 0xe1, 0x3a, 0x33, 0xc3, 0x6a, 0x77,
                       0xbe, 0x26, 0x39, 0x39, 0x6e, 0x13, 0x93, 0x3e };

    int keylength = 256;

    /* generate a key with a given length */
    unsigned char aes_key[keylength/8];
    memset(aes_key, 0, keylength/8);
    memcpy(aes_key, key, 8);

    size_t inputslength = strlen(cstr);

    unsigned char aes_input[inputslength];
    memcpy(aes_input, cstr, 8);
    /* generate input with a given length */

    /* init vector */
    unsigned char iv_enc[AES_BLOCK_SIZE], iv_dec[AES_BLOCK_SIZE];

    memcpy(iv_dec, iv, AES_BLOCK_SIZE);

    // buffers for encryption and decryption
    const size_t encslength = ((inputslength + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char enc_out[encslength];
    unsigned char dec_out[inputslength];
    memset(enc_out, 0, sizeof(enc_out));
    memset(dec_out, 0, sizeof(dec_out));

    // so i can do with this aes-cbc-128 aes-cbc-192 aes-cbc-256
    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(aes_key, keylength, &enc_key);
    AES_cbc_encrypt(aes_input, enc_out, inputslength, &enc_key, iv_enc, AES_ENCRYPT);

    AES_set_decrypt_key(aes_key, keylength, &dec_key);
    AES_cbc_encrypt(enc_out, dec_out, encslength, &dec_key, iv_dec, AES_DECRYPT);

    printf("original:\t");
//    hex_print(aes_input, sizeof(aes_input));
//
//    printf("encrypt:\t");
//    hex_print(enc_out, sizeof(enc_out));
//
//    printf("decrypt:\t");
//    hex_print(dec_out, sizeof(dec_out));



    return env->NewStringUTF((char*)enc_out);
    //return env->NewStringUTF(hello.c_str());
}

