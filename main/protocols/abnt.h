#pragma once
#include <stdint.h>
#include "cmd.h"
#include "utils.h"

typedef enum
{
    ABNT_SET,
    ABNT_SEND,
    ABNT_OPEN_SESSION,
    ABNT_CLOSE_SESSION
}ABNT_DEFAULT_COMMANDS;

typedef struct
{
    uint8_t ds[66];
    uint8_t dr[258];
}ABNT_data;

typedef struct
{
    uint8_t data[66];
}ABNT_queue;

typedef int (*ABNT_FUNC)(ABNT_data*, int); 

typedef struct 
{
    int cmd[10];
    ABNT_FUNC abnt_funcs[10];
}ABNT_callbacks;


void abnt_callback_register(ABNT_callbacks *abnt_callbacks, ABNT_FUNC *func, int cmd);
void abnt_callback_register_default(ABNT_callbacks *abnt_callbacks);

void abnt_clear(ABNT_data *data);

void abnt_set_state_from_queue(ABNT_data *data, ABNT_queue q);
int abnt_set_data(ABNT_data *data, int cmd);
int abnt_send(ABNT_data *data, int cmd);
int abnt_send_hmac_string(ABNT_data data);
int abnt_open_session(ABNT_data *data, int cmd);
int abnt_close_session(ABNT_data *data, int cmd);
void abnt_fsm(ABNT_data *data, uint8_t *buffer);
void abnt_fsm_default(ABNT_data *data, CMD_queue *cmd_queue);