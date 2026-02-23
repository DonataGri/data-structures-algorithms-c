#include <stdio.h>
#include <stdlib.h>

int stringLength(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
    }
    return i;
}

void toUpperCase(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] - 32;
    }
}

void toggleString(char str[])
{
    int k;
    for (k = 0; str[k] != '\0'; k++)
    {
        if (str[k] >= 65 && str[k] <= 90)
        {
            str[k] += 32;
        }
        else if (str[k] >= 90 && str[k] <= 122)
        {
            str[k] -= 32;
        }
    }
}

// count start of each word: Non-space character comes after space.
void countWords(char str[])
{
    int i, words = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
        {
            words++;
        }
    }
    printf("Counted words %d\n", words);
}

void reverseString(char str[])
{
    char t;
    int i, j;
    for (j = 0; str[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

void compareString(char str1[], char str2[])
{
    int i;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            break;
        }
    }
    if (str1[i] == str2[i])
    {
        printf("Equal\n");
    }
    else if (str1[i] < str2[i])
    {
        printf("Smaller\n");
    }
    else
    {
        printf("Greater\n");
    }
}

int isPalindrome(char str[])
{
    int i, j;
    for (j = 0; str[j] != '\0'; j++)
    {
    }

    for (i = 0, j = j - 1; i <= j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
    }
    return 1;
}

// O(n*n)
void findDuplicatesCompare(char str[])
{
    int i, j, k;

    for (i = 0; str[i] != '\0'; i++)
    {
        // Skip if this character appeared before position i
        for (k = 0; k < i; k++)
        {
            if (str[k] == str[i])
                break;
        }
        // skip to next interation
        if (k < i)
            continue;

        // Check if any duplicates after position i
        for (j = i + 1; str[j] != '\0'; j++)
        {
            if (str[i] == str[j])
            {
                printf("Duplicate for letter: %c\n", str[i]);
                break;
            }
        }
    }
}

void findDuplicatesHashTable(char str[])
{
    // 97 - 122
    // 0  -  26
    int lowerCaseRange = 26;

    int H[26] = {0};
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        H[str[i] - 97] += 1;
    }

    for (i = 0; i < lowerCaseRange; i++)
    {
        if (H[i] > 1)
        {
            printf("Duplicate char/time: %c/%d\n", i + 97, H[i]);
        }
    }
}

void findDuplicatesBitwise(char str[])
{

    long int H = 0, x = 0, printed = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        x = 1L;
        x = x << (str[i] - 97);
        if ((H & x) > 0)
        {
            if ((printed & x) == 0)
            {
                printf("Duplicated %c \n", str[i]);
                printed = printed | x;
            }
        }
        else
        {
            H = H | x;
        }
    }
}

void isAnagram(char str1[], char str2[])
{
    int i, H[26] = {0};
    for (i = 0; str1[i] != '\0'; i++)
    {
        H[str1[i] - 97] += 1;
    }

    for (i = 0; str2[i] != '\0'; i++)
    {
        H[str2[i] - 97] -= 1;
        if (H[str2[i] - 97] < 0)
        {
            printf("Not an anagram\n");
            break;
        }
    }

    if (str2[i] == '\0')
    {
        printf("It's an anagram\n");
    }
}

void countVowelsAndConsonants(char str[])
{
    int i, vcount = 0, ccount = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            vcount++;
        }
        else if ((str[i] >= 65 && str[i] < 90) || (str[i] >= 97 && str[i] <= 122))
        {
            ccount++;
        }
    }
    printf("Vowels count %d\n", vcount);
    printf("Consonants count %d\n", ccount);
}

// O(n*n!)
void perm(char str[], int k)
{

    static int A[10] = {0};
    static char Res[10];
    int i;

    if (str[k] == '\0')
    {
        Res[k] = '\0';
        printf("Result: %s\n", Res);
    }
    else
    {
        for (i = 0; str[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = str[i];
                A[i] = 1;         // Mark as used
                perm(str, k + 1); // Recurse (uses same static A and Res)
                A[i] = 0;         // Unmark (backtrack)
            }
        }
    }
}

void swap(char *ch1, char *ch2)
{
    char temp;
    temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void permSwap(char str[], int low, int high)
{
    int i;
    if (low == high)
    {
        printf("Result: %s\n", str);
    }
    else
    {
        for (i = low; i <= high; i++)
        {
            swap(&str[low], &str[i]);
            permSwap(str, low + 1, high);
            swap(&str[low], &str[i]);
        }
    }
}

int main(void)
{
    char ch1[5];
    char ch2[5] = {'A', 'B', 'C', 'D', 'F'};
    char ch3[5] = {'A', 'B', 'C', 'D', 'F'};
    char ch4[] = {65, 66, 67, 68, 69};
    char ch5[5] = {'A', 'B'};

    char name[10] = {'J', 'o', 'h', 'n'};

    printf("%s\n", ch4);

    char s[] = "welcome";
    printf("String length:  %d\n", stringLength(s));
    toUpperCase(s);
    printf("String upper case:  %s\n", s);

    char s2[] = "WeLCOme";
    toggleString(s2);
    printf("Toggle string %s \n", s2);

    countVowelsAndConsonants(s);
    char word[] = "How are you?";
    char empty[] = "";
    countWords(word);
    countWords(empty);

    reverseString(s);
    printf("Reversed string %s \n", s);

    compareString("Painter", "Painting");

    printf("Is palindrome: %d\n", isPalindrome("abba"));
    printf("Is palindrome: %d\n", isPalindrome("madam"));
    printf("Is palindrome: %d\n", isPalindrome("maddamm"));
    findDuplicatesCompare("abbaa");
    findDuplicatesCompare("finding");
    findDuplicatesHashTable("abbaa");
    findDuplicatesHashTable("finding");
    findDuplicatesBitwise("abbaa");
    findDuplicatesBitwise("finding");
    isAnagram("decimal", "medical");
    isAnagram("verbose", "observee");
    perm("ABC", 0);
    printf("<<<<<<<<<<<>>>>>>>>>>\n");
    char abc[] = "ABC";
    permSwap(abc, 0, 2);

    return 0;
}