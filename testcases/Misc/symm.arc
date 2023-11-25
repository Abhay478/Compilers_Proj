fn main(): i32 {
    let x1: [i32] = [1, 3, 4, 2, 0];
    let y1: Symmetric<5> = x1 as (Symmetric<5>);

    let x2: [i32] = [1, 2, 0, 4, 3];
    let y2: Symmetric<5> = x2 as (Symmetric<5>);

    print(y1 as (str));
    print(y2 as (str));

    print("");

    print((y1 + y2) as (str));

    print("");

    let w1: Alternating<5> = x1 as (Alternating<5>);
    print(w1 as (str));

    let w2: Alternating<5> = x2 as (Alternating<5>);
    print(w2 as (str));
}
