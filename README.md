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
# UI file

Create a frame :

Template :
```
frame
{
    type : <t_frame_type>           // ui_frame.h
    resize_type : <t_resize_type>   // ui_button.h
    ratio : x.f y.f w.f h.h         // ratio for responsive interface 0 <= n <= 1
    data
    {
        // depending on the frame's type
    }
}
```
UI_FRAME_SIMPLE :
```
data
{
    texture : <path> // texture path
}
```

Create a button :

Frames contains buttons. Buttons can't be creating without frame.

Template:
```
button
{
    id : <str>
    type : <t_button_type>                      // ui_button.h
    resize_type : <t_resize_type>               // ui_button.h
    ratio : x.f y.f w.f h.h                     // ratio for responsive interface 0 <= n <= 1
    data
    {
        // depending on the button's type
    }
}
```
UI_BUTTON_SIMPLE :
```
data
{
    text : <str>                            // button's text (optional)
    texture_normal : <path>                 // texture path
    texture_clicked : <path>                // texture path
    texture_on_mouse : <path>               // texture path
    clicked_condition : <t_mouse_button>    // ui_event.h
}
```
UI_BUTTON_TEXT_ENTRY :
```
data
{
    name : <str>                    // button name (optional)
    text : <str>                    // starting text (optional)
    max_text_size : <int>           // max str's len
    min_int : <int>                 // min if digital value
    max_int : <int>                 // max if digital value
    name_side_texture : <path>      // texture path
    normal_box_texture : <path>     // texture path
    writting_box_texture : <path>   // texture path
    text_side : <t_text_align>      // ui_texture.h
    text_type : <t_text_type>       // ui_button.h
}
```
UI_BUTTON_TEXT_AREA :
```
data
{
    text : <str>                            // text
    resize_text : UI_RESIZE_TEXT_LINEAR     // resizing type
    text_height : <int>                     // if UI_RESIZE_TEXT_LINE 0 <= <int> <= 1 else use an absolute height.
    text_align : <t_text_align>             // ui_texture.h
    text_color : <int> <int> <int> <int>    // R G B A
}
```

Interface example
```
frame
{
    type : UI_FRAME_SIMPLE
    resize_type : UI_RESIZE_ALL_LINEAR
    ratio : 0.025 0.025 0.95 0.95
    data
    {
        texture : "textures/ui_frame.png"
    }
    button
    {
        id : "id_button"
        type : UI_BUTTON_SIMPLE
        resize_type : UI_RESIZE_ALL_LINEAR
        ratio : 0.35 0.6 0.3 0.1
        data
        {
            text : "text"
            texture_normal : "textures/ui_normal_button.png"
            texture_clicked : "textures/ui_clicked_button.png"
            texture_on_mouse : "textures/ui_on_mouse_button.png"
            clicked_condition : UI_MOUSE_LEFT
        }
    }
    button
    {
        id : "text_area"
        type : UI_BUTTON_TEXT_AREA
        resize_type : UI_RESIZE_ALL_LINEAR
        ratio : 0 0.1 1 0.15
        data
        {
            text : "LIBUI"
            resize_text : UI_RESIZE_TEXT_LINEAR
            text_height : 1
            text_align : TEXT_ALIGN_CENTER
            text_color : 255 255 255 255
        }
    }
    button
    {
        id : "button3"
        type : UI_BUTTON_TEXT_ENTRY
        resize_type : UI_RESIZE_ALL_LINEAR
        ratio : 0.35 0.45 0.3 0.1
        data
        {
            name : "puet"
            text : ""
            max_text_size : 20
            min_int : 0
            max_int : 9000
            name_side_texture : "textures/ui_text_entry_button_normal.png"
            normal_box_texture : "textures/ui_text_entry_button_normal.png"
            writting_box_texture : "textures/ui_text_entry_button_writting.png"
            text_side : UI_TEXT_SIDE_LEFT
            text_type : UI_TEXT_TYPE_NONE
        }
    }
```
Result :
![Simple UI Example](https://zupimages.net/up/20/06/vcq3.png)
