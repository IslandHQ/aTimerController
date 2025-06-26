#include <string>
#include <aTimerController.h>

bool statusFlags[255];
unsigned int statusValue[255];
String dbgStr = "";

enum TimeValue
{
    T_TIME_1ms = 1,
    T_TIME_1s = 1000,
    T_TIME_1m = 60000,
    T_TIME_1h = 360000,
    T_TIME_1d = 86400000,
    T_TIME_1w = 604800000,
};

enum TimerIndex
{
    M_TIMER_CURRENT, // 現在の経過時間を追跡するタイマー
    M_TIMER,         // 汎用イベント管理タイマー
    M_TIMER_TEST,    // テスト目的のタイマー
};

enum statusIndex
{
    S_RUN,   // 動作状態
    S_LIGHT, // ライト状態
};

aTimerController ct(M_TIMER_CURRENT);

void initTimers()
{
    ct.setWaitTimer(M_TIMER, T_TIME_1ms * 5); // 制御用タイマ
    ct.setWaitTimer(M_TIMER_TEST, T_TIME_1s); // デバッグログ出力用のタイマ
}

void initStatus()
{
    statusFlags[S_RUN] = false;
    statusFlags[S_LIGHT] = false;
    statusValue[S_LIGHT] = 0;
}

void setup()
{
    initTimers(); // タイマの初期化
    initStatus(); // 状態の初期化
}

void loop()
{
    ct.updateCurrentTime(millis());

#pragma region 制御
    if (ct.isTimerElapsed(M_TIMER))
    {
        statusFlags[S_RUN] = !statusFlags[S_RUN];
        ct.resetTimer(M_TIMER);
    }
    statusFlags[S_LIGHT] = statusFlags[S_RUN];
#pragma endregion

#pragma region デバッグ用処理
    if (ct.isTimerElapsed(M_TIMER_TEST))
    {
        dbgStr = String(ct.getTimer(M_TIMER_CURRENT)) + ":";
        dbgStr.concat(statusFlags[S_RUN] ? "IV.RUN," : "IV.STOP,");
        dbgStr.concat(statusFlags[S_LIGHT] ? "RY.HIGH," : "RY.LOW,");

        ct.resetTimer(M_TIMER_TEST);
    }
#pragma endregion
}