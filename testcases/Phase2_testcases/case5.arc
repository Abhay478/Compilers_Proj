fn maxOfThree(a: u32, b: u32, c: u32): u32 {
    if (a > b && a > c) {
        return a;
    } else if (b > c) {
        return b;
    } else {
        return c;
    }
}

fn factorial(n: u32): u32 {
    let result = 1;
    for (let i: u32 = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

fn main(): i32 {
    let num1: u32 = 15, num2: u32 = 20, num3: u32 = 10;
    let maxVal: u32 = maxOfThree(num1, num2, num3);
    print("The maximum value is ");
    let max_val: str = maxVal as (str);
    print(max_val);
    print("Enter value of number to calculate factorial of");
    let inp: str;
    input(inp);
    let n: u32 = inp as (u32);
    let factVal: u32 = factorial(n);
    print("Factorial of n is ");
    let fact_val: str = factVal as (str);
    print(fact_val);
    return 0;
}
