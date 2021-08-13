# 函数接口

Button List共开放4个接口供用户使用

```c
void buttonInit();
void buttonConfig(Button*, buttonCallBackEvent_TypeDef,buttonLevel_TypeDef, level_t);
void buttonTicks();
void addButton(Button *);
```

- buttonInit负责初始化

- buttonConfig负责配置按键

- buttonTicks负责驱动按键

- addButton负责添加按键

  

  <font color = "red">注：addButton函数内会申请堆内存，所以使用使用malloc申请的内存在调用此函数后手动释放，以免内存泄漏</font>