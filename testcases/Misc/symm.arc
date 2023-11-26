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

fn main_() : i32 {
    let arr: [[i32]] = [[1, 2], [5, 6]];
    let q: Symmetric<4> = [1, 2, 3, 0] as (Symmetric<4>);
    let u: Matrix<i32> = arr as (Matrix<i32>);
    let v: Matrix<i32> = u + u;
    for i: [i32] in v as ([[i32]]){
        print(i as (str));
    }
    v = u * u;
    for i: [i32] in v as ([[i32]]){
        print(i as (str));
    }

    let s: Matrix<i32> = u + u;
    let t: Matrix<i32> = u * u;

    print("");
    for i: [i32] in s as ([[i32]]){
        print(i as (str));
    }
    print("");
    for i: [i32] in t as ([[i32]]){
        print(i as (str));
    }
}

