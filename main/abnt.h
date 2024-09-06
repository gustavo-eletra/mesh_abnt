#pragma once
#include <stdint.h>
#include "utils.h"

typedef struct
{
    uint8_t[66];
    uint8_t[258];
}ABNT_data;

void abnt_set_data(ABNT_data *data, uint8_t command, uint8_t *payload, uint8_t length);
void abnt_send(ABNT_data *data, );
int abnt_send_hmac_string(ABNT_data *data);
void abnt_open_session(ABNT_data *data);
void abnt_close_session(ABNT_data *data);
void abnt_fsm(ABNT_data *data, uint8_t *buffer);