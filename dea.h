#pragma once

int inputInAlphabet    (char* _input       , int iSize, char* _alphabet , int aSize);
int positionInZustaende(char* _start       , int sSize, char* _zustaende, int zSize);
int checkUebergaenge   (char *_uebgergaenge, int uSize, char* _zustaende, int zSize, char* _alphabet    , int aSize);
int wechselZustand     (char *_current     , int cSize, char* _input    , int iSize, char* _uebgergaenge, int uSize);
int istGleicherZustand (char* _current     , int cSize, char* _ende     , int eSize);