
typedef enum 
{
    OFF = 0,
    ON = 1,
    PROTECTED = 2,
} button_state;

button_state button_state_off(void);
button_state button_state_on(void);
button_state button_state_protected(void);
