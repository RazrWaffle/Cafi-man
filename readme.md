# 🍔 College Cafeteria Order Management System

A simple, command-line based C program to manage cafeteria orders using fundamental data structures. This project was developed for the **CSS2281 Problem Based Learning Activity**.

## 📌 Project Overview
This system simulates the workflow of a college cafeteria, handling orders from the moment a student places them to the moment they are picked up. It utilizes two core data structures to manage the flow of orders efficiently:

*   **Queue (Pending Orders):** Implements a **First-In-First-Out (FIFO)** approach. When students place an order, they join the back of the queue. The kitchen always prepares the oldest pending order first.
*   **Stack (Ready for Pickup):** Implements a **Last-In-First-Out (LIFO)** approach. Once the kitchen finishes preparing an order, it is placed on the pickup counter (the stack). The staff hands over the most recently completed orders sitting on top of the counter.

## 🚀 Features
*   **Place New Order:** Adds a student's order to the pending queue.
*   **Prepare Next Order:** Moves the oldest order from the pending queue to the ready stack.
*   **Dispatch Ready Order:** Hands over the most recently prepared food item to the student.
*   **View Pending Orders:** Displays all orders currently waiting to be prepared.
*   **View Orders Ready for Pickup:** Displays all prepared orders sitting on the counter.

## 🛠️ How to Compile and Run

### Prerequisites
You will need a C compiler (like `gcc`) installed on your system. 

### Compilation
Open your terminal or command prompt, navigate to the project folder, and run:
```bash
gcc cafeteria_management.c -o cafeteria_management
```

### Execution
*   **On Windows:**
    ```bash
    cafeteria_management.exe
    ```
*   **On Linux / macOS:**
    ```bash
    ./cafeteria_management
    ```

## 👥 Group Details
*Please update this section before submitting the link!*
*   **Group Member 1:** [Name] - [Register Number]
*   **Group Member 2:** [Name] - [Register Number]
*   **Group Member 3:** [Name] - [Register Number]
*   **Group Member 4:** [Name] - [Register Number]
*   **Group Member 5:** [Name] - [Register Number]