#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256

int main()
{
    time_t now;
    struct tm *clock;
    int hour;

    char time_string[64]; // Storage for the string filled by strftime() function
    time(&now);
    clock = localtime(&now);

    const char FILENAME[] = "pithy.txt"; // assumed to be in the same directory
    FILE *file_ptr;
    char buffer[BUFFER_SIZE]; // used to read text from the file; the size is a guess

    char *read_result, *current_line;
    int num_lines, random_index;
    char **line_list;

    file_ptr = fopen(FILENAME, "r"); // open the file for reading
    if (file_ptr == NULL)
    { // check if the file was opened successfully
        fprintf(stderr, "Unable to open file %s\n", FILENAME);
        exit(1);
    }

    // allocate memory for the line list
    line_list = (char **)malloc(sizeof(char *) * 100);
    if (line_list == NULL)
    {
        fprintf(stderr, "Unable to allocate memory \n");
        exit(1);
    }

    // read lines from the file and store them in memory
    num_lines = 0;
    while (!feof(file_ptr))
    {
        read_result = fgets(buffer, BUFFER_SIZE, file_ptr);               // read a line from the file
        current_line = (char *)malloc(sizeof(char) * strlen(buffer) + 1); // allocate memory for the line
        if (read_result == NULL)
        {
            fprintf(stderr, "Unable to allocate memory\n");
            break;
        }
        strcpy(current_line, buffer);            // copy the line from the buffer to the line
        *(line_list + num_lines) = current_line; // store the line in the line list
        num_lines++;
    }

    // if the number of lines is a multiple of 100, reallocate memory for the line list
    if (num_lines % 100 == 0)
    {
        line_list = (char **)realloc(line_list, sizeof(char *) * (num_lines + 100));
        if (line_list == NULL)
        {
            fprintf(stderr, "Unable to reallocate memory\n");
            exit(1);
        }
    }

    fclose(file_ptr); // close the file

    // print all lines from the line list to the console
    // for (int i = 0; i < num_lines; i++) {
    // printf("%s", *(line_list + i));
    //}
    time(&now);
    clock = localtime(&now);
    hour = clock->tm_hour; // to use this in all the script ;)

    printf("Good ");

    if (hour < 12)
        printf("morning"); // before noon say goood morning
    else if (hour < 17)
        printf("afternoon"); // from nnoon to 5pm good afternoon
    else
        printf("evening"); // otherwise evening

     // U must fill a localtime() tm struct to make the strftime() function work
    strftime(time_string, 64, "Today is %A, %B %d, %Y%nIt is %r%n", clock);
    printf("!\n%s", time_string);
    // generate a random index and print the corresponding line to the console
    srand((unsigned)time(NULL));
    random_index = rand() % (num_lines - 1);
    printf("Rembember: \n");
    printf("%s", *(line_list + random_index));

    // free memory allocated for the line list
    // for (int i = 0; i < num_lines; i++) {
    // free(*(line_list + i)); // free memory allocated for the line
    //}
    // free(line_list); // free memory allocated for the line list
    return (0);
}