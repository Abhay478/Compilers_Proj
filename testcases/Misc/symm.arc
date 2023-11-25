fn main(): i32 {
    let x: [i32] = [1, 2, 0, 4, 3];
    let y: Symmetric<5> = x as (Symmetric<5>);

    print(y as (str));

    let w: Alternating<5> = x as (Alternating<5>);
}
