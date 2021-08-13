# 可更改宏

```
#define TICKS_INTERVAL 10
```

按键扫描的延时毫秒数

```c
#define BUTTON_SHORT_COUNT_MIN 2
```

短按的触发最小毫秒数(value = BUTTON_SHORT_COUNT_MIN * TICKS_INTERVAL)

```c
#define BUTTON_LONG_COUNT_MIN 20
```

长按的触发最小毫秒数(value = BUTTON_LONG_COUNT_MIN * TICKS_INTERVAL)

```c
#define BUTTON_KEEP_PSC_COUNT 10
```

连按的触发毫秒数的分频(连按启动后 value 毫秒触发)(value = TICKS_INTERVAL * BUTTON_KEEP_PSC_COUNT)

```c
#define BUTTON_KEEP_COUNT_MIN 100
```

连按的启动最小毫秒数(value = BUTTON_KEEP_COUNT_MIN * TICKS_INTERVAL)

```c
#define BUTTON_KEEP_COUNT_MAX 200
```

最大值255

