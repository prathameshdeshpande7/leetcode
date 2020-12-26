#define MIN(a, b)   ((a) < (b) ? (a) : (b))

double angleClock(int hour, int minutes){
    
    if (hour == 12)
    {
        hour = 0;
    }
    double hour_angle = 0.5 * (hour * 60 + minutes);
    double minute_angle = 6 * minutes;
    double angle = fabs(hour_angle - minute_angle);
    angle = MIN(360 - angle, angle);
    return angle;
}
