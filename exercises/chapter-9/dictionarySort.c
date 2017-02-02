#include <stdio.h>

struct entree
{
	char word[30];
	char definition[50];
};

void dictionarySort (struct entree dictionary[], int totalWords)
{
	int i, j, k;
	
	struct entree temp;
	
	for ( i = 0; i < totalWords - 1; ++i )
		for ( j = i + 1; j < totalWords; ++j )
			for ( k = 0; k < 10; ++k ) // loop to find different letter
			{
				if ( dictionary[i].word[k] < dictionary[j].word[k] ) // if one letter is lower than another, they are already in order
					break;
				if ( dictionary[i].word[k] > dictionary[j].word[k] )
					// if different letter of first word is larger than different letter of second word, swap words
				{
					temp = dictionary[i];
					dictionary[i] = dictionary[j];
					dictionary[j] = temp;
					break;
				}
			}
}

int main (void)
{
	void dictionarySort (struct entree dictionary[], int totalWords);
	int i;
	int totalWords = 11;
	
	struct entree dictionary[100] =
	{	{ "affix", "to append; attach" },
		{ "agar", "a jelly made from seaweed" },
		{ "ahoy", "a nautical call of greeting" },
		{ "aardvark", "a burrowing African mammal" },
		{ "aigrette", "an ornamental cluster of feathers" },
		{ "abyss", "a bottomless pit" },
		{ "acumen", "mentally sharp; keen" },
		{ "banana", "my favourite fruit" },
		{ "addle", "to become confused" },
		{ "aerie", "a high nest" },
		{ "ajar", "partially opened" } };
	
	printf ("Dictionary before sorting:\n");
	
	for ( i = 0; i < totalWords; ++i)
		printf ("%s: %s\n", dictionary[i].word, dictionary[i].definition);
	
	dictionarySort (dictionary, totalWords);
	
	printf ("\nDictionary after sorting:\n");
	
	for ( i = 0; i < totalWords; ++i )
		printf ("%s: %s\n", dictionary[i].word, dictionary[i].definition);
	
	return 0;
}

/* OUTPUT:
 Dictionary before sorting:
 affix: to append; attach
 agar: a jelly made from seaweed
 ahoy: a nautical call of greeting
 aardvark: a burrowing African mammal
 aigrette: an ornamental cluster of feathers
 abyss: a bottomless pit
 acumen: mentally sharp; keen
 banana: my favourite fruit
 addle: to become confused
 aerie: a high nest
 ajar: partially opened
 
 Dictionary after sorting:
 aardvark: a burrowing African mammal
 abyss: a bottomless pit
 acumen: mentally sharp; keen
 addle: to become confused
 aerie: a high nest
 affix: to append; attach
 agar: a jelly made from seaweed
 ahoy: a nautical call of greeting
 aigrette: an ornamental cluster of feathers
 ajar: partially opened
 banana: my favourite fruit 
 */
