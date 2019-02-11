/*
 * StockTransactionProgram.c
 *
 *  Created on: February 11, 2019
 *      Author: Ryan Guidry
 */
#include <stdio.h>

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

