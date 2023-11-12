#include "bmi_check.h"
#include <stdio.h>

int main(int argc, const char* argv[])
{
    printf("Let's check your BMI\n");

    printf("身長[m]を入力してください。\n");
    double height = 0.0;
    scanf("%lf", &height);

    printf("体重[kg]を入力してください。\n");
    double weight = 0.0;
    scanf("%lf", &weight);

    printf("年齢を入力してください。\n");
    int age = 0;
    scanf("%d", &age);

    double bmi = calcBMI(height, weight);
    SHAPE shape = checkBMI(bmi, age);

    const char* shape_comment = "";
    switch (shape) {
    case STANDARD:
        shape_comment = "標準的";
        break;
    case SLIM:
        shape_comment = "痩せすぎ";
        break;
    case FAT:
        shape_comment = "太りすぎ";
        break;
    default:
        shape_comment = "不明";
        break;
    }

    printf("あなたのBMI値は%lfで%sです\n", bmi, shape_comment);
    return 0;
}