#include <stdlib.h>
#include <stdio.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s)
{
    int i;
    printf("Enter dimensions: ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter no of non-zero elements: ");
    scanf("%d", &s->num);

    s->ele = malloc(sizeof(struct Element) * s->num);
    printf("Enter all non-zero elements [row][col][value]: ");
    for (i = 0; i < s->num; i++)
    {
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    };
};

void display(struct Sparse s)
{
    int i,
        j,
        k = 0;

    // 0-based: i = 0, i < s.m — enter coordinates starting from 0 (e.g. 0 0 5)
    // 1-based: i = 1, i <= s.m — enter coordinates starting from 1 (e.g. 1 1 5)
    for (i = 1; i <= s.m; i++)
    {
        for (j = 1; j <= s.n; j++)
        {
            if (k < s.num && i == s.ele[k].i && j == s.ele[k].j)
            {
                printf("%d ", s.ele[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
};

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;

    if (s1->m != s2->m || s1->n != s2->n)
    {
        return NULL;
    }

    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    int sumNum = s1->num + s2->num;
    sum->ele = malloc(sizeof(struct Element) * sumNum);

    sum->m = s1->m;
    sum->n = s1->n;

    int i = 0, j = 0, k = 0;

    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
        {
            sum->ele[k++] = s1->ele[i++];
        }
        else if (s1->ele[i].i > s2->ele[j].i)
        {
            sum->ele[k++] = s2->ele[j++];
        }
        else
        {
            if (s1->ele[i].j < s2->ele[j].j)
            {
                sum->ele[k++] = s1->ele[i++];
            }
            else if (s1->ele[i].j > s2->ele[j].j)
            {
                sum->ele[k++] = s2->ele[j++];
            }
            else
            {
                sum->ele[k] = s1->ele[i++];
                sum->ele[k++].x += s2->ele[j++].x;
            }
        }
    };
    for (; i < s1->num; i++)
    {
        sum->ele[k++] = s1->ele[i];
    }
    for (; j < s2->num; j++)
    {
        sum->ele[k++] = s2->ele[j];
    }

    sum->num = k;

    return sum;
}

int main(void)
{
    struct Sparse s1, s2, *sum;

    create(&s1);
    display(s1);
    create(&s2);
    display(s2);

    sum = add(&s1, &s2);
    printf("\n<<<<<<<<<<>>>>>>>>>>\n");
    display(*sum);

    return 0;
}