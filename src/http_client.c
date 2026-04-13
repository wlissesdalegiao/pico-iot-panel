#include "http_client.h"
#include <stdio.h>

void http_send_data(float temp, int joy, int pwm) {
    printf("HTTP -> temp=%.1f joy=%d pwm=%d\n", temp, joy, pwm);
}