/*
    03 - PRATYBOS
    pratybų metu realizuoti:
        loginius elementus per NAND – 1 balas.
        full adderį – 1 balas.
*/

#include <iostream>
using namespace std;

// ------------------------
// -- LOGINIAI ELEMENTAI --
// ------------------------

bool NAND(bool x, bool y)
{
    if (x == 1 && y == 1)
        return 0;
    else
        return 1;
}

bool OR(bool x, bool y)
{
    return NAND(NAND(x, x), NAND(y, y));
}

bool AND(bool x, bool y)
{
    return NAND(NAND(x, y), NAND(x, y));
}

bool NOT(bool x)
{
    return NAND(x, x);
}

bool XOR(bool x, bool y)
{
    bool t = NAND(x, y);
    return NAND(NAND(x, t), NAND(y, t));
}

bool NOR(bool x, bool y)
{
    bool t1 = NAND(x, x);
    bool t2 = NAND(y, y);
    bool t3 = NAND(t1, t2);
    return NAND(t3, t3);
}

// ------------------------
// ----- 1 BITO SUMA ------
// ------------------------

void HALFADDER(bool A, bool B, bool& Sum, bool& Carry)
{
    Sum = XOR(A, B);
    Carry = AND(A, B);
}

void FULLADDER(bool A, bool B, bool Cin, bool& Sum, bool& Cout)
{
    bool s1, c1;
    bool c2;

    HALFADDER(A, B, s1, c1);
    HALFADDER(s1, Cin, Sum, c2);

    Cout = OR(c1, c2);
}

// ------------------------
// ----- 1 BITO ALU -------
// ------------------------

void ONEBITALU(bool A, bool B, bool ENA, bool ENB, bool M0, bool M1, bool CarryIn, bool& CarryOut, bool& Output)
{
    bool A_en = NAND(NAND(A, ENA), NAND(A, ENA));
    bool B_en = NAND(NAND(B, ENB), NAND(B, ENB));

    bool Sum;
    FULLADDER(A_en, B_en, CarryIn, Sum, CarryOut);

    bool t1 = NAND(A_en, B_en);
    bool ANDres = NAND(t1, t1);

    bool notA = NAND(A_en, A_en);
    bool notB = NAND(B_en, B_en);
    bool ORres = NAND(notA, notB);

    bool NOTres = NAND(A_en, A_en);

    if (M1 == 0 && M0 == 0)
        Output = ANDres;
    else if (M1 == 0 && M0 == 1)
        Output = ORres;
    else if (M1 == 1 && M0 == 0)
        Output = Sum;
    else
        Output = NOTres;
}

// ------------------------
// -------- MAIN ----------
// ------------------------

int main()
{
    cout << "\nONE BIT ALU testas:\n";
    cout << "-------------------------------------------\n";
    cout << "A B | M1 M0 | Out Carry\n";
    cout << "-------------------------------------------\n";

    for (int A = 0; A < 2; A++)
    {
        for (int B = 0; B < 2; B++)
        {
            for (int m = 0; m < 4; m++)
            {
                bool M0 = m % 2;
                bool M1 = m / 2;

                bool Out, Carry;

                ONEBITALU(A, B,
                    1, 1,
                    M0, M1,
                    0,
                    Carry, Out);

                cout << A << " " << B
                    << " |  " << M1 << "  " << M0
                    << " |  " << Out
                    << "    " << Carry << "\n";
            }
        }
    }

    cout << "\n";

    cout << " NAND teisingumo lentele:\n";
    cout << "-----------------\n";
    cout << " A  B | Output\n";
    cout << "-----------------\n";

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cout << " " << i << "  " << j
            << " | " << NAND(i, j) << "\n";

    cout << "\n";

    cout << " OR teisingumo lentele:\n";
    cout << "-----------------\n";
    cout << " A  B | Output\n";
    cout << "-----------------\n";

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cout << " " << i << "  " << j
            << " | " << OR(i, j) << "\n";

    cout << "\n";

    return 0;
}
