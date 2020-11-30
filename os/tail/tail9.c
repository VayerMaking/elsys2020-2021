int file = open(filename, O_RDONLY);
    if (file < 0)
    {
        char error[] = "tail: cannot open for reading '";
        strcat(error, filename);
        strcat(error, "' for reading");
        perror(error);
        return;
    }
    char buffer[BUFFER_SIZE + 1] = {0};
    int symbols = read(file, buffer, BUFFER_SIZE);
    int counter = 0;
    if (symbols > 0)
    {
        int position = symbols;
        while (position > 0)
        {
            if (buffer[position] == '\n')
            {
                counter++;
            }
            if (counter == 10)
            {
                break;
            }
            position--;
        }
        int temp = 0;
        if (position != 0)
        {
            temp = position + 1;
        }
        //printf("%d, %d, %d\n", position, lseek(file,position,SEEK_SET),symbols); //just to check
        char result[BUFFER_SIZE] = {0};
        for (int i = 0; i < BUFFER_SIZE - position - 1; i++)
        {
            result[i] = buffer[temp + i];
        }
        write(1, &result, BUFFER_SIZE);
    }
    else
    {
        char error[] = "tail: error reading '";
        strcat(error, filename);
        strcat(error, "'");
        errno = 21;
        perror(error);
    }
    if (close(file) < 0)
    {
        char error[] = "tail: error reading '";
        strcat(error, filename);
        strcat(error, "'");
        errno = 5;
        perror(error);
    }
    write(1, "\n", 1);
