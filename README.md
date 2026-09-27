# Inventory with a Circular Doubly Linked List

A small **C++ data-structures exercise**: a command-line inventory built on a hand-written **circular doubly linked list**, with manual memory management.

## Features

- Each node stores an item's **name, quantity and unit price**, plus `next` and `prev` pointers. The last node links back to the first, and the first back to the last.
- **Adding an existing item merges it:** the quantity is increased and the **lower price is kept**, instead of creating a duplicate node.
- **Traversal in both directions** (forward and reverse), which is the main advantage of a doubly linked list.

## Commands

```
add <name> <quantity> <price>   add an item, or merge it into an existing one
print                           print the unit prices, forwards and then backwards
exit                            quit
```

## Built with

C++ · Visual Studio
