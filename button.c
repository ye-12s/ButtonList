//
// Created by An on 2021/7/29.
//

#include <main.h>
#include <malloc.h>
#include <stdio.h>
#include "button.h"
#include <stdarg.h>

Button *button = NULL;

uint8_t size = 0;

#if 0
uint16_t shortCache = 0; //0000 0000 0000 0000
uint16_t longCache = 0;
uint16_t evenCache = 0;
void resetCache() {
    shortCache = 0;
    longCache = 0;
    evenCache = 0;
}
void setButtonCache(uint8_t id,pressEvent event) {
    if(id > 15)
        return;
    switch (event) {
        case Short:
            shortCache |= 1 << id;
            break;
        case Long:
            longCache |= 1 << id;
            break;
        case Even:
            evenCache |= 1 << id;
        default:
            break;
    }
}

uint8_t isButtonDown(uint8_t id,pressEvent event) {
    if(id > 15)
        return 0;
    switch (event) {
        case Short:
            return shortCache & (1 << id);
        case Long:
            return longCache & (1 << id);
        case Even:
            return evenCache & (1 << id);
        default:
            return 0;
    }
}
#endif

void buttonConfig() {
    button = (Button *)malloc(sizeof (Button));
}

void buttonScan(void) {
    static uint8_t count = 0;
    static uint8_t evenCount = 0;
    Button * p = button;
    if(count++ < TICKS_INTERVAL)
        return;
    count = 0;
    for(uint8_t i = 0;i < size; i++)
    {
        p = p->next;
        if(p->PinState != p->buttonLevel()) {                   //此举为键盘弹起后处理语句
            if(p->count > 0){
                if(p->count >= BUTTON_SHORT_COUNT_MIN) {        //此行为保证键盘保持了最低限度的短按
                    if(p->count < BUTTON_EVEN_COUNT_MIN) {      //此行为保证键盘保持在长按短按之内排除出连按
                        if(p->count >= BUTTON_LONG_COUNT_MIN) { //此句判断是否为长按按键计数是否大于最小的长按指标
                            p->workupCallBackEvent(Long);
                        }else {
                            p->workupCallBackEvent(Short);
                        }
                    }
                }
                p->workupCallBackEvent(Up);
                p->count = 0;
            }
        } else {
            if(p->count == 0)
                p->workupCallBackEvent(Down);
            if(p->count > BUTTON_EVEN_COUNT_MIN) {
                if(p->count > BUTTON_EVEN_COUNT_MAX) {
                    p->count = BUTTON_EVEN_COUNT_MIN;
                } else {
                    if(evenCount++ >= 10) {
                        p->workupCallBackEvent(Even);
                        p->count++;
                        evenCount = 0;
                    }
                }
            } else {
                p->count++;
            }
        }
    }
}

void addButton(Button * b1) {
    Button *but =NULL;
    if((but = (Button*)malloc(sizeof (Button))) == NULL)
    {
        Error_Handler();
    }
    but->id = size++;
    but->count = 0;
    but->PinState = b1->PinState;
    but->buttonLevel = b1->buttonLevel;
    but->workupCallBackEvent = b1->workupCallBackEvent;
    //使用头插法将按键插入链表中
    Button *b = button->next;
    button->next = but;
    but->next = b;
}
void addBurrons(int num,...) {
    va_list vaList;
    va_start(vaList, num);
    for (int i = 0; i < num; ++i) {
        addButton(va_arg(vaList, Button*));
    }
    va_end(vaList);
}