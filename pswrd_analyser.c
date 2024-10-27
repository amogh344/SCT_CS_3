#include<stdio.h>
#include<ctype.h>
#include<string.h>
int test_pswrd_str(const char *pswrd)
{
    int score=0;
    int length = strlen(pswrd);
    int has_upper=0;
    int has_lower=0;
    int has_digit=0;
    int has_special=0;
    if(length>=12)
    {
        score+=2;
    }
    for(int i=0;i<length;i++)
    {
        if(isupper(pswrd[i]))
        {
            has_upper=1;
        }
        else if(islower(pswrd[i]))
        {
            has_lower=1;
        }
        else if(isdigit(pswrd[i]))
        {
            has_digit=1;
        }
        else if(strchr("@$!%*?&",pswrd[i]))
        {
            has_special=1;
        }
    }
    score+=has_upper+has_digit+has_lower;
    score+=has_special*2;
    if(score <= 2)
    {
        printf("Password Strength: Weak\n");
    }
    else if(score <= 4)
    {
        printf("Password Strength: Moderate\n");
    }
    else if(score <= 6)
    {
        printf("Password Strength: Strong\n");
    }
    else
    {
        printf("Password Strength: Very Strong\n");
    }
    if(score<=6)
    {
        printf("Suggestions to improve your password:\n");
        if(length<12)
        {
            printf("- Increase the length of to at least 12 characters.\n");
        }
        if(!has_upper)
        {
            printf("- Add at least one uppercase letter.\n");
        }
        if(!has_lower)
        {
            printf("- Add at least one lowercase letter.\n");
        }
        if(!has_digit)
        {
            printf("- Include at least one number.\n");
        }
        if(!has_special)
        {
            printf("- Use at least one special character.\n");
        }
    }
    return score;
}
int main()
{
    char pswrd[100];
    int score;
    while(1)
    {
        printf("Enter a password to assess: ");
        scanf("%99s",pswrd);

        score=test_pswrd_str(pswrd);

        if(score>6)
        {
            printf("Great! You have entered a strong password.\n");
            break;
        }
    }
    return 0;
}