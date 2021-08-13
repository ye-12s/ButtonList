# Examples

```c
void func1(ButtonPressEvent event)
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
void func2(ButtonPressEvent event)
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
level_t readPin1() {
    return HAL_GPIO_ReadPin(/*do something...*/);
}
level_t readPin2() {
    return HAL_GPIO_ReadPin(/*do something...*/);
}

void text_button()
{
	buttonInit();
    Button button = {0};
    buttonConfig(&button,func1,readPin1,0);
    addButton(&button);
    buttonConfig(&button,func2,readPin2,0);
    addButton(&button);
}

void main() {
    //do something...
    text_button();
    while(1);
}
```

