//
// Created by ye-12s on 2021/7/29.
//

#include "button.h"
#include "stdlib.h"

Button *button = NULL;

uint8_t size = 0;

//头节点初始化函数
void buttonInit() {
    button = (Button *) malloc(sizeof(Button));
    button->next = NULL;
    button->buttonCallBackEvent = NULL;
    button->buttonLevel = NULL;
    button->activeLevel = 0;
    button->count = 0;
}

void buttonConfig(Button *pButton, buttonCallBackEvent_TypeDef buttonCallBackEvent,
                  buttonLevel_TypeDef buttonLevel, level_t activeLevel) {
    pButton->activeLevel = (activeLevel != 0)?1:0;
    pButton->buttonLevel = buttonLevel;
    pButton->buttonCallBackEvent = buttonCallBackEvent;
}

//按键扫描函数
static void buttonScan(void) {
    Button *p = button;
    for (uint8_t i = 0; i < size; i++) {
        p = p->next;
        if (p->activeLevel != p->buttonLevel()) {                   //此举为键盘弹起后处理语句
            if (p->count > 0) {
                if (p->count >= BUTTON_SHORT_COUNT_MIN && p->count < BUTTON_KEEP_COUNT_MIN) {
                    if (p->count >= BUTTON_LONG_COUNT_MIN) {        //判断长短按
                        p->buttonCallBackEvent(pressEvent_long);
                    } else {
                        p->buttonCallBackEvent(pressEvent_short);
                    }
                }
                p->buttonCallBackEvent(pressEvent_up);
                p->count = 0;
            }
        } else {
            if (p->count == 0)
                p->buttonCallBackEvent(pressEvent_down);
            if (p->count > BUTTON_KEEP_COUNT_MIN) {
                if (p->count >= BUTTON_KEEP_COUNT_MAX) {
                    p->count = BUTTON_KEEP_COUNT_MIN;
                } else {
                    static uint8_t count = 0;
                    if (count++ >= BUTTON_KEEP_PSC_COUNT) {
                        p->buttonCallBackEvent(pressEvent_keep);
                        p->count++;
                        count = 0;
                    }
                }
            } else {
                p->count++;
            }
        }
    }
}

//按键延时函数
void buttonTicks() {
    static uint8_t tick = 0;
    if (++tick < TICKS_INTERVAL)
        return;
    tick = 0;
    buttonScan();
}

void addButton(Button *b1) {
    Button *but = NULL;
    buttonMalloc:
    if ((but = (Button *)malloc(sizeof(Button))) == NULL) {
        goto buttonMalloc;
    }
    ++size;
    but->count = 0;
    but->activeLevel = b1->activeLevel;
    but->buttonLevel = b1->buttonLevel;
    but->buttonCallBackEvent = b1->buttonCallBackEvent;
    //使用头插法将按键插入链表中
    Button *b = button->next;
    button->next = but;
    but->next = b;
}
