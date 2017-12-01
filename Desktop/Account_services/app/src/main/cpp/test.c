
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "aes256.h"

//#define DUMP(s, i, buf, sz)  {printf(s);                   \
// for (i = 0; i < (sz);i++)    \
// printf("%02x ", buf[i]); \
// printf("\n");}

/*
CBC���ܣ�������������16λ��32λ..��16�ı��������뷽ʽ��Ӧ��Java�е�NoPadding���������ȵ��������뷽ʽ��һ�£���Java����г���
AES 256
*/
int main(int argc, char *argv[])
{
	aes256_context ctx;
	uint8_t i;
	uint8_t enc_out[48];    //���ܺ���
	uint8_t dec_out1[3840];  //���ܺ���
	clock_t start, finish;
	double duration;

	unsigned char key[] = "abcdefghijkomnopqrstuvwxyz123456";//��Կ��32λ
	unsigned char iv[] = "a1a2a3a4a5a6a7a8";//������16λ
	//unsigned char encypt_input[] = "1234567890123456";//�������ݣ�16λ
	unsigned char encypt_input[] = "�������ܽ��������������ܽ�������";//�������ݣ�16λ��32λ
	//��������
	//uint8_t decode_input[3840] = { 0x19,0x58,0x86,0x27,0x09,0x58,0x72,0x71,0x6d,0x96,0xb7,0x04,0x9d,0xc6,0xa8,0x8b };
	uint8_t decode_input[32] = { 0x13,0x11,0xff,0x87,0xea,0x30,0xd5,0x51,0x0a,0xf2,0x58,0xf1,0x25,0x2c,0xcb,0xf7,0xd9,0xba,0x50,0x44,0xe5,0xc2,0x96,0x82,0x56,0x6e,0xa3,0xa9,0xb2,0x4f,0xbb,0xeb };

	start = clock();
	aes256_init(&ctx, key);//��ʼ����Կ
	/*aes256_decrypt(&ctx,iv, input);*/
	aes256_encrypt_cbc(&ctx, encypt_input, iv, enc_out);//����
	aes256_decrypt_cbc(&ctx, decode_input, iv, dec_out1);//����
	
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	printf("\n��Կ16����:");
	for (i = 0; i<32; i++)
	{
		printf("%02x", key[i]);
	}
	printf("\n����16����:");
	for (i = 0; i<16; i++)
	{
		printf("%02x", iv[i]);
	}

	printf("\n��������16����:");
	for (i = 0; i<32; i++)
	{
		printf("%02x", encypt_input[i]);
	}

	printf("\n\n���ܽ��16����:");
	for (i = 0; i<32; i++)
	{
		printf("%02x", enc_out[i]);
	}

	printf("\n\n��������16����:");
	for (i = 0; i<32; i++)
	{
		printf("%02x", decode_input[i]);
	}

	printf("\n���ܽ��16����:");
	for (i = 0; i<32; i++)
	{
		printf("%02x", dec_out1[i]);
	}
	printf("\n");
	//aes256_done(&ctx);

	return 0;
}
