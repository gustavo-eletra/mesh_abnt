#include "abnt.h"

void abnt_clear(ABNT_data *data)
{
    for(int i = 0; i < 66; i++)
    {
        data->ds[i] = 0;
    }

    for(int i = 0; i < 258; i++)
    {
        data->dr[i] = 0;
    }
}

void abnt_callback_register_default(ABNT_callbacks *abnt_callbacks)
{
    abnt_callbacks->abnt_funcs[0] = &abnt_set_data;
    abnt_callbacks->abnt_funcs[1] = &abnt_send;
    abnt_callbacks->abnt_funcs[2] = &abnt_open_session;
    abnt_callbacks->abnt_funcs[3] = &abnt_close_session;

    abnt_callbacks->cmd[0] = ABNT_SET;
    abnt_callbacks->cmd[1] = ABNT_SEND;
    abnt_callbacks->cmd[2] = ABNT_OPEN_SESSION;
    abnt_callbacks->cmd[3] = ABNT_CLOSE_SESSION;
}

//Demo on how to operate the fsm
void abnt_fsm_default(ABNT_data *data, CMD_queue *cmd_queue, ABNT_queue *q)
{
    ABNT_callbacks callbacks;
    abnt_callback_register_default(&callbacks);
    
    abnt_clear(&data);

    int state = 0;
    while(state < cmd_queue->size || state >= 0)
    {
        abnt_set_state_from_queue(data, q[state]);
        state = callbacks.abnt_funcs[state](data, state);
    }
}