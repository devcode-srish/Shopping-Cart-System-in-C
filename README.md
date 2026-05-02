# 🛒 Shopping Cart System in C

A console-based Shopping Cart System built using **C programming**, demonstrating core concepts like **linked lists, dynamic memory allocation, and modular design**.

---

## 📌 Overview

This project simulates a basic e-commerce system where users can:

- Browse inventory
- Add/remove items from cart
- Manage stock dynamically
- View real-time billing

It focuses on **low-level memory management and data structures**, making it ideal for mastering C fundamentals.

---

## ⚙️ Features

### 📦 Inventory Management
- Add new products
- Remove products
- Display product list (ID, Name, Price, Quantity)

### 🛒 Shopping Cart
- Add items with stock validation
- Remove items (auto-restock)
- Update quantities
- View cart summary with total cost

### 🔄 Real-Time Updates
- Prevents overselling
- Maintains consistency between inventory and cart

---

## 🧠 Concepts Used

- Structures (`struct`)
- Pointers
- Dynamic Memory Allocation (`malloc`, `free`)
- Singly Linked Lists
- Modular Programming

---

## 🏗️ System Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Display Menu]
    B --> C{User Choice}

    C -->|View Inventory| D[Display Products]
    C -->|Add Product| E[Insert into Inventory]
    C -->|Remove Product| F[Delete from Inventory]
    C -->|Add to Cart| G[Check Stock]

    G -->|Available| H[Update Cart]
    G -->|Not Available| I[Show Error]

    H --> J[Reduce Inventory Stock]
    C -->|Remove from Cart| K[Update Inventory Stock]

    C -->|View Cart| L[Display Cart + Total]
    C -->|Exit| M[Free Memory]

    M --> N[End]
