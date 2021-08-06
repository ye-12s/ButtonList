# Examples

```c
void workup1(pressEvent event) {
    switch (event) {
        case Long:
            // do someththing...
            break;
        case Short:
            // do someththing...
            break;
        case Even:
            // do someththing...
            break;
        case Up:
            // do someththing...
            break;
        case Down:
            // do someththing...
            break;
        default:
            break;
    }
}
void workup2(pressEvent event) {
    switch (event) {
        case Long:
            // do someththing...
            break;
        case Short:
            // do someththing...
            break;
        case Even:
            // do someththing...
            break;
        case Up:
            // do someththing...
            break;
        case Down:
            // do someththing...
            break;
        default:
            break;
    }
}

GPIO_PinState readPin1() {
    return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12);
}
GPIO_PinState readPin2() {
    return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13);
}

void text_button()
{
    Button button1 = {
            .PinState = GPIO_PIN_RESET,
            .workupCallBackEvent = workup1,
            .buttonLevel = readPin1
    };
    Button button2 = {
            .PinState = GPIO_PIN_RESET,
            .workupCallBackEvent = workup2,
            .buttonLevel = readPin2
    };
    buttonConfig();
    addBurrons(2,&button1,&button2);
}

void main() {
    /*SomeBody*/
    text_button();
    while(1);
}
```

