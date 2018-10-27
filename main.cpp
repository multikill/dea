#pragma once

#include "dea.h"
#include <cstdio>
#include <cstring>
#include <iostream>

int main()
{
	
	char zustaende[][2] = {
		'q' , '0' ,
		'q' , '1' ,
		'q' , '2' ,
		'q' , 'T' ,
		'\0'
	};

	char alphabet[] = { 'a' , 'b' , 'c', '\0' };

	char uebgergaenge[][5] = {
		// from  -> with ->  to
		'q' , '0' , 'a' , 'q' , '1' ,
		'q' , '0' , 'b' , 'q' , 'T' ,
		'q' , '0' , 'c' , 'q' , 'T' ,

		'q' , '1' , 'a' , 'q' , '1' ,
		'q' , '1' , 'b' , 'q' , '1' ,
		'q' , '1' , 'c' , 'q' , '2' ,

		'q' , '2' , 'a' , 'q' , '1' ,
		'q' , '2' , 'b' , 'q' , '1' ,
		'q' , '2' , 'c' , 'q' , '2' ,

		'q' , 'T' , 'a' , 'q' , 'T' ,
		'q' , 'T' , 'b' , 'q' , 'T' ,
		'q' , 'T' , 'c' , 'q' , 'T' ,
		'\0'
	};

	char start[3] = { 'q' , '0' , '\0' };

	char ende[3] = { 'q' , '2' , '\0' };

	//char input[] = { 'a' , 'b' , 'c' , '\0' };
	char input[30] = { };

	char current[3] = { start[0], start[1], '\0' };

	printf("Der Wort muss mit \"a\" beginnen und \"c\" enden. Geben Sie ein Wort ein: ");
	std::cin >> input;

	int ok = 0;
	ok |= inputInAlphabet    (&input[0]          , strlen(input)           , &alphabet[0]    , sizeof(alphabet)  - 1);
	ok |= positionInZustaende(&start[0]          , sizeof(start)        - 1, &zustaende[0][0], sizeof(zustaende) - 2);
	ok |= positionInZustaende(&ende[0]           , sizeof(ende)         - 1, &zustaende[0][0], sizeof(zustaende) - 2);
	ok |= checkUebergaenge   (&uebgergaenge[0][0], sizeof(uebgergaenge) - 5, &zustaende[0][0], sizeof(zustaende) - 2, &alphabet[0]       , sizeof(alphabet)     - 1);
	ok |= wechselZustand     (&current[0]        , sizeof(current)      - 1, &input[0]       , strlen(input)        , &uebgergaenge[0][0], sizeof(uebgergaenge) - 5);
	ok |= istGleicherZustand (&current[0]        , sizeof(current)      - 1, &ende[0]        , sizeof(ende)      - 1);

	printf("Das Wort \"%s\" ist %sein Teil der Sprache", input, ok ? "k" : "");

	return 0;
}
