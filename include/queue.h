#ifndef Queue_H
#define Queue_H

#include <stdint.h>
#include <stddef.h>

typedef struct CircularQueue_
{
    uint32_t size;
    uint32_t capacity;
    uint32_t head;
    uint32_t tail;
    int *array;
} CircularQueue;

typedef struct queue_t
{
    void *data;
    size_t item_size;
    int current_size;
    int max_size;
    int front;
    int rear;
} queue_t;

/* Create a circular queue */
int queue_init(CircularQueue *queue, uint32_t size);
int queue_enqueue(CircularQueue *queue, int value);
int queue_dequeue(CircularQueue *queue);
void queue_print(CircularQueue *queue);
int queue_peek(CircularQueue *queue);
int queue_is_empty(CircularQueue *queue);
int queue_clear(CircularQueue *queue);

/* Generic Circular queue implementation */
queue_t *qinit(int size, size_t item_size);
void qprint(queue_t *queue);
int qadd(queue_t *queue, void *item);
void *qremove(queue_t *queue);

#endif