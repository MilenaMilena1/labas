#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char* word;
    size_t n = 0;
	getline(&word, &n, stdin);
	int wl = strlen(word);
	
	char* consonants = "bcdfghjklmnpqrstvwxz";
	char* vowels = "aeiouy";
	
	int cs = 0, vs = 0;
	
	for (int i = 0; i < strlen(vowels); i++)
	{
		for (int j = 0; j < wl; j++)
		{
			if ( word[j] == vowels[i])
				vs++;
		}
	}
	cs = wl - vs;
	printf("Your line\n%shas %d symbols with %d vowels and %d consonants\n", word, wl, vs, cs);
	return 0;
}