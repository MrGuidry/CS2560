/**
* @file StockTransactionProgram.c
* @author Ryan Guidry
* @date 11 Feb 2019
* @brief Source File for RestaurantBill part of Homework #2
*/
#include <stdio.h>

/**
* @brief StockTransactionProgram method that declares the cost per share price when shares were bought/sold,
* the commission for each transaction, the amount paid/sold, and the net profit. All of the declarations are 
* displayed on the console.
  @code{.c}
    int shares = 1000;															//Number of shares
	double costPerShareBought = 45.50;											//Cost of each share when bought
	double commission1 = (shares * costPerShareBought) * (.02);					//Commission payed for the purchase of the shares
	double costPerShareSold = 56.90;											//Cost of each share when sold
	double commission2 = (shares * costPerShareSold) * (.02);					//Commission payed for the selling of the shares

	double amountPaid = (shares * costPerShareBought);							//Total amount paid for the shares
	double amountSold = (shares * costPerShareSold);							//Total amount sold for the shares
	double netProfit = amountSold - amountPaid - commission1 - commission2;		//Net profit from the transactions (if negative, then net loss)

	printf("Amount Paid for the Stock: $%.2f\n", amountPaid);					//Printing amount paid for the shares
	printf("Amount of Commission Joe paid during Buy: $%.2f\n",commission1);	//Printing amount Joe paid as commission for the purchase
	printf("Amount Sold for the Stock: $%.2f\n",amountSold);					//Printing amount sold for the shares
	printf("Amount of Commission Joe paid during Sell: $%.2f\n",commission2);	//Printing amount Joe paid as commission for the sale
	printf("Net Profit: $%.2f\n",netProfit);									//Printing net profit from the transactions

	return 0;
  @endcode
* @return Returns an arbitrary @c int in which we use 0.
*/
int StockTransactionProgram(){

	int shares = 1000;															//Number of shares
	double costPerShareBought = 45.50;											//Cost of each share when bought
	double commission1 = (shares * costPerShareBought) * (.02);					//Commission payed for the purchase of the shares
	double costPerShareSold = 56.90;											//Cost of each share when sold
	double commission2 = (shares * costPerShareSold) * (.02);					//Commission payed for the selling of the shares

	double amountPaid = (shares * costPerShareBought);							//Total amount paid for the shares
	double amountSold = (shares * costPerShareSold);							//Total amount sold for the shares
	double netProfit = amountSold - amountPaid - commission1 - commission2;		//Net profit from the transactions (if negative, then net loss)

	printf("Amount Paid for the Stock: $%.2f\n", amountPaid);					//Printing amount paid for the shares
	printf("Amount of Commission Joe paid during Buy: $%.2f\n",commission1);	//Printing amount Joe paid as commission for the purchase
	printf("Amount Sold for the Stock: $%.2f\n",amountSold);					//Printing amount sold for the shares
	printf("Amount of Commission Joe paid during Sell: $%.2f\n",commission2);	//Printing amount Joe paid as commission for the sale
	printf("Net Profit: $%.2f\n",netProfit);									//Printing net profit from the transactions

	return 0;
}

