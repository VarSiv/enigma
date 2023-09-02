#include <stdio.h>
#include <stdlib.h>
//DUDA: como aclaramos tests?
struct letter {
    char letter;
    int position;
    struct letter* next;
};
struct wheel {
    struct letter* first;
    char* alphabet;
    int count;
};
struct littleEnigma {
    struct wheel** wheels;
    int wheelsCount;
};

int strLen(char* src) {
    //calcula longitud de string src
    //avanza por los caracteres hasta encontrar el nulo
    int count = 0;
    while (src[count]!='\0'){
        count++;
    }
    return count;
}

char* strDup(char* src) {
    //devuelve un puntero  
    char* c = (char*)malloc(sizeof(char)*(strLen(src)+1));
    for (int i = 0; i < strLen(src); i++ ){
        c[i] = src[i];
    }
    c[strLen(src)] = 0;
    return c;
}
int letterToIndex(char letter) {
    //dada
    if('A' <= letter && letter <= 'Z') return letter-'A';
    return 0;
}
struct wheel* makeWheelFromString(char* alphabetPermutation) {
    //por cada letra asignamos un malloc
    //tenemos guardada la letra anterior para asignar el next
    //guardamos la 1ra letra para hacer la lista circular y asignar el first de wheel
    struct wheel* w = (struct wheel*)malloc(sizeof(struct wheel));
    struct letter* letterPointer;
    struct letter* first;
    for (int i = 0; i<strLen(alphabetPermutation); i++){
        struct letter* myLetter = (struct letter*)malloc(sizeof(struct letter));
        myLetter->letter = alphabetPermutation[i];
        myLetter->position = i;
        if (i==0){
            first = myLetter;
        }
        if (i != 0){
            letterPointer->next = myLetter;
        }
        if (i == strLen(alphabetPermutation)-1){
            myLetter ->next = first;
        }
        letterPointer = myLetter;
    }

    w->first = first;
    w->alphabet = strDup(alphabetPermutation);
    w->count = strLen(alphabetPermutation);
    return w;
}

struct littleEnigma* littleEnigmaNew(char** alphabetPermutation, int count) {
    //por cada alfabeto creamos una nueva rueda con makeWheelFromString y la agregamos al arreglo enigma->wheels
    //pedimos un malloc para la estructura en si y otro para el arreglo de ruedas
    struct littleEnigma* enigma = (struct littleEnigma*)malloc(sizeof(struct littleEnigma));
    enigma->wheelsCount = count;
    enigma->wheels = (struct wheel**)malloc(sizeof(struct wheel*) * count );

    for (int i = 0; i < count; i++) {
        enigma->wheels[i] = makeWheelFromString(alphabetPermutation[i]);
    }
    return enigma;
}
void setWheel(struct wheel* w, int position) {
    //dada
    struct letter* current = w->first;
    while(current->position != position%(w->count)) {
        current = current->next;
    }
    w->first = current;   
}
void littleEnigmaSet(struct littleEnigma* le, int* password) {
    //ponemos a cada rueda en la posicion necesaria con indices del arreglo password
    for (int i = 0; i<le->wheelsCount; i++){
        setWheel(le->wheels[i], password[i]);
    }
    
}
char encryptWheel(struct wheel* w, char letter) {
    //dada
    int index =  letterToIndex(letter);
    struct letter* current = w->first;
    int i = 0;
    while(i<index) {
        current = current->next;
        i++;
    }
    return current->letter;
}

void rotateWheel(struct wheel* w, int steps) {
    //movemos el puntero first steps veces 
    for (int i=0; i<steps%(w->count); i++){
        w-> first = w->first->next;
    }

}

void rotateWheels(struct wheel** wheels, int wheelsCount) {
    //rotamos la 1ra rueda
    //si una rueda es 0, rotamos por 1 la siguiente
    //si no salimos del ciclo
    rotateWheel(wheels[0], 1);
    for (int i=0; i<wheelsCount-1; i++){
        if (wheels[i]->first->position==0){
            rotateWheel(wheels[i+1], 1);
        }
        else{
            return;
        }
    }
    

}

char encryptOneLetter(struct littleEnigma* le, char letter) {
    //encriptamos rueda por rueda usando encryptWheel
    char vr = letter;
    for (int i=0; i<(le->wheelsCount); i++){
        vr = encryptWheel(le->wheels[i], vr);
    }
    rotateWheels(le->wheels, le->wheelsCount);
    return vr;
}

char indexToletter(int index) {
    //dada
    if(0 <= index && index <= 25) return index+'A';
    return 0;
}
void wheelPrint(struct wheel* w) {
    //dada
    printf("%s", w->alphabet);
    struct letter* current = w->first;
    int i = 0;
    while(i<w->count) {
        printf("(%c-%i)", current->letter, current->position);
        current = current->next;
        i++;
    }
}
char decryptWheel(struct wheel* w, char letter) {
    //dada
    struct letter* current = w->first;
    int i = 0; 

    while(current->letter != letter) {
        current = current->next;
        i++;
    }

    return indexToletter(i);
}
char decryptOneLetter(struct littleEnigma* le, char letter) {
    //vamos de atras hacia delante, haciendo el proceso inverso a encryptOneLetter
    
    char curLetter = letter;
    for(int i = (le->wheelsCount)-1; i>=0; i--){
        curLetter = decryptWheel(le->wheels[i], curLetter);


    }
    rotateWheels(le->wheels, le->wheelsCount);

    return curLetter;
}

void littleEnigmaPrint(struct littleEnigma* le) {
    //dada
    for(int i=0; i<le->wheelsCount; i++) {
        wheelPrint(le->wheels[i]);
        printf("\n");
    }
}

char* littleEnigmaEncrypt(struct littleEnigma* le, char* text){
    //por cada letra llamamos encryptOneLetter
    //cada letra ponemos en el indice correspondiente de vr
    char* vr = (char*) malloc(sizeof(char)*strLen(text)+1);
    for (int i = 0; i<strLen(text); i++){
        vr[i] = encryptOneLetter(le, text[i]);
    }
    vr[strLen(text)] = '\0';
    return vr;
}

char* littleEnigmaDecrypt(struct littleEnigma* le, char* code) {
    //mismo que littleEnigmaEcrypt, vamos letra por letra usando decryptOneLetter
    char* res = (char*) malloc(sizeof(char)*strLen(code)+1);
    int i = 0;
    for (int i = 0; i<strLen(code); i++){

        res[i]=decryptOneLetter(le, code[i]);
        
    }
    res[strLen(code)] = '\0';
    return res;
}




void wheelDelete(struct wheel* w) {
    //utilizamos copia para conservar el puntero al siguiente, borramos borrar
    //luego liberamos el puntero a alphabet y la rueda en si
    struct letter* copia = w->first;
    for (int i = 0; i < w->count; i++){
        struct letter* borrar = copia;
        copia = copia->next;
        free(borrar);
    }
    free(w->alphabet);
    free(w);
}

void littleEnigmaDelete(struct littleEnigma* le) {
    //borramos cada rueda, luego el puntero al arreglo wheels y luego la estructura en si
    for (int i=0; i<le->wheelsCount; i++){
        wheelDelete(le->wheels[i]);
    }
    free(le->wheels);
    free(le);
}    
