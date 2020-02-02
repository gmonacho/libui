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
# Txt file

Create a frame :

Template :
```
frame
{
    type : <t_frame_type> // ui_frame.h
    resize_type : <t_resize_type> // ui_button.h
    ratio : x.f y.f w.f h.h // ratio for responsive interface 0 <= n <= 1
    data
    {
        texture : <str> // texture path
    }
}
```

Example :
```
frame
{
    type : UI_FRAME_SIMPLE
    resize_type : UI_RESIZE_ALL_LINEAR
    ratio : 0.1 0.1 0.5 0.8
    data
    {
        texture : "textures/ui_frame.png"
    }
}
```
