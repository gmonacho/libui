# libui (in development)

## Description

Libui is a functionnal C interface library based on SDL2 respecting the 42 norm.

**It provides to :**
* **create and manage window and renderer.**
* **create an responsive interface using .txt(see examples, json coming soon).**
* **create different types of button with many options**
* **assign functions to buttons**
---
## How to use libui

Create your interface without coding and load it using the ```ui_load``` function :

```C
int ui_load(const char *path, t_winui *win);
```
