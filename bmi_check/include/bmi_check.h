#ifndef _BMI_CHECKER_H_
#define _BMI_CHECKER_H_

/// @enum SHAPE
/// 体型を表す列挙体
typedef enum _SHAPE {
    UNKNOWN,
    SLIM,
    STANDARD,
    FAT
} SHAPE;

double calcBMI(double height, double weight);
SHAPE checkBMI(double bmi, int age);

#endif