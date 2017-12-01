package com.example.xingyan.accountservices;

import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;

import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

/**
 * Created by xingyan on 01/11/2017.
 */

public class AES {
    private static final String ALGORITHM = "AES/CBC/PKCS5Padding";
    //加密
    public static byte[] AES_cbc_encrypt(byte[] srcData,byte[] key,byte[] iv) {
        try{
            SecretKeySpec keySpec = new SecretKeySpec(key, "AES");
            Cipher cipher = Cipher.getInstance(ALGORITHM);
            cipher.init(Cipher.ENCRYPT_MODE, keySpec, new IvParameterSpec(iv));
            byte[] encData = cipher.doFinal(srcData);
            return encData;
        }catch (Exception e){
        }
        return srcData;
    }

    //解密
    public static byte[] AES_cbc_decrypt(byte[] encData,byte[] key,byte[] iv)
    {
        try{
            SecretKeySpec keySpec = new SecretKeySpec(key, "AES");
            Cipher cipher = Cipher.getInstance(ALGORITHM);
            cipher.init(Cipher.DECRYPT_MODE, keySpec, new IvParameterSpec(iv));
            byte[] decbbdt = cipher.doFinal(encData);
            return decbbdt;
        }catch (Exception e){
        }

        return encData;
    }
}
