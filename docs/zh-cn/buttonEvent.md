# 按键事件



|       事件       |            说明，触发条件             |
| :--------------: | :-----------------------------------: |
|  pressEvent_up   |        按键被按下后抬起，触发         |
| pressEvent_down  |        按键首次被按下后，触发         |
| pressEvent_short |   按键在被按下两百毫秒内可以，触发    |
| pressEvent_long  | 按键在被按下  两百毫秒 ~ 一秒内，触发 |
| pressEvent_keep  |        按键被按下一秒后，触发         |

## 原型为：

```c
typedef enum {
    pressEvent_up = 0u,
    pressEvent_down,
    pressEvent_short,
    pressEvent_long,
    pressEvent_keep
}ButtonPressEvent;
```

#### 使用时需要编写回调函数

```c
void func(ButtonPressEvent event)
{
        switch (event) {
        case pressEvent_long:
            // do something...
            break;
        case pressEvent_short:
            // do something...
            break;
        case pressEvent_keep:
            // do something...
            break;
        case pressEvent_up:
            // do something...
            break;
        case pressEvent_down:
            // do something...
            break;
        default:
            break;
    }
}
```

