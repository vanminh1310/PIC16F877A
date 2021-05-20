#include <16F877A.h>
#fuses NOWDT, PUT, XT, NOPROTECT
#use delay (clock=4000000)
// Define which timer to use and minor_cycle for RTOS
#use rtos(timer=1, minor_cycle=10ms)
// Declare TASK 1 - called every 250ms
#task(rate=250ms, max=10ms)
void task_B0()
{
output_toggle(PIN_D4); // Toggle RB0
}
// Declare TASK 2 - called every 500ms
#task(rate=500ms, max=10ms)
void task_B1()
{
output_toggle(PIN_D5); // Toggle RB1
}
// Declare TASK 3 - called every second
#task(rate=1s, max=10ms)
void task_B2()
{
output_toggle(PIN_D6); // Toggle RB2
}
// Declare TASK 4 - called every 2 seconds
#task(rate=2s, max=10ms)
void task_B3()
{
output_toggle(PIN_D7); // Toggle RB3
}
// Start of MAIN program
void main()
{
set_tris_b(0); // PORTB as outputs
setup_timer_1 (T1_EXTERNAL);
rtos_run(); // Start RTOS
}