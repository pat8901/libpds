#include <queue.h>
#include <stdlib.h>
#include <stdio.h>

queue_t *qinit(int max_size, size_t item_size)
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->data = malloc(item_size * max_size);
    queue->max_size = max_size;
    queue->current_size = 0;
    queue->item_size = item_size;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

void qprint(queue_t *queue)
{
    if (queue == NULL || queue->current_size == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = 0; i < queue->max_size; i++)
        {
            int value = queue->data;
        }
    }
}

int qadd(queue_t *queue, void *item)
{
    if (queue->current_size == queue->max_size)
    {
        printf("Queue is full\n");
        return -1;
    }
    else if (queue->current_size == 0)
    {
        void *target = (char *)queue->data + (queue->rear * queue->item_size);
        printf("Queue is empty\n");
        memcpy(target, item, queue->item_size);
        queue->current_size += 1;
    }
    else
    {
        printf("Queue is not empty\n");
        queue->rear = (queue->rear += 1) % queue->max_size;
        void *target = (char *)queue->data + (queue->rear * queue->item_size);
        memcpy(target, item, queue->item_size);
        queue->current_size += 1;
    }
    return 0;
}

void *qremove(queue_t *queue)
{
    if (queue->current_size == 0)
    {
        printf("Queue is empty\n");
        return NULL;
    }

    void *target = (char *)queue->data + (queue->front * queue->item_size);
    if (queue->current_size == 1)
    {
        printf("Queue has only 1 item\n");
        queue->current_size--;
        queue->front = 0;
        queue->rear = 0;
        return target;
    }
    printf("Queue has more than 1 item\n");
    queue->current_size--;
    queue->front = (queue->front += 1) % queue->max_size;
    return target;
}

int queue_init(CircularQueue *queue, uint32_t size)
{
    queue->size = size;
    printf("size: %d\n", size);
    queue->capacity = 0;
    queue->array = malloc(sizeof(uint32_t) * size);
    return 0;
}

int queue_enqueue(CircularQueue *queue, int value)
{
    if (queue->capacity == queue->size)
    {
        printf("Queue is full\n");
        return -1;
    }
    // queue is empty
    if (queue->capacity == 0)
    {
        printf("Queue is empty: adding (%d)\n", value);
        queue->head = 0;
        queue->tail = 0;
        queue->array[queue->tail] = value;
        queue->capacity++;
    }
    else
    {
        printf("Queue not empty: adding (%d)\n", value);
        queue->tail = (queue->tail += 1) % queue->size;
        queue->array[queue->tail] = value;
        queue->capacity++;
        printf("New Capacity: %d\n", queue->capacity);
    }
    return 0;
}

int queue_dequeue(CircularQueue *queue)
{
    if (queue->capacity == 0)
    {
        printf("Queue is empty! Cannot dequeue\n");
        return 0;
    }
    if (queue->head == queue->tail)
    {
        printf("One item found: (%d)\n", queue->array[queue->head]);
        int return_value = queue->array[queue->head];
        queue->head = 0;
        queue->tail = 0;
        queue->capacity = 0;
        return return_value;
    }
    int return_value = queue->array[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    queue->capacity--;
    printf("Dequeued (%d)\n", return_value);
    return return_value;
}

int queue_clear(CircularQueue *queue)
{
    if (queue_is_empty(queue))
    {
        printf("Can not clear, queue is already empty\n");
        return 1;
    }

    queue->capacity = 0;
    queue->head = 0;
    queue->tail = 0;

    return 0;
}

void queue_print(CircularQueue *queue)
{
    for (int i = 0; i < queue->size; i++)
    {
        if (queue->head == i && queue->tail == i)
        {
            printf("%d: value=%d (head)(tail)\n", i, queue->array[i]);
        }
        else if (queue->head == i)
        {
            printf("%d: value=%d (head)\n", i, queue->array[i]);
        }
        else if (queue->tail == i)
        {
            printf("%d: value=%d (tail)\n", i, queue->array[i]);
        }
        else
        {
            printf("%d: value=%d\n", i, queue->array[i]);
        }
    }
}

int queue_peek(CircularQueue *queue)
{
    if (queue->capacity == 0)
    {
        printf("Peek: queue is empty!\n");
        return 1;
    }
    int value = queue->array[queue->head];
    printf("Peek: %d\n", value);
    return value;
}

int queue_is_empty(CircularQueue *queue)
{
    if (queue->capacity == 0)
    {
        return 1;
    }
    return 0;
}