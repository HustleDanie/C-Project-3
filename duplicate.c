#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


int isDigitOnly(const char *s)
{
    while (*s) {
        if (isdigit(*s++) == 0) return 0;
    }

    return 1;
}

int main()
{
    FILE *file = fopen("files.in", "r");
    if (file == NULL)
    {
        printf("Unable to open file");
    }

    char currentLine[100];

    char contentArray[100][100];

    int lineIndex = 0;

    // Appending all the current line into the contentArray
    while (fgets(currentLine, 50, file) != NULL)
    {
        if (lineIndex == 0)
        {
            lineIndex++;
            continue;
        }

        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(contentArray[lineIndex], currentLine);

        lineIndex++;
    }

    // Looping through each line
    for (int i = 0; i < lineIndex + 1; i++)
    {
        // Checking what line is a digit
        int isPureDigit = isDigitOnly(contentArray[i]);

        if (isPureDigit)
        {

            int length = atoi(contentArray[i]);
            char currentSubset[length][100];
            int index = 0;

            // Get the subset of the files based on the digit and storing all those file elements inside currentSubset
            for (int j = i + 1; j <= i + atoi(contentArray[i]); j++)
            {

                strcpy(currentSubset[index], contentArray[j]);

                index++;
            }

            int size = sizeof(currentSubset) / sizeof(*currentSubset);

            char checkedElements[size][100];

            int idIndex = 0;
            char id[20] = "";

            for (int i = size - 1; i >= 0; i--)
            {
                char currentElement[100];
                int isPresent = 0;

                strcpy(currentElement, currentSubset[i]);

                strtok(currentElement, " ");

                for (int i = 0; i < size; ++i)
                {
                    if (!strcmp(checkedElements[i], currentElement))
                    {
                        isPresent = 1;
                    }
                }

                if (!isPresent)
                {
                    char string[50];

                    strcpy(string, currentSubset[i]);

                    char *currentId = strrchr(string, ' ');

                    strcat(id, currentId);

                    strcpy(checkedElements[idIndex], currentElement);
                }

                idIndex++;
            }

            printf("\n%s", id);
        }
    }

    fclose(file);

    return 0;
}