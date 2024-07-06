#include "aTimerController.h"

aTimerController::aTimerController(unsigned char index)
    : activeTimerIndex(index)
{
    for (unsigned char i = 0; i < this->MAX_TIMERS; i++)
    {
        this->timers[i] = 0;
        this->waitDurations[i] = 0;
    }
}

void aTimerController::setWaitTimer(unsigned char index, unsigned long value)
{
    if (index >= 0 && index < this->MAX_TIMERS)
    {
        this->waitDurations[index] = value;
    }
}

void aTimerController::setCurrentTimer(unsigned char index, unsigned long value)
{
    if (index >= 0 && index < this->MAX_TIMERS)
    {
        this->timers[index] = value;
    }
}

unsigned long aTimerController::getTimer(unsigned char index) const
{
    if (index >= 0 && index < this->MAX_TIMERS)
    {
        return this->timers[index];
    }
    return 0;
}

void aTimerController::updateCurrentTime(unsigned long currentMillis)
{
    this->timers[this->activeTimerIndex] = currentMillis;
}

void aTimerController::resetTimer(unsigned char index)
{
    this->setCurrentTimer(index, this->timers[this->activeTimerIndex]);
}

bool aTimerController::isTimerElapsed(unsigned char index) const
{
    if (index >= 0 && index < this->MAX_TIMERS)
    {
        return this->timers[this->activeTimerIndex] - this->timers[index] >= this->waitDurations[index];
    }
    return false;
}