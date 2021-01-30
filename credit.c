#include <stdio.h>
#include <cs50.h>
#include <math.h>

// MASTERCARD: 16-Digit #'s, Start with: 51, 52, 53, 54, or 55
// VISA: 13-16-Digit #'s, Start with: 4
// AMEX: 15-Digit #'s, Star with: 34 or 37

// Luhn's Algorithm:
// 1. Multiply every other digit by 2, starting with the second number to the last
// 2. Add the sum of those digits
// 3. Add the sum of the other digits
// 4. If the total sum ends with a 0, it is valid!

int main (void)
{
      // Get card number
    long n = get_long("Number: ");
    // Count length
    int i = 0;
    long cc = n;
    while (cc > 0)
    {
        cc = cc / 10;
        i++;
    }
    // Check if length is valid
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    // Calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long x = n;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;
    do
    {
        // Remove last digit and add to sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
        // Remove second last digit
        mod2 = x % 10;
        x = x / 10;
        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);
    total = sum1 + sum2;
    // Get starting digits
    long start = n;
    do
    {
        start = start / 10;
    }
    while (start > 100);
    // Next check starting digits for card type
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}
