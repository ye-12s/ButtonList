# 特性

自定义的数据类型

```c
typedef level_t (*buttonLevel_TypeDef)(void);
typedef void (*buttonCallBackEvent_TypeDef)(ButtonPressEvent);
typedef uint8_t level_t;
```

使用C语言编写，基于面向对象（OOP）思想，每一个按键都是一份单独的数据结构管理。

```c
typedef enum {
    pressEvent_up = 0u,
    pressEvent_down,
    pressEvent_short,
    pressEvent_long,
    pressEvent_keep
}ButtonPressEvent;
typedef struct Button {
    uint8_t count;
    level_t activeLevel;
    buttonLevel_TypeDef buttonLevel;
    buttonCallBackEvent_TypeDef buttonCallBackEvent;
    struct Button *next;
}Button;
```

这样每个按键单独存在使用链表相连，各自进入自己的Callback Event事件，并使用枚举类型进行事件的回调。所以每个按键的状态都是独自存在的。

