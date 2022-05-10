//
//  main.c
//  testc
//
//  Created by Yu Yang on 2022/3/22.
//

#include <stdio.h>
#include <string.h>

void swap(char v1, char v2)
{
    printf("更换前：v1=%d, v2=%d\n", v1, v2);

    char temp;
    temp = v1;
    v1 = v2;
    v2 = temp;

    printf("更换后：v1=%d, v2=%d\n", v1, v2);
}

void swap2(char *v1, char *v2)
{
    printf("更换前：v1=%d, v2=%d\n", *v1, *v2);

    char temp;
    temp = *v1;
    *v1 = *v2;
    *v2 = temp;

    printf("更换后：v1=%d, v2=%d\n", *v1, *v2);
}

// 将字符串str中的小写字母变成大写字母，并返回改变后的字符串
// 注意的是：这里的参数要传字符串变量，不能传字符串常量
char *upper(char *str)
{
    // 先保留最初的地址。因为等会str指向的位置会变来变去的。
    char *dest = str;

    // 如果还不是空字符
    while (*str != '\0')
    {
        // 如果是小写字母
        if (*str >= 'a' && *str <= 'z')
        {
            // 变为大写字母。小写和大写字母的ASCII值有个固定的差值
            *str -= 'a' - 'A';
        }

        // 遍历下一个字符
        str++;
    }

    // 返回字符串
    return dest;
}

int main(int argc, const char *argv[])
{

    // 定义一个字符串变量
    char str[] = "lmj";

    // 调用函数
    char *dest = upper(str);

    printf("%s", dest);

    //    char s[] = {'m', 'j', 'j', '\0'};
    //    int len = strlen(s);
    //    printf("字符串长度：%d", len);

    //    printf("%s", s[0]);
    //    printf("%s", s[1]);

    //    char a = 10, b = 9;
    //    printf("更换前：a=%d, b=%d\n", a, b);
    //    swap(a, b);
    //    printf("更换后：a=%d, b=%d", a, b);

    //    char a = 10, b = 9;
    //    printf("更换前：a=%d, b=%d\n", a, b);
    //    swap2(&a, &b);
    //    printf("更换后：a=%d, b=%d", a, b);

    //    char s1[] = "abc";
    //    char s2[] = "abc";
    //    char s3[] = "aBc";
    //    char s4[] = "ccb";
    //
    //    printf("%d, %d, %d", strcmp(s1, s2), strcmp(s1, s3), strcmp(s1, s4));

    //    printf("Hello, World!\n");

    //    char a = 'a';
    //    printf("%c\n", a);

    //    printf("The price is %-3d.\n", 14);

    //    printf("Please input your age:");
    //    int age;
    //    scanf("%d", &age);
    //    printf("Your age is %d.", age);

    //    char array[5];
    //    array[0] = 1;
    //    array[1] = 2;
    //    array[2] = 3;
    //    array[3] = 4;
    //    array[4] = 5;
    //
    //    printf("%s", array);

    //    array[0] = 1;
    //    array[1] = 2;
    //    array[2] = 3;
    //    array[3] = 4;
    //    array[4] = 5;

    //    printf("%s", array);

    //    short array[3][2] = {{1,2},{3,4},{5,6}};
    //    short array[3][2] = {1, 2, 3, 4, 5, 6, 7, 8};

    //    printf("a的地址是%d\n",array);
    //    printf("a的地址是%d",&array[0]);

    //    printf("%s", array);
    //    printf("%d", array[0]);

    return 0;
}
