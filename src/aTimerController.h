/**
 * @file aTimerController.h
 * @brief タイマー制御を管理するクラスを提供します。
 *
 * aTimerControllerクラスは、複数のタイマーを管理し、特定のタイマーが設定された時間を経過したかどうかを判断する機能を提供します。
 * このクラスは、特定のイベントの発生をタイミング良く管理するために使用されます。
 *
 * @version 0.1
 * @date 2024-07-06
 */

#pragma once

class aTimerController
{
public:
    /**
     * @brief aTimerControllerクラスのコンストラクタ。
     * @param index 初期化時にアクティブにするタイマーのインデックス。デフォルトは0。
     */
    aTimerController(unsigned char index = 0);

    /**
     * @brief 指定されたタイマーの待機時間を設定します。
     * @param index 設定するタイマーのインデックス。
     * @param value 待機時間（ミリ秒）。
     */
    void setWaitTimer(unsigned char index, unsigned long value);

    /**
     * @brief 指定されたタイマーの現在時間を設定します。
     * @param index 設定するタイマーのインデックス。
     * @param value 現在時間（ミリ秒）。
     */
    void setCurrentTimer(unsigned char index, unsigned long value);

    /**
     * @brief 指定されたタイマーの現在時間を取得します。
     * @param index 取得するタイマーのインデックス。
     * @return unsigned long タイマーの現在時間（ミリ秒）。
     */
    unsigned long getTimer(unsigned char index) const;

    /**
     * @brief 現在のシステム時間を更新します。
     * @param currentMillis 現在のシステム時間（ミリ秒）。
     */
    void updateCurrentTime(unsigned long currentMillis);

    /**
     * @brief 指定されたタイマーの現在時間を更新します。
     * @param index 更新するタイマーのインデックス。
     */
    void resetTimer(unsigned char index);

    /**
     * @brief 指定されたタイマーが設定された時間を経過したかどうかを判断します。
     * @param index 判断するタイマーのインデックス。
     * @return true タイマーが時間を経過した場合。
     * @return false タイマーがまだ時間を経過していない場合。
     */
    bool isTimerElapsed(unsigned char index) const;

    static const unsigned char MAX_TIMERS = 255; ///< 管理できるタイマーの最大数。

private:
    unsigned char activeTimerIndex = 0;      ///< 現在アクティブなタイマーのインデックス。
    unsigned long timers[MAX_TIMERS];        ///< 各タイマーの現在時間を保持する配列。
    unsigned long waitDurations[MAX_TIMERS]; ///< 各タイマーの待機時間を保持する配列。
};
