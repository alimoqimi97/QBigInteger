#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class BigInteger
{
private:
    string Number;
public:
    BigInteger()
    {
        this->Number = "0";
    }
    BigInteger(const int & Number)
    {
        this->Number = to_string(Number);
    }
    BigInteger(const string Number)
    {
        this->Number = Number;
    }
    void setNumber(string number) { this->Number = number;}
    string getNumber() const { return this->Number;}

    bool operator == (const BigInteger & otherNumber);
    bool operator > (const BigInteger & otherNumber);
    bool operator < (const BigInteger & otherNumber);
    bool operator >= (const BigInteger & otherNumber);
    bool operator <= (const BigInteger & otherNumber);
    bool operator != (const BigInteger & otherNumber);
    BigInteger operator = (const BigInteger & otherNumber);
    BigInteger operator + (const BigInteger & otherNumber);
    BigInteger operator - (const BigInteger & otherNumber);
    BigInteger operator * (const BigInteger & otherNumber);
    BigInteger operator += (const BigInteger & otherNumber);
    BigInteger operator -= (const BigInteger & otherNumber);
    BigInteger operator *= (const BigInteger & otherNumber);
};


bool BigInteger::operator ==(const BigInteger & otherNumber)
{
    if(this->Number == otherNumber.getNumber())
    {
        return true;
    }
    return false;
}

bool BigInteger::operator >(const BigInteger & otherNumber)
{
    if(this->Number > otherNumber.getNumber())
    {
        return true;
    }
    return false;
}

bool BigInteger::operator <(const BigInteger & otherNumber)
{
    if(this->Number < otherNumber.getNumber())
    {
        return true;
    }
    return false;
}

bool BigInteger::operator >=(const BigInteger & otherNumber)
{
    if(this->Number > otherNumber.getNumber())
    {
        return true;
    }
    if(this->Number == otherNumber.getNumber())
    {
        return true;
    }
    return false;
}

bool BigInteger::operator <=(const BigInteger & otherNumber)
{
    if(this->Number < otherNumber.getNumber())
    {
        return true;
    }
    if(this->Number == otherNumber.getNumber())
    {
        return true;
    }
    return false;
}

bool BigInteger::operator !=(const BigInteger &otherNumber)
{
    if(!(this->Number == otherNumber.getNumber()))
    {
        return true;
    }
    return false;
}

BigInteger BigInteger::operator =(const BigInteger & otherNumber)
{
    BigInteger  Result ;

    this->Number = otherNumber.getNumber();

    Result.setNumber(this->Number);

    return Result;
}

BigInteger BigInteger::operator +(const BigInteger & otherNumber)
{
    string  t = "", My_Num = this->Number , other_Num = otherNumber.getNumber();
    int Bsize = 0,carry = 0;
    BigInteger  BI;

    if(My_Num.size() > other_Num.size())
    {
        int dif = My_Num.size() - other_Num.size();

        Bsize = this->Number.size();

        for(int i =0 ; i < dif ; i++)
        {
            other_Num.insert(other_Num.begin(),'0');
        }
    }
    if(My_Num.size() < other_Num.size())
    {
        int dif = other_Num.size() - My_Num.size();

        Bsize = otherNumber.getNumber().size();

        for(int j = 0 ; j < dif ; j++)
        {
            My_Num.insert(My_Num.begin(),'0');
        }
    }
    if(this->Number.size() == otherNumber.getNumber().size())
    {
        Bsize = this->Number.size();
    }

    for(int i = 0 ; i < Bsize ; ++i)
    {
        int sum = 0;

        sum = (My_Num[Bsize - i - 1] - 48) + (other_Num[Bsize - i - 1] - 48) + carry;

        carry = 0;

        if(sum >= 10)
        {
            carry = 1;
            sum -= 10;
        }

         sum += 48;
         t.push_back((char)sum);
    }

    if(carry == 1)
    {
        carry += 48;
        t.push_back((char)carry);
    }
    std::reverse(t.begin(),t.end());
    BI.setNumber(t);

    return BI;
}

BigInteger BigInteger::operator -(const BigInteger & otherNumber)
{
    string  t = "" , My_Num = this->Number , other_Num = otherNumber.getNumber();
    BigInteger BI;
    int Bsize = 0 ;
    char sign = '+';

    if(My_Num > other_Num)
    {
        int dif = this->Number.size() - otherNumber.getNumber().size();

        Bsize = My_Num.size();

        for(int i = 0 ; i < dif ; i++)
        {
            other_Num.insert(other_Num.begin(),'0');
        }
    }
    if(My_Num < other_Num)
    {
        int dif = other_Num.size() - My_Num.size();

        Bsize = other_Num.size();

        for(int j = 0 ; j < dif ; j++)
        {
            My_Num.insert(My_Num.begin(),'0');
        }

        My_Num = otherNumber.getNumber();
        other_Num = this->Number;
        sign = '-';
    }
    if(this->Number == otherNumber.getNumber())
    {
        BI.setNumber("0");
        return  BI;
    }



    for(int i = 0 ; i < Bsize ; i++)
    {
        int temp = 0 ;

        temp = ((int)My_Num[Bsize - i - 1] - 48) - (other_Num[Bsize - i -1] - 48);

        if(temp < 0)
        {
            temp += 10;
            --My_Num[Bsize - i - 2];

        }

        temp += 48;

        t.push_back((char)temp);
    }

    if(sign == '-')
    {
        t.push_back((char)'-');
    }

    std ::reverse(t.begin(),t.end());

    BI.setNumber(t);

    return BI;
}

BigInteger BigInteger::operator *(const BigInteger & otherNumber)
{
//    int  mulsize = stoi(this->Number);

    BigInteger  My_num , other_num ;
    BigInteger  Result ;

    My_num.setNumber(this->Number);
    other_num.setNumber(otherNumber.getNumber());

    for(int i = other_num.getNumber().size() - 1 ; i >= 0  ; --i)
    {
        for(int j = My_num.getNumber().size() - 1 ; j >= 0  ; --j)
        {
            string  temp;
            int  r = other_num.getNumber()[i];
            BigInteger B , m;

            temp = My_num.getNumber()[j];
            m.setNumber(temp);

            r -= 48;


            for(int h = 0 ; h < r ; h++)
            {
                B = B + m;
            }

            temp = B.getNumber();


            for(int k = 0 ; k < (My_num.getNumber().size() - j - 1) + (other_num.getNumber().size() - i - 1) ; k++)
            {
                temp.push_back('0');
            }

            B.setNumber(temp);

            Result = Result + B;
        }
    }

    return Result;

//    BigInteger  BigCounter, BigOne;
//    BigOne.setNumber("1");
//    while(BigCounter != this->Number)
//    {
//        Result = Result + otherNumber;
//        BigCounter = BigCounter + BigOne;
//    }
}

BigInteger BigInteger::operator +=(const BigInteger & otherNumber)
{
    BigInteger * Result = this;
    string  other_num = otherNumber.getNumber();
    int dif = this->Number.size() - otherNumber.getNumber().size();

    for(int i = 0 ; i < dif ; i++)
    {
        other_num.insert(other_num.begin(),'0');
    }

    *Result = *Result + otherNumber;

    return *Result;
}

BigInteger BigInteger::operator -=(const BigInteger & otherNumber)
{
    BigInteger * Result = this;
    string  other_num = otherNumber.getNumber();
    int dif = this->Number.size() - otherNumber.getNumber().size();

    for(int i = 0 ; i < dif ; i++)
    {
        other_num.insert(other_num.begin(),'0');
    }

    *Result = *Result - otherNumber;

    return *Result;
}

BigInteger BigInteger::operator *=(const BigInteger &otherNumber)
{
    BigInteger * Result = this;
    string  other_num = otherNumber.getNumber();
    int dif = this->Number.size() - otherNumber.getNumber().size();

    for(int i= 0 ; i < dif ; i++)
    {
        other_num.insert(other_num.begin(),'0');
    }


    *Result = *Result * otherNumber;

    return  *Result;
}


BigInteger  Math_operation(BigInteger & n1,BigInteger & n2,string s)
{
    BigInteger  result;

    if(s == "*")
    {
        result = n1 * n2;
    }
    else if(s == "+")
    {
        result = n1 + n2;
    }
    else if(s == "-")
    {
        result = n1 - n2;
    }
    else if(s == "*=")
    {
        n1 *= n2;
        result = n1;
    }
    else if(s == "+=")
    {
        n1 += n2;
        result = n1;
    }
    else if(s == "-=")
    {
        n1 -= n2;
        result = n1;
    }

    return  result;
}

int main()
{
    BigInteger  num1 , num2;
    string  temp, sign;
    BigInteger  Result;

//    cin >> num1 ;
//    cin >> sign ;
//    cin >> num2 ;

    cin >> temp;
    num1.setNumber(temp);

    cin >> sign;

    cin >> temp;
    num2.setNumber(temp);

//    cout << "num1 : " << num1.getNumber() << endl;
//    cout << "num2 : " << num2.getNumber() << endl;
//    cout << "sign : " << sign << endl;

    Result = Math_operation(num1,num2,sign);

    cout << Result.getNumber() << endl;
}
