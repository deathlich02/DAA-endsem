#include<stdio.h>
#include<string.h>

#define max 256

void shift_table(char pattern[],int st[])
{
    int m = strlen(pattern);
    int i;

    for(i = 0;i < max;i++)
        st[i] = m;
    for(i = 0;i < m-1;i++)
    {
        st[(int)pattern[i]] = m - i - 1;
    }
}

int horspool(char pattern[],char text[])
{
    int m = strlen(pattern);
    int n = strlen(text);
    int st[max];
    shift_table(pattern,st);

    int i = m-1;
    while(i < n)
    {
        int j = 0;
        while(j < m && pattern[m - j - 1] == text[i - j])
            j++;
        if(j == m)
            return i - m + 1;
        i += st[(int)text[i]];
    }
    return -1;
}

void main()
{
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    char pattern[] = "sit";
    
    int matchIndex = horspool(pattern, text);

    if (matchIndex != -1)
        printf("Pattern found at index: %d\n", matchIndex);
    else
        printf("Pattern not found.\n");

}
