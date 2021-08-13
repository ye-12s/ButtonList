//
// Created by An on 2021/7/29.
//

#ifndef BUTTON_LIST_BUTTON_H
#define BUTTON_LIST_BUTTON_H

#include "stdint.h"

#define TICKS_INTERVAL 10               //按键扫描的延时毫秒数
#define BUTTON_SHORT_COUNT_MIN 2        //短按的触发最小毫秒数(value = BUTTON_SHORT_COUNT_MIN * TICKS_INTERVAL)
#define BUTTON_LONG_COUNT_MIN 20        //长按的触发最小毫秒数(value = BUTTON_LONG_COUNT_MIN * TICKS_INTERVAL)
#define BUTTON_KEEP_PSC_COUNT 10        //连按的触发最小毫秒数的分频
#define BUTTON_KEEP_COUNT_MIN 100       //连按的启动最小毫秒数(value = BUTTON_KEEP_COUNT_MIN * TICKS_INTERVAL)
#define BUTTON_KEEP_COUNT_MAX 200       //最大值为255


typedef enum {
    pressEvent_up = 0u,
    pressEvent_down,
    pressEvent_short,
    pressEvent_long,
    pressEvent_keep
}ButtonPressEvent;

typedef uint8_t level_t;
typedef level_t (*buttonLevel_TypeDef)(void);
typedef void (*buttonCallBackEvent_TypeDef)(ButtonPressEvent);


typedef struct Button {
    uint8_t count;
    level_t activeLevel;
    buttonLevel_TypeDef buttonLevel;
    buttonCallBackEvent_TypeDef buttonCallBackEvent;
    struct Button *next;
}Button;

void buttonConfig(Button*, buttonCallBackEvent_TypeDef, buttonLevel_TypeDef, level_t);
void buttonInit();
void buttonTicks();
void addButton(Button *);
#endif //BUTTON_LIST_BUTTON_H
