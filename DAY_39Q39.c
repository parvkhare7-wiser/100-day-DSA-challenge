/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Deque {
    int arr[MAX];
    int front;
    int rear;
    int size;
};
void initDeque(struct Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}
void push_front(struct Deque* dq, int value) {
    if (dq->size == MAX) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = value;
    dq->size++;
}
void push_back(struct Deque* dq, int value) {
    if (dq->size == MAX) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq->rear == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = value;
    dq->size++;
}
void pop_front(struct Deque* dq) {
    if (dq->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
    dq->size--;
}
void pop_back(struct Deque* dq) {
    if (dq->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    dq->size--;
}
void front(struct Deque* dq) {
    if (dq->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq->arr[dq->front]);
}

void back(struct Deque* dq) {
    if (dq->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq->arr[dq->rear]);
}

void empty(struct Deque* dq) {
    printf("%d\n", dq->size == 0);
}


void size(struct Deque* dq) {
    printf("%d\n", dq->size);
}
int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);
    struct Deque dq;
    initDeque(&dq);
    for (int i = 0; i < n; i++) {
        char operation[20];
        int value;
        scanf("%s", operation);
        if (strcmp(operation, "push_front") == 0) {
            scanf("%d", &value);
            push_front(&dq, value);
        } else if (strcmp(operation, "push_back") == 0) {
            scanf("%d", &value);
            push_back(&dq, value);
        } else if (strcmp(operation, "pop_front") == 0) {
            pop_front(&dq);
        } else if (strcmp(operation, "pop_back") == 0) {
            pop_back(&dq);
        } else if (strcmp(operation, "front") == 0) {
            front(&dq);
        } else if (strcmp(operation, "back") == 0) {
            back(&dq);
        } else if (strcmp(operation, "empty") == 0) {
            empty(&dq);
        } else if (strcmp(operation, "size") == 0) {
            size(&dq);
        }
    }
    return 0;
}
