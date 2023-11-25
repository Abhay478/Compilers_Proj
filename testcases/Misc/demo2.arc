fn fibonacci(n: u32): [u32] {
    let fib: [u32] = [0, 1];
    for (let i: u32 = 2; i < n; i++) {
        let next: u32 = fib[i - 1] + fib[i - 2];
        push(fib, next);
    }
    return fib;
}

fn main(): i32 {
    let inp: str = input("Enter length of fibonacci array: ");
    let n: u32 = inp as (u32);

    let fibSeries: [u32] = fibonacci(n);
    for num: u32 in fibSeries {
        print(num as (str));
    }

    return 0;
}