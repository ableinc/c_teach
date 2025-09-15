package main

/*
#cgo CFLAGS: -I .
#cgo LDFLAGS: -L . -lcalc
#include "calculator.h"
*/
import "C"

import (
	"fmt"
	"log"
	"os"
	"strconv"
)

func main() {
	args := os.Args[1:]
	if len(args) < 3 {
		fmt.Println("Usage: calculator <operation> <num1> <num2>")
		return
	}

	operation := args[0]
	if err := isValidOperation(operation); err != nil {
		log.Fatalf("Error: %v\n", err)
		return
	}
	num1 := args[1]
	num2 := args[2]
	if err := isValidNumber(num1); err != nil {
		log.Fatalf("Error: %v\n", err)
		return
	}
	if err := isValidNumber(num2); err != nil {
		log.Fatalf("Error: %v\n", err)
		return
	}

	num1Int, _ := strconv.Atoi(num1)
	num2Int, _ := strconv.Atoi(num2)

	switch operation {
	case "add":
		result := _add(num1Int, num2Int)
		fmt.Printf("Result: %d\n", result)
	case "subtract":
		result := _subtract(num1Int, num2Int)
		fmt.Printf("Result: %d\n", result)
	case "multiply":
		result := _multiply(num1Int, num2Int)
		fmt.Printf("Result: %d\n", result)
	case "divide":
		result := _divide(num1Int, num2Int)
		fmt.Printf("Result: %.2f\n", result)
	case "modulus":
		result := _modulus(num1Int, num2Int)
		fmt.Printf("Result: %d\n", result)
	case "power":
		result := _power(num1Int, num2Int)
		fmt.Printf("Result: %d\n", result)
	case "gcd":
		result := _gcd(num1Int, num2Int)
		fmt.Printf("Result: %d\n", result)
	case "lcm":
		result := _lcm(num1Int, num2Int)
		fmt.Printf("Result: %d\n", result)
	default:
		fmt.Println("Unknown operation")
	}
}

func _add(a, b int) int {
	return int(C.add(C.int(a), C.int(b)))
}

func _subtract(a, b int) int {
	return int(C.subtract(C.int(a), C.int(b)))
}

func _multiply(a, b int) int {
	return int(C.multiply(C.int(a), C.int(b)))
}

func _divide(a, b int) float64 {
	return float64(C.divide(C.int(a), C.int(b)))
}

func _modulus(a, b int) int {
	return int(C.modulus(C.int(a), C.int(b)))
}

func _power(a, b int) int {
	return int(C.power(C.int(a), C.int(b)))
}

func _gcd(a, b int) int {
	return int(C.gcd(C.int(a), C.int(b)))
}

func _lcm(a, b int) int {
	return int(C.lcm(C.int(a), C.int(b)))
}

func isValidOperation(operation string) error {
	validOperations := []string{"add", "subtract", "multiply", "divide", "modulus", "power", "gcd", "lcm"}
	for _, op := range validOperations {
		if operation == op {
			return nil
		}
	}
	return fmt.Errorf("invalid operation: %s", operation)
}

func isValidNumber(num string) error {
	// Simple check to see if the string can be converted to an integer
	_, err := strconv.Atoi(num)
	if err != nil {
		return fmt.Errorf("invalid number: %s", num)
	}
	return nil
}
