#include "dea.h"

int inputInAlphabet(char* _input, int iSize, char* _alphabet, int aSize)
{
	// Loop every char in input
	for (int i = 0; i < iSize; i++)
	{
		// loop every char in alphabet
		for (int j = 0; j < aSize; j++)
		{
			// OK
			if (_input[i] == _alphabet[j])
				break;

			// False
			if (j == (aSize - 1))
				return 1;
		}
	}
	return 0;
}

int positionInZustaende(char* _start, int sSize, char* _zustaende, int zSize)
{
	// Loop every element in zustaende
	for (int i = 0, j = 1; i < zSize; i += 2, j += 2)
	{
		// OK
		if ((_start[0] == _zustaende[i]) && (_start[1] == _zustaende[j]))
			break;

		// False
		if (i == (zSize - 2))
			return 1;
	}
	return 0;
}

int checkUebergaenge(char *_uebgergaenge, int uSize, char* _zustaende, int zSize, char* _alphabet, int aSize)
{
	// Loop through Uebergaenge
	for (int i = 0; i < uSize; i += 5)
	{
		// Startzustand
		for (int j = 0; j < zSize; j += 2)
		{
			// OK
			if ((_uebgergaenge[i] == _zustaende[j]) && (_uebgergaenge[i + 1] == _zustaende[j + 1]))
				break;

			// False
			if (j == (zSize - 2))
				return 1;
		}

		// Alphabet Check
		for (int k = 0; k < aSize; k += 1)
		{
			// OK
			if (_uebgergaenge[i + 2] == _alphabet[k])
				break;

			// False
			if (k == (aSize - 1))
				return 1;
		}

		// Endzustand Check
		for (int l = 0; l < zSize; l += 2)
		{
			// OK
			if ((_uebgergaenge[i + 3] == _zustaende[l]) && (_uebgergaenge[i + 4] == _zustaende[l + 1]))
				break;

			// False
			if (l == (zSize - 2))
				return 1;
		}


	}
	return 0;
}

int wechselZustand(char *_current, int cSize, char *_input, int iSize, char* _uebgergaenge, int uSize)
{
	for (int i = 0; i < iSize; i += 1)
	{
		// Startzustand
		for (int j = 0; j < uSize; j += 5)
		{
			// OK
			if ((_uebgergaenge[j] == _current[0])
				&& (_uebgergaenge[j + 1] == _current[1])
				&& (_uebgergaenge[j + 2] == _input[i]))
			{
				_current[0] = _uebgergaenge[j + 3];
				_current[1] = _uebgergaenge[j + 4];
				break;
			}

			// False
			if (j == (uSize - 2))
			{
				_current[0] = 'q';
				_current[1] = 'T';
				break;
			}

		}
	}

	return 0;
}

int istGleicherZustand(char* _current, int cSize, char* _ende, int eSize)
{

	if ((_current[0] == _ende[0]) && (_current[1] == _ende[1]))
		return 0;

	return 1;
}