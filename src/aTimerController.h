#pragma once

class aTimerController
{
public:
    aTimerController(unsigned char index = 0);
    void setWaitTimer(unsigned char index, unsigned long value);
    void setCurrentTimer(unsigned char index, unsigned long value);
    unsigned long getTimer(unsigned char index) const;
    void updateCurrentTime(unsigned long currentMillis);
    void resetTimer(unsigned char index);
    bool isTimerElapsed(unsigned char index) const;
    static const unsigned char MAX_TIMERS = 255;

private:
    unsigned char activeTimerIndex = 0;
    unsigned long timers[MAX_TIMERS];
    unsigned long waitDurations[MAX_TIMERS];
};
