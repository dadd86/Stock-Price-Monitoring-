Stock Price Monitoring Project

This project aims to monitor the stock prices of a specific stock throughout a trading day, 
evaluating its behavior and determining if the sequence of prices exceeds a control based on variations from the first recorded value.
The application enables real-time analysis of stock prices, evaluating upward trends, downward trends, or stability.

Project Description
The program allows users to input stock prices at 10-minute intervals and provides statistics on these prices, such as the number of prices higher, lower, 
or equal to the first value, and whether there is an upward or downward trend.
The system also verifies if the stock price is within trading hours (from 9:00 AM to 5:00 PM) and analyzes prices cumulatively.

Data Structures:
Cotización (Stock Price): Represents a stock price with:
	OrdenCronologico: Chronological order number of the price.
	valor: Value of the stock price at the time it is recorded.
	Structure tm (time and date): Structure used to store the current time and date.

Functionalities:
	Get Current Time: Retrieves the current date and time using the function obtenerHoraActual().
	Verify Trading Hours: Checks if the current time is within trading hours (9:00 AM to 5:00 PM) using the function verificarTiempo().
	Verify 10-Minute Interval: Ensures at least 10 minutes have passed since the last recorded stock price using verificarMinutos().
	Input Stock Price Data: Allows the user to enter stock price data, such as the value and chronological order, through the function EscrituraDatos().
	Print Results: Prints the analysis results, including the average price, the number of prices higher, lower, and equal to the first value, and whether the sequence indicates an upward or downward trend.
	Price Trend Analysis: Determines if the price trend is upward or stable based on the last three recorded prices.
	Consecutive Declines: If four consecutive downward prices are recorded, a downward trend is marked, and the analysis ends.

Program Flow:
	Start: The program checks if the current time is within trading hours. If not, it displays an error message and exits.
	Input Stock Prices: The user inputs stock prices at 10-minute intervals.
	The program calculates the average price, counts the number of prices lower, higher, or equal to the first value, and detects any downward trend (consecutive declines).
	Calculation and Analysis: After recording the stock prices, the program calculates the average and analyzes the price trend, determining if the sequence exceeds a control based on price behavior.
	Results: The program prints a detailed analysis of the stock prices and the detected trend.

Key Functions:
	obtenerHoraActual(): Retrieves the current system time.
	verificarTiempo(): Checks if the current time is within trading hours (9:00 AM to 5:00 PM).
	verificarMinutos(): Verifies if at least 10 minutes have passed since the last recorded price.
	EscrituraDatos(): Allows the user to input stock price data (value and chronological order).
	imprimirResultados(): Prints the final analysis of the stock prices, including their trend.
	tendencia(): Determines if the stock prices are trending upward, stable, or downward.

Requirements:
	Compiler: A C compiler compatible with the C99 standard or higher is required.
	Operating System: Compatible with Windows, Linux, and macOS.

Usage Instructions:
Compilation and Execution:
To compile the project, use a C compiler (e.g., GCC) with the following command:
	gcc -o stock_monitor stock_monitor.c
To run the program, use the following command:
	./stock_monitor

Interaction:
The program checks if the current time is within trading hours (from 9:00 AM to 5:00 PM).
If within trading hours, the user can input stock prices at 10-minute intervals.
At the end of the trading day or when four consecutive declines are detected, the program prints a detailed analysis.

Example Usage:
Input Stock Prices:
	The user enters stock price data, including the value and chronological order. The program records this data for statistical calculations.
Trend Verification:
	The program analyzes the trend of the stock prices, indicating if they are trending upward, stable, or downward, and checks for four consecutive declines.
Analysis Results:
	The program prints the final analysis, including the average price, the number of prices lower, higher, and equal to the first value, 
		and a message indicating whether the sequence is trending upward or downward.

Contributions:
Contributions to the project are welcome. If you want to improve the code, add new features, or fix bugs, please follow these steps:
Fork the repository.
Create a new branch for your changes:
	git checkout -b feature/new-feature
Make your changes and commit them:
	git commit -am 'Add new feature'
Push to the branch:
	git push origin feature/new-feature
Create a pull request describing the changes made.