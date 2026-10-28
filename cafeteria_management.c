#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 100

// Structure to define an Order
typedef struct {
    int orderId;
    char studentName[50];
    char foodItem[50];
} Order;

// Queue structure for Pending Orders
typedef struct {
    Order queueData[MAX_ORDERS];
    int front;
    int rear;
} PendingQueue;

// Stack structure for Completed/Ready Orders
typedef struct {
    Order stackData[MAX_ORDERS];
    int top;
} ReadyStack;

// Initialize the data structures
void initQueue(PendingQueue *q) {
    q->front = -1;
    q->rear = -1;
}

void initStack(ReadyStack *s) {
    s->top = -1;
}

// Check if Queue is empty
int isQueueEmpty(PendingQueue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Check if Stack is empty
int isStackEmpty(ReadyStack *s) {
    return (s->top == -1);
}

// Queue Operation: Add a new order to the pending queue
void placeOrder(PendingQueue *q, Order newOrder) {
    if (q->rear == MAX_ORDERS - 1) {
        printf("\n[!] The cafeteria queue is full. Cannot accept more orders right now.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->queueData[q->rear] = newOrder;
    printf("\n[SUCCESS] Order #%d for %s (%s) added to the pending queue.\n", 
           newOrder.orderId, newOrder.studentName, newOrder.foodItem);
}

// Queue to Stack Operation: Kitchen processes order from Queue and moves to Stack
void prepareNextOrder(PendingQueue *q, ReadyStack *s) {
    if (isQueueEmpty(q)) {
        printf("\n[!] No pending orders in the queue to prepare.\n");
        return;
    }
    
    // Dequeue from pending
    Order preparedOrder = q->queueData[q->front];
    q->front++;
    
    // Reset queue pointers if all items are processed
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    
    // Push to ready stack
    if (s->top == MAX_ORDERS - 1) {
        printf("\n[!] Pickup counter is completely full! Cannot place more ready orders.\n");
        return;
    }
    s->top++;
    s->stackData[s->top] = preparedOrder;
    
    printf("\n[KITCHEN] Order #%d (%s) is prepared and pushed to the pickup counter.\n", 
           preparedOrder.orderId, preparedOrder.foodItem);
}

// Stack Operation: Hand over the most recently prepared order to the student
void dispatchReadyOrder(ReadyStack *s) {
    if (isStackEmpty(s)) {
        printf("\n[!] No ready orders on the pickup counter.\n");
        return;
    }
    
    Order dispatch = s->stackData[s->top];
    s->top--;
    
    printf("\n[DISPATCH] Handed over Order #%d (%s) to %s.\n", 
           dispatch.orderId, dispatch.foodItem, dispatch.studentName);
}

// Display Pending Queue
void displayPendingOrders(PendingQueue *q) {
    if (isQueueEmpty(q)) {
        printf("\n--- Pending Orders ---\nNo pending orders.\n");
        return;
    }
    printf("\n--- Pending Orders (Queue) ---\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("Order #%d | Student: %s | Item: %s\n", 
               q->queueData[i].orderId, q->queueData[i].studentName, q->queueData[i].foodItem);
    }
}

// Display Ready Stack
void displayReadyOrders(ReadyStack *s) {
    if (isStackEmpty(s)) {
        printf("\n--- Ready for Pickup ---\nNo items currently on the counter.\n");
        return;
    }
    printf("\n--- Ready for Pickup (Stack) ---\n");
    for (int i = s->top; i >= 0; i--) {
        printf("Order #%d | Student: %s | Item: %s\n", 
               s->stackData[i].orderId, s->stackData[i].studentName, s->stackData[i].foodItem);
    }
}

int main() {
    PendingQueue q;
    ReadyStack s;
    initQueue(&q);
    initStack(&s);
    
    int choice;
    int orderCounter = 1001; // Auto-generating order IDs
    
    while (1) {
        printf("\n==========================================\n");
        printf("   College Cafeteria Order Management\n");
        printf("==========================================\n");
        printf("1. Place New Order (Enqueue)\n");
        printf("2. Prepare Next Order (Dequeue -> Push)\n");
        printf("3. Dispatch Ready Order (Pop)\n");
        printf("4. View Pending Orders\n");
        printf("5. View Orders Ready for Pickup\n");
        printf("6. Exit / Shutdown System\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                Order newOrder;
                newOrder.orderId = orderCounter++;
                printf("Enter Student Name: ");
                scanf(" %[^\n]", newOrder.studentName); // Reads string with spaces
                printf("Enter Food Item: ");
                scanf(" %[^\n]", newOrder.foodItem);
                placeOrder(&q, newOrder);
                break;
            }
            case 2:
                prepareNextOrder(&q, &s);
                break;
            case 3:
                dispatchReadyOrder(&s);
                break;
            case 4:
                displayPendingOrders(&q);
                break;
            case 5:
                displayReadyOrders(&s);
                break;
            case 6:
                printf("\nShutting down the cafeteria system. Goodbye!\n");
                exit(0);
            default:
                printf("\n[!] Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
