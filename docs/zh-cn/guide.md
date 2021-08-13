

# 使用指南

1. 需要先申请一块按键空间

   ```c 
   Button button;
   ```

2. 初始化头节点按键对象

   ```c
   void buttonInit(void);			/*初始化头节点*/
   ```

3. 为按键添加设置属性、行为

   ```c
   void buttonConfig(Button *pButton, buttonCallBackEvent_TypeDef buttonCallBackEvent,
                     buttonLevel_TypeDef buttonLevel, level_t activeLevel)
   ```
   
4. 将按键添加到链表中

   ```c
   void addButton(Button* b1);
   ```
   
5. 将按键扫描函数放入滴答，或其他毫秒级的定时器中

   ```c
   void buttonTicks(void);
   ```

   

   
