#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *s;
};

void push(struct Stack *st, char x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow \n");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

char pop(struct Stack *st)
{
    char x = -1;
    if (st->top == -1)
    {
        printf("Stack underflow \n");
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}

int isBalance(char *exp)
{
    struct Stack st;
    int i;
    st.size = strlen(exp);
    st.top = -1;
    st.s = (char *)malloc(sizeof(char) * st.size);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(&st, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(st))
            {
                return 0;
            }
            pop(&st);
        }
    }
    int result = isEmpty(st) ? 1 : 0;
    free(st.s);
    return result;
}

int main(void)
{
    char *exp = "((a+b))*(c-d)";
    printf("%d ", isBalance(exp));

    char *exp2 = "((a+b))*(c-d))";
    printf("%d ", isBalance(exp2));

    return 0;
};