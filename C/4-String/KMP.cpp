#include "iostream"

using namespace std;

typedef struct {
    char* ch;
    int length;
} Str;

//将字符串ch赋值给串str的ch
int strAssign(Str &str, char* ch, int &length) {
    //如果str的ch不为null 清空
    if (str.ch) {
        free(str.ch);
    }

    //如果ch为null 返回失败信息
    if (!ch) {
        return 0;
    }

    //得到ch长度 因为要赋值str需要先知道它的长度，不能边赋边增
    length = 0;
    //不能直接让ch++，因为之后还要用到它
    char* c = ch;
    while (*c) {
        ++length;
        ++c;
    }
    //kmp中字符存在1~length上，所以输入的ch第一个元素是无意义的，length也对应的多了一个，这里要减一个
    length--;
    //如果ch是空字符串 返回失败信息
    if (length == 0) {
        str.length = 0;
        str.ch = nullptr;
        return 0;
    } else {
        //要预留'\0'的位置，所以length+1个空间
        str.ch = (char*) malloc((length + 1) * sizeof (char));
        for (int i = 0; i <= length; ++i) {
            str.ch[i] = *ch;
            ++ch;
        }
        str.length = length;
        return 1;
    }
}

//求next[]
//找到截止某个位置之前，模式串的最长字串（除了自身）
//为了方便，next[]直接存放如果当前索引处比对失败，下次应该比较的位置，不是最大子串的最后一个字母的索引，
//而是这个索引+1（如果有最大子串）
//字符串一般从索引1位置开始
//到i、j处匹配成功时，此时子串（模式串）匹配到j，则next[i+1]处的值应该为j+1，此时子串从i+1处往前的j个元素的序列
//和前j个元素的序列相同
//到i处匹配失败时，应该有2种状态
//第1种：有最长字串，则主串位置不动，找最长子串，和模式串一起从最长字串的后一个子母重新开始比对，则令j = next[j]，i不变
//第2种：无最长字串，这个也有两种特殊情况，一个是j != 1，此时应该主串位置不动，从j = 1处重新比对，则next[j]会等于1
//（在比较上一个元素时就已经确定了），所以，next[2]无论如何也为1
//另一种特殊情况：j == 1，主串位置向后一位，模式串也从零开始（实际上从第一个元素，从零开始说起来顺口），
//但为了程序美观，令1不特殊，即仍令j = next[j]，且保证下一次循环顺利，即进入“匹配成功”的分支，next[i+1] = j+1，则令next[j] = 0，
//同时，判断匹配成功的分支加一个特殊条件 j == 0，但是实际上，这个j == x，和next[1]的值相同就可以了（当然，也不能大于0）
//要改成-1也可以，一起改，只是为了能顺利进入这个分支的循环
//综上，next[]应该有两个初始值，一个是next[1] = 0，一个是next[2] = 1
void getNext(Str substr, int next[]) {
    next[1] = 0;
    int i = 1;
    int j = 0;
    while (i < substr.length) {
        if (j == 0 || (substr.ch[i] == substr.ch[j]))
        {
            next[++i] = ++j;
        } else {
            j = next[j];
        }
    }
}

//在求得next[]的基础上，针对kmp的应用场景优化得nextVal[]
//上文当匹配失败时，j = next[j]，若substring.ch[i] == substring.ch[j]，则下一次比对仍然会匹配失败，所以要考虑到这一点，直接跳过这种情况
//所以要在对next[i]赋值的时候检查一下substring.ch[i]和substring.ch[j]是否相等 相等的话就让next[i] = next[j]
//从递归的思想来看，i之前的next[]一定都是满足了这个条件（substring.ch[next[x]] != substring.ch[y], y < i）的
//所以只需要一次j = next[j]即可
void getNext_optimized(Str substr, int next[]) {
    next[1] = 0;
    int j = 0;
    int i = 1;
    while (i < substr.length) {
        if (j == 0 || (substr.ch[i] == substr.ch[j]))
        {
            i++;
            j++;
            if (substr.ch[i] == substr.ch[j])
            {
                //这里不需离开，   ···  要改j的值
                next[i] = next[j];
            } else {
                next[i] = j;
            }
        } else {
            j = next[j];
        }
    }
}

int KMP(Str str, Str substr, int next[])
{
    int i = 1;
    int j = 1;
    while (i <= str.length && j <= substr.length) {
        if (j == 0 || str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > substr.length) {
        return i - substr.length;
    } else {
        return 0;
    }
}

//从某处开始与substr串匹配的子串的位置
//next[]函数i的起始位置不需要改
int KMP(Str str, Str substr, int begin, int next[])
{
    int i = begin;
    int j = 1;
    while (i <= str.length && j <= substr.length) {
        if (j == 0 || str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > substr.length) {
        return i - substr.length;
    } else {
        return 0;
    }
}

//求不重叠子串的个数
int KMP_count(Str str, Str substr, int next[])
{
    int num = 0;
    int i = 1;
    int j = 1;
    while (i <= str.length && j <= substr.length) {
        if (j == 0 || str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
            if (j == substr.length + 1) {
                num++;
                j = 1;
            }
        } else {
            j = next[j];
        }
    }
    return num;
}



int main() {
    int length;

    Str str;
    str.ch = nullptr;
    str.length = 0;
    char ch[] = "Xaaaaaa";
    strAssign(str, ch, length);

    Str substr;
    substr.ch = nullptr;
    substr.length = 0;
    char subch[] = "Xaaa";
    strAssign(substr, subch, length);
    int next[length + 1];
    getNext_optimized(substr, next);

    int nums = KMP_count(str, substr, next);
    printf("%d", nums);
}