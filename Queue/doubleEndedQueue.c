#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{

    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueueFront(struct Queue *q, int x)
{
    if (q->front == 0)
    {
        printf("Queue is full!");
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->Q[0] = x;
    }
    else
    {
        q->Q[q->front] = x;
        q->front--;
    }
};

void enqueueRear(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full!");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
};

int dequeueFront(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("DEQueue Underflow!");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }

    return x;
};

int dequeueRear(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("DEQueue Underflow");
    }
    else
    {
        x = q->Q[q->rear];
        q->rear--;
    }

    return x;
};

void display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main(void)
{
    struct Queue q;
    create(&q, 5);

    enqueueRear(&q, 10);
    enqueueRear(&q, 20);
    enqueueRear(&q, 30);
    enqueueRear(&q, 40);
    enqueueRear(&q, 50);

    printf("%d \n", dequeueFront(&q));
    printf("%d ", dequeueRear(&q));

    printf("\n");

    display(q);
}