#include <stdio.h>
#define gen 0x11021
long int msb(long int temp);
long int checksum(long int frame);
int main()
{
    long int opframe, inframe, flag, r_frame;
    printf("Enter the frame to be transmitted in hex:");
    scanf("%lx", &inframe);
    inframe = inframe << 16;
    opframe = inframe ^ (checksum(inframe));
    printf("The frame to be transmitted is %lx\n", opframe);
    printf("Enter the received frame:");
    scanf("%lx", &r_frame);
    printf("For the received frame\n ");
    flag = checksum(r_frame);
    if (flag > 0)
        printf("\nError!!!!\n");
    else
        printf("\ndata received is error free\n");
}
long int checksum(long int frame)
{
    long int posit_frame, posit_gen, g = gen, g1, temp;
    posit_frame = msb(frame);
    posit_gen = msb(g);
    while (posit_gen <= posit_frame)
    {

        g1 = g << (posit_frame - posit_gen);
        frame = g1 ^ frame;
        posit_frame = msb(frame);
    }
    printf("The checksum is %lx\n", frame);
    return (frame);
}
long int msb(long int temp)
{
    int i = 0;
    if (temp == 0)
        return 0;
    while (temp > 0)
    {
        temp = temp << 1;
        i++;
    }
}