fn maxOfThree(a: u32, b: u32, c: u32): u32 {
    if (a > b && a > c) {
        return a;
    } else if (b > c) 
        return b;
    } else {
        return c;
    }
}

fn factorial(n: u32): u32 {
    let mut result: u32 = 1;
    for (let i: u32 = 1; i <= n; i++) {
        result *= i
    }
    return result;
}

main(): i32 {
    let num1: u32 = 15, num2: u32 = 20, num3: u32 = 10;
    let maxVal: u32 = maxOfThree(num1, num2, num3);
    print("The maximum value is ");
    print(maxVal);

    let factVal: u32 = factorial(5);
    print("Factorial of 5 is ");
    print(factVal);

    return 0;
}