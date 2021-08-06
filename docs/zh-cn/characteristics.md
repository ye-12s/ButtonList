# 特性

使用C语言编写，基于面向对象（OOP）思想，每一个按键都是一份单独的数据结构管理。

```c
typedef struct Button {
    uint8_t id;
    uint8_t count;
    GPIO_PinState PinState;		/*GPIO_PinState是HAL库中定义的数据类型*/
    GPIO_PinState (*buttonLevel)(void);
    void (*workupCallBackEvent)(pressEvent);
    struct Button *next;
}Button;
```

这样每个按键单独存在使用链表相连，各自进入自己的CallBackEvent()事件，所以每个按键的状态都是独自存在的。

GPIO_PinState具体实现如下：

```c
typedef enum
{
  GPIO_PIN_RESET = 0U,
  GPIO_PIN_SET
} GPIO_PinState;
```

