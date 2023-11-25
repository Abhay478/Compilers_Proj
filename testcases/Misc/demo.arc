fn factorial(n: u32): u32 {
    let result: u32 = 1;
    for (let i: u32 = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

fn main(): i32 {
    let inp: str = input("Enter value of number to calculate factorial of: \n");
    let n: u32 = inp as (u32);
    let factVal: u32 = factorial(n);
    print("Factorial of n is ");
    print(factVal as (str));
    return 0;
}