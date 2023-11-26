fn main(): i32 {
    print("Symmetric/Alternating:");
    let x1: [i32] = [1, 0, 5, 4, 7, 2, 3, 6];
    let y1: Symmetric<8> = x1 as (Symmetric<8>);
    let x2: [i32] = [1, 2, 0, 7, 3, 5, 4, 6];
    let y2: Symmetric<8> = x2 as (Symmetric<8>);
    print(y1 as (str));
    print(y2 as (str));
    print("  Product:");

    let y: Symmetric<8> = y1 + y2;
    print(y as (str));
    print("  Alternating:");
    let w1: Alternating<8> = y as ([i32]) as (Alternating<8>);
    print(w1 as (str));

    print("\nBigInt/Rational:");
    let a: BigInt = "1234567890123456789012345678901234567890" as (BigInt);
    let b: BigInt = "4567890123456789012345678901234567890123" as (BigInt);
    let c: BigInt = a + b;
    print(c as (str));
    c = a * b;
    print(c as (str));

    let n: i32 = 6;
    let d: i32 = 8;
    let rat: Rational = (n as (BigInt), d as (BigInt)) as (Rational);
    print(rat as (str));

    print("\nCyclic:");
    let x: Cyclic<5> = 4 as (Cyclic<5>);
    x = x * 7 as (Cyclic<5>);
    print(x as (str));
}
