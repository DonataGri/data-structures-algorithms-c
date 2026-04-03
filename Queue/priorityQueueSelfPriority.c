#include <stdio.h>
#include <stdlib.h>

#define PRIORITIES 3
#define SIZE 5

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *queues, int size)
{
    for (int i = 0; i < PRIORITIES; i++)
    {
        queues[i].size = size;
        queues[i].front = queues[i].rear = -1;
        queues[i].Q = (int *)malloc(size * sizeof(int));
    }
}

void enqueue(struct Queue *q, int priority, int x)
{

    if (q[priority].rear == q[priority].size - 1)
    {
        printf("Queue is full");
    }
    else
    {
        q[priority].rear++;
        q[priority].Q[q[priority].rear] = x;
    }
};

int dequeue(struct Queue *q)
{
    int x = -1;
    int i = 0;

    for (i = 0; i < PRIORITIES; i++)
    {
        if (q[i].rear != q[i].front)
        {
            break;
        }
    }

    if (i == PRIORITIES)
    {
        printf("Queue is empty\n");
        return x;
    }

    q[i].front++;
    x = q[i].Q[q[i].front];

    return x;
};

void display(struct Queue *q)
{
    int i, j;
    for (i = 0; i < PRIORITIES; i++)
    {
        printf("Priority: %d \n", i);
        for (j = q[i].front + 1; j <= q[i].rear; j++)
        {
            printf("%d ", q[i].Q[j]);
        }
        printf("\n");
    }
}

int main(void)
{
    struct Queue queues[PRIORITIES];
    create(queues, SIZE);
    enqueue(queues, 0, 6);
    enqueue(queues, 0, 11);
    enqueue(queues, 1, 10);
    enqueue(queues, 2, 36);

    display(queues);
    printf("////////////////////\n");
    printf("%d ", dequeue(queues));
    printf("%d ", dequeue(queues));
    printf("%d ", dequeue(queues));
    printf("\n////////////////////\n");
    display(queues);
    enqueue(queues, 1, 9);
    display(queues);

    for (int i = 0; i < PRIORITIES; i++)
    {
        free(queues[i].Q);
    }

    return 0;
};