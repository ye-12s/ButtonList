//
// Created by An on 2021/7/29.
//

#ifndef BUTTON_TEXT_BUTTON_H
#define BUTTON_TEXT_BUTTON_H

#define TICKS_INTERVAL 10
#define BUTTON_LONG_COUNT_MIN 20
#define BUTTON_SHORT_COUNT_MIN 2
#define BUTTON_EVEN_COUNT_MIN 100
#define BUTTON_EVEN_COUNT_MAX 200

typedef enum {
    Up = 0u,
    Down,
    Short,
    Long,
    Even
}pressEvent;

typedef struct Button {
    uint8_t id;
    uint8_t count;
    GPIO_PinState PinState;
    GPIO_PinState (*buttonLevel)(void);
    void (*workupCallBackEvent)(pressEvent);
    struct Button *next;
}Button;

void buttonConfig();
void buttonScan(void);
void addButton(Button *);
void addBurrons(int num,...);
#endif //BUTTON_TEXT_BUTTON_H
