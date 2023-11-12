#include "bmi_check.h"

/// @brief BMIを計算する
/// @param height 身長 [m]
/// @param weight 体重 [kg]
/// @return BMI値
double calcBMI(double height, double weight) {
    return weight / (height * height);
}

/// @brief BMIと年齢から体型をチェックする
/// @param bmi BMI値
/// @param age 年齢
/// @return 標準: STANDARD, 痩せ: SLIM, 肥満: FAT, 不明: UNKNOWN 
SHAPE checkBMI(double bmi, int age) {
    if (age < 18)
        return UNKNOWN;

    SHAPE ret = STANDARD;
    if (bmi >= 25.0) {
        ret = FAT;
    } else if (18 <= age && age < 50 && bmi < 18.5) {
        ret = SLIM;
    } else if (50 <= age && age < 70 && bmi < 20.0) {
        ret = SLIM;
    } else if (70 <= age && bmi < 21.5) {
        ret = SLIM;
    }
    return ret;
}
