#define WRONG_ARGUMENTS -1
#define TEXTFILE_OPEN_ERROR -2
#define VOCABULARYFILE_OPEN_ERROR -3
#define TEMPFILE_OPEN_ERROR -4
#define TEXTFILE_CLOSE_ERROR -5
#define VOCABULARYFILE_CLOSE_ERROR -6
#define TEMPFILE_CLOSE_ERROR -7
#define REMOVE_ERROR -8
#define RENAME_ERROR -9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* wordInVocabulary(char* word, FILE* vfile);
char* getNextWord(FILE* f, char** spacesOutput);
char* copyFromArray(char arr[], int size);

int main(int argc,char* argv[])
{
	char* word_org;
	char* word_new;
	char* spaces;
	int rc=0;
	FILE* tfile;
	FILE* vfile;
	FILE* ofile;
	/*wrong arguments*/
	if (argc!=3)
	{
		printf("The right usage is voc_switch <text file> <vocabulary file>\n");
		return WRONG_ARGUMENTS;
	}
	/*open files*/
	tfile = fopen(argv[1],"r");
	if (tfile == NULL)
	{
		printf("Could not open %s\n",argv[1]);
		return TEXTFILE_OPEN_ERROR;
	}
	vfile = fopen(argv[2], "r");
	if (vfile == NULL)
	{
		printf("Could not open %s\n", argv[2]);
		return VOCABULARYFILE_OPEN_ERROR;
	}
	ofile = fopen("temp", "w");
	if (ofile==NULL)
	{
		return TEMPFILE_CLOSE_ERROR;
	}

	while (!feof(tfile))
	{
		word_org = getNextWord(tfile, &spaces); /*updates spaces*/
		word_new = wordInVocabulary(word_org, vfile); /*get new word from vocabulary, word_org is returned if it isn't in vocabulary*/
		/*write word_new and spaces to the new file*/
		fputs(word_new, ofile); // T: check for fputs failure
		if (spaces != NULL){ 
			fputs(spaces, ofile); // T: check for fputs failure
		}
		/*free alocated strings*/
		if (word_new!=word_org)
		{
			free(word_new);
		}
		free(word_org);
		free(spaces);
	}

	/*close files*/
	if (!fclose(tfile))
	{
		rc = TEXTFILE_CLOSE_ERROR;
	}
	if (!fclose(vfile))
	{
		rc = VOCABULARYFILE_CLOSE_ERROR;
	}
	if (!fclose(ofile))
	{
		rc = TEMPFILE_CLOSE_ERROR;
	}
	/*remove and rename temp*/
	if (remove(argv[1])!=0)
	{
		rc = REMOVE_ERROR;
	}
	if (rename("temp", argv[1])!=0)
	{
		rc = RENAME_ERROR;
	}
	return rc;
}
char* wordInVocabulary(char* word,FILE* vfile)
{
	/*vocabulary format:*/
	/*definiton - synonym1 synonym2 synonym3 ...*/
	char c;
	char* definition;
	while (!feof(vfile))
	{
		definition = getNextWord(vfile,NULL);
		if (strcmp(definition,word)==0)
		{
			while (!isalpha(fgetc(vfile))); /*skip non alpha*/
			fseek(vfile, -1, SEEK_CUR);
			return getNextWord(vfile, NULL);
		}
		else
		{
			while ((c = fgetc(vfile)) != EOF&&c != '\n');/*skips line*/
		}
	}
	fseek(vfile, 0, SEEK_SET);
	return word; // T: free definition memory
}
char* getNextWord(FILE* f, char** spacesOutput)
{
	/*if spacesOutput is NULL, spaces will not be returned*/
	char arr[20];
	int size = 0;
	char c;
	char* word;
	/*copy a word to array*/
	while ((c = fgetc(f))!=EOF)
	{
		if (isspace(c))
		{
			break;
		}
		arr[size] = c;
		size++;
	}

	word = copyFromArray(arr, size);

	/*handling spaces and returning a string containig the following spaces, if spacesOutput is not NULL*/
	if (spacesOutput!=NULL)
	{
		if (c != EOF){ /*true if last fgetc exited because it was a space and not eof*/
			arr[0] = c;
			size = 1;
			while ((c = fgetc(f)) != EOF)
			{
				if (!isspace(c))
				{
					break;
				}
				arr[size] = c;
				size++;
			}
			if (c != EOF) /*if returned because c is not a space, go back so c can be read for the next word*/
			{
				fseek(f, -1, SEEK_CUR);
			}
			*spacesOutput = copyFromArray(arr, size);

		}
		else
		{
			*spacesOutput = NULL;
		}
	}
	
	


	return word;
}
char* copyFromArray(char arr[],int size) // T: you included string.h you can use memcpy or strndup
{
	int i;
	/*allocate memmory so the word can live on other scpoes and coppy it*/
	char* word = malloc(sizeof(char)*(size + 1));/*sizeof(char) is always 1*/ // T: malloc can fail and return null
	for (i = 0; i < size; i++)
	{
		word[i] = arr[i];
	}
	word[size] = '\0';
	return word;
}
