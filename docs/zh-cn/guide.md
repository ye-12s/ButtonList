

# 使用指南

1. 需要先申请一块按键空间

   ```c 
   Button button;
   ```

2. 初始化头节点按键对象

   ```c
   void buttonConfig(void);			/*为头节点申请空间*/
   ```

3. 为按键添加设置属性、行为

   ```c
   button.PinState					/*设置按键触发电平*/
   button.buttonLevel				/*绑定按键的GPIO电平接口*/
   button.workupCallBackEvent		/*绑定按键的回调函数*/
   ```

4. 将按键添加到链表中

   ```c
   void addButton(Button* );
   /*此方法可以一次性添加多个按键，num一次性添加按键的数量*/
   void addButtons(int num,...);	
   ```

5. 将按键扫描函数塞入滴答，或其他毫秒级的定时器中

   ```c
   void buttonScan(void);
   ```

   

   
