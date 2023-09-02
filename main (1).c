#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {

    // strLen
    int len1 = strLen("");   // String vacío
    printf("strLen(\"\") -> %i\n", len1);
    printf("\n");

    int len2 = strLen("a");   // String de un carácter
    printf("strLen(\"a\") -> %i\n", len2);
    printf("\n");

    int len3 = strLen("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789");   // String con todos los caracteres válidos distintos de cero
    printf("strLen(\"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789\") -> %i\n", len3);
    printf("\n");

    int len4 = strLen("lalal");   // String de longitud impar
    printf("strLen(\"lalal\") -> %i\n", len4);
    printf("\n");

    int len5 = strLen("lala");   // String de longitud par
    printf("strLen(\"lala\") -> %i\n", len5);
    printf("\n");

    int len6 = strLen("   ");   // String que contiene espacios en blanco
    printf("strLen(\"   \") -> %i\n", len6);
    printf("\n");

    int len7 = strLen("!@#$");   // String que contiene caracteres especiales
    printf("strLen(\"!@#$\") -> %i\n", len7);
    printf("\n");

    int len8 = strLen("12345");   // String que contiene números
    printf("strLen(\"12345\") -> %i\n", len8);
    printf("\n");

    
    //strDup
    char *dup1 = strDup("");   // String vacío
    printf("strDup(\"\") -> \"%s\"\n", dup1);
    printf("\n");
    
    char *dup2 = strDup("b");   // String de un carácter
    printf("strDup(\"b\") -> \"%s\"\n", dup2);
    printf("\n");

    char *dup3 = strDup("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789");   // String con caracteres válidos distintos de cero
    printf("strDup(\"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789\") -> \"%s\"\n", dup3);
    printf("\n");

    char *dup4 = strDup("   ");   // String que contiene espacios en blanco
    printf("strDup(\"   \") -> \"%s\"\n", dup4);
    printf("\n");

    char *dup5 = strDup("!@#$");   // String que contiene caracteres especiales
    printf("strDup(\"!@#$\") -> \"%s\"\n", dup5);
    printf("\n");

    char *dup6 = strDup("987654");   // String que contiene números
    printf("strDup(\"987654\") -> \"%s\"\n", dup6);
    printf("\n");

    free(dup1);
    free(dup2);
    free(dup3);
    free(dup4);
    free(dup5);
    free(dup6);

    // wheel
    struct wheel* w1 = makeWheelFromString("Q"); //Wheel con un alfabeto de 1 caracter
    wheelPrint(w1);
    printf("\n");
    
    setWheel(w1, 5);
    wheelPrint(w1);
    printf("\n");

    rotateWheel(w1, 100);
    wheelPrint(w1);
    printf("\n");

    wheelDelete(w1);
    printf("\n\n");

    struct wheel* w2 = makeWheelFromString("QWERTYUIOP");  //Wheel con un alfabeto de 10 caracteres
    wheelPrint(w2);
    printf("\n");

    setWheel(w2, 5);
    wheelPrint(w2);
    printf("\n");

    rotateWheel(w2, 100);
    wheelPrint(w2);
    printf("\n");

    wheelDelete(w2);
    printf("\n\n");

    struct wheel* w3 = makeWheelFromString("TREWQYUIOPASDFGHJKLMNBVCXZ");  //Wheel con un alfabeto de 26 caracteres
    wheelPrint(w3);
    printf("\n");

    setWheel(w3, 5);
    wheelPrint(w3);
    printf("\n");

    rotateWheel(w3, 100);
    wheelPrint(w3);
    printf("\n");

    wheelDelete(w3);
    printf("\n\n");

    // rotateWheel

    struct wheel* w4 = makeWheelFromString("TREWQYUIOPASDFGHJKLMNBVCXZ");  //Wheel con un alfabeto de 26 caracteres con una posicion de rotacion
    wheelPrint(w4);
    printf("\n");

    setWheel(w4, 25);
    wheelPrint(w4);
    printf("\n");

    setWheel(w4, 0);
    wheelPrint(w4);
    printf("\n");

    setWheel(w4, 5);
    wheelPrint(w4);
    printf("\n");

    rotateWheel(w4, 1);
    wheelPrint(w4);
    printf("\n");

    rotateWheel(w4, 0);
    wheelPrint(w4);
    printf("\n");
    wheelDelete(w4);
    printf("\n\n");

    struct wheel* w5 = makeWheelFromString("TREWQYUIOPASDFGHJKLMNBVCXZ");  //Wheel con un alfabeto de 26 caracteres con 26 posiciones de rotacion
    wheelPrint(w5);
    printf("\n");

    setWheel(w5, 5);
    wheelPrint(w5);
    printf("\n");

    rotateWheel(w5, 26);
    wheelPrint(w5);
    printf("\n");

    rotateWheel(w5, 1);
    wheelPrint(w5);
    printf("\n");

    rotateWheel(w5, 25);
    wheelPrint(w5);
    printf("\n");
    wheelDelete(w5);
    printf("\n\n");

    struct wheel* w6 = makeWheelFromString("TREWQ");  //Wheel con un alfabeto de 5 caracteres con 26 posiciones de rotacion
    wheelPrint(w6);
    printf("\n");

    setWheel(w6, 5);
    wheelPrint(w6);
    printf("\n");

    rotateWheel(w6, 26);
    wheelPrint(w6);
    printf("\n");

    wheelDelete(w6);
    printf("\n\n");

    struct wheel* w7 = makeWheelFromString("T");  //Wheel con un alfabeto de 1 caracter con 26 posiciones de rotacion
    wheelPrint(w7);
    printf("\n");

    setWheel(w7, 5);
    wheelPrint(w7);
    printf("\n");

    rotateWheel(w7, 26);
    wheelPrint(w7);
    printf("\n");

    wheelDelete(w7);
    printf("\n\n");

// littleEnigma

    char* alphabetPermutation[2];
    alphabetPermutation[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    alphabetPermutation[1] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    struct littleEnigma* le1 = littleEnigmaNew(alphabetPermutation, 2);
    printf("\n\n");

    int password[2] = { 3, 5 };
    littleEnigmaSet(le1, password);
    littleEnigmaPrint(le1);
    printf("\n\n");

    char* text1 = ""; //encriptr y desincriptar string vacio
    char* code1 = littleEnigmaEncrypt(le1, text1);
    

    littleEnigmaSet(le1, password);
    printf("\n\n");

    char* decode1 = littleEnigmaDecrypt(le1, code1);
    printf("%s -> %s -> %s\n\n", text1, code1, decode1);


    int password_[2] = { 0, 0 };
    littleEnigmaSet(le1, password_);
    char* text_ = "A"; //Encriptar y desincriptar una letra
    char* code_ = littleEnigmaEncrypt(le1, text_);
    littleEnigmaSet(le1, password_);
    printf("\n\n");
    char* decode_ = littleEnigmaDecrypt(le1, code_);
    printf("%s -> %s -> %s\n\n", text_, code_, decode_);
    if(code1) free(code1);
    if(decode1) free(decode1);
    if(code_) free(code_);
    if(decode_) free(decode_);
    littleEnigmaDelete(le1);



    char* alphabetPermutation2[1];
    alphabetPermutation2[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    struct littleEnigma* le2 = littleEnigmaNew(alphabetPermutation2, 1);
    printf("\n\n");

    int password2[1] = { 3 };
    littleEnigmaSet(le2, password2);
    littleEnigmaPrint(le2);
    printf("\n\n");

    char* text2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    char* code2 = littleEnigmaEncrypt(le2, text2);
    
    littleEnigmaSet(le2, password2);
    printf("\n\n");

    char* decode2 = littleEnigmaDecrypt(le2, code2);
    printf("%s -> %s -> %s\n\n", text2, code2, decode2);

    if(code2) free(code2);
    if(decode2) free(decode2);

    littleEnigmaDelete(le2);



    char* alphabetPermutation3[3];
    alphabetPermutation3[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    alphabetPermutation3[1] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    alphabetPermutation3[2] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    struct littleEnigma* le3 = littleEnigmaNew(alphabetPermutation3, 3);
    printf("\n\n");

    int password3[3] = { 3, 5, 1 };
    littleEnigmaSet(le3, password3);
    littleEnigmaPrint(le3);
    printf("\n\n");

    char* text3 = "BLABLALALA";
    char* code3 = littleEnigmaEncrypt(le3, text3);

    littleEnigmaSet(le3, password3);
    printf("\n\n");

    char* decode3 = littleEnigmaDecrypt(le3, code3);
    printf("%s -> %s -> %s\n\n", text3, code3, decode3);

    if(code3) free(code3);
    if(decode3) free(decode3);

    littleEnigmaDelete(le3);



    // Maquina Enigma con mensaje de 10 caracteres con 5 discos

    char* alphabetPermutation4[5];
    alphabetPermutation4[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    alphabetPermutation4[1] = "NZPSFBTOKMWRCJDIVLAEYUXHGQ";
    alphabetPermutation4[2] = "NTZPSFBOKMWRDIVLAEYUXHGQCJ";
    alphabetPermutation4[3] = "BOKMWRCJDIVLANTZPSFEYUXHGQ";
    alphabetPermutation4[4] = "NTZPSFMWRCJDIVLAEYUXBOKHGQ";
    struct littleEnigma* le4 = littleEnigmaNew(alphabetPermutation4, 5);
    int password4[5] = { 2, 5, 1, 4, 2 };
    littleEnigmaSet(le4, password4);
    littleEnigmaPrint(le4);
    printf("\n\n");


    char* text4 = "ABEBEBEBEB";
    char* code4 = littleEnigmaEncrypt(le4, text4);
    littleEnigmaSet(le4, password4);
    
    printf("\n\n");

    char* decode4 = littleEnigmaDecrypt(le4, code4);
    printf("%s -> %s -> %s\n\n", text4, code4, decode4);

    int password41[5] = { 25, 25, 25, 4, 2 }; //probar que las siguientes ruedas funcionan correctamente cuando giran
    littleEnigmaSet(le4, password41);
    littleEnigmaPrint(le4);
    char* text41 = "XYZ";
    char* code41 = littleEnigmaEncrypt(le4, text41);
    littleEnigmaSet(le4, password41);
    printf("\n\n");

    char* decode41 = littleEnigmaDecrypt(le4, code41);
    printf("%s -> %s -> %s\n\n", text41, code41, decode41);
    if(code4) free(code4);
    if(decode4) free(decode4);
    if(code41) free(code41);
    if(decode41) free(decode41);



    littleEnigmaDelete(le4);




    // Maquina Enigma con mensaje de 10 caracteres con 5 discos

    char* alphabetPermutation5[8];
    alphabetPermutation5[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    alphabetPermutation5[1] = "NTZPSFBOKMWRCJDIVLXHGQAEYU";
    alphabetPermutation5[2] = "FBOKMWRCJDIVLAEYUXHNTZPSGQ";
    alphabetPermutation5[3] = "WRCJDIVLAEYUNTZPSFBOKMXHGQ";
    alphabetPermutation5[4] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    alphabetPermutation5[5] = "NTZPSFBOKCJDIVLMWRAEYUXHGQ";
    alphabetPermutation5[6] = "ZPSFHBOKMNTWRCJDIVLAEYUXGQ";
    alphabetPermutation5[7] = "NTZPSFQBOKMWRCJDIVLAEYUXHG";

    struct littleEnigma* le5 = littleEnigmaNew(alphabetPermutation5, 8);
    int password5[8] = { 3, 10, 5, 1, 4, 21, 2, 1 };
    littleEnigmaSet(le5, password5);
    littleEnigmaPrint(le5);
    printf("\n\n");


    char* text5 = "HOLACOMOVA";
    char* code5 = littleEnigmaEncrypt(le5, text5);
    littleEnigmaSet(le5, password5);
    
    printf("\n\n");

    char* decode5 = littleEnigmaDecrypt(le5, code5);
    printf("%s -> %s -> %s\n\n", text5, code5, decode5);


 
    if(code5) free(code5);
    if(decode5) free(decode5);

    littleEnigmaDelete(le5);

    return 0;
}
