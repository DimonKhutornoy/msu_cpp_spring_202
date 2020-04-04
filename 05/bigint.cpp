#include "bigint.h"

BigInt::BigInt(int64_t data)
{
    cnt = 0;
    data < 0 ? sgn = 1 : sgn = 0;
    if (sgn)
    {
        data *= (-1);
    }
    num = nullptr;
    while (data >= 10)
    {
        num = (char*)realloc(num, sizeof(char) * (cnt + 1));
        num[cnt] = data % 10 + '0';
        data /= 10;
        cnt++;
    }
    num = (char*)realloc(num, sizeof(char) * (cnt + 2));
    num[cnt] = data + '0';
    cnt++;
    num[cnt] = '\0';
}

BigInt::BigInt()
{
    sgn = 0;
    cnt = 1;
    num = (char*)malloc(sizeof(char) * 2);
    num[0] = '0';
    num[1] = '\0';
}

BigInt::BigInt(const BigInt& copied)
    : num((char*)malloc(sizeof(char) * (copied.cnt)))
    , cnt(copied.cnt)
    , sgn(copied.sgn)
{
    std::copy(copied.num, copied.num + cnt, num);
}

BigInt& BigInt::operator=(const BigInt& copied)
{
    if (this == &copied)
        return *this;
    char* ptr = (char*)malloc(sizeof(char) * (copied.cnt));
    free(num);
    num = ptr;
    cnt = copied.cnt;
    sgn = copied.sgn;
    std::copy(copied.num, copied.num + cnt, num);
    return *this;
}

BigInt::BigInt(BigInt&& moved)
    : num(moved.num)
    , cnt(moved.cnt)
    , sgn(moved.sgn)
{
    moved.num = nullptr;
    moved.cnt = 0;
    moved.sgn = 0;
}

BigInt& BigInt::operator=(BigInt&& moved)
{
    if (this == &moved)
        return *this;
    free(num);
    num = moved.num;
    cnt = moved.cnt;
    sgn = moved.sgn;
    moved.num = nullptr;
    moved.cnt = 0;
    moved.sgn = 0;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const BigInt& c)
{
    if (c.sgn)
    {
        out << '-';
    }
    for (int i = c.cnt - 1; i >= 0; i--)
    {
        out << c.num[i];
    }
    return out;
}

bool BigInt::operator==(BigInt op) const
{
    bool fl = true;
    if (cnt != op.cnt || sgn != op.sgn)
        return false;
    for (int i = 0; i < cnt; i++)
    {
        if (!fl)
            break;
        fl = (num[i] == op.num[i]);
    }
    return fl;
}

bool BigInt::operator!=(BigInt op) const
{
    bool fl = (*this == op);
    return !fl;
}

bool BigInt::operator<(BigInt op) const
{
    int i = cnt - 1;
    if (sgn == true && op.sgn == false)
        return true;
    if (sgn == false && op.sgn == true)
        return false;
    if (sgn == false && op.sgn == false)
    {
        if (cnt < op.cnt)
            return true;
        if (cnt > op.cnt)
            return false;
        while (i >= 0 && num[i] == op.num[i])
            i--;
        if (num[i] < op.num[i])
            return true;
        return false;
    }
    BigInt x;
    BigInt y;
    x = *this;
    y = op;
    x.sgn = false;
    y.sgn = false;
    return x > y;
}

bool BigInt::operator>(BigInt op) const
{
    int i = cnt - 1;
    if (sgn == true && op.sgn == false)
        return false;
    if (sgn == false && op.sgn == true)
        return true;
    if (sgn == false && op.sgn == false)
    {
        if (cnt < op.cnt)
            return false;
        if (cnt > op.cnt)
            return true;
        while (i >= 0 && num[i] == op.num[i])
            i--;
        if (num[i] > op.num[i])
            return true;
        return false;
    }
    BigInt x;
    BigInt y;
    x = *this;
    y = op;
    x.sgn = false;
    y.sgn = false;
    return x < y;
}

bool BigInt::operator<=(BigInt op) const
{
    bool fl = (*this > op);
    return !fl;
}

bool BigInt::operator>=(BigInt op) const
{
    bool fl = (*this < op);
    return !fl;
}

BigInt& BigInt::operator-()
{
    if (cnt == 1 && num[0] == '0')
        return *this;
    sgn = !sgn;
    return *this;
}

BigInt BigInt::operator+(BigInt op2) const
{
    BigInt res;
    uint8_t left = 0;
    uint32_t i = 0;
    char* ptr_max;
    uint32_t max_cnt, min_cnt, tmp;
    if (sgn == false && op2.sgn == true)
    {
        BigInt x;
        x = op2;
        x.sgn = false;
        res = *this - x;
        return res;
    }
    if (sgn == true && op2.sgn == false)
    {
        BigInt x;
        x = *this;
        x.sgn = false;
        res = op2 - x;
        return res;
    }
    if (sgn == true && op2.sgn == true)
        res.sgn = true;
    else
        res.sgn = false;
    if (cnt >= op2.cnt)
    {
        ptr_max = num;
        max_cnt = cnt;
        min_cnt = op2.cnt;
    }
    else
    {
        ptr_max = op2.num;
        max_cnt = op2.cnt;
        min_cnt = cnt;
    }
    char* ptr = (char*)malloc(sizeof(char) * (max_cnt + 2));
    free(res.num);
    res.num = ptr;
    while (i < min_cnt)
    {
        tmp = num[i] + op2.num[i] - 2 * '0' + left;
        left = tmp / 10;
        res.num[i] = tmp % 10 + '0';
        i++;
    }
    while (i < max_cnt)
    {
        tmp = ptr_max[i] - '0' + left;
        left = tmp / 10;
        res.num[i] = tmp % 10 + '0';
        i++;
    }
    if (left != 0)
    {
        res.num[i] = left + '0';
        i++;
    }
    res.num[i] = '\0';
    res.cnt = i;
    return res;
}

BigInt BigInt::operator-(BigInt op2) const
{
    BigInt res;
    uint8_t left = 0;
    uint32_t i = 0;
    char *ptr_max, *ptr_min;
    uint32_t max_cnt, min_cnt, tmp;
    if (sgn == false && op2.sgn == true)
    {
        BigInt x;
        x = op2;
        x.sgn = false;
        res = *this + x;
        return res;
    }
    if (sgn == true && op2.sgn == false)
    {
        BigInt x;
        x = op2;
        x.sgn = true;
        res = x + *this;
        return res;
    }
    if (*this >= op2)
        res.sgn = false;
    else
        res.sgn = true;
    BigInt x;
    BigInt y;
    x = *this;
    y = op2;
    x.sgn = false;
    y.sgn = false;
    if (x >= y)
    {
        ptr_max = num;
        ptr_min = op2.num;
        max_cnt = cnt;
        min_cnt = op2.cnt;
    }
    else
    {
        ptr_max = op2.num;
        ptr_min = num;
        max_cnt = op2.cnt;
        min_cnt = cnt;
    }
    char* ptr = (char*)malloc(sizeof(char) * (max_cnt + 1));
    free(res.num);
    res.num = ptr;
    while (i < min_cnt)
    {
        if (ptr_max[i] - left < ptr_min[i])
        {
            res.num[i] = ptr_max[i] + 10 - ptr_min[i] + '0' - left;
            left = 1;
        }
        else
        {
            res.num[i] = ptr_max[i] - ptr_min[i] + '0' - left;
            left = 0;
        }
        i++;
    }
    while (i < max_cnt)
    {
        if (ptr_max[i] == '0' && left)
        {
            res.num[i] = ptr_max[i] + 10 - left;
            left = 1;
        }
        else
        {
            res.num[i] = ptr_max[i] - left;
            left = 0;
        }
        i++;
    }
    res.num[i] = '\0';
    res.cnt = i;
    res.del_zero();
    return res;
}

void BigInt::del_zero()
{
    int i = cnt - 1;
    while (num[i] == '0')
    {
        i--;
    }
    if (i == -1)
    {
        BigInt z;
        *this = z;
        return;
    }
    char* ptr = (char*)malloc(sizeof(char) * (i + 2));
    ptr[i + 1] = '\0';
    cnt = i + 1;
    while (i >= 0)
    {
        ptr[i] = num[i];
        i--;
    }
    free(num);
    num = ptr;
    return;
}

BigInt::~BigInt()
{
    free(num);
}
