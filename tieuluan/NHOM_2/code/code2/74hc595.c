#define SH PIN_C0
#define DS PIN_C1
#define ST PIN_C2
void khoitao(void);
void dich_byte(int8 nData);
void chot_byte(int8 nData);
void OnLow2High(void);
void ghi_byte(int8 nData);

void khoitao(void)
{
    output_low(SH);
    output_low(DS);
    output_low(ST);
}

void dich_byte(int8 nData)
{
    int8 i, nMask;
    nMask = 0x80;

    for (i = 0; i < 8; i++)
    {
        output_low(SH);

        if (nData & nMask)
            output_high(DS); //DS=1
        else
            output_low(DS); // DS=0

        output_high(SH);
        Delay_us(1);
        output_low(SH);

        nMask = nMask >> 1;
    }
}

void ghi_byte(int8 nData)
{
    output_low(ST);
    dich_byte(nData);
    output_high(ST);
}

