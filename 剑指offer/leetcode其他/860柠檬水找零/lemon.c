#include <stdio.h>
#include <stdbool.h>

/*
Intuition:

When the customer gives us $20, we have two options:

    To give three $5 in return
    To give one $5 and one $10.

On insight is that the second option (if possible) is always better than the first one.
Because two $5 in hand is always better than one $10

Explanation:

Count the number of $5 and $10 in hand.

if (customer pays with $5) five++;
if (customer pays with $10) ten++, five--;
if (customer pays with $20) ten--, five-- or five -= 3;

Check if five is positive, otherwise return false.

Time Complexity

Time O(N) for one iteration
Space O(1)

*/

/*
由于顾客买柠檬水的面值是固定的：5,10,20； 
if(顾客花费==5) five++; 
if(顾客花费==10) five--; ten++; 
if(顾客花费==20) five--; ten--; 或者if(ten < 0) five -= 3; ​ 
*那么我们如何判定终止条件呢？* 我们发现，无论顾客花费多少钱买柠檬水我们要想顺利找零，手中必须要有5美元的零钱；
显然，终止条件是判断if(five < 0);
*/

bool lemonadeChange(int* bills, int billsSize){
    if(bills == NULL || billsSize <=0)
        return false;

    int five = 0;
    int ten = 0;

    for(int i=0;i<billsSize;i++)
    {
        if (bills[i] == 5) five++;
        else if (bills[i] == 10) {five--; ten++;}
        else 
        {
            if (ten > 0) {ten--; five--;} //ten>0优先执行
            else five -= 3;
        }

        if (five < 0) return false; //最后统一判定，手里没5块的就false
    }
    return true;
}
